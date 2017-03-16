#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int a[30][30];

int main(){
    int t,n,m,c;
    //freopen("A-large.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin >> t;
    for(int ca=1;ca<=t;ca++){
        cin>>n>>m>>c;
        memset(a,0,sizeof(a));
        int cnt=1;
        int s=c;
        while(m-s>=c){
            s+=c;cnt++;
        }
        cnt*=n;
        if(c!=1){
            cnt+=c;
            if(s==m) cnt--;
        }
        printf("Case #%d: %d\n",ca,cnt);
    }
}
