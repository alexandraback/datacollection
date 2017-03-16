#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
#define N 1005

char ans[N];
string s;

void recursion(int discuss,int start,int end){
    if(discuss==-1){
        return;
    }

    int i;
    for(i=0;i<discuss;i++){
        if(s[i]>s[discuss]){
            ans[--end] = s[discuss];
            break;
        }
    }
    if(i==discuss) ans[start++] = s[discuss];
    recursion(discuss-1,start,end);
}

void solve(){

    cin>>s;
    recursion(s.length()-1,0,s.length());
    ans[s.length()] = '\0';
    cout<<ans<<endl;
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("a_output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        printf("Case #%d: ",i+1);
        solve();
    }
    return 0;
}
