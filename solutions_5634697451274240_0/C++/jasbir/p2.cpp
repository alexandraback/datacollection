#include<cstdio>
int ar[10];
using namespace std;
char ch[102];
char tmp[102];
char flip(char c)
{
	if(c=='+') return '-';
	else return '+';
}



int solve(int len)
{
	
	int f=1;
	for(int i=0;i<=len;i++) 
	if(ch[i]=='-') 
	{
	f=0; break;	
	}
	if(f) return 0;
	
	if(ch[0]=='-')
	{
		for(int i=0;i<=len;i++)
		tmp[i] = flip(ch[i]);
		for(int i=0;i<=len;i++) ch[i] = tmp[len-i];
		while(len>=0)
		{
			if(ch[len]=='+') len--;
			else break;
		}
		if(len<0) return 1;
		return (1+solve(len));
	}
	if(ch[0]=='+')
	{
		for(int i=0;i<=len;i++)
		{
			if(ch[i]=='+') ch[i]='-';
			else break;
		}
		
		return (1+solve(len));
	}
	
}
int main()
{
	int ntc; scanf("%d",&ntc);
	for(int tc=1;tc<=ntc;tc++)
	{
		printf("Case #%d: ",tc);
		scanf("%s",&ch);
		int len = 0; while(ch[len]!='\0') len++;
		len--;
		while(len>=0)
		{
			if(ch[len]=='+') len--;
			else break;
		}
		if(len<0) printf("0\n");
		else
		printf("%d\n",solve(len));
		
	}
}
