#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string a1[200],a2[200];
string ans1,ans2;
int b1[100005],b2[100005],n;
int min1=INT_MAX;
ll fk[105];

int main()
{
    ll t,p,i,j,r,c=1,k;

    freopen("C-small-attempt0 (1).in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        set<string > s;
        for(i=0;i<n;i++)
        {
           // scanf("%s%s",&a1,&a2);
           cin>>a1[i]>>a2[i];
            s.insert(a1[i]);
            s.insert(a2[i]);
        }
        i=0;
        map<string,int> mp;
        set<string> :: iterator it;
        for(it=s.begin();it!=s.end();it++)
        {
            mp[*it]=i;
            i++;
        }
        for(i=0;i<n;i++)
        {
            b1[i]=mp[a1[i]];
            b2[i]=mp[a2[i]];
           // printf("%d %d\n",b1[i],b2[i]);
        }
        //func(0,0);
        //scanf("%s%s",&a1,&a2);
        ll p=pow(2,n),q,ans=0;
        for(i=0;i<p;i++)
        {
            q=i;
            ll count1=0;
            memset(fk,0,sizeof(fk));
            while(q>0)
            {
                if(q&1)
                {
                    fk[count1]=1;
                }
                q=q/2;
                count1++;
            }
            ll count2=0,f1,f2,flag=1;
            /*printf("i: %lld \n",i);
            for(k=0;k<n;k++)
            {
                printf("%d ",fk[k]);
            }
            printf("\n");*/
            for(k=0;k<n;k++)
            {
                if(fk[k]==1)
                {
                   // printf("k: %lld\n",k);
                    f1=0;
                    f2=0;
                    for(j=0;j<n;j++)
                    {
                        if(fk[j]==0)
                        {
                           // printf("kj : %lld %lld\n",k,j);
                            if(b1[k]==b1[j])
                            f1=1;
                            if(b2[k]==b2[j])
                            f2=1;
                            //printf("%d %d %d %d\n",b1[k],b2[k],b1[j],b2[j]);
                        }
                    }
                    if(f1==1 && f2==1)
                    {
                        count2++;
                    }
                    else
                    {
                        flag=0;
                        break;
                    }
                }
            }
            if(flag==1)
            ans=max(count2,ans);


        }
        printf("Case #%lld: ",c++);
            printf("%lld\n",ans);

        //func(0);



        /*for(i=0;i<100;i++)
        {
            if(b[i]>0)
            {
                printf("%c",i);
                //break;
            }
        }*/

    }
    return 0;
}
