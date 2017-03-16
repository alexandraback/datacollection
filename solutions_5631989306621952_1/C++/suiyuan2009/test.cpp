#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
const int maxn=1005;
typedef long long ll;

string s,ret;

int main(){
    freopen("A-large.in","r",stdin);
    freopen("out","w",stdout);
    int T,ncase=0;
    scanf("%d",&T);
    while(T--){
        cin>>s;
        ret="";
        for(int i=0;i<s.size();i++){
            if(ret.size()==0||ret[0]<=s[i])ret=s[i]+ret;
            else ret=ret+s[i];
        }
        printf("Case #%d: ",++ncase);
        cout<<ret<<endl;
    }
    return 0;
}
