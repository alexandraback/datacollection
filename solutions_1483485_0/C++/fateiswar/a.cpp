#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

char l1[500],l2[500];
int main(){
	//memset(f, -1, sizeof(f));
	//memset(fr, -1, sizeof(fr));
	//for(int i=1; i<=3; i++){
	//	gets(l1); gets(l2);
	//	for(int j=0, len=strlen(l1); j<len; j++)
	//	{
	//		f[l1[j]-'a']=l2[j]-'a';
	//		fr[l2[j]-'a']=l1[j]-'a';
	//	}
	//}
	//bool use[30]; memset(use, 0, sizeof(use));
	//for(int i=0; i<26; i++)
	//	if(fr[i]!=-1){ printf("%c", fr[i]+'a');use[fr[i]]=1;}
	//	else printf("*");
	//printf("\n");
	//for(int i=0; i<26; i++)
	//	if(f[i]!=-1) printf("%c", f[i]+'a');
	//	else printf("*");
	//printf("\n");
	//for(int i=0; i<26; i++) if(!use[i]) printf("unused: %c\n", i+'a');
	char f[30]="yhesocvxduiglbkrztnwjpfmaq";
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-out.txt", "w", stdout);
	int T; cin>>T;
	gets(l1);
	for(int cas=1; cas<=T; cas++){
		gets(l1);
		printf("Case #%d: ", cas);
		for(int i=0, len=strlen(l1); i<len; i++){
			if(l1[i]==' ') printf(" ");
			else printf("%c", f[l1[i]-'a']);
		}
		printf("\n");
	}
	return 0;
}