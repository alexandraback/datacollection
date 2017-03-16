#include<fstream>
#include<string>
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

#define OO 1000000

ifstream fin("A-large.in");
ofstream fout("A-large.out");

int ans, n, m[101];

long long a;

int main() {
    int T,c;
    fin>>T;

    for (c=1; c<=T; ++c) {
        int min = OO,tmp;

        fin>>a>>n;

        ans =n;

        int i,j,k,x;

        for (i=0; i<n; ++i)
            fin>>m[i];

        for (i=0;i<n-1;++i) {
            for (j=i+1; j<n; ++j) {
                 if (m[i]>m[j]) {
                    tmp = m[i]; m[i] = m[j]; m[j] = tmp;
                 }
            }
        }

        // for (i=0; i<n; ++i) fout<<m[i]<<endl;

        for (x=0;x<=n; ++x) {
            int tmp = x;
            long long ta = a;

            for (i=0; i<n-x; ++i) {
                while (a<=m[i] && tmp<=n) {
                    a+=(a-1);
                    tmp += 1;
                }
                
                a+=m[i];
                if (tmp>n) break;
            }

            if (tmp<ans)
                ans = tmp;

            a = ta;
        }
    

        // output
        fout<<"Case #"<<c<<": ";
    
        fout<<ans;

        fout<<endl;
    }
    return 0;
}
