#include<iostream>
#include<math.h>
using namespace std;
int no_of_digits(int i)
{
    int count=0;
    while(i)
    {
        i=i/10;
        count++;
    }
    return count;
}
int transform(int num,int &flag)
{
    int temp1 = num%(int)pow(10.0,no_of_digits(num)-1);
    int t=no_of_digits(num)-no_of_digits(temp1);
    int temp2 = num/(int)pow(10.0,no_of_digits(num)-1);
    temp1=(temp1*10)+temp2;
    if(t>1)
    {
       temp1=temp1*(int)pow(10.0,t-1); 
       flag=t-1;
    }
    return temp1;
}
int not_dup(int a[],int n)
{
    for(int i=0;i<n;i++)
        if(a[i]==a[n])return 0;
    return 1;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    int T;
    cin>>T;
    int a=T;
    while(T--)
    {
        int A,B,count=0,k=1;
        cin>>A>>B;
        for(int i=A;i<=B;i++)
        {
            int num=i;
            int temp[10];
            int x=1;
            temp[0]=num;
            for(int j=1;j<no_of_digits(i);j++)
            {
                int flag=0;
                temp[x]=transform(temp[x-1],flag);
                if(not_dup(temp,x))
                {
                    if(temp[x]>=A&&temp[x]<=B&&temp[x]>num&&no_of_digits(temp[x])==no_of_digits(num))
                    {
                        count++;
                        //cout<<k++<<" "<<num<<" "<<temp[x]<<"\n";
                    }

                }
                x++;
            }

        }
        cout<<"Case #"<<a-T<<": "<<count<<"\n";
    }
}