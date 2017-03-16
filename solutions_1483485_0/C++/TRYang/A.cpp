#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <ctype.h>
#include <string>

using namespace std;

const string str1[3]={"ejpmysljylckdkxveddknmcrejsicpdrysi",
					"rbcpcypcrtcsradkhwyfrepkymveddknkmkrkcd",
					"dekrkdeoyakwaejtysrreujdrlkgcjv"};
const string str2[3]={"ourlanguageisimpossibletounderstand",
					"therearetwentysixfactorialpossibilities",
					"soitisokayifyouwanttojustgiveup"};
char ch[300];
char buf[10010];
int main(){
	for (int i=0;i<3;i++)
		for (int j=0;j<str1[i].length();j++)
			ch[str1[i][j]]=str2[i][j];
	ch['q']='z';
	ch['z']='q';
	int tn,cp;
	for (scanf("%d",&tn),cp=1;cp<=tn;cp++){
		if (cp==1) buf[0]=getchar();
		gets(buf);
		printf("Case #%d: ",cp);
		int len=strlen(buf);
		for (int i=0;i<len;i++){
			if (islower(buf[i])) buf[i]=ch[buf[i]];
			printf("%c",buf[i]);
		}
		puts("");
	}
	return 0;
}
