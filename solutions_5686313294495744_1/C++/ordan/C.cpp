#include <bits/stdc++.h>
#define N 1123

using namespace std;

vector <int> graph[N];
int l[N], r[N];
bool marcado[N];

bool dfs (int v){
    if (marcado[v]) return false;
    marcado[v] = true;
    for (int i = 0; i < graph[v].size(); i++)
        if (r[graph[v][i]] == -1 || dfs (r[graph[v][i]])){
            r[graph[v][i]] = v;
            l[v] = graph[v][i];
            return true;
        }
    return false;
}

int _max (int n){
    int k = 0;
    for (int i = 0; i < n; i++){
        memset(marcado, false, sizeof marcado);
        k += dfs (i);
    }
    return k;
}


int main(){
    int TESTS;
    scanf ("%d", &TESTS);
    for (int CASE = 1; CASE <= TESTS; CASE++){
        int li = 0, ri = 0;
        map <string, int> L;
        map <string, int> R;
        memset(l, -1, sizeof l);
        memset(r, -1, sizeof r);
        printf ("Case #%d:", CASE);
        int n;
        scanf ("%d", &n);
        for (int i = 0; i < n; i++) graph[i].clear();
        for (int i= 0; i < n; i++){
            string a, b;
            cin >> a >> b;
            if (L.find(a) == L.end()){
                L[a] = li++;
            }
            if (R.find(b) == R.end()){
                R[b] = ri++;
            }
            graph[L[a]].push_back (R[b]);
        }
        int k = _max (li);
        for (int i= 0; i < li; i++)
            if (l[i] == -1) k++;

        for (int i= 0; i < ri; i++)
            if (r[i] == -1) k++;
        printf (" %d\n", n - k);
    }
    return 0;
}
