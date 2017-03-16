#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
char co[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r',
'z','t','n','w','j','p','f','m','a','q'};
int main()
{
    freopen("Redownload A-small.in","r",stdin);
    freopen("a.out","w",stdout);
    int total;
    string tmp;
    scanf("%d\n",&total);
    for (int t=1;t<=total;t++)
    {
        getline(cin,tmp);
        printf("Case #%d: ",t);
        for (int i=0;i<tmp.size();i++)
            if (tmp[i]!=' ')cout<<co[tmp[i]-'a'];else cout<<' ';
            cout<<endl;
    }
}
