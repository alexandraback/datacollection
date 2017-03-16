#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <cstring>

using namespace std;

class Chest
{
public:
  Chest(int id, int &lock, vector<int> &items)
  {
    this->id = id;
    this->lock = lock;
    this->items = items;
    this->open = false;
  }

  int         id;
  int         lock;
  bool        open;
  vector<int> items;
};

class State
{
public:
  typedef pair<vector<bool>, vector<short> > cache_key;

  vector<bool>  open;
  vector<short> keys;
  list<int>     path;
  vector<Chest> &chests;

  State(vector<short> keys, vector<Chest> &chests) : chests(chests), open(chests.size())
  {
    this->keys = keys;
  }

  cache_key key()
  {
    return cache_key(open, keys);
  }

  bool solved() const
  {
    return path.size() == chests.size();
  }
};

State*  find_path(map<State::cache_key, bool> &cache, State *state)
{
  if (cache[state->key()])
  {
    return NULL;
  }
  if (state->solved())
  {
    return state;
  }
  else
  {
    for(int i = 0; i < state->chests.size(); i++)
    {
      Chest &chest = state->chests[i];
      if ((!state->open[i]) && (state->keys[chest.lock] > 0))
      {
        State *child = new State(*state);
        child->open[i] = true;
        child->keys[chest.lock] -= 1;
        for(int i = 0; i < chest.items.size(); i++)
          child->keys[chest.items[i]] += 1;
        child->path.push_back(chest.id);

        State *result;
        if (result = find_path(cache, child))
          return result;
        delete child;
      }
    }
    cache[state->key()] = true;
    return NULL;
  }
}

int main(int argc, char const *argv[])
{
  if (argc >= 1) {
    ifstream  file;
    int       cases;

    file.open(argv[1]);
    file >> cases;
    // cout << cases << " cases:" << endl;
    for (int j = 0; j < cases; j++) {
      int           key_count, chest_count;
      vector<short> keys(200);
      vector<Chest> chests;
      list<int>     path;

      file >> key_count >> chest_count;
      // cout << key_count << " keys, " << chest_count << " chests" << endl;
      for (int k = 0; k < key_count; k++) {
        int key;

        file >> key;
        keys[key]++;
      }
      for (int c = 0; c < chest_count; c++) {
        int lock, size;
        vector<int> items;

        file >> lock >> size;
        for (int i = 0; i < size; i++) {
          int item;

          file >> item;
          items.push_back(item);
        }
        chests.push_back(Chest(c+1, lock, items));
      }
      cout << "Case #" << j+1;
      State *start = new State(keys, chests);
      map<State::cache_key, bool> cache;
      State *result;
      if (result = find_path(cache, start))
      {
        for(list<int>::iterator it = result->path.begin(); it != result->path.end(); ++it)
          cout << " " << *it;
        cout << endl;
      }
      else
      {
        cout << " IMPOSSIBLE" << endl;
      }
    }
    file.close();
    return 0;
  }
  return 1;
}