#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char map[26]={'y','h','e','s','o','c','v','x','d','u','i',
'g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

char s[100000];
int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int t;
    scanf("%d",&t);
    getchar();
    int cot=1;
    while(t--)
    {
        printf("Case #%d: ",cot++);
        gets(s);
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            if(s[i]==' ') cout <<" " ;
            else
            {
                cout << (char)(map[s[i]-'a']) ;
            }
        }
        cout << endl;
    }
    return 0;
}







