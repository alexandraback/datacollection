
#include <iostream>

#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long

using namespace std;

int t,n,b, i;
ll c;

int main()
{
    cin >> t;
    rep(ii,t)
    {
        cin >> n;
        c=0; b=0;
        for(i=1;i<=1000;i++)
        {
            c = n*i;
            while(c>0)
            {
                b |= 1 << (c%10);
                c/=10;
            }
            if(b==1023)break;
        }
        if(b==1023){
            cout << "Case #"<<ii+1<<": " << i*n<<endl;
        }
        else {
            cout << "Case #"<<ii+1<<": INSOMNIA"<<endl;
        }
    }
}
