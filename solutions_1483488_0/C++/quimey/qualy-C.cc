#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<set>

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) (v).begin(),(v).end()
using namespace std;

int main()
{
    int T;
    cin>>T;
    forn(t,T)
    {
        int A, B;
        cin>>A>>B;
        int c=0;
        for(int i=A;i<=B;i++)
        {
            stringstream ss;
            ss<<i;
            string s=ss.str();
            set<int> cont;
            forn(j,s.size())
            {
                stringstream tt;
                tt<<s.substr(j)<<s.substr(0,j);
                int n;
                tt>>n;
                if(n>i and n<=B and n>=A and s[j]!='0')
                {
                    //cout<<i<<" "<<n<<endl;
                    cont.insert(n);
                }
            }
            c+=cont.size();
        }
        cout<<"Case #"<<t+1<<": "<<c<<endl;
    }
    return 0;
}
