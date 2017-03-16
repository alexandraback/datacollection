#include<bits/stdc++.h>
using namespace std;
#define gc getchar
#define ll long long
#define v vector
#define pr pair<int,int>
#define sd second
#define ft first
#define pb push_back
#define mp make_pair
#define total 400000
#define pie 3.1415926535897932384626433832795
int main()
{
    freopen("A-large.in","r",stdin);
     freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    int i,j,k,t,val;
    cin>>t;
    for(k=1;k<=t;k++)
    {
        int a[10]={0};
        int b[26]={0};
        string s;
        cin>>s;
        string c[10]={"ZERO", "GEIHT", "XSI","UFOR","WTO","ONE", "FIVE",  "SEVEN", "THREE", "INNE"};
        int d[10]={0,8,6,4,2,1,5,7,3,9};
        for(i=0;i<s.length();i++)
        {
             b[s[i]-65]++;
        }
        cout<<"Case #"<<k<<": ";
        for(i=0;i<10;i++)
        {
            val=b[c[i][0]-65];
            a[d[i]]=val;
            for(j=0;j<c[i].length();j++)
            {
                b[c[i][j]-65]-=val;
            }
        }
        for(i=0;i<10;i++)
        {
            for(j=0;j<a[i];j++)
            {
                cout<<i;
            }
        }
        cout<<endl;
    }
    return 0;
}
