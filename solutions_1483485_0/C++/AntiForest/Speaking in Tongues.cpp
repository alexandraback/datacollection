#include <cstdio>
#include <cstring>
using namespace std;

char orig[]={'q','a','o','z','o','u','r','l','a','n','g','u','a','g','e','i','s','i','m','p','o','s','s','i','b','l','e','t','o','u','n','d','e','r','s','t','a','n','d','t','h','e','r','e','a','r','e','t','w','e','n','t','y','s','i','x','f','a','c','t','o','r','i','a','l','p','o','s','s','i','b','i','l','i','t','i','e','s','s','o','i','t','i','s','o','k','a','y','i','f','y','o','u','w','a','n','t','t','o','j','u','s','t','g','i','v','e','u','p'};
char tran[]={'z','y','e','q','e','j','p','m','y','s','l','j','y','l','c','k','d','k','x','v','e','d','d','k','n','m','c','r','e','j','s','i','c','p','d','r','y','s','i','r','b','c','p','c','y','p','c','r','t','c','s','r','a','d','k','h','w','y','f','r','e','p','k','y','m','v','e','d','d','k','n','k','m','k','r','k','c','d','d','e','k','r','k','d','e','o','y','a','k','w','a','e','j','t','y','s','r','r','e','u','j','d','r','l','k','g','c','j','v'};
char cipher[300];
char nextline[500];


int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("test.out","w",stdout);
    int osiz=strlen(orig);
    for(int i=0;i<osiz;i++){
        cipher[tran[i]]=orig[i];
    }
    cipher[32]=' ';
    int num;
    scanf("%d ",&num);
    for(int i=1;i<=num;i++){
        printf("Case #%d: ",i);
        gets(nextline);
        for(int i=0;i<strlen(nextline);i++){
            printf("%c",cipher[nextline[i]]);
        }
        printf("\n");
    }
    return 0;
}
