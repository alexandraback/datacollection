#include<iostream>
#include<cstdio>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

inline bool isPal(long long &num)
{
    stringstream ss;
    ss << num;
    string s = ss.str();
    reverse(s.begin(), s.end());
    return ss.str() == s;
}
vector<long long> palindromes;

void genPal()
{
    for (long long i=1LL;;++i)
    {
        long long n1 = i;
        long long n2 = i;
        long long n = i;
        bool flag = false;
        while ( n > 0) {
            n2 = n2 * 10LL + n % 10LL;
            if ( flag ) {
                n1 = n1 * 10LL + n % 10LL;
            }
            flag = true;
            n/=10LL;
        }
        if ( n1 * n1 > 100000000000000LL) break;
        palindromes.push_back(n1);
        palindromes.push_back(n2);
    }
    sort(palindromes.begin(), palindromes.end());
}


long long cnt(long long a, long long b)
{
    long long cnt = 0LL;

    for (int i=0;i<palindromes.size();++i){
        long long pal = palindromes[i];
        long long sq = pal * pal;
        if ( sq > b ) break;

        if ( sq >= a && sq <=b && isPal(sq)) {
            cnt+=1LL;
        }
    }
    return cnt;
}

int main(void)
{
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);


    int t;

    std::stringstream ss;

    scanf ("%d", &t);
    vector<vector<int> > field;
    genPal();
    for (int _test=1;_test<=t;++_test) {
        if (_test % 100 == 0 )fprintf(stderr, "%d/%d\n", _test, t);
        long long a, b;
        scanf("%lld %lld", &a, &b);
        long long c = cnt ((long long)a, (long long)b);
        printf ("Case #%d: %lld\n", _test, c);
    }


    return 0;
}
