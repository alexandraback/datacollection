#include <iostream>
#include <vector>
#include <queue>

using namespace std;



struct vertex {
       bool visited;
       vector<int> nb;
};



bool bfs (vector<vertex> &g, int a){

     queue<int> q;
     q.push(a);
     while (!q.empty()) {
           int v=q.front();
           q.pop();
           if (g[v].visited) return true;
           else {
              g[v].visited=1;
              for (int i=0;i<g[v].nb.size();i++) q.push(g[v].nb[i]);
           }
     }
     return false;

}



bool graph () {

     vector<vertex> g;

     int n;
     cin >> n;


     g.resize(n+1);

     for (int x=1;x<=n;x++){
         int m;
         cin >> m;
         for (int y=0;y<m;y++){
             int a;
             cin >> a;
             g[x].nb.push_back(a);
         }
     }

     for (int j=1;j<g.size();j++){
         for (int i=1;i<g.size();i++) g[i].visited=0;

         if (bfs(g,j)) return true;

     }
     return false;

}


int main()
{
    int t;
    cin >> t;
    for (int i=1;i<=t;i++){
        cout << "Case #" << i << ": ";
        if (graph()) cout << "Yes";
        else cout << "No";
        cout << "\n";

    }
    return 0;
}
