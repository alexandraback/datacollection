#include <bits/stdc++.h>

using namespace std;

void resolver(int t)
{
    int n, v[1000], i, q, r = 0, p[1000], qc = 0, k, q2 = 0, l, a, bi, bk, j;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>v[i];
        v[i]--;
    }
    for(i=0;i<n;i++)
    {
        if(v[v[i]]==i && i<v[i])
        {
            q2+=2;
            k = v[i];
            bi = bk = 0;
            for(j=0;j<n;j++)
            {
                if(j!=i && j!=k)
                {
                    memset(p, 0, sizeof(p));
                    p[i] = 1;
                    p[k] = 1;
                    l = j;
                    a = 0;
                    //cout<<"Teste "<<l<<": ";
                    while(l!=i && l!=k && p[l]==0)
                    {
                        a++;
                        p[l] = 1;
                        l = v[l];
                        //cout<<l<<" ";
                    }
                    if(l==i && a>bi)
                        bi = a;
                    if(l==k && a>bk)
                        bk = a;

                    //cout<<": "<<a<<endl;
                }
            }
            //cout<<i<<" "<<k<<" "<<bi<<" "<<bk<<endl;
            q2+=bi+bk;
        }
    }
    //cout<<"q2 "<<q2<<endl;
    for(i=0;i<n;i++)
    {
        j = i;
        memset(p,0,sizeof(p));
        q = 0;
        do
        {
            q++;
            p[j] = 1;
            j = v[j];
        }while(j!=i && p[j]==0);
        if(j==i && q>r)
        {
            r = q;
        }
    }
    if(q2>r)
        r = q2;
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
