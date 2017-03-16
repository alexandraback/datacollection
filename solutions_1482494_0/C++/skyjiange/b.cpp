#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#define mod 1000000007
using namespace std;
int n,m;
string s;
priority_queue<int,vector<int>,greater<int> > v1;
vector<pair<int,int> > v2;
int main(){
    //freopen("in.in","r",stdin);
    //freopen("out2","w",stdout);
    int T,cas=0;
    cin>>T;
    while(T--){
        while(v1.size()) v1.pop();
        v2.clear();        
        cin>>n;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            v2.push_back(pair<int,int>(x,y));
        }
        int t=0,tag=0,ans=0;
        while(v1.size()||v2.size()){
            bool flag=0;
            for(int i=0;i<v2.size();i++)
                if(v2[i].second<=t){
                    v2.erase(v2.begin()+i);
                    t+=2;
                    flag=1;
                    ans++;
                    break;
                }
            if(!flag){
                int p=-1;
                for(int i=0;i<v2.size();i++)
                    if(v2[i].first<=t)
                        if(p==-1||v2[i].second>v2[p].second) p=i;
                if(p==-1){
                    tag=1;break;
                }
                t++;
                v1.push(v2[p].second);
                v2.erase(v2.begin()+p);
                ans++;
            }
            while(v1.size()&&v1.top()<=t) v1.pop(),t++,ans++;
        }
        //printf("%d %d\n",v1.size(),v2.size());
        printf("Case #%d: ",++cas);
        if(tag) printf("Too Bad\n");
        else printf("%d\n",ans);
    }
    //fclose(stdout);
    return 0;
}
