#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
     vector<string> VS; 
     set<int> neigh[50];
     int vis[50];
string dfs(int root) {
    vis[root] = 1;
    string ans;
    while (true) {
    int minid =-1;
    for (set<int>::iterator iV = neigh[root].begin(); iV!=neigh[root].end(); iV++) 
       if (!vis[*iV])
    {
       if (minid <0) minid = *iV;
       if (VS[*iV].compare(VS[minid]) <0) minid = *iV;
    }
    if (minid <0) break;
    ans += dfs(minid);
    //cout << root << "->"<<minid << endl;
    }


    return VS[root] + ans;
}
using namespace std;
int main() {
  int t;
   cin >> t ;
  for (int ii = 1; ii<=t; ii++) {
     cout <<"Case #"<<ii<<": "; VS.clear();
     int siz,brdge;
     cin >> siz >> brdge ; //string tmp; cin >> tmp;
     for (int i = 0 ; i < siz; i++) {
     string s;
     cin >> s;// s.push_back('#');
     VS.push_back(s);
     neigh[i].clear(); 
     }
     for (int i = 0 ; i < brdge; i++) { 
         int a,b;
        cin >> a >> b;
        neigh[a-1].insert(b-1);
        neigh[b-1].insert(a-1);
     }
     int minid = 0;
     for (int i = 1; i< siz; i++)
         if (VS[i].compare(VS[minid]) < 0)
           minid = i;
     for (int i = 0; i< siz; i++)
         vis[i] = 0;
     cout << dfs(minid) << endl;
  }
  return 0;
}
