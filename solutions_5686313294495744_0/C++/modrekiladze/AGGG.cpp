#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <set>
#include <stack>
#include <iterator>
#include <queue>
#include <string>
#include <sstream>
#include <fstream>
#define pb push_back
#define fs first
#define sc second
#define mp make_pair
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;

main()
{
    ifstream cin("C-small-attempt1.in");
    ofstream cout("C.txt");
    int T,n;
    string s1,s2;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cin>>n;
        vector<pair<string,string> > v(n);
    for(int i=0;i<n;i++)
    {
        cin>>s1>>s2;
        v[i]=mp(s1,s2);
    }

    int fk(0);
    for(int i=0;i<v.size();i++)
    {
        bool b=0,bb=0;
           for(int j=0;j<v.size();j++)
           {
               if(i==j) continue;
               if(v[i].fs==v[j].fs) b=1;
               if(v[i].sc==v[j].sc) bb=1;
           }
           if(b && bb)
           {
               v[i].fs="";
               v[i].sc="";
               fk++;
           }
    }
    cout<<"Case #"<<t<<": ";
    cout<<fk<<endl;
    }
    return 0;
}
