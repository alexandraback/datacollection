#include <iostream>
#include <fstream>

using namespace std;

ifstream in("a.in");
ofstream out("a.out");

int main()
{
    int t;
    in>>t;
    for(int i=1;i<=t;++i){
        string s;
        in>>s;
        string n="0";
        n[0]=s[0];
        for(int j=1;j<s.size();++j)
            if(s[j]<n[0]){
                string a="0";
                a[0]=s[j];
                n+=a;
            }
            else{
                string a="0";
                a[0]=s[j];
                n=a+n;
            }
        out<<"Case #"<<i<<": "<<n<<endl;
    }
    return 0;
}
