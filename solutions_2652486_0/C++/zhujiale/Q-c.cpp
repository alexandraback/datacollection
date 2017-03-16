#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <string>

using namespace std;

int T,t;
int r,n,m,k,f[100];

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    cin>>T;
    cout<<"Case #1:"<<endl;
    while (t<T){
        t++;
        cin>>r>>n>>m>>k;
        int flag = 0;
        for (int i = 1; i<=r; i++){
            flag = 0;
            for (int j = 1; j<=k; j++) cin>>f[j];
            for (int a = 2; a<=m; a++){
                if (flag) break;
                for (int b = 2; b<=m; b++){
                    if (flag) break;
                    for (int c = 2; c<=m; c++){
                        flag = 1;
                        for (int j = 1; j<=k; j++){
                            int tmp = f[j];
                            if (tmp==1) continue;
                            else if(a*b==tmp||b*c==tmp||a*c==tmp||a*b*c==tmp||a==tmp||b==tmp||c==tmp) continue;
                            else {flag = 0; break;}
                        }
                        if (flag){cout<<a<<b<<c<<endl;break;}
                    }
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
}
