#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std ;

const int MAXN = 1000000;

bool isvowel(char ch)
{
	return (ch=='a')||(ch=='e')||(ch=='o')||(ch=='i')||(ch=='u');
}
char str[MAXN+5];
int id[MAXN+5];
int n;
int k;

void getIds()
{
	id[0] = 0;
	for (int c=1;c<n;c++)
		id[c] = id[c-1] + (isvowel(str[c])!=isvowel(str[c-1]));
	return ;
}


int main()
{
	freopen("cons.in","r",stdin);
	freopen("cons.out","w",stdout);
	int c,c2;
	int tests;
	scanf("%d",&tests);
	for (int test=1;test<=tests;test++){
		printf("Case #%d: ",test);
		scanf("%s%d",str,&k);
		n = strlen(str);
		
		getIds();
		/*for (c=0;c<n;c++)
			printf("%d ",id[c]);
		printf("\n");*/
		
		long long ret =0;
		int s=0,e=-1;
		int cons = 0;
		while (e < n){
			if (cons >= k){
				//printf("at %d,%d , += %d\n",s,e,n-e);
				ret+= n - e;
				if (id[s] == id[e])cons--;
				s++;
			}
			else {
				e++;
				if (e < n && !isvowel(str[e]))cons++;
				else cons = 0;
			}
		}
		cout << ret << endl;
		//printf("%lld\n",ret);
	}
	
	
	return 0;
}
