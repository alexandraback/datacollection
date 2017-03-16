#include<iostream>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<sstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<numeric>
#include<utility>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;

const int MAXN = 10005;

struct barber
{
    long long num;
    long long time;
    barber(long long i)
    {
        num = i;
        time = 0;
    }
};

struct cmp
{
    bool operator()(barber a, barber b)
    {
        return a.time != b.time ? b.time < a.time: b.num < a.num;
    }
};

long long gcd(long a, long b)
{
    return b == 0? a : gcd(b, a%b);
}

int comp(int a, int b) {//increasing
    return a < b;
}


int main() {
    int i,j,k,t,Case = 1;
    string a;
    cin>>t;
    while(t--)
    {
        string result;
        cin>>a;
        for (int i = 0; i < a.length(); i++) {
            if (result.length() == 0 || result[0] > a[i]) {
                result += a[i];
            } else {
                result = a[i] + result;
            }
        }
        
        cout<<"Case #"<<Case++<<": "<<result<<endl;
        
    }
    return 0;
}
