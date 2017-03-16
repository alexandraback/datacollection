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

void solve()
{
    char in[10000];
    scanf("%s\n", in);

    string s (in, 1);
    for (int i = 1; i < strlen(in); i++)
    {
        if (in[i] >= s[0])
            s = in[i] + s;
        else
            s = s + in[i];
    }
    printf("%s\n", s.c_str());
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
