//#include <iostream>
//#include <cstdio>
//#include <map>
//using namespace std;
//map<char,char> ma;
//int main()
//{
//    freopen("1.txt","r",stdin);
//    char a[213],b[213];
//    int n=3;
//    while(n--)
//    {
//        gets(a);
//        gets(b);
//        for(int i=0; a[i]; ++i)
//        {
//            if(islower(a[i]))
//                ma[a[i]]=b[i];
//        }
//    }
//    for(map<char,char>::iterator w=ma.begin();w!=ma.end();w++)
//       printf("%c",w->first);
//    printf("\n");
//    for(map<char,char>::iterator w=ma.begin();w!=ma.end();w++)
//       printf("%c",w->second);
//    printf("\n");
//    return 0;
//}
#include <iostream>
#include <cstdio>

using namespace std;
char str[27]="yhesocvxduiglbkrztnwjpfmaq";
int main()
{
    //freopen("1.in","r",stdin);
    //freopen("o.txt","w",stdout);
    char ori[102];
    int n;
    scanf("%d", &n);
    getchar();
    for(int ca = 1; ca <= n; ++ca )
    {
        gets(ori);
        printf("Case #%d: ", ca );
        for(int i = 0; ori[i]; ++i )
        {
            if(islower(ori[i]))
                putchar(str[ ori[i] - 'a' ]);
            else
                putchar(ori[i]);
        }
        printf("\n");
    }
}
