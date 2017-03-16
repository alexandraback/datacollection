#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;

#define maxm 1150


char s1[maxm],s2[maxm];
char map[]="yhesocvxduiglbkrztnwjpfmaq";
char s[]=  "abcdefghijklmnopqrstuvwxyz";

int main(){

	int i,j,k,l,test,t=1;


    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);

    scanf("%d",&test);
    gets(s1);

	while(test--){

	    gets(s1);
	    printf("Case #%d: ",t++);
	    for(i=0;s1[i];i++){
	        if(s1[i]==' '){
	            printf(" ");
	            continue;
	        }
	        printf("%c",map[s1[i]-'a']);
	    }
	    printf("\n");

	}


	return 0;
}
