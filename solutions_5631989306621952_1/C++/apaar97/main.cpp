#include <bits/stdc++.h>
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MOD 1000000007
#define lli long long int
#define li long int

using namespace std;

int main()
{   ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("C:\\Users\\atul5095\\Downloads\\A-small-attempt0.in","r",stdin);
    //freopen("A-small-output.out","w",stdout);
    freopen("C:\\Users\\atul5095\\Downloads\\A-large.in","r",stdin);
    freopen("A-large-output.out","w",stdout);
    lli t,c,i;
    cin>>t;
    for(c=1;c<=t;c++)
    {   cout<<"Case #"<<c<<": ";
        string s,res;
        cin>>s;
        list <char> l(1,s[0]);
        list<char>::iterator it;
        for(i=1;i<s.size();i++)
        {   if(s[i]>=l.front())
                l.push_front(s[i]);
            else
                l.push_back(s[i]);
        }
        for(it=l.begin();it!=l.end();++it)
            cout<<*it;
        cout<<endl;
    }
    return 0;
}
