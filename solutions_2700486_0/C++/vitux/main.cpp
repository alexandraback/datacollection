#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <math.h>

#define cin in
#define cout out

#define long long long
using namespace std;
ifstream in("input3.in");
ofstream out("output3.txt");

long t,n,x,y;

long mod(long ee){
if (ee<0) return -1*ee;
return ee;
}

long fac(long w){
    long ans=1;
    if (w==0) return 1;
for (long r=w;r>0;r--)
    ans*=r;
return ans;
}

long cnk(long nn,long kk){
long v=fac(nn),vv=fac(kk),vvv=fac(nn-kk);
v/=vv;
v/=vvv;
return v;
}

int main()
{
    cin>>t;

    for (long i=1;i<=t;i++){
        cin>>n>>x>>y;
        cout<<"Case #"<<i<<": ";

        if (x==0 && y==0){
        cout<<"1.00000000"<<endl;
        }
        else{
        long k;
        long m;
            if (n>=1 && n<=5) k=1,m=1;
            if (n>=6 && n<=14) k=2,m=6;
            if (n>=15 && n<=20) k=3,m=15;
        n-=m;
        long y1=y;
        long need=2*k;
        long fld=0;

        while (n>need){
            n-=2;
            y1--;
            fld++;
            need--;
        }
        long zn=pow(2,n);
k++;
        if ((mod(x)+mod(y))/2+1<k){
        cout<<"1.0000000"<<endl;
        }
        else{
        if ((mod(x)+mod(y))/2+1>k){
        cout<<"0.0000000"<<endl;
        }
            else{

                y++;
                if (fld>=y){
                cout<<"1.00000000"<<endl;
                }

                else{
                    y=y1+1;
                long ch=0;
                for (long j=n;j>=y;j--){
                    ch+=cnk(n,j);
                    //cout<<ch<<endl;
                }
                double answ=ch*1.0/zn;

                cout<<fixed<<setprecision(8)<<answ<<endl;
                }
            }
        }

        }

    }
    return 0;
}
