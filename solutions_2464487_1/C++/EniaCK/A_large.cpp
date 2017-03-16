#include <cstdio>
#include <iostream>
using namespace std;
long long r, t;
int T;
long long ans;

long long calc(long long n)
{
    if(n >= t/r)return 2000000000000000201;
    return (r*(n<<1)) + (((1+(n<<2)-3)*n)>>1);
}

int main()
{
    cin >> T;
    for(int cas = 1; cas <= T; cas++){
        cin >> r >> t;
        long long lower = 1, upper = 2*707106780+10, mid, cost;
        while(lower < upper){
            mid = (lower + upper) / 2;
            cost = calc(mid);
            //cout<<mid<<" "<<cost<<endl;
            if(cost > t)upper = mid;
            else lower = mid+1;
        }
        cout << "Case #"<< cas << ": "<<lower-1<<endl;
    }
    return 0;
}
