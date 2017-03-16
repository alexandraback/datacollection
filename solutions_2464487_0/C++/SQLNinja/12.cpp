#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    int k,r,t,p,cnt,c=0;
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
        cin>>k;
        while(k--)
        {
                cnt=0;c++;
                cin>>r>>t;
                for(int i=1;;i+=2)
                {
                        p=(r+i)*(r+i)-(r+i-1)*(r+i-1);
                        if(p<=t)
                        {
                                cnt++;
                                t-=p;
                        }
                        else
                        break;

                }
                printf("Case #%d: %d\n",c,cnt);

        }
}
