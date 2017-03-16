#include <iostream>
#include <algorithm>
#include <vector>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int tt,t,n,a[1100],c[1100],f[1100], r[1100], lst, result;
vector<int> b[1100];

int dfs(int p, int prev, int root){
    f[p] = 1;
    if(f[a[p]]!=0){
        if(a[p] == prev){
            lst = p;
            return c[p] = 1;
        }
        if(a[p] == root){
            return c[p] = 1;
        }
        else {
            lst = -2;
            return c[p] = 0;
        }
    }
    c[p] = dfs(a[p], p, root)+1;
    return c[p];
}

int dfs2(int c){
    int maxdep = 0;
    rep(i,b[c].size()){
        if(f[b[c][i]]==0){
           maxdep = max(maxdep, dfs2(b[c][i]) + 1); 
        }
    }
    return maxdep;
}



int main()
{
    cin >> tt;
    rep(ii,tt)
    {
        cin >> n;
        result = 0;
        lst = -1;

        rep(i,n){
            b[i].clear();
            f[i] = 0;
            a[i] = 0;
            c[i] = 0;
            r[i] = 0;
        }
        rep(i,n){
            cin >> t;t--;
            a[i] = t;
            b[t].push_back(i);
        }

        rep(i,n) 
        {
            int cr = 0;
            rep(j,n){f[j] = 0;c[j]=0;}
            lst = -1;
            cr = dfs(i, -1, i);
            if(lst == -2)continue;

            if(lst >= 0){
                cr += dfs2(lst);
            }
            result = max(result, cr);
        }
        cout << "Case #"<<ii+1<<": " << result <<endl;

    }
}
