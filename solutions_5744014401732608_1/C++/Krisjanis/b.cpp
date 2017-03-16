#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<algorithm>

using namespace std;

int T;

long long b;
long long m;



int main() {
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);

    cin>>T;
    for(int C=0;C<T;C++) {
        cin>>b>>m;
        long long ma=1;
        ma<<=(b-2);
        if(m>ma) {
            cout<<"Case #"<<C+1<<": IMPOSSIBLE"<<endl;
        } else {
            cout<<"Case #"<<C+1<<": POSSIBLE"<<endl;
            for(int i=0;i<b;i++) {
                for(int j=0;j<b;j++) {
                    if(i>=j) {
                        cout<<"0";
                    } else {
                        if(j!=b-1) {
                            cout<<"1";
                        } else {
                            if(m==ma) {
                                cout<<"1";
                            } else {
                                if(i>0) {
                                    long long t=m;
                                    t>>=(i-1);
                                    cout<<t%2;
                                } else {
                                    cout<<"0";
                                }
                            }
                        }
                    }
                }
                cout<<endl;
            }
        }
    }
}
