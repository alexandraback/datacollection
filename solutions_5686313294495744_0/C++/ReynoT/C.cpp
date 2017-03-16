// =====================================================================================
//
//       Filename:  C.cpp
//         Author:  Reyno Tilikaynen, r.tilikaynen@gmail.com
//   Organization:  University of Waterloo
//
// =====================================================================================

#include <bits/stdc++.h>

using namespace std; 

int main (){ 
    int tt; 
    cin >> tt; 
    for (int cases = 1; cases <= tt; cases++){
        printf ("Case #%d: ", cases);
        int n; 
        cin >> n;
        vector <pair <string, string> > topics (n);
        unordered_map <string, int> f;
        unordered_map <string, int> s;
        int cap [2*n+2][2*n+2];
        vector <int> adj [2*n+2];
        for (int i = 0; i < 2*n+2; i++)
            for (int j = 0; j < 2*n+2; j++)
                cap[i][j] = 0;
        int nf = 1, ns = n+1;
        for (int i = 0; i < n; i++){
            string ss, t; 
            cin >> ss >> t;
            topics[i] = pair <string, string> (ss, t);
            if (f[ss] == 0)
                f[ss] = nf++;
            if (s[t] == 0)
                s[t] = ns++;
            adj[f[ss]].push_back (s[t]);
            cap[f[ss]][s[t]] = 1;
        }
        for (int i = 1; i < nf; i++){
            adj[0].push_back (i);
            cap[0][i] = 1;
        }
        for (int i = n+1; i < ns; i++){
            adj[i].push_back (2*n+1);
            cap[i][2*n+1] = 1;
        }
        int totalflow = 0, maxloc;
        while (1){
            vector <int> prev (2*n+2, -1);
            vector <int> flow (2*n+2, 0);
            vector <bool> visited (2*n+2, false);
            flow[0] = 3*n;
            while (1){
                int maxflow = 0;
                maxloc = -1;
                for (int i = 0; i < 2*n+2; i++){
                    if (i >= nf && i <= n || i >= ns && i <= 2*n)
                        continue;
                    if (flow[i] > maxflow && !visited[i]){
                        maxflow = flow[i];
                        maxloc = i;
                    }
                }
                if (maxloc == -1)
                    break;
                if (maxloc == 2*n+1)
                    break;
                visited[maxloc] = true;
                for (int i = 0; i < adj[maxloc].size (); i++){
                    int next = adj[maxloc][i];
                    if (flow[next] < min (maxflow, cap[maxloc][next])){
                        prev[next] = maxloc;
                        flow[next] = min (maxflow, cap[maxloc][next]);
                    }
                }
            }
            if (maxloc == -1)
                break;
            int pathcap = flow[2*n+1];
            totalflow = totalflow + pathcap;
            int cur = 2*n+1;
            while (cur){
                int next = prev[cur];
                cap[next][cur] -= pathcap;
                cap[cur][next] += pathcap;
                cur = next;
            }
        }
        cout << n - (f.size () + s.size () - totalflow) << "\n";
   }
}
