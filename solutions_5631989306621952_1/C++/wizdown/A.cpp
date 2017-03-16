#include<bits/stdc++.h>
#define scd(x) scanf("%d",&x)
#define prd(x) printf("%d",x)
#define sclld(x) scanf("%lld",&x)
#define prlld(x) printf("%lld",x)
#define f_in(x) freopen(x,"r",stdin)
#define f_out(x) freopen(x,"w",stdout)

using namespace std;

typedef long long int llt;

int main()
{
    ios::sync_with_stdio(false);
    list<char> v;
    int t,len;
    list<char>::iterator it;
    string s;
   // f_in("input.txt");
    //f_out("output.txt");
    cin>>t;
    for(int j = 1 ; j<=t ; j++)
    {
        cin>>s;
        len = s.length();
        v.push_back(s[0]);
        for(int i = 1 ; i < len ; i++)
        {
            it=v.begin();
            if(s[i] >= (*it))
            {
                v.push_front(s[i]);
            }
            else
                v.push_back(s[i]);
        }
        cout<<"Case #"<<j<<": ";
        for(it = v.begin() ; it != v.end() ; it++)
            cout<<(*it);
        cout<<"\n";
        v.clear();

    }


    return 0;
}
