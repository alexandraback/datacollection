#include <iostream>
#include <vector>
#include <string>
#include <map>


#define debug false

using namespace std;

#define uint unsigned int
#define UNMATCHED 0xffffffff


#define MAX_INSTANCE_SIZE 2000

using namespace std;

uint size_A, size_B, num_edges;

vector<uint> graph[MAX_INSTANCE_SIZE];

uint matched[MAX_INSTANCE_SIZE];

bool visited[MAX_INSTANCE_SIZE];

typedef struct _vertex {
  char type;
  uint id;
} vertex;


uint vertex_to_uid(vertex v) {
  return ((v.type == 'A') ? 0 : size_A) + v.id;
}

vertex uid_to_vertex(uint uid) {
  vertex ret;
  if (uid < size_A) {
    ret = (vertex) { 'A', uid };
  } else {
    ret = (vertex) { 'B', uid - size_A };
  }
  ret.type = (uid < size_A) ? 'A' : 'B';
  ret.id = (uid < size_A) ? uid : uid - size_A;
  return ret;
}

bool augment_path(uint uid) {
  visited[uid] = true;

  for (uint i = 0; i < graph[uid].size(); i++) {
    uint neighbour = graph[uid][i];
    if (visited[neighbour]) {
      continue;
    }

    if (matched[neighbour] == UNMATCHED) {
      matched[uid] = neighbour;
      matched[neighbour] = uid;
      return true;
    } else if (matched[neighbour] != uid) {

      visited[neighbour] = true;
      if (augment_path(matched[neighbour])) {
        matched[uid] = neighbour;
        matched[neighbour] = uid;
        return true;
      }
    }
  }

  return false;
}
int main() {
  int T;
  cin >> T;
  for (int round = 1;round <= T;round++) {
    int ans = 0;
    int orig = 0;
    int n;
    map<string,int> left,right;
    map<string,bool> left_covered,right_covered;
    vector<pair<string,string>> topic;
    cin >> n;
    for (int i = 0;i < n;i++) {
      string s1,s2;
      cin >> s1 >> s2;
      topic.push_back({s1,s2});
      left[s1]++;
      right[s2]++;
    }

    //remove obvious original
    vector<pair<string,string>> remain;
    for (auto &t : topic ) {
      bool remove = false;
      if (left.find(t.first) != left.end() && left[t.first] == 1) {
        remove = true;
      }
      if (right.find(t.second) != right.end() && right[t.second] == 1) {
        remove = true;
      }
      if (!remove) {
        remain.push_back(t);
      } else {
        left_covered[t.first] = true;
        right_covered[t.second] = true;
        orig++;
      }
    }

    //do matching
    map<string,int> left_to_id;
    map<string,int> right_to_id;
    int lid  = 0 ;
    int rid  = 0 ;

    fill(matched, matched + MAX_INSTANCE_SIZE, UNMATCHED);
    size_A = n;
    size_B = n;
    for (int i = 0;i < MAX_INSTANCE_SIZE;i++) {
      graph[i].clear();
    }
    for (auto &t : remain) {
      if (!left_covered[t.first] && left_to_id.find(t.first) == left_to_id.end()) {
        left_to_id[t.first] = lid++;
      }
      if (!right_covered[t.second] && right_to_id.find(t.second) == right_to_id.end()) {
        right_to_id[t.second] = rid++;
      }
      if ( !(!left_covered[t.first] && !right_covered[t.second]) ) {
        //this topic cannot cover both words
        continue;
      }
      vertex va,vb;
      va.type = 'A';
      va.id = left_to_id[t.first];
      vb.type = 'B';
      vb.id = right_to_id[t.second];

      int uid_A = vertex_to_uid(va);
      int uid_B = vertex_to_uid(vb);

      graph[uid_A].push_back(uid_B);
      graph[uid_B].push_back(uid_A);
    }

    uint size_matching = 0;
    for (uint i = 0; i < size_A; i++) {
      if (matched[i] == UNMATCHED) {
        fill(visited, visited + MAX_INSTANCE_SIZE, false);
        if (augment_path(i)) {
          size_matching++;
        }
      }
    }

    //debug
    if (debug) {
      printf(" n = %d\n",orig);
      printf(" orig = %d\n",orig);
      printf(" left remain = %d\n",lid);
      printf(" right remain = %d\n",rid);
      printf(" maching = %d\n",size_matching);
    }
    ans = n - size_matching - orig - (lid - size_matching) - (rid - size_matching);

    printf("Case #%d: %d\n",round,ans);

  }
}

