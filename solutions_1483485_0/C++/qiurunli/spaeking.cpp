#include <stdio.h>
#include <cstring>
#include <string>

using namespace std;

const int MAXN = 1100;
char A[] = "ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv";
char B[] = "ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup";
int mp[300];

void init()
{
    memset(mp, -1, sizeof(mp));
    int len(strlen(A));
    for(int i = 0; i < len; ++i)
    {
        if(mp[A[i]] != -1 && mp[A[i]] != B[i])  puts("error");
        mp[A[i]] = B[i];
    }
//    for(int i = 'a'; i <= 'z'; ++i)
//    {
//        printf("%c  <%c>\n", i, mp[i]);
////        putchar(mp[i]);
//    }
    mp['q'] = 'z';
    mp['z'] = 'q';
    mp[' '] = ' ';
}
char org[MAXN], res[MAXN];

int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out","w", stdout);

    init();
    int test, cas(1);
    scanf("%d", &test);
    getchar();
    while(test--)
    {
        gets(org);
//        puts(org);
        int len = strlen(org);
        for(int i = 0; i < len; ++i)
            res[i] = mp[org[i]];
        res[len] = 0;
        printf("Case #%d: %s\n",cas++, res);
    }

    return 0;
}
