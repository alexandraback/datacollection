#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
char mapping[200];
int main()
{
    freopen("mapping.out", "r", stdin);
    gets(mapping+'a');
    fclose(stdin);
    mapping[' '] = ' ';
    freopen("tongue.in", "r", stdin);
    int t;
    char str[200];
    cin >> t;
    gets(str);
    for (int i=1; i<=t; i++)
    {
        gets(str);
        for (int j=0; str[j]; j++) str[j] = mapping[str[j]];
        printf("Case #%d: ", i);
        puts(str);
    }
    return 0;
}
