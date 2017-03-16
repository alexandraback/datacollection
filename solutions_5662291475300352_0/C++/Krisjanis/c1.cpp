#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>


using namespace std;

int t;
int n;

long long hpos[20];
long long htime[20];


int main() {
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);

    cin>>t;
    for(int cases=0;cases<t;cases++) {
        cin>>n;
        int th=0;
        for(int i=0;i<n;i++) {
            int di,hi,mi;
            cin>>di>>hi>>mi;
            while(hi>0) {
                hpos[th]=di;
                htime[th]=mi;
                th++;
                hi--;
                mi++;
            }
        }
        if(th<2) {
            cout<<"Case #"<<cases+1<<": "<<0<<endl;
        } else {
            long long ft[2];
            ft[0]=(360-hpos[0])*htime[0];
            ft[1]=(360-hpos[1])*htime[1];
            if(ft[0]>ft[1]) {
                long long a=htime[0];
                htime[0]=htime[1];
                htime[1]=a;
                a=hpos[0];
                hpos[0]=hpos[1];
                hpos[1]=a;
                a=ft[0];
                ft[0]=ft[1];
                ft[1]=a;
            }

            if(ft[0]+360*htime[0]<=ft[1]) {
            cout<<"Case #"<<cases+1<<": "<<1<<endl;
            }    else {

                cout<<"Case #"<<cases+1<<": "<<0<<endl;
            }
        }
    }
}
