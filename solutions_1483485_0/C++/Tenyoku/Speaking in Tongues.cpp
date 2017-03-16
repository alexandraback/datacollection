#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

const int decode[26] = {24, 7, 4, 18, 14, 2, 21, 23, 3, 20, 8, 6, 11, 1, 10, 17, 25, 19, 13, 22, 9, 15, 5, 12, 0, 16};

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    string a;
    int T;
    scanf("%d ", &T);
    for(int i=1; i<=T; ++i)
    {
        getline(cin, a);
        printf("Case #%d: ", i);
        for(int i=0; i<a.size(); ++i) putchar((a[i]==' ')?' ':(decode[a[i]-'a']+'a'));
        puts("");
    }
    return 0;
}
