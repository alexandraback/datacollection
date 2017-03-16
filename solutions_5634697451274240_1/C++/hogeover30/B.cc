#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int T; cin>>T;
    for(int t=1; t<=T; ++t) {
        string s; cin>>s;
        int n=s.size();
        vector<int> a(n+1, 1);
        for(int i=0; i<n; ++i) a[i]=s[i]=='+';

        int res=0;
        while (true) {
            int k=0;
            while (k<n and not(a[k]==0 and a[k+1]==1)) ++k;
            if (a[k]==0) {
                for(int i=0; i<=k; ++i) a[i]=!a[i];
                ++res;
            }
            else {
                break;
            }
        }
        cout<<"Case #"<<t<<": "<<res<<endl;
    }
}
