#include <bits/stdc++.h>

using namespace std;

string aa,bb;

void update(string a,string b)
{
    int an=0,bn=0;
    int ao=0,bo=0;
    int i;
    if(aa=="tmp"&&bb=="tmp")
    {
        aa=a; bb=b;
        return;
    }
    for(i=0;i<aa.size();i++)
    {
        an*=10;
        an+=(a[i]-'0');
        bn*=10;
        bn+=(b[i]-'0');
        ao*=10;
        ao+=(aa[i]-'0');
        bo*=10;
        bo+=(bb[i]-'0');
    }
    if(abs(an-bn)<abs(ao-bo))
    {
        aa=a; bb=b;
    }
    else if(abs(an-bn)==abs(ao-bo))
    {
        if(an<ao)
        {
            aa=a; bb=b;
        }
        else if(an==ao&&bn<bo)
        {
            aa=a; bb=b;
        }
    }
}

void dfs(string a,string b,int ind)
{
    if(ind>=a.size())
    {
        update(a,b);
        return;
    }
    if(a[ind]=='?'&&b[ind]=='?')
    {
        int i,j;
        for(i=0;i<10;i++)
        {
            for(j=0;j<10;j++)
            {
                a[ind]='0'+i;
                b[ind]='0'+j;
                dfs(a,b,ind+1);
            }
        }
    }
    else if(a[ind]=='?')
    {
        int i;
        for(i=0;i<10;i++)
        {
            a[ind]=i+'0';
            dfs(a,b,ind+1);
        }
    }
    else if(b[ind]=='?')
    {
        int i;
        for(i=0;i<10;i++)
        {
            b[ind]=i+'0';
            dfs(a,b,ind+1);
        }
    }
    else dfs(a,b,ind+1);
}


int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B_small_bf.out","w",stdout);
    int t;
    cin >> t;
    int tc;
    for(tc=1;tc<=t;tc++)
    {
        aa="tmp";
        bb="tmp";
        string x,y;
        cin >> x >> y;
        dfs(x,y,0);
        cout << "Case #" << tc << ": " << aa << " " << bb << endl;
    }
}
