#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main () {
    ifstream inp;
    ofstream outp;
    inp.open("ci.txt");
    outp.open ("co.txt");
    int *f, t, n, *cl, *hop, *pr, id, temp, ct, Mcl, Mop;
    f=(int*) malloc(sizeof(int)*1001);
    cl=(int*) malloc(sizeof(int)*1001);
    hop=(int*) malloc(sizeof(int)*1001);
    pr=(int*) malloc(sizeof(int)*1001);
    inp>>t;
    for(int i=1;i<=t;i++){
        inp>>n;
        for(int j=1;j<=n;j++){
            inp>>f[j];
            cl[j]=0;
            hop[j]=0;
            pr[j]=0;
        }
        outp<<"Case #"<<i<<": ";
        Mcl=0;//find Mcl
        Mop=0;
        id=1;
        while(id<=n){
            while(cl[id]!=0){
                id++;
                if(id==n+1){
                    break;
                }
            }
            if(id==n+1){
                break;
            }
            temp=id;
            cl[id]=id*(n+1)+0;
            ct=1;
            while((cl[f[temp]]/(n+1))!=id){
                temp=f[temp];
                cl[temp]=id*(n+1)+ct;
                ct++;
            }
            if((cl[temp]-cl[f[temp]])==1){
                hop[f[temp]]=max(hop[f[temp]], cl[temp]-id*(n+1));
                pr[temp]=f[temp];
                pr[f[temp]]=temp;
            }
            else{
                Mcl=max(Mcl, cl[temp]-cl[f[temp]]+1);
            }
        }
        for(int id=1;id<=n;id++){   //find Mop
            if(pr[id]!=0){
                Mop+=hop[id];
                if(hop[id]==0){
                    Mop++;
                }
            }
        }
        outp<<max(Mop, Mcl)<<endl;
    }
    return 0;
}

        