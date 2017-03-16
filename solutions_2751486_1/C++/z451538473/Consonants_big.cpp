#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
char  str[1000005];
struct Node
{
    int b,e,pre;
} data[1000005];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    for(int cas=1; cas<=t; cas++)
    {
        printf("Case #%d: ",cas);
        int n;
        scanf("%s%d",str,&n);
        int count=0,len=strlen(str);
        int cnt=0;
        int b=0,e=0;
        long long ans=0;
        for(int i=0; i<len; i++)
        {
            if(str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u')
            {
                if(!count)
                    b=i;
                e=i;
                count++;
            }
            else
            {
                //cout<<count<<endl;
                if(count>=n)
                {
                    //cout<<b<<" "<<e<<endl;
            //        cout<<"cnt "<<cnt<<endl;
                    if(cnt)
                    {
                 //       cout<<"pre "<<data[cnt-1].b<<" "<<data[cnt-1].e<<endl;
                        data[cnt].pre=max(0,data[cnt-1].e+1-n+1);
                    }
                    else data[cnt].pre=0;
                    data[cnt].b=b;
                    data[cnt].e=e;
                    cnt++;
                }
                count=0;
            }
        }
        if(count>=n)
        {
            //cout<<b<<" "<<e<<endl;
            if(cnt)
                data[cnt].pre=max(0,data[cnt-1].e-1);
            else data[cnt].pre=0;
            data[cnt].b=b;
            data[cnt].e=e;
            cnt++;
        }
      //  cout<<"len "<<len<<endl;
       // cout<<"cnt "<<cnt<<endl;
        for(int i=0; i<cnt; i++)
        {
          //  cout<<data[i].b<<" "<<data[i].e<<" "<<data[i].pre<<endl;
            for(int j=data[i].b; j+n-1<=data[i].e; j++)
            {
                //cout<<j<<endl;
                ans+=(len-(j+n-1))*(data[i].b-data[i].pre+1);
    //            cout<<len-(j+n-1)<<endl;
       //         cout<<"ans "<<ans<<endl;
            }
        }
        cout<<ans<<endl;
    }
}
