#include<iostream>
#include<string.h>
#include<stdio.h>
#include<math.h>

using namespace std;


int main()
{

    freopen("0in.txt","r",stdin);
    freopen("0out.txt","w",stdout);
    int i,j,k,t,n;
    scanf("%d",&t);

    string aa,ans;


    for(int kk1=1;kk1<=t;kk1++)
    {
        ans="";
        cin>>aa;

        int len;
        len=aa.size();

        ans=ans+aa[0];

        for(i=1;i<len;i++)
        {
            if((int)aa[i]>=(int)ans[0])
            {
                ans=aa[i]+ans;
            }
            else
            {
                ans=ans+aa[i];
            }
        }

        printf("Case #%d: ",kk1);

        cout<<ans<<endl;

    }


}
