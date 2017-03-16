#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<map>
using namespace std;
int n;
long arr[1000],a;
int fromto(int to,long stn)
{
   // cout<<"entering "<<to<<" or "<<arr[to]<<" stn is"<<stn<<endl;
    if(to==n)
        return 0;
    int ret=0;
    if(arr[to]>=stn)
    {
        while(stn<=arr[to])
        {
            stn+=(stn-1);
            ret++;
            if(ret>=(n-to))
            {
                ret=n-to;
                goto hey;
            }
        }
        //stn+=(arr[to]);
    }
        ret+=fromto(to+1,stn+arr[to]);
    hey:
    //    cout<<"temp  ret for "<<arr[to]<<" is"<<ret;
    ret=(ret<(n-to)?ret:(n-to));
   // cout<<"for element "<<arr[to]<<"plavr "<<to<<" ret is "<<ret<<endl;
    return ret;
}
using namespace  std;
int main()
{
    int T,t,i;
    scanf(" %d",&T);
    t=1;

    while(t<=T)
    {
        scanf(" %ld %d",&a,&n);
        i=0;
        while(i<n)
        {
            scanf(" %ld",&arr[i++]);
        }
        int op=0,tot=a;
        if(a==1)
        {
            op=n;
            goto end;
        }
        sort(arr,arr+n);
        op=fromto(0,a);
        end:
        printf("Case #%d: %d\n",t,op);

        t++;
    }
	return 0;
}
