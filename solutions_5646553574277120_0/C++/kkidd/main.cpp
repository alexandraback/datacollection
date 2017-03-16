#include <iostream>
#include <fstream>
using namespace std;

ofstream f2("f3out.out");
int b[1000]={0};
int flag=0;
int C,D,V;
void judge(int m)
{
    for(int k=0;k<V+1;k++)
    {
        if(b[k]==1)
        {
            b[k+m]=1;
        }
    }
}

int main()
{
    int T;
    cin>>T;
    int a[6]={0};

    int y=0;
    int count;
    for(int i=0;i<T;i++)
    {
        count=0;
        y=0;
        cin>>C>>D>>V;
        for(int j=0;j<40;j++)
        {
            b[j]=0;
        }
        for(int j=0;j<6;j++)
        {
            a[j]=0;
        }
        for(int j=0;j<D;j++)
        {
            cin>>a[j];
        }
        for(int i1=0;i1<2;i1++)
        {
            for(int i2=0;i2<2;i2++)
            {
                for(int i3=0;i3<2;i3++)
                {
                    for(int i4=0;i4<2;i4++)
                    {
                        for(int i5=0;i5<2;i5++)
                        {
                            count=i1*a[0]+i2*a[1]+i3*a[2]+i4*a[3]+i5*a[4];
                            b[count]=1;
                        }
                    }
                }
            }
        }

        for(int j=0;j<V+1;j++)
        {
            if(b[j]==0)
            {
                y++;
                judge(j);
            }
        }
        f2<<"Case #"<<i+1<<": "<<y<<endl;
    }
    return 0;
}
