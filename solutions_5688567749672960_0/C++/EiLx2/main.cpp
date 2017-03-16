#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int T,N,K,q[1000010]; bool v[1000010];

int rev(int x){
    int res=0;
    while (x){
        res=res*10+x%10;
        x/=10;
    }

    return res;
}

int main(){
    ifstream fin("input.in");
    ofstream fout("output.txt");
    fin >> T;

    int cost=0,i,l,t; bool f=0;
    for (t=1; t<=T; t++){
        memset(v,0,sizeof(v));
        fin >> N;
        fout << "Case #" <<t << ": ";
        K=1;
        q[1]=0; v[0]=1;
        f=0;
        l=1;
        cost=0;
        int aux;
        while (!f){
            aux=K;
            for (i=l; i<=aux; i++){
                if (!v[q[i]+1]){
                    q[++K]=q[i]+1;
                    v[q[K]]=1;
                    if (q[K]==N) { f=1; break; }
                }
                if (!v[rev(q[i])]){
                    q[++K]=rev(q[i]);
                    v[q[K]]=1;
                    if (q[K]==N) { f=1; break; }
                }
            }

            l=aux+1;
            cost++;
        }

        fout << cost << "\n";
    }
    return 0;
}
