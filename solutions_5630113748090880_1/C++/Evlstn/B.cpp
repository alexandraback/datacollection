#include<iostream>
using namespace std;
int main()
{
	int i,j,k,l,n,t,y,temp;
	int data[2500],count[2500],datalong,out[100],outlong;
	cin>>n;
    for(t=1;t<=n;t++)
    {
        cin>>y;
        datalong =0;
        for(i=0;i<2500;i++)
        {
            data[i]=0;
            count[i]=0;
        }
        for(i=0;i<(2*y-1);i++)
        {
            for(j=0;j<y;j++)
            {
                cin>>temp;
                l=0;
                for(k=0;k<datalong;k++)
                {
                    if(temp==data[k])
                    {
                        l=1;
                        count[k]++;
                    }
                }
                if(l==0)
                {
                    data[datalong]=temp;
                    count[datalong]++;
                    datalong++;
                }
            }
        }
        /*
        cout<<"ASD\n";
        for(i=0;i<10;i++)
        {
            cout<<i<<" "<<data[i]<<" "<<count[i]<<endl;
        }
        */
        for(i=0;i<100;i++)
        {
            out[i]=0;
        }
        outlong =0;
        for(i=0;i<datalong;i++)
        {
            if(count[i]%2==1)
            {
                out[outlong]=data[i];
                outlong++;
            }
        }
        for(i=0;i<outlong;i++)
        {
            for(j=0;j<outlong-1;j++)
            {
                if(out[j]>out[j+1])
                {
                    temp=out[j];
                    out[j]=out[j+1];
                    out[j+1]=temp;
                }
            }
        }
        cout<<"Case #"<<t<<": ";
        for(i=0;i<outlong;i++)
        {
            cout<<out[i]<<" ";
        }
        cout<<endl;
    }

}
