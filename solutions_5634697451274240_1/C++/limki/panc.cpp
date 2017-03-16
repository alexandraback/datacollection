#include <cstdio>
#include <cstring>
using namespace std;
char inp[110];
int rv;
int T;
char tgt;
char tmp;
int main(){
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		tgt = '+';
		rv=0;
		scanf("%s",inp);
		//printf("%s\n",inp);
		for(int i=strlen(inp)-1;i>=0;i--){
			if (inp[i]!=tgt){
				/*
				for(int j=0;j<i;j++){
					tmp = 88 - inp[i-j-1];
					inp[i-j-1] = 88 - inp[j];
					inp[j] = tmp;
					if (j+1>i-j-2)
						break;
				}*/
				//printf("%c[%s]\n",tgt,inp);
				tgt = 88-tgt;
				rv++;
			}
		}
		printf("Case #%d: %d\n",t,rv);
	}	
}

