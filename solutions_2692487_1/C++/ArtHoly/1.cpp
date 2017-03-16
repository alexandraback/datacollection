#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int n,m,T;
int a[10000001]; 

int exitnow(int a){
    return m-a+1;
}

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    cin>>T;
    for (int Case=1;Case<=T;Case++){
        cin>>n>>m;
        int now=n;
        for (int i=1;i<=m;i++) cin>>a[i];
        if (now==1){cout<<"Case #"<<Case<<": "<<m<<endl;continue;} 
        sort(a+1,a+m+1);
        //for (int i=1;i<=m;i++) cout<<a[i]<<" ";cout<<endl; 
        int ans=2147483647;
        int cnt=0;
        for (int i=1;i<=m;i++){
            ans=min(ans,cnt+exitnow(i));
            while (now<=a[i]){cnt++;now=now*2-1;}
            now+=a[i];
        } 
        ans=min(ans,cnt);
        cout<<"Case #"<<Case<<": "<<ans<<endl;
    } 
} 
