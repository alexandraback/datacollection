#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

string to_string(int x, int n)
{
    ostringstream s;
    s<<x;
    string res=s.str();
    if (n<res.size()) return "";
    return string(n-res.size(), '0')+res;
}

int main()
{
    int T; cin>>T;
    for(int t=1; t<=T; ++t) {
        string C, J; cin>>C>>J;

        int n=C.size();
        int mindif=1<<30, resC, resJ;
        for(int i=0; i<1000; ++i) {
            string a=to_string(i, n);
            if (a=="") break;
            bool ok=true;
            for(int k=0; k<n; ++k)
                if (C[k]!='?' and a[k]!=C[k]) ok=false;
            if (!ok) continue;
            for(int j=0; j<1000; ++j) {
                string b=to_string(j, n);
                if (b="") break;
                ok=true;
                for(int k=0; k<n; ++k)
                    if (J[k]!='?' and b[k]!=J[k]) ok=false;
                if (!ok) continue;
                if (mindif>abs(i-j)) {
                    mindif=abs(i-j);
                    resC=i;
                    resJ=j;
                }
                else if (mindif==abs(i-j)) {
                    if (resC>i) {
                        resC=i, resJ=j;
                    }
                    else if (resC==i and resJ>j) {
                        resJ=j;
                    }
                }
            }
        }
        cout<<"Case #"<<t<<": "<<to_string(resC, n)<<' '<<to_string(resJ, n)<<endl;
    }
}
