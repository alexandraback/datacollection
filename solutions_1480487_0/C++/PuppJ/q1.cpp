#include <iostream>
#include <fstream>;
 #include <iomanip>
using namespace std;

long t,n,m;
double s1,s2,s3,a[10000];

int main(){
    ifstream in("A-small-attempt2.in");
    ofstream out("A-small.txt");
    in>>t;
    for (long i=1;i<=t;i++){
        in>>n;
        s1=0;s2=0;m=n;
        for (long j=1;j<=n;j++) {in>>a[j];s1+=a[j];}
        s2=s1*2/n;s3=s1;
        for (long j=1;j<=n;j++) if (s2<=a[j]) {s1=s1-a[j]/2;a[j]=-1;m--;}
         cout<<"Case #"<<i<<":"<<s1<<endl;       
        s2=s1*2/m;
        out<<"Case #"<<i<<":";
        cout<<"Case #"<<i<<":"<<s2<<endl;                
        for (long j=1;j<=n;j++) if (a[j]==-1) out<<' '<<0; else out<<' '<<setprecision(8)<<(s2-a[j])*100/s3;
        out<<endl;
    }
    in.close();
    out.close();
    system("pause");
    return 0;
}
            
