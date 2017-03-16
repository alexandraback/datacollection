#include<iostream>
#include<cstdio>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

bool isPal(long long num)
{
    stringstream ss;
    ss << num;
    string s = ss.str();
    reverse(s.begin(), s.end());
    return ss.str() == s;
}

long long cnt(long long a, long long b)
{
    long long cnt = 0LL;
    for (long long i=1LL;;++i)
    {
        stringstream ss;
        ss << i;

        string tmp1 = ss.str().substr(0, ss.str().size() - 1);
        reverse(tmp1.begin(), tmp1.end());
        string pal1 = ss.str() + tmp1;
        long long n1;
        sscanf(pal1.c_str(), "%lld", &n1);
        long long sq1 = n1 * n1;
        if ( sq1 > b ) break;
        if (sq1 >= a && sq1 <= b && isPal(sq1)) {
            cnt+=1LL;
        }


        string tmp2 = ss.str();
        reverse(tmp2.begin(), tmp2.end());
        string pal2 = ss.str() + tmp2;
        long long n2;
        sscanf(pal2.c_str(), "%lld", &n2);
        long long sq2 = n2 * n2;
        if(sq2 >= a && sq2 <= b && isPal(sq2)) {
            cnt+=1LL;
        }
    }
    return cnt;
}

int main(void)
{
    freopen("C-small.in", "r", stdin);
    freopen("C-small.out", "w", stdout);

    int t;

    std::stringstream ss;

    scanf ("%d", &t);
    vector<vector<int> > field;
    for (int _test=1;_test<=t;++_test) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        long long c = cnt ((long long)a, (long long)b);
        printf ("Case #%d: %lld\n", _test, c);
    }



    return 0;
}
