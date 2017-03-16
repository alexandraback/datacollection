#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct asdf {
    long long ans[2],minmax[2],maxmin[2];
}a_t;
void print(long long x , int len)
{
    long long tmp = x;
    int l = 0;
    while(tmp>0)
    {
        tmp/=10;
        l++;
    }
    if(x==0)
        l=1;
    for(int i=0 ; i<(len-l) ; i++)
    {
        cout<<"0";
    }
    cout<<x;
}
int main()
{
    int t;
    cin>>t;
    for(int i=1 ; i<=t ; i++)
    {
        string c,j;
        cin>>c;
        cin>>j;
        int len = c.length();
        a_t dp[len];

        //For last bits
        //For ans
        int k = len-1;
        if(c[k]=='?' && j[k]=='?')
        {
            dp[k].ans[0] = 0;
            dp[k].ans[1] = 0;
        }
        else if(c[k]=='?' && j[k]!='?')
        {
            dp[k].ans[0] = j[k]-'0';
            dp[k].ans[1] = j[k]-'0';
        }
        else if(c[k]!='?' && j[k]=='?')
        {
            dp[k].ans[0] = c[k]-'0';
            dp[k].ans[1] = c[k]-'0';
        }
        else
        {
            dp[k].ans[0] = c[k]-'0';
            dp[k].ans[1] = j[k]-'0';
        }

        //For minmax
        if(c[k]=='?' && j[k]=='?')
        {
            dp[k].minmax[0] = 0;
            dp[k].minmax[1] = 9;
        }
        else if(c[k]=='?' && j[k]!='?')
        {
            dp[k].minmax[0] = 0;
            dp[k].minmax[1] = j[k]-'0';
        }
        else if(c[k]!='?' && j[k]=='?')
        {
            dp[k].minmax[0] = c[k]-'0';
            dp[k].minmax[1] = 9;
        }
        else
        {
            dp[k].minmax[0] = c[k]-'0';
            dp[k].minmax[1] = j[k]-'0';
        }


        //For maxmin
        if(c[k]=='?' && j[k]=='?')
        {
            dp[k].maxmin[0] = 9;
            dp[k].maxmin[1] = 0;
        }
        else if(c[k]=='?' && j[k]!='?')
        {
            dp[k].maxmin[0] = 9;
            dp[k].maxmin[1] = j[k]-'0';
        }
        else if(c[k]!='?' && j[k]=='?')
        {
            dp[k].maxmin[0] = c[k]-'0';
            dp[k].maxmin[1] = 0;
        }
        else
        {
            dp[k].maxmin[0] = c[k]-'0';
            dp[k].maxmin[1] = j[k]-'0';
        }

        long long pow10 = 10;
        for(k = len-2 ; k>=0 ; k--)
        {
            //For finding the values for c[k...n] j[k...n]

            //For minmax
            if(c[k]=='?' && j[k]=='?')
            {
                dp[k].minmax[0] = 0*pow10 + dp[k+1].minmax[0];
                dp[k].minmax[1] = 9*pow10 + dp[k+1].minmax[1];
            }
            else if(c[k]=='?' && j[k]!='?')
            {
                dp[k].minmax[0] = 0*pow10 + dp[k+1].minmax[0];
                dp[k].minmax[1] = (j[k]-'0')*pow10 + dp[k+1].minmax[1];
            }
            else if(c[k]!='?' && j[k]=='?')
            {
                dp[k].minmax[0] = (c[k]-'0')*pow10 + dp[k+1].minmax[0];
                dp[k].minmax[1] = 9*pow10 + dp[k+1].minmax[1];
            }
            else
            {
                dp[k].minmax[0] = (c[k]-'0')*pow10 + dp[k+1].minmax[0];
                dp[k].minmax[1] = (j[k]-'0')*pow10 + dp[k+1].minmax[1];
            }

            //For maxmin
            if(c[k]=='?' && j[k]=='?')
            {
                dp[k].maxmin[0] = 9*pow10 + dp[k+1].maxmin[0];
                dp[k].maxmin[1] = 0*pow10 + dp[k+1].maxmin[1];
            }
            else if(c[k]=='?' && j[k]!='?')
            {
                dp[k].maxmin[0] = 9*pow10 + dp[k+1].maxmin[0];
                dp[k].maxmin[1] = (j[k]-'0')*pow10 + dp[k+1].maxmin[1];
            }
            else if(c[k]!='?' && j[k]=='?')
            {
                dp[k].maxmin[0] = (c[k]-'0')*pow10 + dp[k+1].maxmin[0];
                dp[k].maxmin[1] = 0*pow10 + dp[k+1].maxmin[1];
            }
            else
            {
                dp[k].maxmin[0] = (c[k]-'0')*pow10 + dp[k+1].maxmin[0];
                dp[k].maxmin[1] = (j[k]-'0')*pow10 + dp[k+1].maxmin[1];
            }

            //For ans
            if(c[k]!='?' && j[k]!='?')
            {
                if(c[k]==j[k])
                {
                    dp[k].ans[0] = (c[k]-'0')*pow10 + dp[k+1].ans[0];
                    dp[k].ans[1] = (j[k]-'0')*pow10 + dp[k+1].ans[1];
                }
                else if(c[k]<j[k])
                {
                    dp[k].ans[0] = (c[k]-'0')*pow10 + dp[k+1].maxmin[0];
                    dp[k].ans[1] = (j[k]-'0')*pow10 + dp[k+1].maxmin[1];
                }
                else
                {
                    dp[k].ans[0] = (c[k]-'0')*pow10 + dp[k+1].minmax[0];
                    dp[k].ans[1] = (j[k]-'0')*pow10 + dp[k+1].minmax[1];
                }
            }
            else if(c[k]!='?' && j[k]=='?')
            {
                long long t[2],d,maxt[2],maxd;

                //x x
                maxt[0] = (c[k]-'0')*pow10 + dp[k+1].ans[0];
                maxt[1] = (c[k]-'0')*pow10 + dp[k+1].ans[1];
                maxd = abs(maxt[0]-maxt[1]);

                //x x+1
                if((c[k]-'0') != 9)
                {
                    t[0] = (c[k]-'0')*pow10 + dp[k+1].maxmin[0];
                    t[1] = (c[k]-'0'+1)*pow10 + dp[k+1].maxmin[1];
                    d = abs(t[0]-t[1]);
                    if((d<maxd) || (d==maxd && t[0]<maxt[0]) || (d==maxd && t[0]==maxt[0] && t[1]<maxt[1]))
                    {
                        maxd = d;
                        maxt[0] = t[0];
                        maxt[1] = t[1];
                    }
                }

                //x x-1
                if((c[k]-'0') != 0)
                {
                    t[0] = (c[k]-'0')*pow10 + dp[k+1].minmax[0];
                    t[1] = (c[k]-'0'-1)*pow10 + dp[k+1].minmax[1];
                    d = abs(t[0]-t[1]);
                    if((d<maxd) || (d==maxd && t[0]<maxt[0]) || (d==maxd && t[0]==maxt[0] && t[1]<maxt[1]))
                    {
                        maxd = d;
                        maxt[0] = t[0];
                        maxt[1] = t[1];
                    }
                }

                dp[k].ans[0] = maxt[0];
                dp[k].ans[1] = maxt[1];
            }
            else if(c[k]=='?' && j[k]!='?')
            {
                long long t[2],d,maxt[2],maxd;

                //x x
                maxt[0] = (j[k]-'0')*pow10 + dp[k+1].ans[0];
                maxt[1] = (j[k]-'0')*pow10 + dp[k+1].ans[1];
                maxd = abs(maxt[0]-maxt[1]);

                //x x+1
                if((j[k]-'0') != 0)
                {
                    t[0] = (j[k]-'0'-1)*pow10 + dp[k+1].maxmin[0];
                    t[1] = (j[k]-'0')*pow10 + dp[k+1].maxmin[1];
                    d = abs(t[0]-t[1]);
                    if((d<maxd) || (d==maxd && t[0]<maxt[0]) || (d==maxd && t[0]==maxt[0] && t[1]<maxt[1]))
                    {
                        maxd = d;
                        maxt[0] = t[0];
                        maxt[1] = t[1];
                    }
                }

                //x x-1
                if((j[k]-'0') != 9)
                {
                    t[0] = (j[k]-'0'+1)*pow10 + dp[k+1].minmax[0];
                    t[1] = (j[k]-'0')*pow10 + dp[k+1].minmax[1];
                    d = abs(t[0]-t[1]);
                    if((d<maxd) || (d==maxd && t[0]<maxt[0]) || (d==maxd && t[0]==maxt[0] && t[1]<maxt[1]))
                    {
                        maxd = d;
                        maxt[0] = t[0];
                        maxt[1] = t[1];
                    }
                }

                dp[k].ans[0] = maxt[0];
                dp[k].ans[1] = maxt[1];
            }
            else
            {
                long long t[2],d,maxt[2],maxd;

                //x x
                maxt[0] = (0)*pow10 + dp[k+1].ans[0];
                maxt[1] = (0)*pow10 + dp[k+1].ans[1];
                maxd = abs(maxt[0]-maxt[1]);

                //x x+1
                t[0] = (0)*pow10 + dp[k+1].maxmin[0];
                t[1] = (1)*pow10 + dp[k+1].maxmin[1];
                d = abs(t[0]-t[1]);
                if((d<maxd) || (d==maxd && t[0]<maxt[0]) || (d==maxd && t[0]==maxt[0] && t[1]<maxt[1]))
                {
                    maxd = d;
                    maxt[0] = t[0];
                    maxt[1] = t[1];
                }

                //x x-1
                t[0] = (1)*pow10 + dp[k+1].minmax[0];
                t[1] = (0)*pow10 + dp[k+1].minmax[1];
                d = abs(t[0]-t[1]);
                if((d<maxd) || (d==maxd && t[0]<maxt[0]) || (d==maxd && t[0]==maxt[0] && t[1]<maxt[1]))
                {
                    maxd = d;
                    maxt[0] = t[0];
                    maxt[1] = t[1];
                }

                dp[k].ans[0] = maxt[0];
                dp[k].ans[1] = maxt[1];
            }
            pow10 = 10*pow10;
        }

        cout<<"Case #"<<i<<": ";
        print(dp[0].ans[0],len);
        cout<<" ";
        print(dp[0].ans[1],len);
        cout<<endl;
    }
    return 0;
}
