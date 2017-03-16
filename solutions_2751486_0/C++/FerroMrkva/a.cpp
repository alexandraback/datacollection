#include<cstdio>
#include<cstring>

using namespace std;

#define MX 1001001

char S[MX];
int n;

int isc(char c){
	if (c=='a') return 0;
	if (c=='e') return 0;
	if (c=='i') return 0;
	if (c=='o') return 0;
	if (c=='u') return 0;
	return 1;
}

int main()
{
	int T;
	scanf("%d\n",&T);
	for(int t=1;t<=T;++t){
		printf("Case #%d: ",t);
		scanf("%s %d\n",S,&n);
		int L=strlen(S);
		int last=-1;
		long long vys=0;
		for(int i=0,j=0;i<L;++i){
			if (isc(S[i])){
				++j;
				if (j>=n){
					vys+=i-n+2;
					last=i;
				} else if (last!=-1){
					vys+=last-n+2;
				}
			}
			else {
				j=0;
				if (last!=-1){
					vys+=last-n+2;
				}
			}
		}
		printf("%lli\n",vys);
	}
	return 0;
}
