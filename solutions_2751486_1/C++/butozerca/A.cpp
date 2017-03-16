#include<cstdio>
#include<cstring>
using namespace std;
char S[7000000];

int main(){
	int Z;
	scanf("%d",&Z);
	for(int q = 1; q <= Z; ++q){
		long long res = 0;
		
		int l = 0, n, beg = 0;
		scanf("%s %d",S, &n);
		l = strlen(S);
		
		int buf = 0;
		for(int i = 0; i < l; ++i){
			if(S[i]!='a' && S[i]!='e' && S[i]!='i' && S[i]!='o' && S[i]!='u')buf++;
			else buf = 0;
			if(buf >= n ){
				res = res + (i - n + 2 - beg) * (l - i);
				beg = i - n + 2;
			}
		}
		
		for(int i = 0; i <= l; ++i)S[i]='\0';
		printf("Case #%d: %lld\n",q, res);
	}
	return 0;
}
