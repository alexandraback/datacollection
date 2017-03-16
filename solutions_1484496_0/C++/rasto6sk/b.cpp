#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<deque>
#include<set>
using namespace std;
#define ll long long
#define VI vector<ll>
#define VS vector<string>
#define PI pair<int,int>
#define MP make_pair
#define PB push_back

int u(int x) {
 return x+1100000;
}


int main() {
    int T; cin>>T;
    for (int t=0;t<T;t++) {
        int n; cin>>n;
        VI a = VI(n,0);
        for (int i =0;i<n;i++) cin>>a[i];
        //short v[20][220000] = {0};
        VI pom = VI(2200000,0);
        vector<VI> v;
        for (int i =0;i<21;i++) v.PB(pom);
        v[0][u(0)]=1;
        for (int k=1;k<=n;k++)
        for (int j=-999999; j<999999;j++) {
            v[k][u(j)]+=v[k-1][u(j+a[k-1])];
            v[k][u(j)]+=v[k-1][u(j-a[k-1])];
            v[k][u(j)]+=v[k-1][u(j)];
        }
        cout<<"Case #"<<t+1<<": "<<endl;
        /*     for (int i=0;i<=n;i++) {
                for (int j=-20;j<=20;j++) cout<<v[i][u(j)]<<" ";
                cout<<endl;
            }
        */
        if (v[n][u(0)]==1) cout<<"Impossible"<<endl;
        else {
            VI A;
            VI B;
            int val = 0;
            int UNIT = 1;

           for (int i = n;i>=1;i--) {
                if (v[i-1][u(val)]>UNIT) continue;
                if (v[i-1][u(val+a[i-1])]>0) { UNIT = 0; A.PB(a[i-1]); val+=a[i-1]; }
                else {
                    B.PB(a[i-1]); val-=a[i-1]; UNIT = 0;
                }
            }
            sort(A.begin(),A.end());
            sort(B.begin(),B.end());
            for (int i=0;i<A.size();i++) {
                if (i!=0) cout<<" ";
                cout<<A[i];
            }cout<<endl;
            for (int i=0;i<B.size();i++) {
                if (i!=0) cout<<" ";
                cout<<B[i];
            }cout<<endl;
        }
    }

}
