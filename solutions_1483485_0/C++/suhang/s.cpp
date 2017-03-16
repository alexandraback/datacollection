#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int		n,len;
char	s[4][100],t[4][100];
char	ch[1024],S[1000010];
bool	mk[1024];

int main(){
	/*freopen("s.in","r",stdin);

	for (int i=1;i<=3;i++)
		gets(s[i]);
	for (int i=1;i<=3;i++)
		gets(t[i]);
	for (int i=1;i<=3;i++){
		len=strlen(s[i]);
		for (int j=0;j<len;j++)
			ch[s[i][j]]=t[i][j];
	}*/
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	ch['a']='y';
ch['b']='h';
ch['c']='e';
ch['d']='s';
ch['e']='o';
ch['f']='c';
ch['g']='v';
ch['h']='x';
ch['i']='d';
ch['j']='u';
ch['k']='i';
ch['l']='g';
ch['m']='l';
ch['n']='b';
ch['o']='k';
ch['p']='r';
ch['q']='z';
ch['r']='t';
ch['s']='n';
ch['t']='w';
ch['u']='j';
ch['v']='p';
ch['w']='f';
ch['x']='m';
ch['y']='a';
ch['z']='q';
ch[' ']=' ';
	scanf("%d\n",&n);
	
	for (int test=1;test<=n;test++){
		printf("Case #%d: ",test);
		gets(S);		
		len=strlen(S);
		for (int j=0;j<len;j++)
			printf("%c",ch[S[j]]);
		printf("\n");
		
	}
	
	return 0;
}
