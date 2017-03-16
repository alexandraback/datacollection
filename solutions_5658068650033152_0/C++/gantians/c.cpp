#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

typedef pair<int,int> PII;
int t,n,m,k;
int f[11],hash[1025];
string a[11];
string ans[110000];
map<PII,string> g;
int bo;
vector<int> e[10];
int stack[110000];
int mask[1100000];


int main(){
    freopen("C-small-attempt0 (1).in","r",stdin);
    freopen("1.out","w",stdout);
    cin >> t;
    for (int ti=1;ti<=t;ti++){
        scanf("%d%d%d",&n,&m,&k);
        cout << "Case #"<<ti<<": ";
        int cnt=k;
        if (n>2 && m>2){
           n-=2;
           m-=2;
           for (int i=1;i<=n;i++)
               for (int j=1;j<=m;j++){
                   //if (i*j*3>k) break;
                   int tot=i*j+2*(i+j);
                   int ans=2*(i+j);
                   if (tot>=k) cnt=min(cnt,ans);
                      else cnt=min(cnt,ans+k-tot);
               }
        }
        cout<<cnt<<endl;
    }
    //system("pause");
    return 0;
}
