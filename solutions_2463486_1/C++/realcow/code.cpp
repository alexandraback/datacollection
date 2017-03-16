#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

typedef unsigned long long ull;

vector<ull> v;

bool isSqpal(char* s, ull& outSq)
{
    ull x;
    char sqs[200];

    sscanf(s, "%llu", &x);
    sprintf(sqs, "%llu", x * x);

    size_t len = strlen(sqs);
    size_t mid = len / 2;
    for (size_t i = 0; i < mid; i++) {
        if (sqs[i] != sqs[len - i - 1])   return false;
    }
    outSq = x * x;
    return true;
}

void init()
{
    //v.push_back(1), v.push_back(4), v.push_back(9);
    ull t;
    char s[100], pal[200], sqpal[200];
    for (t = 1; t <= 10000000; t++)
    {
        sprintf(s, "%llu", t);
        int len = strlen(s);
        ull x;

        
        // pal 1.  ==
        strcpy(pal, s);
        strcpy(pal + len, s);
        strrev(pal + len);
        if (isSqpal(pal, x)) v.push_back(x);


        // pal 2. =|=
        strcpy(pal, s);
        strcpy(pal + len - 1, s);
        strrev(pal + len - 1);
        if (isSqpal(pal, x)) v.push_back(x);
    }
    sort(v.begin(), v.end());
}

int main()
{
    ull a, b;
    int pn = 1;
    init();
    scanf("%*d");
    while (2 == scanf("%llu%llu", &a, &b)) {
        auto l = std::lower_bound(v.begin(), v.end(), a);
        auto r = std::upper_bound(v.begin(), v.end(), b);
        size_t n = (r - l);
        printf("Case #%u: %u\n", pn++, n);
    }
    
    return 0;
}