#include<iostream>
using namespace std;
int main()
{
	char inp[2000],otp[2000],temp[2000];
	int i,j,k,l,n,t;


	cin>>n;
	for(t=1;t<=n;t++)
    {
        for(i=0;i<2000;i++)
        {
            inp[i]=0;
            otp[i]=0;
            temp[i]=0;
        }

        cin>>inp;
        otp[0]=inp[0];
        for(i=1;inp[i]!='\0';i++)
        {
            if(inp[i]>=otp[0])
            {
                temp[0]=inp[i];
                for(j=0;otp[j]!='\0';j++)
                {
                    temp[j+1] = otp[j];
                }
                temp[j+1] = '\0';
                for(j=0;temp[j]!='\0';j++)
                {
                    otp[j]=temp[j];
                }
            }
            else
            {
                otp[i] = inp[i];
            }
        }
        cout<<"Case #"<<t<<": "<<otp<<endl;
    }
}
