#include<iostream>
using namespace std;
int main()
{
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        int D;
        cin>>D;
        int P[D];
        int max=0;
        for(int i=0;i<D;i++)
        {
            cin>>P[i];
                if(P[i]>max)
                    max=P[i];
        }
        int ans=max;
        for(int i=max;i>=1;i--)
        {
            int possible=0;
            for(int j=0;j<D;j++)
                if(P[j]>i)
                {
                    if(P[j]%i==0)
                        possible+=((P[j]/i)-1);
                    else
                        possible+=(P[j]/i);
                }
            possible+=i;
            if(possible<ans)
                ans=possible;
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;
    }
	return 0;
}
