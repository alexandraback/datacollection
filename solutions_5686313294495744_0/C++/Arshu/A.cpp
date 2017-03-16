#include<bits/stdc++.h>
using namespace std;
typedef long long lli;

std::map<string,int>mymap,mymap1,mymap2;

int t,X,n,i,j,flag,temp,temp2,ans,cnt;
string str[17],str1[17],str2[17];

int main()
{
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&t);

    while(t--)
    {
        X++;
        printf("Case #%d: ",X);

        ans=0;
        cin>>n;

        for(i=0; i<n; i++)
        {
            cin>>str1[i]>>str2[i];
            str[i]=str1[i]+"_"+str2[i];
        }

        for(i=0; i<(1<<n); i++)
        {
            //cout<<"\n\n"<<i<<"\n\n";
            flag=0;

            mymap.clear();
            mymap1.clear();
            mymap2.clear();

            temp=i;
            temp2=0;

            while(temp)
            {
                if(temp&1)
                {
                    if(mymap.find(str[temp2])!=mymap.end())
                    {
                        flag=1;
                        break;
                    }

                    if(flag)
                        break;

                    mymap1[str1[temp2]]=1;
                    mymap[str[temp2]]=1;
                    mymap2[str2[temp2]]=1;
                }

                if(flag)
                    break;
                temp>>=1;
                temp2++;
            }

            if(flag)
                continue;

            //cout<<"aaasa";

            temp=i;
            temp2=0;
            cnt=0;

            for(j=0;  j<n; j++)
            {
                if(!(temp&(1<<j)))
                {
                    if((!(mymap.find(str[temp2])!=mymap.end())) && ((mymap1.find(str1[temp2])!=mymap1.end())) && ((mymap2.find(str2[temp2])!=mymap2.end())))
                    {
                        mymap[str[temp2]]=1;
                        cnt++;
                    }
                    else
                    {
                        flag=1;
                    }

                    if(flag)
                        break;
                }

                if(flag)
                    break;
                temp2++;
            }

            if(flag)
                continue;
           // cout<<"AAfvdfcs";
            ans=max(ans,cnt);
        }

        printf("%d\n",ans);
    }
    return 0;
}
