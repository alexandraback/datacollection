#include <iostream>
#include <fstream>

using namespace std;

long a[100],b[100],c[2000000],d[3000000],e[100],t,n,m;
bool q;

int main(){
    ifstream in("C-small-attempt0.in");
    ofstream out("C-small.txt");
    in>>t;
    for (long i=1;i<=t;i++){
        out<<"Case "<<i<<":"<<endl;
        in>>n;
        for (long j=1;j<=n;j++) {in>>a[j];b[j]=0;e[j]=0;}
        for (long j=1;j<=2000000;j++) c[j]=0;
        for (long j=1;j<=3000000;j++) d[j]=0;
        b[21]=0;
        m=0;
        while (b[21]==0){
            b[1]++;m++;q=false;
            for (long j=1;j<=n;j++) 
            {
                if (b[j]==2){b[j]=0;b[j+1]++;};
                c[m]+=b[j]*a[j];
            }
            d[c[m]]++;
            if (d[c[m]]>1) {
                long p=0,k=0;
                for (long j=1;j<=m;j++) if (c[j]==c[m]) {p=j;break;}
                while (p>0){
                    k++;
                    e[k]=p % 2;
                    p=p/2;
                }
                
                for (long j=1;j<=k;j++) 
                    if (e[j]==1) 
                        if (p==0) {out<<a[j];p=1;} else out<<' '<<a[j];
                out<<endl;
                for (long j=1;j<=n;j++)
                    if (b[j]==1)
                        if (p==1) {out<<a[j];p=0;} else out<<' '<<a[j];
                out<<endl;
                q=true;
            }
            if (q) break;
        }
        if (b[21]==1) out<<"Impossible"<<endl;
}
in.close();out.close();
    system("pause");
    return 0;
}
        
                  
            
