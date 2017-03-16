#include <iostream>
#include <fstream>
using namespace std;

long long v[10005],ans;

long long max(long long a,long long b){
          if (a<b) return b;
                    else return a;
}

void dfs(int E, int i, int s, int e, int r, int n)
{
        if (i == n || E==0){
                ans = max(ans, s);
                return;
        }

        for (int j = 0; j <= E; ++j)
        {
                int se = E - j + r;
                if (se > e)se = e;
                dfs(se, i + 1, s + j * v[i],e,r,n);
        }
}

int main() {
          ifstream cin("B-small-attempt0 (1).in");
          ofstream cout("b-large.txt");
          int T;
          cin >> T;
          for(int ti=1; ti<=T; ti++){
                    long long e, r, n;

                    cin >> e >> r >> n;

                    for (int i = 0; i < n; i++){
                        cin >> v[i];
                    }

                ans = 0;
                dfs(e, 0, 0,e,r,n);
                cout << "Case #" << ti << ": " << ans << endl;
          }
          return 0;
}
