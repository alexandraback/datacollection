#include <bits/stdc++.h>
#define ll long long
using namespace std;

int tab[5][5]= {{0,0,0,0,0}, {0,1,2,3,4}, {0,2,-1,4,-3}, {0,3,-4,-1,2}, {0,4,3,-2,-1}};

int main()
{
    freopen("C-small-attempt1.in","r", stdin);
    freopen("C-small-attempt1.out","w", stdout);

    int t,cs=1, frnt[10004],bck[10004], sign[10004],l,m,a[10004],ng;
    char s[10004];
    scanf("%d",&t);

    while(t--)
    {
        ll n,x,c=0,d=0;
        int fl=0;
        scanf("%lld %lld",&n,&x);

        scanf("%s",s);

        int ans=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='i') a[i]=2;
            if(s[i]=='j') a[i]=3;
            if(s[i]=='k') a[i]=4;

//            printf("%d %d\n",i,a[i]);
        }

        ans= a[0];
        frnt[0]=ans;
        sign[0]=1;
        if(ans==2) c=1;

        {
            for(int i=1; i<n; i++)
            {
                frnt[i]= tab[frnt[i-1]][a[i]];

                if(frnt[i]==2 && c==0)
                {
                    c= i+1;
                }
                if(frnt[i]<0)
                {
                    frnt[i]= -frnt[i];
                    sign[i]=sign[i-1]*(-1);
                }
                else sign[i]= sign[i-1];
            }

            if(x%4==1) if(frnt[n-1]*sign[n-1]==-1) fl=1;

            l= frnt[n-1];
            m= sign[n-1];

            for(int i=0; i<3; i++)
            {
//                printf("   %d %d\n",l,m);
                if(c==0)
                {
                    for(int j=0; j<n; j++)
                    {
                        if(m*sign[j]*tab[l][frnt[j]]==2)
                        {
                            c=(i+1)*n +j+1;
                            break;
                        }
                    }
                }
                l= tab[l][frnt[n-1]];
                m*= sign[n-1];
                if(l<0)
                {
                    l=-l;
                    m*= -1;
                }
                if(x%4== i+2)
                {
                    if(l*m==-1) fl=1;
                }
            }
        }
        ng= sign[n-1];
        ans= a[n-1];
        bck[n-1]=ans;
        sign[n-1]=1;
        if(ans==4) d=1;

        {
            for(int i=n-2; i>=0; i--)
            {
                bck[i]= tab[a[i]][bck[i+1]];

                if(bck[i]==4 && d==0)
                {
                    d= n-i;
                    break;
                }
                if(bck[i]<0)
                {
                    bck[i]= -bck[i];
                    sign[i]=sign[i+1]*(-1);
                }
                else sign[i]= sign[i+1];
            }

            l= bck[0];
            m= sign[0];

            for(int i=0; i<3; i++)
            {
                if(d==0)
                {
                    for(int j=n-1; j>=0; j--)
                    {
//                        printf("  %d %d %d %d %d   %d %d\n",i,j,tab[a[j]][l], m*sign[j]*tab[a[j]][l],m,l,a[j]);
                        if(m*sign[j]*tab[bck[j]][l]==4)
                        {
                            d=(i+1)*n +n-j;
                            break;
                        }
                    }
                }
                l= tab[bck[0]][l];
                m*= sign[0];
                if(l<0)
                {
                    l=-l;
                    m*= -1;
                }
            }
        }

//        printf("%lld %lld %d %d\n",c,d,frnt[0], bck[n-1]);
        if(c==0 || d==0 || c+d>= n*x || fl==0)
        {
            printf("Case #%d: NO\n",cs++);
        }
        else
        {
            printf("Case #%d: YES\n",cs++);
        }
    }
}
