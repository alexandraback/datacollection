#include<iostream>


using namespace std;

long long gcd ( long long a, long long b )
{
  long long c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}

int main()
{
    double n, pow=1, num, den;
    long long t;
    cin>>t;
    for(long long z=1;z<=t;z++)
    {
        long long count = 0, g;
        char x;
        cin>>num>>x>>den;
        g = gcd((long long)num,(long long )den);
        long long y =((long long)den)/g;
        while(y > 0)
        {
            if(y!=1 && y%2 == 1)
            {
                cout<<"Case #"<<z<<": "<<"impossible"<<endl;
                break;
            }

            y=y/2;

        }
        if(y >0)
            continue;
        n = ((double) num)/den;
        pow = 1.0;
        while(pow> n)
        {
            count++;
            pow=pow/2;

        }
        cout<<"Case #"<<z<<": "<<count<<endl;

    }
}
