#include<cstdio>
#include<string>
using namespace std;

const char m[26][2]=
{{'a','y'},
{'b','h'},
{'c','e'},
{'d','s'},
{'e','o'},
{'f','c'},
{'g','v'},
{'h','x'},
{'i','d'},
{'j','u'},
{'k','i'},
{'l','g'},
{'m','l'},
{'n','b'},
{'o','k'},
{'p','r'},
{'q','z'},
{'r','t'},
{'s','n'},
{'t','w'},
{'u','j'},
{'v','p'},
{'w','f'},
{'x','m'},
{'y','a'},
{'z','q'}};

int test,len;
char str[10005];

int main(){
	freopen("i.txt","r",stdin);
	scanf("%d",&test);
	gets(str);
	int cnt=1;
	for (;test--;cnt++){
		printf("Case #%d: ",cnt);
		gets(str);
		len=strlen(str);
		for (int i=0;i<len;i++) if (str[i]>='a' && str[i]<='z'){
			str[i]=m[str[i]-'a'][1];
		}
		puts(str);
	}
	return 0;
}
