#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>
using namespace std;
ofstream fout("last.out");
const int LEN=1024;
int t;
string s;
char a[2*LEN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    for(int i=1;i<=t;++i)
    {
        cin>>s;
        int idx=s.size();
        int sz=s.size();
        a[idx]=s[0];
        int first=idx,second=idx;
        for(int j=1;j<sz;++j)
        {
            if(a[first]<=s[j])
            {
                --first;
                a[first]=s[j];
            }
            else
            {
                ++second;
                a[second]=s[j];
            }
        }
        fout<<"Case #"<<i<<": ";
        for(int j=first;j<=second;++j)fout<<a[j];
        fout<<"\n";
    }
    return 0;
}
