#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("3.in","r",stdin);
    freopen("3.out","w",stdout);
    int i,j,k,cases,t,n,com,res,can;
    cin>>cases;
    for(t=1;t<=cases;t++){
        cin>>n;
        int g[n+1];
        for(i=1;i<=n;i++){
            cin>>g[i];
        }
        res=0;
        vector< vector<bool> > v;
        vector<int> vc;
        vector<int> u;
        for(i=1;i<=n;i++){
            vector<bool> visit;
            visit.assign(n+1, 0);
            j=i;
            can=0;
            while(!visit[j]){
                visit[j]=1;
                j=g[j];
                can++;
            }
            if(j==g[g[j]]){
                v.push_back(visit);
                vc.push_back(can);
                u.push_back(j);
            }
            else{
                if(j==i){
                    if(res<can)res=can;
                }
            }
        }
        map<int, int> m;
        can=0;
        for(i=0;i<v.size();i++){
            for(j=i+1;j<v.size();j++){
                if(u[i]==u[j])continue;
                vector<int> au;
                can=0;
                for(k=1;k<=n;k++){
                    if(v[i][k]||v[j][k])can++;
                    if(v[i][k]&&v[j][k])au.push_back(k);
                }
                if(au.size()==2){
                    m[au[0]]=max(m[au[0]], can);
                }
            }
        }
        can=0;
        for(k=1;k<=n;k++){
            can+=m[k];
        }
        if(res<can)res=can;
        cout<<"Case #"<<t<<": "<<res<<endl;
    }
}
