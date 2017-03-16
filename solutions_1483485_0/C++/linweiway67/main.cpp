#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char st[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n',
           'w','j','p','f','m','a','q'};

int main()
{
    freopen("aa.txt","r",stdin);
    freopen("bb.txt","w",stdout);
    int cas,ta=1;
    cin >> cas;

    while(cas--)
    {
        char s[200],ans[200];
        int i,l;

        if(ta == 1)
          getchar();
        gets(s);
        l = strlen(s);
        for(i=0; i<l; i++)
        {
            if(s[i] == ' ') ans[i] = ' ';
            else ans[i] = st[s[i]-'a'];
        }

        printf("Case #%d: ",ta++);
        for(i=0; i<l; i++)
           printf("%c",ans[i]);
        printf("\n");
    }
    return 0;
}
