#include<iostream>
#include<cstdio>
#include<cmath>
#include<set>

using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a,b, total=0;
        cin>>a>>b;
        for(int j=a;j<b;j++)
        {
            char buffer[10];
            int n = sprintf (buffer, "%d", j);
            //cout<<"n="<<n<<endl;
            if(n==1)continue;
            int pot1=10, pot2=pow(10,n-1);
            set<int> num;
            for(int k=0;k<n-1;k++)
            {
                int val=(j%pot1)*pot2+floor(j/pot1);
                //cout<<val<<' ';
                if(val>j&&val<=b)num.insert(val);

                pot1*=10;
                pot2/=10;
            }
            total+=num.size();

        }
        cout<<"Case #"<<i+1<<": "<<total<<endl;
    }
    return 0;
}
