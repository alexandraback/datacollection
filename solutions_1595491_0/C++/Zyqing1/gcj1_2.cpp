#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int check(int ti,int x)
{
    if(ti==0) return 0;
    int tmp=ti/3;
    if(ti%3==0){
        return tmp+x;
    }
    else if(ti%3==1){
        return tmp+1;
    }
    else
        return tmp+1+x;
}

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    int T;
    cin>>T;
    for(int x=1;x<=T;x++){
        int ans=0;
        int s,p,ti,n;
        cin>>n>>s>>p;
        for(int i=0;i<n;i++){
            cin>>ti;
            if(check(ti,0)>=p)
                ans++;
            else if(s>0 && check(ti,1) >= p){
                ans++;
                s--;
            }
        }
        printf("Case #%d: %d\n",x,ans);
    }
    return 0;
}
