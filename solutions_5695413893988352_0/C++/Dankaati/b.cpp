#include <bits/stdc++.h>

using namespace std;

int x;
string a, b;
long long mia[20], mib[20], maa[20], mab[20], mida[20], midb[20], miha[20], mihb[20];

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);

cin >> x;
for(int y=1;y<=x;y++) {
    cin >> a >> b;
    cout << "Case #" << y << ": ";
    int n=a.size();
    mia[n]=mib[n]=maa[n]=mab[n]=mida[n]=midb[n]=miha[n]=mihb[n]=0;
    long long t=1;
    for(int i=n-1;i>=0;i--,t*=10) {
        mida[i]=midb[i]=10*t;
        if(a[i]=='?') {
            mia[i]=mia[i+1];
            maa[i]=maa[i+1]+9*t;
        }else {
            mia[i]=mia[i+1]+t*(a[i]-'0');
            maa[i]=maa[i+1]+t*(a[i]-'0');
        }
        if(b[i]=='?') {
            mib[i]=mib[i+1];
            mab[i]=mab[i+1]+9*t;
        }else {
            mib[i]=mib[i+1]+t*(b[i]-'0');
            mab[i]=mab[i+1]+t*(b[i]-'0');
        }
        for(int j=0;j<=9;j++) for(int k=0;k<=9;k++) {
            if(a[i]!='?' && a[i]!='0'+j) continue;
            if(b[i]!='?' && b[i]!='0'+k) continue;
            long long moa=10*t,mob=10*t,mha,mhb;
            if(j<k) {
                mob=(k-j)*t-maa[i+1]+mib[i+1];
                mhb=k*t+mib[i+1];
            }
            if(k<j) {
                moa=(j-k)*t-mab[i+1]+mia[i+1];
                mha=j*t+mia[i+1];
            }
            if(k==j) {
                mob=midb[i+1];
                mhb=k*t+mihb[i+1];
                moa=mida[i+1];
                mha=j*t+miha[i+1];
            }
            if(mob<midb[i]) {
                midb[i]=mob;
                mihb[i]=mhb;
            }
            if(moa<mida[i]) {
                mida[i]=moa;
                miha[i]=mha;
            }
        }
    }
    if(mida[0]<midb[0] || (mida[0]==midb[0] && miha[0]<=mihb[0]-midb[0])) {
        cout.width(n);
        cout.fill('0');
        cout << miha[0] << " ";
        cout.width(n);
        cout.fill('0');
        cout << miha[0]-mida[0];
    } else {
        cout.width(n);
        cout.fill('0');
        cout << mihb[0]-midb[0] << " ";
        cout.width(n);
        cout.fill('0');
        cout << mihb[0];;
    }
    cout << endl;
}
    return 0;
}
