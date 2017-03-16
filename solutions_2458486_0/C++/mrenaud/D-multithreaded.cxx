#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <utility>



// Treasure chest.
struct chest
{
  int num;
  int key_to_open;
  std::multiset<int> keys;
};


// Comparison operator for storing in a set.
bool operator <(chest const& lhs, chest const& rhs)
{
  return lhs.num < rhs.num;
}

bool operator ==(chest const& lhs, chest const& rhs)
{
  return lhs.key_to_open == rhs.key_to_open && lhs.keys == rhs.keys;
  // return lhs.num == rhs.num;
}


namespace std {

// Adapted from boost.functional.hash.
template <typename T>
struct hash< std::multiset<T> >
{
  size_t operator ()(std::multiset<T> const& ms)
  {
    size_t seed = 0;
    for (int i : ms)
      seed ^= std::hash<T>()(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    return seed;
  }
};


template <typename T>
struct hash< std::set<T> >
{
  size_t operator ()(std::set<T> const& ms)
  {
    size_t seed = 0;
    for (T const& i : ms)
      seed ^= std::hash<T>()(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    return seed;
  }
};


template <>
struct hash<chest>
{
  std::size_t operator ()(chest const& c) const
  {
    std::hash<int> int_hash;
    std::hash< std::multiset<int> > ms_hash;

    return int_hash(c.key_to_open) ^ ms_hash(c.keys);
  }
};


template <>
struct hash<tuple<set<chest>, multiset<int> > >
{
  std::size_t operator ()(tuple<set<chest>, multiset<int> > const& c) const
  {
    return hash<set<chest> >()(get<0>(c)) ^ hash<multiset<int> >()(get<1>(c));
  }
};

} // namespace std



// Istream overload to read in chests.
std::istream& operator >>(std::istream& is, chest& ch)
{
  int key;
  int num_keys_inside;

  is >> key >> num_keys_inside;

  // Set the key needed to open the chest.
  ch.key_to_open = key;

  // Add all of the keys inside the chest.
  for (int i = 0; i < num_keys_inside; ++i)
  {
    is >> key;
    ch.keys.insert(key);
  }

  return is;
}

std::ostream& operator <<(std::ostream& os, chest const& ch)
{
  os << "(" << ch.num << "," << ch.key_to_open << ")";
  return os;
}


// Search through the available chests looking for a solution.
// Return <true, seq> if a path is found.
//
bool dfs(
  std::set<chest> const& chests,
  std::multiset<int> const& keys,
  std::vector<int>& path,
  std::unordered_set<
    std::tuple<std::set<chest>, std::multiset<int> >
  >&
  failed_branches
)
{
  // If the current chest, key combination has already failed, stop here.
  if (failed_branches.find(std::make_tuple(chests,keys)) != failed_branches.end())
    return false;

  // We found a path!
  if (chests.empty())
    return true;

  // If there are no keys, we can't do anything else.
  if (keys.empty())
  {
    failed_branches.insert(std::make_tuple(chests, keys));
    return false;
  }

  // Go through each available chest and try the path starting with that chest.
  std::set<chest>::iterator c = chests.begin();
  for (; c != chests.end(); ++c)
  {
    // If we can unlock this chest, call dfs removing the chest and
    // the key needed to open it.
    if (keys.find(c->key_to_open) != keys.end())
    {
      // Remove the key needed to open this chest and add all the
      // keys found in the chest.
      std::multiset<int> updated_keys(keys);
      updated_keys.erase(updated_keys.find(c->key_to_open));
      updated_keys.insert(c->keys.begin(), c->keys.end());

      // Remove the current chest from the set of chests availeble.
      std::set<chest> updated_chests(chests);
      updated_chests.erase(updated_chests.find(*c));

      // Add the current chest to the path.
      path.push_back(c->num + 1);

      bool dfs_res = dfs(
        updated_chests,
        updated_keys,
        path,
        failed_branches
      );

      // If a path was found, return.
      if (dfs_res == true)
        return true;

      // If not, remove the chest from the path and go to the next chest.
      path.pop_back();

    }
  }

  // No path. Add the current state to the set of failed states.
  failed_branches.insert(std::make_tuple(chests, keys));
  return false;
}



void solve()
{
  int K, N;
  std::set<chest> chests;

  // Read in number of keys and chests.
  std::cin >> K >> N;

  // Read in keys.
  std::multiset<int> keys;
  for (int i = 0; i < K; ++i)
  {
    int key;
    std::cin >> key;
    keys.insert(key);
  }

  // Read in the chests.
  for (int i = 0; i < N; ++i)
  {
    chest ch;
    std::cin >> ch;
    ch.num = i;
    chests.insert(ch);
  }

  // DEBUG:
  // std::cout << "Keys: ";
  // std::copy(
  //   keys.begin(), keys.end(),
  //   std::ostream_iterator<int>(std::cout, " ")
  // );
  // endl(std::cout);

  // std::cout << "Chests: ";
  // std::copy(
  //   chests.begin(), chests.end(),
  //   std::ostream_iterator<chest>(std::cout, " ")
  // );
  // endl(std::cout);

  // Prechecks...

  std::multiset<int> available_keys(keys.begin(), keys.end());
  for (chest const& c : chests)
    available_keys.insert(c.keys.begin(), c.keys.end());

  std::map<int,int> keys_needed;

  for (chest const& c : chests)
    ++keys_needed[c.key_to_open];


  // Make sure that there are enough keys to open all the chests.
  for (std::pair<int,int> const& p_key_count : keys_needed)
    if (available_keys.count(p_key_count.first) < p_key_count.second)
    {
      std::cout << "IMPOSSIBLE\n";
      return;
    }


  std::unordered_set<
    std::tuple<std::set<chest>, std::multiset<int> >
  >
    failed_branches;

  std::vector<int> path;

  // Solve using DFS.
  // std::pair<bool,std::vector<int>> res = dfs(
  bool res = dfs(
    chests,
    keys,
    path,
    failed_branches
  );

  if (res == true)
  {
    std::copy(
      path.begin(), path.end(),
      std::ostream_iterator<int>(std::cout, " ")
    );
    endl(std::cout);
  }
  else
  {
    std::cout << "IMPOSSIBLE\n";
  }

}


int main()
{
  int T;
  std::cin >> T;

  for (int i = 1; i <= T; ++i)
  {
    std::cout << "Case #" << i << ": ";
    solve();
  }
}
