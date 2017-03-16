#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define LL long long

using namespace std;

int main()
{
    int T, c, n, m, r, i, j, p[7], v[8], f[8], tot[8], k, s, two;
    cin>>T;
    c=1;
    while(T--)
    {
        cout<<"Case #"<<c++<<":\n";
        cin>>r>>n>>m>>k;
        while(r--)
        {
            two=0;
            s=0;
            for(j=2; j<=m; ++j)
                v[j]=f[j]=tot[j]=0;
            for(i=0; i<k; ++i)
            {
                for(j=2; j<=m; ++j)
                    v[j]=0;
                cin>>p[i];
                //int temp1 = p[i];
                while(p[i]>1)
                {
                    if(p[i]%5==0)
                    {
                        v[5]++; tot[5]++;
                        p[i]/=5;
                    }
                    if(p[i]%3==0)
                    {
                        v[3]++; tot[3]++;
                        p[i]/=3;
                    }
                    if(p[i]%2==0)
                    {
                        v[2]++; tot[2]++;
                        p[i]/=2;
                    }
                }
                for(j=2; j<=m; ++j)
                {
                    //cout<<v[j];
                    if(v[j]>f[j])
                        f[j]=v[j];
                }
                if(v[2]%2)
                {
                    two=1;
                }
            }
            for(j=2; j<=m; ++j)
                s+=f[j];
            if(s>n)
            {
                //cout<<"too many twos";
                //for(j=2;j<=m;++j) cout<<' '<<f[j];
                if(f[2]>1)
                {
                    f[4] = f[2]/2;
                    f[2] = f[2]%2;
                    tot[4] = tot[2]/2;
                    tot[2] = tot[2]%2;
                }
            }
            if(s<n)
            {
                while(s<n)
                {
                    s++;
                    //cout<<"two:"<<two;
                    if(two && f[2]==0)
                    {
                        f[2]=1;
                        continue;
                    }
                    if(tot[5]>=tot[3] && tot[5]>=tot[2] && tot[5]>=tot[4])
                    {
                        f[5]++;
                        tot[5]/=2;
                    }
                    else if(tot[4]>=tot[3] && tot[4]>=tot[2] && tot[4]>=tot[5])
                    {
                        f[4]++;
                        tot[4]/=2;
                    }
                    else if(tot[3]>=tot[5] && tot[3]>=tot[2] && tot[3]>=tot[4])
                    {
                        f[3]++;
                        tot[3]/=2;
                    }
                    else
                    {
                        f[2]++;
                        tot[2]/=2;
                    }
                }
            }
            //for(j=2;j<=m;++j)   cout<<f[j]<<' ';
            for(j=2; j<=m; ++j)
                while(f[j]--)
                    cout<<j;
            cout<<'\n';
        }
    }
    return 0;
}
