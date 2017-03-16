#include<bits/stdc++.h>
using namespace std;
int main()
{
     freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    int j=0,i,t,res=0,n;
    double k1,k2,a,m1,m2,time1,time2;
	cin>>t;
	while(t--)
    {
            j++;
            cin>>n;
            if(n==1)
            {
                cin>>k1>>a>>m1;
                if(a==1)
                    res=0;
                else
                {
                    k2=k1;
                    m2=m1+1;
                    time1=(((360-k1))/360)*m2;
                    time2=((720-k1)/360)*m1;
                    if(time2<=time1)
                        res=1;
                    else
                        res=0;
                }
            }
            else
            {
                cin>>k1>>a>>m1;
                cin>>k2>>a>>m2;
                if(m1<m2){
                time1=(((360-k2))/360)*m2;
                time2=((720-k1)/360)*m1;
                if(time2<=time1)
                    res=1;
                else
                    res=0;
                }
                else
                {
                    time1=(((360-k1))/360)*m1;
                    time2=((720-k2)/360)*m2;
                    if(time2<=time1)
                        res=1;
                    else
                        res=0;
                }

            }
            cout<<"Case #"<<j<<": "<<res<<"\n";
    }
	return 0;
}
