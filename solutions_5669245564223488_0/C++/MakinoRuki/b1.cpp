#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
ll ans;
int T,N;
vector<string>word;
string s;
int num[30];
void dfs(int cur, int s, string res){
  //   cout<<cur<<" "<<res<<endl;
     if(cur==N){
                int i=1;
                int cnt=1;
                while(i<res.size()){
                           if(res[i]==res[i-1])
                              cnt++;
                           else{
                                if(cnt!=num[res[i-1]-'a'])
                                    break;
                                cnt=1;
                                //i++;
                           }
                           i++;
                }
                if(cnt==num[res[i-1]-'a'])
                    ans = (ans+1LL)%mod;
                return ;
     }
                for(int i=0;i<N;++i){
                        if((1<<i)&s)continue;
                //        int x = word[i][0]-'a';
                  //      if((1<<x)&t){
                      //               if(w
                    //    }
                     //   int len=word[i].size();
                        dfs(cur+1,s|(1<<i),res+word[i]);
                }
}
int main(){
    freopen("B-small-attempt1.in","r",stdin);
  // freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>T;
    for(int cas=1;cas<=T;++cas){
            cin>>N;
            word.clear();
            memset(num,0,sizeof(num));
            for(int i=0;i<N;++i){
                  cin>>s;
                  word.push_back(s);
                  for(int j=0;j<s.size();++j)
                          num[s[j]-'a']++;  
            }
            ans=0LL;
            dfs(0,0,"");
            printf("Case #%d: ",cas);
            printf("%I64d\n",ans);
    }
    return 0;
}
