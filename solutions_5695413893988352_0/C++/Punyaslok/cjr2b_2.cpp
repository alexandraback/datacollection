#include<bits/stdc++.h>
#define ll long long int
#define PB push_back
#define F first
#define S second
#define tr(c,i) for(auto i = (c).begin(); i != (c).end(); i++) 
#define sint(n); scanf("%d",&n);
#define sll(n); scanf("%lld",&n);
#define pint(n); printf ("%d\n",n);
#define pll(n); printf ("%lld\n",n);
#define sst(n); scanf("%s",n);
#define pst(n); printf ("%s\n",n);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define set(a,b) memset(a, b, sizeof(a))


using namespace std;

string c, j, c2, j2, ac, aj;
ll diff, cs, js;

int satisfy (string aa, string bb)
{
    char tmp1[50], tmp2[50];
    ll ct=0;
    tr(aa, i)
    {
        tmp1[ct++] = *i;
    }
    tmp1[ct] = '\0';
    
    ct=0;
    tr(bb, i)
    {
        tmp2[ct++] = *i;
    }
    tmp2[ct] = '\0';

    ll l2 = strlen(tmp2);
    f(i, 0, l2)
    {
        if (tmp1[i]!='?' && tmp1[i]!=tmp2[i])
            return 0;
    }
    return 1;
    //pst(tmp1);  pst(tmp2);
}

int main()
{
    ll t;
    cin>>t;
    f(tst, 1, t+1)
    {
        diff = LLONG_MAX;
        cin>>c>>j;
        ll len = c.length();
        ll upp = pow(10, len)-1;
        f(i, 0, upp+1)
        {
            f(jj, 0, upp+1)
            {
                c2 = to_string(i);
                ll var;
                var = c.length()-c2.length();
                f(i, 0, var)
                {
                    c2.insert(0, "0");
                }
                
                j2 = to_string(jj);
                var = j.length()-j2.length();
                f(i, 0, var)
                {
                    j2.insert(0, "0");
                }

                if (satisfy(c, c2) == 1 && satisfy(j, j2)==1)
                {
                    //cout<<"satisfied for "<<i<<" "<<jj<<endl;
                    if (abs(i-jj)<diff)
                    {
                        diff = abs(i-jj);
                        ac=c2;
                        aj=j2;
                        cs = i;
                        js = jj;
                    }
                    else if (abs(i-jj)==diff)
                    {
                        if (i<cs)
                        {
                            ac=c2;
                            aj=j2;
                            cs = i;
                            js = jj;
                        }
                        else if (i==cs && jj<js)
                        {
                            ac=c2;
                            aj=j2;
                            cs = i;
                            js = jj;
                        }
                    }
                    //cout<<cs<<" "<<js<<endl;
                }
            }
        }
        cout<<"Case #"<<tst<<": ";
        cout<<ac<<" "<<aj<<endl;
    }
    return 0;
}
