#include <iostream>
#include <fstream>
using namespace std;

long t,x,y,q,k,p,ans,a[20000000],b[20000000];

int main(){
    ifstream in("C-large.in");
    ofstream out("31.txt");
    q=0;
    for (long j=12;j<=2000000;j++){
        k=j;p=1;
        while (k>0){p=p*10;k=k/10;}
        p=p/10;
        k=j/p+(j%p)*10;
        while (k!=j){            
            if (k>j&&k<2000000) {q++; a[q]=j;b[q]=k;}
            k=k/p+(k%p)*10;
        }}
    in>>t;
    for (long i=1;i<=t;i++){
    in>>x>>y;
    ans=0;
    for (long j=1;j<=q;j++){
        if (x>a[j]) continue; 
        if (x<=a[j]&&b[j]<=y) ans++;
        if (a[j]>y) break; 
        }
    out<<"Case #"<<i<<": "<<ans<<endl;}
    out.close();
    system("pause");
    return 0;
}
            
        
            
