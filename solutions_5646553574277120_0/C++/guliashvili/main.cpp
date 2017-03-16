#include<vector>
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

char in[60][60];
int ind[60][60];
int n,m;
int con;

void dfs(int a,int b){
    if(a<0 || b<0 || a>=n  || b>=m) return;
    if(ind[a][b] != -1) return;
    if(in[a][b]!='#') return;

    ind[a][b] = con;

    for(int i = -1; i<=1;i++)
    for(int j = -1; j<=1;j++){
        if(i!=0 || j!=0){
            dfs(a+i,b+j);
        }
    }
}
/*
void dfs2(int a,int b){
    if(a<0 || b<0 || a>=n  || b>=m) return;
    if(ind[a][b] != -1) return;
    if(in[a][b]!='#') return;
    ind[a][b] = con2;

    for(int i = -1;i <=1;i++)
    for(int j = -1; j<=1;j++){
        if(abs(i) + abs(j)>0){
            dfs2(a+i,b+j);
        }
    }
}*/
vector<pair<int,pair<int,int> > > edges;

void build(int a,int b){
    if(in[a][b]!='#') return;

    //vert

    for(int i = 0; i < n ;i++){

        for(int j = max(0,b-1); j <= min(b+1,m-1); j++){
            if(in[i][j]!='#') continue;
            if (ind[i][j]!=ind[a][b])
            edges.push_back(make_pair(max(0,(int)abs(i-a)-1),make_pair(ind[i][j],ind[a][b])));

        }
    }

    //horiz

    for(int j = 0; j < m ;j++){

        for(int i = max(0,a-1); i <= min(a+1,n-1); i++){
            if(in[i][j]!='#') continue;
            if (ind[i][j]!=ind[a][b])
            edges.push_back(make_pair(max(0,(int)abs(j-b)-1),make_pair(ind[i][j],ind[a][b])));

        }
    }

}

int par[60*60];

int getpar(int a){
    if (par[a]==-1) return a;
    par[a]=getpar(par[a]);
    return par[a];
}
bool merge(int a,int b){//cout<<a<<' '<<b<<endl;
    a = getpar(a);
    b = getpar(b);
    if(a==b) return 0;
    par[a]  = b;
    return 1;
}


void solve(){
    con = 0;
    edges.clear();

    for(int i =0 ;i<n; i++) cin>>in[i];
    memset(ind,-1,sizeof(ind));
    memset(par,-1,sizeof(par));

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m ;j++){
        if(ind[i][j]==-1 && in[i][j]=='#'){
            con++;
            dfs(i,j);
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) build(i,j);


    sort(edges.begin(),edges.end());

    int cc = 0;
    int dist = 0;

    for(int i = 0; i < edges.size(); i++){

        if(merge(edges[i].second.first,edges[i].second.second)){
            cc++;
            dist += edges[i].first;
        }
    }

    //cout<<"---"<<cc<<' '<<dist<<' '<<con<<endl;


    /*con2 = 0;
    for(int i = 0; i < n; i++)for(int j = 0; j < m ;j++){
        if(ind[i][j]==-1 && in[i][j]=='#'){
            con2++;
            dfs2(i,j);
        }
    }*/


    if(con < 2){
        printf("No bridges are needed.\n");
    }else if(con >= 2 && !cc)  printf("No bridges are possible.\n");
    else {
            if(cc==1)
                printf("%d bridge of total length %d\n",cc,dist);
            else
                printf("%d bridges of total length %d\n",cc,dist);
        if(cc+1 < con) printf("%d disconnected groups\n",con - cc);
    }
/*

    if(cc+1 == con || con == 0){
        if(!cc){
            puts("No bridges are needed.");
        }else{
            printf("%d bridges of total length %d\n",cc,dist);
        }
    }else{
        if(!cc) puts("No bridges are possible.");
        else
            if(cc==1)
                printf("%d bridge of total length %d\n",cc,dist);
            else
                printf("%d bridges of total length %d\n",cc,dist);
        printf("%d disconnected groups\n",con - cc);
    }

*/




}




int main(){
   // freopen("C:\\a.txt","r",stdin);
    int k =1;
    cin>>n>>m;
    while(!(n==0 && m==0)){
        if(k>1) putchar('\n');
        printf("City %d\n",k++);
        solve();
        cin>>n>>m;
    }

    return 0;
}
