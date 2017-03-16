#include <bits/stdc++.h>

using namespace std;

map<string, int> m1, m2;
string a[2000], b[2000];
int n;

int rec(int i)
{
    if(i==n)
        return 0;
    int maior = 0;
    if(m1[a[i]]>1 && m2[b[i]]>1)
    {
        m1[a[i]]--;
        m2[b[i]]--;
        maior = rec(i+1)+1;
        m1[a[i]]++;
        m2[b[i]]++;
    }
    int a = rec(i+1);
    if(a>maior)
        return a;
    return maior;
}

void resolver(int t)
{
    int i;
    cin>>n;
    m1.clear();
    m2.clear();
    for(i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        m1[a[i]]++;
        m2[b[i]]++;
    }
    int r = rec(0);

    /*for(i=0;i<n;i++)
    {
        if(m1[a[i]]>1 && m2[b[i]]>1)
        {
            m1[a[i]]--;
            m2[b[i]]--;
            r++;
        }
    }*/
    cout<<"Case #"<<t<<": "<<r<<endl;
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
