#include <bits/stdc++.h>
using namespace std;
int test;

int a[10000];
int b[10000];

int d[2005][2005];

vector <int> v[10000];
bool f[2005];
int n,m;

bool go(int x){
    f[x]=1;
    if (x==n+m+1) return 1;
    for (int i=0;i<v[x].size();i++)
    if (f[v[x][i]]==0){
        if (d[x][v[x][i]]>0){
            d[x][v[x][i]]--;
            d[v[x][i]][x]++;
            if (go(v[x][i])) return 1;
            d[x][v[x][i]]++;
            d[v[x][i]][x]--;
        }
    }
    return 0;
}

void sol(){
    int k;
    cin>>k;
    string s;
    map <string,int> Ma,Mb;
    for (int i=1;i<=k;i++){
        cin>>s;
        if (Ma.find(s)==Ma.end()) Ma[s]=Ma.size();
        a[i]=Ma[s];
        cin>>s;
        if (Mb.find(s)==Mb.end()) Mb[s]=Mb.size();
        b[i]=Mb[s];
    }
    n=Ma.size();
    m=Mb.size();
    int ans=0;
    memset(d,0,sizeof(d));
   for (int i=1;i<=k;i++){
    v[a[i]].push_back(b[i]+n);
    v[b[i]+n].push_back(a[i]);
    d[a[i]][b[i]+n]=1;
    d[b[i]+n][a[i]]=1;
   }
   for (int i=1;i<=n;i++) d[0][i]=1;
   for (int i=1;i<=n;i++) d[i][0]=1;
   for (int i=1;i<=m;i++) d[n+i][n+m+1]=1;
   for (int i=1;i<=m;i++) d[n+m+1][n+i]=1;
   for (int i=1;i<=n;i++) v[0].push_back(i);
   for (int i=1;i<=n;i++) v[i].push_back(0);
   for (int i=1;i<=m;i++) v[n+i].push_back(n+m+1);
   for (int i=1;i<=m;i++) v[n+m+1].push_back(n+i);

    int bm=0;
    while (go(0)){
    memset(f,0,sizeof(f));
    bm++;}

    memset(f,0,sizeof(f));


    for (int i=0;i<10000;i++) v[i].clear();
    test++;
    cout<<"Case #"<<test<<": "<<k-(n+m-bm)<<endl;
}

int main() {
    freopen("C2.in","r",stdin);
    freopen("C22.txt","w",stdout);
    int t;
    cin>>t;
    while (t--){
        sol();
    }
    return 0;
}
