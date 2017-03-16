#include <bits/stdc++.h>

using namespace std;

string toString(int a)
{
    stringstream ss;
    ss<<a;
    return ss.str();
}

void resolver(int t)
{
    int j, p, s, k, a, b, c;
    stringstream sa, sb, sc;
    cin>>j>>p>>s>>k;
    cout<<"Case #"<<t<<": ";
    int tot[11][11][11];
    memset(tot, 0, sizeof(tot));
    string r = "";
    int f = 0;
    for(a=1;a<=j;a++)
    {
        for(b=1;b<=p;b++)
        {
            for(c=1;c<=s;c++)
            {
                if(tot[a][b][0]<k && tot[a][0][c]<k && tot[0][b][c]<k)
                {
                    f++;
                    tot[a][b][0]++;
                    tot[a][0][c]++;
                    tot[0][b][c]++;
                    r+=toString(a)+" "+toString(b)+" "+toString(c)+"\n";
                }
            }
        }
    }
    cout<<f<<endl<<r;
    //cout<<endl;
}

int main()
{
    int t, i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        resolver(i);
    }
    return 0;
}
