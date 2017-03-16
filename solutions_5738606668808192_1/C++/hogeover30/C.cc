#include <iostream>
#include <algorithm>
using namespace std;

int p[10][33];

bool is_divisible_by_3(const vector<int>& a, int b, int n)
{
    int res=p[b][n-1]+p[b][0];
    for(int i=0; i<a.size(); ++i) res+=a[i]*p[b][i+1];
    return res%(b==6?31:3)==0;
}
    
int main()
{
    for(int b=2; b<10; ++b) {
        p[b][0]=1;
        for(int i=1; i<33; ++i) p[b][i]=p[b][i-1]*b%(b==6?31:3);
    }

    int T; cin>>T;
    while (T--) {
        cout<<"Case #1:\n";
        int n, j;
        cin>>n>>j;
        vector<int> a(n-2);
        for(int d=0; d<n-2; d+=2) {
            for(int i=0; j and i<d; ++i) a[i]=1;
            do {
                bool ok=true;
                for(int b=2; b<=10; b+=2)
                    if (!is_divisible_by_3(a, b, n)) { ok=false; break; }
                if (ok and j) {
                    cout<<1;
                    for(int i=a.size()-1; i>=0; --i) cout<<a[i];
                    cout<<1;
                    for(int b=2; b<=10; ++b) cout<<' '<<(b==6?31:3-b%2);
                    cout<<endl;
                    if (--j==0) break;
                }
            } while (prev_permutation(begin(a), end(a)));
        }
    }
}
