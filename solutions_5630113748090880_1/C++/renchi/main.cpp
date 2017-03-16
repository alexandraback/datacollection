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
    int i,j,k,t,h,Case = 1;
    int a[3000];
    int b[2500];
    cin>>t;
    while(t--)
    {
        for (int i = 0; i < 3000; i++) {
            a[i] = 0;
        }
        cin>>k;
        for (int i = 0; i < 2*k-1; i++) {
            for (int j = 0; j < k; j++) {
                cin>>h;
                a[h]++;
            }
        }
        int bb = 0;
        for (int i = 0; i < 3000; i++) {
            if(a[i]%2 == 1) {
                b[bb++] = i;
            }
        }
        sort(b, b+bb, comp);
        cout<<"Case #"<<Case++<<":";
        for(int i = 0; i < bb; i++) {
            cout<<" "<<b[i];
        }
        cout<<endl;
        
        
    }
    return 0;
}
