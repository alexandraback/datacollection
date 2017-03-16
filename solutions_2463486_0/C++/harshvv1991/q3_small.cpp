#include<iostream>
#include<cmath>

using namespace std;

bool isPalen(int n)
{
    int n2=0;
    int nc=n;

    for(;n>0;n=n/10)
        n2 = (n2*10)+(n%10);

    return (nc==n2);
}

int main()
{
    int T;
    cin>>T;

    int l, h;

    for(int cas = 1; cas<=T; cas++)
    {
        cin>>l>>h;
        l = (int)ceil(sqrt(l));
        h = (int)floor(sqrt(h));

        int count = 0;

        for(int i=l; i<=h; i++)
        {
            if((i>=4)&&(i<=10))
            {
                i=10;
                continue;
            }

            if(isPalen(i)&&isPalen(i*i))
                count++;
        }
        cout<<"Case #"<<cas<<": "<<count<<endl;
    }

    return 0;
}
