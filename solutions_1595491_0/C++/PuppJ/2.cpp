#include <iostream>
#include <fstream>

using namespace std;
long t,n,s,p,ans,x,y,k;

int main(){
    ifstream in("B-small-attempt0.in");
    ofstream out("2.txt");
    in>>t;
    for (long i=1;i<=t;i++){
        in>>n>>s>>p;
        ans=0;
        x=p*3-2;
        y=p*3-4;
        if (p==1) {x=1;y=1;}
        if (p==0) {x=0;y=0;}
        for (long j=1;j<=n;j++){
            in>>k;
            if (k>=x) ans++;
            else if (k>=y&&s>0) {ans++;s--;}
        }
        out<<"Case #"<<i<<": "<<ans<<endl;
    }
    system("pause");
    in.close();
    out.close();
    return 0;
}
