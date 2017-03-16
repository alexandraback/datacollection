#include <iostream>
#include <map>
using namespace std;

int a[1000][3],cc[1000],R,N,M,K;
double p[1000][126];
map<int,int> mm;

int printout(int sol){
    int i;
        for (i=0; i<N; i++) cout<<""<<a[sol][i]<<"";
        cout<<endl;
}

int main(){
    int u,t,i,j,k;
    cout<<"Case #1:"<<endl;
    cin>>t;
    cin>>R>>N>>M>>K;
    //N=3;
    for (i=2,t=0; i<=M; i++) for (j=2; j<=M; j++) for (k=2; k<=M; k++){
        a[t][0]=i; a[t][1]=j; a[t][2]=k;
        sort(a[t],a[t]+N);
        int xx=a[t][0]*100+a[t][1]*10+a[t][2];
        if (mm.find(xx)==mm.end()) mm[xx]=t++;
        cc[mm[xx]]++; 
    }
    int T=t;
    for (t=0; t<T; t++){
        for (int q=0; q<(1<<N); q++){
            int prod=1;
            for (i=0; i<N; i++) if ((q>>i)&1) prod*=a[t][i];
            p[t][prod]++;
        }
    }

    int x[100],sol,maxprod=0;    
    while(R--){
        for (k=0; k<K; k++) cin>>x[k];
        sol=0;
        maxprod=0;
        for (t=0; t<T; t++){
            double prod=1;
            for (k=0; k<K; k++) prod*=p[t][x[k]];
            prod*=cc[t];
            //cout<<prod<<" ";
            //printout(t);
            if (prod>maxprod){
                sol=t;
                maxprod=prod;
            }
        }
        printout(sol);
    }
    
    return 0;
}

