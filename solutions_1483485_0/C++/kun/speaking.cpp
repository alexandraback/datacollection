#include<cstdio>
#include<cstdlib>
int n,ch[27];
char str[10001];
int main(){
    freopen("A-small-attempt0.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&n); gets(str);
    for(int i=0;i<n;i++){
       gets(str);
       printf("Case #%d: ",i+1);        
       for(int j=0;str[j]!='\0';j++){
          if(str[j] == 'a')printf("y");
          else if(str[j] == 'b')printf("h");
          else if(str[j] == 'c')printf("e");
          else if(str[j] == 'd')printf("s");
          else if(str[j] == 'e')printf("o");
          else if(str[j] == 'f')printf("c");
          else if(str[j] == 'g')printf("v");
          else if(str[j] == 'h')printf("x");
          else if(str[j] == 'i')printf("d");
          else if(str[j] == 'j')printf("u");
          else if(str[j] == 'k')printf("i");
          else if(str[j] == 'l')printf("g");
          else if(str[j] == 'm')printf("l");
          else if(str[j] == 'n')printf("b");
          else if(str[j] == 'o')printf("k");
          else if(str[j] == 'p')printf("r");
          else if(str[j] == 'q')printf("z");
          else if(str[j] == 'r')printf("t");
          else if(str[j] == 's')printf("n");
          else if(str[j] == 't')printf("w");
          else if(str[j] == 'u')printf("j");
          else if(str[j] == 'v')printf("p");
          else if(str[j] == 'w')printf("f");
          else if(str[j] == 'x')printf("m");
          else if(str[j] == 'y')printf("a");
          else if(str[j] == 'z')printf("q");     
          else printf(" ");
       }     
       printf("\n");
    }
    //system("pause");
    return 0;
}
