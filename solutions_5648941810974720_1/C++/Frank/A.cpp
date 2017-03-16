#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<string>
#include<math.h>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
typedef long long LL;
using namespace std;

int bucket[26];
char D[][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int show[10];

struct Order
{
    char c;
    int d;
}order[10] = {{'Z', 0}, {'X', 6}, {'G', 8}, {'H', 3}, {'W', 2}, {'U', 4}, {'O', 1}, {'F', 5}, {'V', 7}, {'I', 9}};

void check(int i)
{
    char c = order[i].c;
    int d = order[i].d;
    int count = bucket[c - 'A'];
    if (count > 0)
    {
        for (int j = 0; j < count; j++)
            show[d]++;
        for (int j = 0; j < strlen(D[d]); j++)
            bucket[D[d][j] - 'A'] -= count;
    }
}

void solve()
{
    for (int i = 0; i < 26; i++)
        bucket[i] = 0;       

    for (int i = 0; i < 10; i++)
        show[i] = 0;

    char in[3000];
    scanf("%s", in);

    for (int i = 0; i < strlen(in); i++)
    {
        char c = in[i];
        bucket[c - 'A']++;
    }

    for (int i = 0; i < 10; i++)
    {
        check(i);
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < show[i]; j++)
            printf("%d", i);
    }
    printf("\n");
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    int cases;
    scanf("%d\n", &cases);

    for(int i = 1; i <= cases; i++)
    {
        printf("Case #%d: ", i);
        solve();
    }
	return 0;

}
