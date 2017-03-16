#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
       int r,c,n,i,k;
       FILE *fo,*fi;
       fi=freopen("D:\\C++\\code jam\\A-small-attempt0.in", "r", stdin);
	   fo=freopen("D:\\C++\\code jam\\A-small-attempt0.out", "w+", stdout);
	   //fi=freopen("D:\\A-small-practice.in", "r", stdin);
	   //fo=freopen("D:\\A-small-practice.out", "w+", stdout);
       scanf("%d\n",&n);
       char a[100],ms;
       char map[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};  
       for(i=0;i<n;i++)
		{	
            scanf("%c",&ms);
			for(k=0;ms!='\n';k++)
			{
					a[k]=ms;
                    scanf("%c",&ms);				
			}
			a[k]='\0';	
			printf("Case #%d: ",i+1);
            for(k=0;a[k]!='\0';k++)
			{
                   if(a[k]>='a'&&a[k]<='z')
				      printf("%c",map[a[k]-'a']);	
                   else
                      printf("%c",a[k])	;	
			}
			/*for(k=0;a[k]!='\0';k++)
			{
                  printf("%c",a[k]);
			}*/
            printf("\n");
        }
		fclose(fo);
		fclose(fi);
		system("pause");
		return 0;
}
