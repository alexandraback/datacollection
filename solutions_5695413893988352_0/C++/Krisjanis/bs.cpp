#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include <iomanip>


using namespace std;

int T;

string s1;
string s2;

int n;

int ans;
int l;
int r;

int main() {
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);

    cin>>T;
    for(int C=0;C<T;C++) {
        cin>>s1;
        cin>>s2;
        n=s1.length();
        ans=100000;
        l=100000;
        r=100000;
        int mv=10;
        if(n>1) mv*=10;
        if(n>2) mv*=10;
        for(int i=0;i<mv;i++) {
            for(int j=0;j<mv;j++){
                int t=i;
                bool good=true;
                for(int k=n-1;k>=0;k--) {
                    if(!(s1[k]=='?'||s1[k]-'0'==t%10)) {
                        good=false;
                    }
                    t/=10;
                }
                t=j;
                for(int k=n-1;k>=0;k--) {
                    if(!(s2[k]=='?'||s2[k]-'0'==t%10)) {
                        good=false;
                    }
                    t/=10;
                }
                if(good) {
                    if(abs(i-j)<ans) {
                        ans=abs(i-j);
                        l=i;
                        r=j;
                    } else {
                        if(abs(i-j)==ans) {
                            if(i<l) {
                                l=i;
                                r=j;
                            } else {
                                if(l==i&&j<r) {
                                    l=i;
                                    r=j;
                                }
                            }
                        }
                    }
                }
            }
        }

        cout<<"Case #"<<C+1<<": "<<setw(n)<<setfill('0')<<l<<" "<<setw(n)<<setfill('0')<<r<<endl;
    }
}
