#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>


using namespace std;

int t;
long long n;
long long m;
long long digits[20];

int main() {
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);

    cin>>t;
    for(int c=0;c<t;c++) {
        cin>>n;
        m=n;
        int nd=0;
        while(m>0) {
            digits[nd]=m%10;
            m/=10;
            nd++;
        }
        long long ans=1;
        int cd=1;
        while(cd<nd) {
            int half=cd/2;
            long long toadd=1;
            if(half>0) ans++;
            while(half>0) {
                ans+=18*toadd;
                toadd*=10;
                half--;
            }
            if(cd%2==1) ans+=9*toadd;
            cd++;
        }
        long long toadd=1;
        for(int i=0;i<nd-1;i++) toadd*=10;

        long long tans=n-toadd;
        if(tans>0) {
            long long lowtarget=0;
            long long hightarget=0;
            int half=nd/2;
            bool odd=(nd%2==1);
            toadd=1;
            for(int i=0;i<half;i++) {
                lowtarget+=digits[i]*toadd;
                toadd*=10;
            }
            if(odd) {
                lowtarget+=digits[half]*toadd;
            }
            bool includemid=false;

            if(lowtarget==0) {
                includemid=true;
                lowtarget=toadd;
                m=n;
                m-=toadd;
                nd=0;
                while(m>0) {
                    digits[nd]=m%10;
                    m/=10;
                    nd++;
                }

            }

            toadd=1;
            for(int i=nd-1;i>half;i--) {
                hightarget+=digits[i]*toadd;
                toadd*=10;
            }
            if(!odd||(odd&&includemid)) {
                hightarget+=digits[half]*toadd;
                toadd*=10;
            }
            tans=min(tans,lowtarget+hightarget);
        }
        ans+=tans;
        cout<<"Case #"<<c+1<<": "<<ans<<endl;
    }
}
