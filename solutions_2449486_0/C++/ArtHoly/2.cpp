#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int map[101][101];
int n,m,T;

bool check(){
     for (int i=0;i<n;i++)
         for (int j=0;j<m;j++){
             bool col=0,row=0;
             for (int k=i+1;k<n;k++) if (map[k][j]>map[i][j]){col=1;break;}
             for (int k=i-1;k>=0;k--) if (map[k][j]>map[i][j]){col=1;break;}
             for (int k=j+1;k<m;k++) if (map[i][k]>map[i][j]){row=1;break;}
             for (int k=j-1;k>=0;k--) if (map[i][k]>map[i][j]){row=1;break;}
             if (row && col) return 0;
         }
     return 1;
}

int main()
{
    freopen("2.in","r",stdin);
    freopen("2.out","w",stdout);
    cin>>T;
    for (int Case=1;Case<=T;Case++){
        cin>>n>>m;
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin>>map[i][j];
        cout<<"Case #"<<Case<<": "; 
        if (check()) cout<<"YES"<<endl;else cout<<"NO"<<endl;
    }
} 
