#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,n,a,cont,x,y,m;
    int ar[101];
    cin>>T;
    for(int k=1 ; k<=T ; k++)
    {
        cin>>a>>n;
        m=-1;
        cont = 0;
        for(int i=0;i<n;i++)
            cin>>ar[i];
        sort(ar,ar+n);
        for(int i=0;i<n;i++)
        {
            if(ar[i] < a)
            {
                a += ar[i];
            }
            else
            {
                if (cont + n-i < m or m == -1)
					m = cont + n-i;
                if(a==1)
                {
                    cont+= n-i;
                    break;
                }
                while (ar[i] >= a)
				{
					cont++;
					a += a-1;
				}
                a += ar[i];
            }
        }
        if (cont < m || m == -1) m = cont;
        cout<<"Case #"<<k<<": "<<m<<endl;
    }
    return 0;
}
