#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <stdint.h>

using namespace std;

typedef int64_t int64;


void diamond(int argc, char* argv[])
{
  int num_tests;
  cin >> num_tests;

  for (int i = 0; i < num_tests; ++i) {

    map<int, vector<int>> graph;

    int num_classes;
    cin >> num_classes;
    for (int j = 0; j < num_classes; ++j) {
      int num_inherit;
      cin >> num_inherit;
      for (int k = 0; k < num_inherit; ++k) {
        int parent;
        cin >> parent;
        graph[parent].push_back(j+1);
      }
    }

    bool found_cycle = false;
    for (int j = 0; j < num_classes; ++j) {
      stack<int> unvisited;
      set<int> visited;
      unvisited.push(j+1);
      while (!unvisited.empty()) {
        int parent = unvisited.top();
        unvisited.pop();
        auto it = visited.find(parent);
        if (it != visited.end()) {
          // cycle
          found_cycle = true;
          goto done;
        }
        visited.insert(parent);
        auto jj = graph.find(parent);
        if (jj != graph.end()) {
          const vector<int> &children = jj->second;
          for (int k = 0; k < (int)children.size(); ++k) {
            unvisited.push(children[k]);
          }
        }
      }
    }

done:;
    printf("Case #%d: %s\n", i + 1, found_cycle ? "Yes" : "No");

  }
}

struct box {
  box(int64 count, int64 item) : count(count), item(item) {}
  int64 count;
  int64 item;
};

int64 max_score = 0;

void bb(const deque<box> &boxes, const deque<box> &toys, int64 score) {
  if (boxes.empty() || toys.empty()) {
    if (score > max_score) {
      max_score = score;
    }
    return;
  }

  int64 best_possible = 0;
  map<int64, int64> box_max;
  for (int i = 0; i < boxes.size(); ++i)
    box_max[boxes[i].item] += boxes[i].count;

  map<int64, int64> toy_max;
  for (int i = 0; i < toys.size(); ++i)
    toy_max[toys[i].item] += toys[i].count;

  for (auto it = begin(box_max); it != end(box_max); ++it) {
    int64 item = it->first;
    best_possible += min(box_max[item], toy_max[item]);
  }

  if (score + best_possible <= max_score)
    return;

  auto &b = boxes.front();
  auto &t = toys.front();

  // throw away box
  {
    auto nb(boxes);
    nb.pop_front();
    if (!nb.empty())
      bb(nb, toys, score);
  }

  // throw away toy
  {
    auto nt(toys);
    nt.pop_front();
    if (!nt.empty())
      bb(boxes, nt, score);
  }

  if (b.item == t.item) {
    auto nb(boxes);
    auto nt(toys);
    int64 to_use = min(b.count, t.count);
    int64 new_score = score + to_use;

    if (to_use == b.count) {
      nb.pop_front();
    } else {

      int64 t_left = 0;
      for (int i = 0; i < toys.size(); ++i) {
        if (toys[i].item == b.item)
          t_left += toys[i].count;
      }

      t_left = max<int64>(0L, t_left - to_use);

      if (t_left == 0) {
        nb.pop_front();
      } else {
        nb.front().count -= to_use;
      }

    }

    if (to_use == t.count) {
      nt.pop_front();
    } else {

      int64 t_left = 0;
      for (int i = 0; i < boxes.size(); ++i) {
        if (boxes[i].item == b.item)
          t_left += boxes[i].count;
      }

      t_left = max<int64>(0L, t_left - to_use);

      if (t_left == 0) {
        nt.pop_front();
      } else {
        nt.front().count -= to_use;
      }
    }
    bb(nb, nt, new_score);
  }

}

void box_thing(int argc, char* argv[])
{
  int num_tests;
  cin >> num_tests;

  for (int i = 0; i < num_tests; ++i) {

    max_score = 0;
    int M, N;
    cin >> N >> M;

    deque<box> boxes;
    deque<box> toys;
    set<int64> n_items, m_items;
    for (int n = 0; n < N; ++n) {
      int64 a, b;
      cin >> a >> b;
      boxes.push_back(box(a, b));
      n_items.insert(b);
    }

    for (int n = 0; n < M; ++n) {
      int64 a, b;
      cin >> a >> b;
      auto it = n_items.find(b);
      if (it != n_items.end()) {
        if (!toys.empty()) {
          if (toys.back().item == b) {
            toys.back().count += a;
          } else {
            toys.push_back(box(a, b));
          }
        } else {
          toys.push_back(box(a, b));
        }
      }
    }

    bb(boxes, toys, 0);

    printf("Case #%d: %I64d\n", i + 1, max_score);
  }
}


int main(int argc, char* argv[])
{
  box_thing(argc, argv);
  return 0;
}
