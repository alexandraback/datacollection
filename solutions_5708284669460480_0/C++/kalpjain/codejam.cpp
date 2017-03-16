#include <bits/stdc++.h>
using namespace std;
bool comp(int a,int b)
{
    return (a>b);
}
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main(void) {
    freopen("in.txt","rt",stdin);
    freopen("test.txt","wt",stdout);
    int t,tc,k,l,s;
    string K,L;
    cin>>t;
    for(tc=1;tc<=t;++tc)
    {
        cin>>k>>l>>s;
        cin>>K>>L;
        cout<<"Case #"<<tc<<": ";
        int i,b,j,a[l];
        int c[26]={0},f=0;
        double ans=0;
        for(i=0;K[i]!='\0';++i)
            c[K[i]-'A']++;
        for(i=0;L[i]!='\0';++i)
        {
            if(!c[L[i]-'A'])
            {
                f=1;
                break;
            }
        }
        if(f)
        {
            cout<<"0.0\n";
            continue;
        }
        a[0]=0;
        for (i=1; i<l; ++i)
        {
            j = a[i-1];
            while (j > 0 && L[i] != L[j])
                j = a[j-1];
            if (L[i] == L[j])  ++j;
            a[i] = j;
        }
        b=(s-l)/(l-a[l-1])+1;
        double p=1,cnt=0;
        for(i=0;i<l;++i)
        {
            p*=(double)c[L[i]-'A']/k;
        }
        ans=p*b;
        ans=b-ans;
        printf("%.8lf\n",ans);
    }
    return 0;
}
