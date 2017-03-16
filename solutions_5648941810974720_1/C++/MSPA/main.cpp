#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>

const int N = 1e5+3;
const int inf = 1e9;

typedef long long ll;

using namespace std;


int a[10];
char s[N];
int al[255];
bool solve()
{
    scanf("%s", s);
    memset(a, 0, sizeof(a));
    memset(al, 0, sizeof(al));
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
        al[s[i]]++;
    a[0] = al['Z'];
    al['E'] -= al['Z'];
    al['R'] -= al['Z'];
    al['O'] -= al['Z'];
    al['Z'] -= al['Z'];
    
    a[2] = al['W'];
    al['T'] -= al['W'];
    al['O'] -= al['W'];
    al['W'] -= al['W'];
    
    a[4] = al['U'];
    al['F'] -= al['U'];
    al['O'] -= al['U'];
    al['R'] -= al['U'];
    al['U'] -= al['U'];
    
    a[6] = al['X'];
    al['S'] -= al['X'];
    al['I'] -= al['X'];
    al['X'] -= al['X'];
    
    a[7] = al['S'];
    al['E'] -= al['S'];
    al['V'] -= al['S'];
    al['E'] -= al['S'];
    al['N'] -= al['S'];
    al['S'] -= al['S'];
    
    a[8] = al['G'];
    al['E'] -= al['G'];
    al['I'] -= al['G'];
    al['H'] -= al['G'];
    al['T'] -= al['G'];
    al['G'] -= al['G'];
    
    a[5] = al['V'];
    al['F'] -= al['V'];
    al['I'] -= al['V'];
    al['E'] -= al['V'];
    al['V'] -= al['V'];
    
    a[3] = al['T'];
    al['H'] -= al['T'];
    al['R'] -= al['T'];
    al['E'] -= al['T'];
    al['E'] -= al['T'];
    al['T'] -= al['T'];
    
    a[9] = al['I'];
    al['N'] -= al['I'];
    al['N'] -= al['I'];
    al['E'] -= al['I'];
    al['I'] -= al['I'];
    
    a[1] = al['O'];
    
    for (int i =0 ; i < 10; ++i)
        while (a[i]) {
            printf("%d", i);
            a[i]--;
        }
    puts("");
    return false;
}

int main()
{
        freopen("input.txt","r", stdin);
        freopen("output.txt", "w", stdout);
    int countTests;
    scanf("%d", &countTests);
    for (int curTest = 1; curTest <= countTests; ++curTest) {
        printf("Case #%d: ", curTest);
        solve();
    }
    
    return 0;
}
