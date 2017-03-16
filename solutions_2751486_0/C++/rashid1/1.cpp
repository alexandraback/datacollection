#include <iostream>
#include <fstream>
using namespace std;
int sait[300];
int f(string s,int n)
{
    int cur = 0;
    for (int i=0;i<s.length();i++)
    {
        if (sait[s[i]]) cur = 0;
        else cur++;
        if (cur >= n) return 1;
    }
    return 0;
}
int main()
{
    ifstream cin("in.txt");
    ofstream cout("out.txt");
    // a, e, i, o, and u
    sait['a'] = sait['e'] = sait['i'] = sait['o'] = sait['u'] = 1;
    int t;
    cin>>t;
    for (int ii=0;ii<t;ii++)
    {
        string name;
        int n,ans = 0;
        cin>>name>>n;
        for (int i=0;i<name.length();i++)
        {
            string cur = "";
            for (int j=i;j<name.length();j++)
            {
                cur += name[j];
                //cout<<cur<<endl;
                ans += f(cur,n);
                //if (f(cur,n)) cout<<cur<<endl;
            }
        }
        cout<<"Case #"<<ii+1<<": "<<ans<<endl;
    }
    return 0;
}
