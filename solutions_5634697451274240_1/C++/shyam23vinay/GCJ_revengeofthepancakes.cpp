#include<bits/stdc++.h>
using namespace std;
int main()
{
    //ofstream fout ("B-large.out");
    //ifstream fin ("B-large.in");
    int t;
    cin >> t;
    for(int tc=1;tc<=t;tc++)
    {
        cout <<"Case #"<<tc<<": ";
        string s;
        cin >> s;
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
        cout << a[0] << endl;
    }
    return 0;
}
