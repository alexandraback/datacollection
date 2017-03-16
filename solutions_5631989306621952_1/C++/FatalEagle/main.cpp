#include <bits/stdc++.h>

using namespace std;

void _main(int TEST)
{
    string s;
    cin>>s;
    string t;
    for(auto it: s)
    {
        if(t.empty() || t[0]<=it)
            t=it+t;
        else
            t=t+it;
    }
    printf("%s\n", t.c_str());
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int TEST;
    scanf("%d", &TEST);
    for(int i=1; i<=TEST; i++)
    {
        printf("Case #%d: ", i);
        _main(i);
    }
    return 0;
}
