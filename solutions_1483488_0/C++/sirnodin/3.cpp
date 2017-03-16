#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define REP(i,n) for(long long i = 0;i<(n);++i)

using namespace std;

long long N;
long long A,B;
long long temp;

long long ans;

long long num[2000001];
long long E[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};

int main()
{
    ifstream fin("C-small-attempt0.in");
    ofstream fout("C-small-attempt0.out");
    fin>>N;
    REP(T,N)
    {
        ans = 0;
        fin>>A>>B;
        for(long long n = A;n<=B;++n)
        {
            num[n]=T+1;
            long long ex=0;
            long long l = 0;
            while(n>=E[ex])
            {
                l++;
                ex++;
            }
            ex = 1;
            while(n>=E[ex])
            {
                temp = n/E[ex]+(n%E[ex])*E[l-ex];
                if(temp<=n || temp>2000000 || num[temp]==n)
                    ;
                else if(temp<=B && temp>=A)
                {
                    num[temp]=n;
                    ans++;
                    //cout<<"Case #"<<T+1<<": "<<n<<" "<<temp<<endl;
                }
                ex++;
            }
        }

        cout<<T+1<<endl;
        fout<<"Case #"<<T+1<<": "<<ans<<endl;
    }
    return 0;
}
