#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

const int N = 100010;
int n, a[N];
char s[N];
multiset<int> se;

void solve(int test)
{
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++) a[s[i]]++;
    while (a['Z'])
    {
        a['Z']--; a['E']--; a['R']--; a['O']--;
        se.insert(0);
    }
    while (a['W'])
    {
        a['T']--; a['W']--; a['O']--;
        se.insert(2);
    }
    while (a['X'])
    {
        a['S']--; a['I']--; a['X']--;
        se.insert(6);
    }
    while (a['U'])
    {
        a['F']--; a['O']--; a['U']--; a['R']--;
        se.insert(4);
    }
    while (a['F'])
    {
        a['F']--; a['I']--; a['V']--; a['E']--;
        se.insert(5);
    }
    while (a['V'])
    {
        a['S']--; a['E']--; a['V']--; a['E']--; a['N']--;
        se.insert(7);
    }
    while (a['G'])
    {
        a['E']--; a['I']--; a['G']--; a['H']--; a['T']--;
        se.insert(8);
    }
    while (a['O'])
    {
        a['O']--; a['N']--; a['E']--;
        se.insert(1);
    }
    while (a['I'])
    {
        a['N']--; a['I']--; a['N']--; a['E']--;
        se.insert(9);
    }
    while (a['E'])
    {
        a['T']--; a['H']--; a['R']--; a['E']--; a['E']--;
        se.insert(3);
    }
    printf("Case #%d: ", test);
    for (auto i : se) printf("%d", i);
    printf("\n");
    se.clear();
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) solve(i);
    return 0;
}
