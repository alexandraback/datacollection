#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int T,C,D,V,a[40]; bool v[40],aux[40],oc[40];

bool dfs(int k, int cnt){
    bool res=0;
    if (oc[k]){
        res=dfs(k+1,cnt);
        return res;
    }
    if (k>V || cnt==0){
        int i; bool ans=1;
        for (i=1; i<=V; i++) if (v[i]!=1) ans=0;
        return ans;
    }

    if (V-k>=cnt) res=dfs(k+1,cnt);
    bool sv[40];
    int i;
    for (i=1; i<=V; i++) sv[i]=v[i];
    memset(aux,0,sizeof(aux));
    for (i=1; i+k<=V; i++)
        if (v[i])
            aux[i+k]=1;
    aux[k]=1;
    for (i=1; i<=V; i++)
        v[i]=(v[i]|aux[i]);

    res|=dfs(k+1,cnt-1);
    for (i=1; i<=V; i++) v[i]=sv[i];
    return res;
}

int main(){
    ifstream fin("input.in");
    ofstream fout("output.txt");
    fin >> T;

    int i,j,k;
    for (k=1; k<=T; k++){
        cout << k << "\n";
        fin >> C >> D >> V;
        fout << "Case #" << k <<": ";
        memset(oc,0,sizeof(oc));
        for (i=1; i<=D; i++){
            fin >> a[i];
            oc[a[i]]=1;
        }
        memset(v,0,sizeof(v));
        for (i=1; i<=D; i++){
            memset(aux,0,sizeof(aux));
            for (j=1; j+a[i]<=V; j++)
                if (v[j])
                    aux[j+a[i]]=1;
            aux[a[i]]=1;
            for (j=1; j<=V; j++)
                v[j]=(v[j]|aux[j]);
        }

        for (i=0; i<=V; i++)
            if (dfs(1,i)){
                fout << i << "\n";
                break;
            }
    }

    return 0;
}
