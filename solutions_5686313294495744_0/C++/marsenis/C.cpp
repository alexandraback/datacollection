#include <algorithm>
#include <map>
#include <cstdio>
#include <string>
#include <vector>

/* Source: https://github.com/flxf/maximum-bipartite-matching/blob/master/bipartite_matching.cpp */
/* ------------------------------------ */
#define uint unsigned int
#define UNMATCHED 0xffffffff
#define MAX_INSTANCE_SIZE 1000

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
/* ------------------------------------ */

#define MAX 1005
char s1[MAX], s2[MAX];
string st1, st2;
map<string, int> mp1, mp2;
map<int, string> rev_mp1, rev_mp2;
int id;

int main() {
   int T, n;

   scanf("%d", &T);
   for (int t = 1; t <= T; t++) {
      scanf("%d", &n);
      id = 0;
      mp1.clear(); mp2.clear();
      rev_mp1.clear(); rev_mp2.clear();
      fill(matched, matched + MAX_INSTANCE_SIZE, UNMATCHED);
      
      for (int i = 0; i < n; i++) {
         int v1, v2;
         scanf(" %s %s", s1, s2);
         st1 = s1; st2 = s2;
         if (mp1.find(st1) == mp1.end()) mp1[st1] = id++;
         v1 = mp1[st1]; rev_mp1[v1] = st1;
         if (mp2.find(st2) == mp2.end()) mp2[st2] = id++;
         v2 = mp2[st2]; rev_mp2[v2] = st2;

         graph[v1].push_back(v2);
         graph[v2].push_back(v1);
      }

      size_A = mp1.size();

      /* Source: https://github.com/flxf/maximum-bipartite-matching/blob/master/bipartite_matching.cpp */
      /* ------------------------------------ */
      uint size_matching = 0;
      for (uint i = 0; i < id; i++) {
        if (matched[i] == UNMATCHED) {
          fill(visited, visited + MAX_INSTANCE_SIZE, false);
          if (augment_path(i)) {
            size_matching++;
          }
        }
      }
     /* ------------------------------------ */

     int cnt = size_matching;
     //printf("size = %d\n", cnt);
     for (uint i = 0; i < id; i++) {
       if (matched[i] == UNMATCHED)
         cnt++;
         /*
         if (rev_mp1.find(i) != rev_mp1.end())
            printf("%s -> %s\n", rev_mp1[i].c_str(), rev_mp2[matched[i]].c_str());
            */
     }
     printf("Case #%d: %d\n", t, n - cnt);

     for (int i =0 ; i < id; i++) graph[i].clear();
   }

  return 0;
}
