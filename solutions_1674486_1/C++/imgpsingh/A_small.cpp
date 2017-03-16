#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<set>
using namespace std;
vector<int> ar[1010];
int visited[1010],ans;
void dfs(int x,int pos){
    vector<int> :: iterator it;
    for(it=ar[x].begin();it!=ar[x].end();++it){
//        cout<<*it<<" ";
        if(visited[*it]==pos){
            ans=1;
            return ;
        }
        visited[*it]=pos;
        dfs(*it,pos);
    }
    return ;
}
main(){
    int t,Kases=0;
    scanf("%d",&t);
    while(t--){
        int n;
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            ar[i].clear();
            int x,y;
            scanf("%d",&x);
            for(int j=0;j<x;j++){
                scanf("%d",&y);
                ar[i].push_back(y);
            }
        }
        cout<<"Case #"<<++Kases<<": ";
        for(int i=1;i<=n && !ans;i++){
            for(int j=1;j<=n;j++)
                visited[j]=0;
//            cout<<i<<" : ";
            dfs(i,i);
//            cout<<flag<<"\n";
            //cout<<i<<" "<<flag<<"\n";
            
        }
        if(ans)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
    //system("pause");
    return 0;
}

