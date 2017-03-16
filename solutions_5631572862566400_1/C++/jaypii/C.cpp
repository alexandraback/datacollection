#include <bits/stdc++.h>

#define verbose 0
#define inf 1e9;
using namespace std;

void write(int n, int ans){
   ofstream ofs;
   ofs.open ("out.txt", ios_base::app);
   // ofs << fixed << setprecision(6);
   ofs << "Case #" << n << ": " << ans << endl;
   ofs.close();
}

int reverse_search(int a, int b, vector<int> &F, vector<vector<int> > &pred){
    // reverse search
    queue<pair<int, int> > Q;
    Q.push(make_pair(a, 0));
    int maxdepth = 0;
    while (!Q.empty()){
        pair<int, int> q = Q.front(); Q.pop();
        F[q.first] = -1;
        for (int p: pred[q.first]){
            if (p == b) continue;
            maxdepth = max(maxdepth, q.second+1);
            Q.push(make_pair(p, q.second+1));
        }
    }
    return maxdepth;
}

int solve(){
    int N; cin >> N;
    // cout << "T" << endl;
    vector<int> F(N); vector<vector<int> > pred(N);
    for (int i = 0; i < N; i++){
        int f; cin >> f;
        F[i] = f-1; pred[f-1].push_back(i);
    }

    vector<pair<int, int> > strpairs;
    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            if( F[i] == j && F[j] == i){
                strpairs.push_back(make_pair(i,j));
            }
        }
    }

    int retpl = 0; int reto = 0;

    for (pair<int, int> p: strpairs){
        retpl += reverse_search(p.first, p.second, F, pred) + reverse_search(p.second, p.first, F, pred) + 2;
    }

    int start = 0;
    while (start < N){
        if (F[start] != -1){
            int i = start;
            vector<int> vis; vis.push_back(i);
            while (F[i] != -1){
                vis.push_back(F[i]);
                int iold = i;
                i = F[i];
                F[iold] = -1;
            }
            if (i == vis[0]){
                // circle
                reto = max(reto, (int) vis.size()-1);
                // cout << "b" << endl;
            }
            else{
                int index = 0;
                while( i != vis[index]){
                    index++;
                }
                reto = max(reto, (int)vis.size()- 1 - index);
                // cout << "d" << endl;
            }
        }
        start++;
    }

    return max(retpl, reto);
}

int main(void){
   remove("out.txt");
   int T;
   cin >> T;
   for (int i = 0; i < T; i++){
       write(i+1, solve());
   }
   return 0;
}
