#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int T, Smax;
char linha[1000010];

int main(){
	scanf("%d\n", &T);
	for(int caso=1; caso<=T; caso++){
		scanf("%d %s\n", &Smax, linha);
		//printf("%d %s\n", Smax, linha);
		int depeh = linha[0]-'0', resp=0;		
		for(int i=1; i<=Smax; i++){
			if(depeh>=i){
				depeh += linha[i]-'0';
			}
			else{
				resp += i-depeh;
				depeh = i;
				depeh += linha[i]-'0';
			}
		}
		printf("Case #%d: %d\n", caso, resp);
	}		
	return 0;
}

