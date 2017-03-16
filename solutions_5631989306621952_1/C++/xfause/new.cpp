#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<set>
#include<stack>
#include<map>
#include<ctime>
#include<bitset>
#define LL long  long
#define db double
#define EPS 1e-15
#define inf 1e9

using namespace std;

int main(){
    freopen ("1.in", "r", stdin);
    freopen ("1.out", "w", stdout);
    int T,cas=1;
    scanf("%d",&T);
    while (T--){
        string s;
        cin>>s;
        string tmp="";
        for (int i=0;s[i];i++){
            if (tmp+s[i]<s[i]+tmp)
                tmp=s[i]+tmp;
            else tmp=tmp+s[i];
        }
        printf("Case #%d: ",cas++);
        cout<<tmp<<endl;
    }
    return 0;
}
