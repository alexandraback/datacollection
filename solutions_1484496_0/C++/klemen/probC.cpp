#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

int N;
int S[30];
map<int, int> mm;
vector<pair<int, int> > rv;

bool c[30];
bool cc[30];

int toint()
{
    int r = 0;
    for (int i = 0; i < N; i++)
        if (c[i])
            r |= (0x1 << i);
    return r;
}

void fromint(int a)
{
    for (int i = 0; i < N; i++) {
        cc[i] = a & 0x1;
        a >>= 1;
    }
}

void printcc()
{
    bool first = true;
    for (int i = 0; i < N; i++) {
        if (cc[i]) {
            if (!first) printf(" ");
            first = false;
            printf("%d", S[i]);
        }
    }
    printf("\n");
}

void r(int i)
{
    if (i == N) {
        int sum = 0;
        for (int j = 0; j < N; j++)
            if (c[j])
                sum += S[j];
        
        
        int a = toint();
        
        map<int, int>::iterator k = mm.find(sum);
        if (k != mm.end()) {
            int b = (*k).second;
            if (a != 0 && b != 0 && a != b)
                rv.push_back(make_pair(a, b));
        }
        
        mm[sum] = a;
    }
    else {
        c[i] = false;
        r(i + 1);
        c[i] = true;
        r(i + 1);
    }    
}

int solve(int T)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &S[i]);
        c[i] = 0;
    }
    
    mm.clear();
    rv.clear();
    
    r(0);
    
    printf("Case #%d:\n", T);
    if (!rv.empty()) {
        int a = rv.front().first;
        int b = rv.front().second;
        fromint(a);
        printcc();
        fromint(b);
        printcc();
    }
    else {
        printf("Impossible\n");
    }
}

int main()
{
    int tc = 0;
    scanf("%d", &tc);
    
    for (int i = 0; i < tc; i++)
        solve(i + 1);
}
