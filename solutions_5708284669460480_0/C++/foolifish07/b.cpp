#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <cstdio>
#include <map>

using namespace std;
const int N=10;
char key[N];
char tar[N];
queue<string> q;
void solve(int k,int l,int s){
    q.push("");
    int ans=0;
    double _max=0;
    while(!q.empty()){
        string now=q.front();
        //cout<<now<<endl;
        q.pop();
        int len=now.length();
        if(len==s){
            int tmp=0;
            for(int i=0;i<=len-l;++i){
                int flag=1;
                for(int j=0;j<l;++j){
                    if(now[i+j]!=tar[j]){
                        flag=0;
                        break;
                    }
                }
                tmp+=flag;  
            }
            _max=max(double(tmp),_max);
            ans+=tmp;
        }
        //cout<<ans<<endl;
        if(len<s){
            for(int i=0;i<k;++i){
                q.push(now+key[i]);
            }
        }
    }
    double d=1;
    for(int i=0;i<s;++i){
        d*=k;
    }
    printf("%.7f\n",_max-(double)ans/d);
}
int main(){
    int T;
    scanf("%d",&T);
    int cas=0;
    while(T--){
        int k,l,s;
        scanf("%d%d%d",&k,&l,&s);
        scanf("%s%s",key,tar);
        printf("Case #%d: ",++cas);
        solve(k,l,s);
    }
    return 0;
}