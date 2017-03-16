#include<iostream>
#include<string>
#include<stdio.h>

using namespace std;
double dp[102][102][102];//第S個，現在到第幾個，已經得幾分了
double p[26];
int trans[102][26];
int main()
{
    int i,j,k,w,u;
    int t,c;
    string s1,s2;
    int l,s;
    cin>>t;
    c=1;
    while(t--)
    {
        cin>>k>>l>>s;
        cin>>s1>>s2;
        for(i=0; i<26; i++) p[i]=0;
        for(i=0; i<k; i++)
        {
            p[s1[i]-'A']+=(1.0/(double)k);
        }
        bool f=true;
        for(i=0;i<l;i++)
        {
            if(p[s2[i]-'A']<0.0001)
            {
                f=false;
            }
        }
        if(f==false)
        {
            cout<<"Case #"<<c<<": 0.00"<<endl;
            c++;
            continue;
        }
        int x=0;
        for(i=l-1;i>0;i--)
        {
            bool ff=true;
            for(j=0;j<i;j++)
            {
                if(s2[j]!=s2[l-i+j])ff=false;
            }
            if(ff)
            {
                x=i;
                break;
            }
        }
        //cout<<x<<endl;
        for(i=0;i<l;i++)
        {
            for(j=0;j<26;j++)
            {
                trans[i][j]=0;
                for(w=(i+1);w>0;w--)
                {
                    bool ff=true;
                    if((s2[w-1]-'A')!=j)
                    {
                        ff=false;
                    }else
                    {
                        for(u=0;u<w-1;u++)
                        {
                            if(s2[u]!=s2[i-w+1+u])
                            {
                                ff=false;
                            }
                        }
                    }
                    if(ff)
                    {
                        trans[i][j]=w;
                        break;
                    }
                }
                //cout<<trans[i][j]<<' ';
            }
            //cout<<endl;
        }
        for(i=0;i<100;i++)
        {
            for(j=0;j<100;j++)
            {
                for(w=0;w<100;w++)
                    dp[i][j][w]=0;
            }
        }
        dp[0][0][0]=1;
        for(i=0;i<s;i++)
        {
            for(j=0;j<l;j++)
            {
                for(w=0;w<s;w++)//得幾分
                {
                    if(dp[i][j][w]>0.000001)
                    {
                        for(u=0;u<26;u++)
                        {
                            if(p[u]>0)
                            {
                                if(j==l-1 && u==(s2[l-1]-'A'))
                                {
                                    dp[i+1][x][w+1]+=dp[i][j][w]*p[u];
                                }else
                                {
                                    dp[i+1][trans[j][u]][w]+=dp[i][j][w]*p[u];

                                }
                            }
                        }
                    }
                }
            }
        }
        double E=0;
        int mx;
        mx = 1+((s-l)/(l-x));
        for(i=0;i<l;i++)
        {
            for(j=0;j<=s;j++)
            {
                if(dp[s][i][j]>0.00000001)
                {
                    //cout<<i<<' '<<j<<' '<<dp[s][i][j]<<endl;
                    E+=dp[s][i][j]*j;
                }
            }
        }
        cout<<"Case #"<<c<<": ";
        printf("%.7lf\n",(double)mx-E);
        c++;

    }
}
