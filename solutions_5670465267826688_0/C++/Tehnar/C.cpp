#define FNAME ""

#include <bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define fornr(i, n) for (int i = n - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = a; i < (int) b; i++)
#define gcd __gcd
 
#ifdef WIN32
    #define I64 "%I64d"
#else
    #define I64 "%lld"
#endif

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair <int, int> pii;
typedef vector <int> vi;

template <class T> T sqr(const T &a) {return a * a;}

struct st
{
    st(){}

    st(char c)
    {
        if (c == 'i')
            x = 2;
        else if (c == 'j')
            x = 3;
        else if (c == 'k')
            x = 4;
        else
            assert(0);
            
    }

    st(int a)
    {
        x = a;
    }
    
    bool operator == (st a)
    {
        return x == a.x;
    }

    st operator * (st a)
    {
        if (abs(x) == 1 || abs(a.x) == 1)
            return st(a.x * x);
        if (abs(x) == abs(a.x))
            return st((x == a.x) ? -1 : 1);         
        if (x == 2)
        {
            if (abs(a.x) == 3)
                return st((a.x == 3) ? 4 : -4);         

            if (abs(a.x) == 4)
                return st((a.x == 4) ? -3 : 3);         
        }

        if (x == 3)
        {
            if (abs(a.x) == 4)
                return st((a.x == 4) ? 2 : -2);         

            if (abs(a.x) == 2)
                return st((a.x == 2) ? -4 : 4);         
        }

        if (x == 4)
        {
            if (abs(a.x) == 2)
                return st((a.x == 2) ? 3 : -3);         

            if (abs(a.x) == 3)
                return st((a.x == 3) ? -2 : 2);         
        }

        if (x == -2)
        {
            if (abs(a.x) == 3)
                return st((a.x == 3) ? -4 : 4);         

            if (abs(a.x) == 4)
                return st((a.x == 4) ? 3 : -3);         
        }

        if (x == -3)
        {
            if (abs(a.x) == 4)
                return st((a.x == 4) ? -2 : 2);         

            if (abs(a.x) == 2)
                return st((a.x == 2) ? 4 : -4);         
        }

        if (x == -4)
        {
            if (abs(a.x) == 2)
                return st((a.x == 2) ? -3 : 3);         

            if (abs(a.x) == 3)
                return st((a.x == 3) ? 2 : -2);         
        }
        assert(0);
    }


    int x;
};

int T, l, pos, good;
st p[1000000], prod, a[1000000];
char s[1000000];
LL x;

int main()
{
    freopen(FNAME".in", "r", stdin);
    freopen(FNAME".out", "w", stdout);
    scanf("%d", &T);
    forn(TT, T)
    {
        scanf("%d%I64d\n", &l, &x);
        gets(s);
        forn(i, min(x, x))
            forn(j, l)
                s[j + i * l] = s[j];
        l *= min(x, x);
        forn(i, l)
            a[i] = st(s[i]);
        pos = -1;
        p[0] = 1;
        forn(i, l)
        {
            p[i + 1] = p[i] * a[i]; 
      //      printf("%d %d\n", a[i].x, p[i + 1].x);
            if (pos == -1 && p[i + 1] == st('i'))
                pos = i;
        }
        
        prod = 1;
        good = 0;
  //      printf("%d\n", pos);
        if (pos != -1)
        fornr(i, l)
        {
            prod = a[i] * prod;
            if (prod == st('k') && p[i] == st('k') && i > pos)
                good = 1;
        }
        printf("Case #%d: ", TT + 1);
        puts(good ? "YES" : "NO");
    }
}

