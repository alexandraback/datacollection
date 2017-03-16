//
//
//  noob
//
//  Created by Lingsong Zeng on 2/29/16.
//  Copyright © 2016 Lingsong Zeng. All rights reserved.
//



#include<set>
#include<map>
#include<stack>
#include<queue>
#include<cmath>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
string pre[5],cur[5],pr[5],cu[5];
long long pred[5],curd[5];
const long long inf=9*1e18;
int main()
{
    int t;
    int cas=0;
    cin>>t;
    while(t--)
    {
        printf("Case #%d: ",++cas);
        string s,t;
        cin>>s>>t;
        memset(pred,0,sizeof(pred));
        reverse(s.begin(),s.end());
        reverse(t.begin(),t.end());
        for(int i=0;i<3;i++)
        {
            pre[i]="";
            pr[i]="";
        }
        long long bit=1;
        for(int i=0;i<s.size();i++)
        {
            curd[0]=-inf;
            curd[1]=inf;
            curd[2]=inf;
            for(long long j=0;j<10;j++)
                for(long long k=0;k<10;k++)
                {
                    if(s[i]!='?'&&j!=s[i]-'0')continue;
                    if(t[i]!='?'&&k!=t[i]-'0')continue;
                    string t1[5],t2[5];
                    for(int p=0;p<3;p++)
                    {
                        t1[p]=to_string(j)+pre[p];
                        t2[p]=to_string(k)+pr[p];
                    }
                    long long tmp1=j*bit,tmp2=k*bit;
                    for(int p=0;p<3;p++)
                    {
                        if(tmp1-tmp2+pred[0]>curd[0])
                        {
                            curd[0]=tmp1-tmp2+pred[0];
                            cur[0]=t1[0];
                            cu[0]=t2[0];
                        }
                        if(tmp1-tmp2+pred[0]==curd[0]&&t1[0]<cur[0])
                        {
                            cur[0]=t1[0];
                            cu[0]=t2[0];
                        }
                        if(tmp1-tmp2+pred[0]==curd[0]&&t1[0]==cur[0]&&t2[0]<cu[0])
                        {
                            cu[0]=t2[0];
                        }
                        if(tmp1-tmp2+pred[1]<curd[1])
                        {
                            curd[1]=tmp1-tmp2+pred[1];
                            cur[1]=t1[1];
                            cu[1]=t2[1];
                        }
                        if(tmp1-tmp2+pred[1]==curd[1]&&t1[1]<cur[1])
                        {
                            cur[1]=t1[1];
                            cu[1]=t2[1];
                        }
                        if(tmp1-tmp2+pred[1]==curd[1]&&t1[1]==cur[1]&&t2[1]<cu[1])
                        {
                            cu[1]=t2[1];
                        }
                        if(abs(tmp1-tmp2+pred[0])<abs(curd[2]))
                        {
                            curd[2]=tmp1-tmp2+pred[0];
                            cur[2]=t1[0];
                            cu[2]=t2[0];
                        }
                        if(abs(tmp1-tmp2+pred[1])<abs(curd[2]))
                        {
                            curd[2]=tmp1-tmp2+pred[1];
                            cur[2]=t1[1];
                            cu[2]=t2[1];
                        }
                        if(abs(tmp1-tmp2+pred[2])<abs(curd[2]))
                        {
                            curd[2]=tmp1-tmp2+pred[2];
                            cur[2]=t1[2];
                            cu[2]=t2[2];
                        }
                        if(abs(tmp1-tmp2+pred[0])==abs(curd[2])&&t1[0]<cur[2])
                        {
                            cur[2]=t1[0];
                            cu[2]=t2[0];
                        }
                        if(abs(tmp1-tmp2+pred[0])==abs(curd[2])&&t1[0]==cur[2]&&t2[0]<cu[2])
                        {
                            cu[2]=t2[0];
                        }
                        if(abs(tmp1-tmp2+pred[1])==abs(curd[2])&&t1[1]<cur[2])
                        {
                            cur[2]=t1[1];
                            cu[2]=t2[1];
                        }
                        if(abs(tmp1-tmp2+pred[1])==abs(curd[2])&&t1[1]==cur[2]&&t2[1]<cu[2])
                        {
                            cu[2]=t2[1];
                        }
                        if(abs(tmp1-tmp2+pred[2])==abs(curd[2])&&t1[2]<cur[2])
                        {
                            cur[2]=t1[2];
                            cu[2]=t2[2];
                        }
                        if(abs(tmp1-tmp2+pred[2])==abs(curd[2])&&t1[2]==cur[2]&&t2[2]<cu[2])
                        {
                            cu[2]=t2[2];
                        }
                    }
                }
            for(int j=0;j<3;j++)
            {
                pred[j]=curd[j];
                pre[j]=cur[j];
                pr[j]=cu[j];
            }
            bit*=10;
        }
        cout<<pre[2]<<" "<<pr[2]<<endl;
    }
}
