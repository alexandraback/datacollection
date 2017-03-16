#include<algorithm>
#include<cstdio>
using namespace std;

char m[26]={
	'y',//a
	'h',//b
	'e',//c
	's',//d
	'o',//e
	'c',//f
	'v',//g
	'x',//h
	'd',//i
	'u',//j
	'i',//k
	'g',//l
	'l',//m
	'b',//n
	'k',//o
	'r',//p
	'z',//q
	't',//r
	'n',//s
	'w',//t
	'j',//u
	'p',//v
	'f',//w
	'm',//x
	'a',//y
	'q'//z
};

char s[1024];

int main()
{
	int t;
	scanf("%d\n",&t);
	for(int ca=1;ca<=t;ca++)
	{
		gets(s);
		int len=strlen(s);
		for(int i=0;i<len;i++)
		{
			if('a'<=s[i]&&s[i]<='z')
			{
				s[i]=m[s[i]-'a'];
			}
		}
		printf("Case #%d: %s\n",ca,s);
	}
	return 0;
}
