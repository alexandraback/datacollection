#include<bits/stdc++.h>
using namespace std;

void fuck()
{
	char s[1010];
	int i,l;
	scanf("%s",s+1);
	l=strlen(s+1);
	deque<char> qu;
	qu.push_back(s[1]);
	for(i=2;i<=l;i++){
		if(s[i]<qu.front()) qu.push_back(s[i]);
		else qu.push_front(s[i]);
	}
	for(auto it:qu) printf("%c",it);
	printf("\n");
}

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
   int i,t;
   scanf("%d",&t);
   for(i=1;i<=t;i++){
	   printf("Case #%d: ",i);
	   fuck();
   }
 return 0;
}

