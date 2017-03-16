#include<map>
#include<cstdio>
using namespace std;
map<char,char>m;
char a[]={"azooejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv"};
char b[]={"yqeeourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup"};
char s[110];
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int i,t,tt=1;
	for(i=0;a[i];i++)
		m[a[i]]=b[i];
	m['q']='z';
	scanf("%d",&t);
	getchar();
	while(gets(s)){
		printf("Case #%d: ",tt++);
		for(i=0;s[i];i++)
			if(s[i]==' ')putchar(' ');
			else printf("%c",m[s[i]]);
		putchar(10);
	}
	return 0;
}
