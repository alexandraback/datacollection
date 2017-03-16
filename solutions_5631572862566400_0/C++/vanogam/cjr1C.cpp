#include<bits/stdc++.h>
using namespace std;
int a,s,d[1002],f[1002],t,g,h,j,k,tp1,tp2,l,i,n,m;
vector<int> v[1002];
int dfs(int idx){
    int y=0;
    while(1){
            y++;
        if(f[idx]==-1) return 0;
        if(f[idx]==0) f[idx]=y;
        else {
            if(f[idx]==y-2) t=idx;
            return y-f[idx];
        }
        f[idx]=y;
        idx=d[idx];
    }
}
void ann(int idx){
    while(f[idx]>0){
        f[idx]=-1;
        idx=d[idx];
    }
    return;
}

int mxt(int idx){
    int ret=0;
    for(vector<int>::iterator it=v[idx].begin();it!=v[idx].end();it++){
        if(*it==t) continue;
        if(*it==d[t]) continue;//cout<<"^"<<*it<<"^";
        ret=max(ret,mxt(*it));
    }//cout<<"$"<<idx<<" "<<ret<<endl;
    return ret+1;
}

main(){
    freopen("out.txt","w",stdout);
    cin>>n;
    for(i=0;i<n;i++){
        cin>>m;
        cout<<"Case #"<<i+1<<": ";
        for(a=1;a<=m;a++){
            cin>>d[a];
            v[d[a]].push_back(a);
        }
        for(a=1;a<=m;a++){
            k=dfs(a);
            ann(a);//cout<<"  "<<k<<" "<<t<<endl;
            if(k!=2) l=max(l,k);
            else {
                    tp1=mxt(t);
                    tp2=mxt(d[t]);
                    s=s+tp1+tp2;
            }
        }
        cout<<max(l,s)<<endl;
        for(a=1;a<=m;a++) {v[a].clear();f[a]=0;}
        l=0;s=0;
    }
}
