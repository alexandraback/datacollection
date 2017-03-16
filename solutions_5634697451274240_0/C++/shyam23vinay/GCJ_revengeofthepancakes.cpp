#include<bits/stdc++.h>
using namespace std;
int main()
{
    ofstream fout ("B-small-attempt0.out");
    ifstream fin ("B-small-attempt0.in");
    int t;
    fin >> t;
    for(int tc=1;tc<=t;tc++)
    {
        fout <<"Case #"<<tc<<": ";
        string s;
        fin >> s;
        int l=s.size();
        int a[l+1];
        if(s[l-1]=='-')
            a[l-1]=1;
        else
            a[l-1]=0;
        for(int i=l-2;i>=0;i--)
        {
            if(s[i]==s[i+1])
                a[i]=a[i+1];
            else
                a[i]=1+a[i+1];
        }
        fout << a[0] << endl;
    }
    return 0;
}
