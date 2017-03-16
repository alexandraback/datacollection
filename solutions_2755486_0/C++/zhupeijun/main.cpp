#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

const int SLIDE = 120;

struct tri
{
    int di,wi,ei,si,d_di,d_pi,d_si,ni,cnt;
}a[100];

int ows[300],nws[300];

int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);

    int cn,ca,i,j,N,p,ans;

    cin >> cn;
    for(ca = 1;ca <= cn;ca++)
    {
        cin >> N;

        for(i = 0;i < N;i++)
        {
            cin >> a[i].di >> a[i].ni >> a[i].wi >> a[i].ei
            >> a[i].si >> a[i].d_di >> a[i].d_pi >> a[i].d_si;
            a[i].cnt = 0;
        }

        ans = 0;

        bool has = true;

        memset(ows,0,sizeof(ows));

        while(has)
        {
            int ad =  6760600;
            for(i = 0;i < N;i++)
                if(a[i].ni > a[i].cnt && a[i].di < ad)
                    ad = a[i].di;

            memset(nws,0,sizeof(-1));
            for(i = 0;i < N;i++)
            {
                if(a[i].di == ad && a[i].ni > a[i].cnt)
                {

                    for(p = a[i].wi + 1;p <= a[i].ei;p++)
                    {
                        if(a[i].si > ows[p + SLIDE])
                            break;
                    }

                    if(p <= a[i].ei)
                    {
                        for(p = a[i].wi + 1;p <= a[i].ei;p++)
                            nws[p + SLIDE] = max(nws[p + SLIDE],a[i].si);
                        ans++;
                    }

                    a[i].di += a[i].d_di;
                    a[i].wi += a[i].d_pi;
                    a[i].ei += a[i].d_pi;
                    a[i].si += a[i].d_si;
                    a[i].cnt ++;
                }
            }

            for(j = 0;j < 300;j++)
            {
                if(nws[j] != -1)
                    ows[j] = max(ows[j],nws[j]);
            }


            has = false;
            for(i = 0;i < N;i++)
            {
                if(a[i].ni > a[i].cnt)
                {
                    has = true;
                    break;
                }
            }
        }

        cout << "Case #"<< ca <<": " << ans << endl;
    }
    return 0;
}
