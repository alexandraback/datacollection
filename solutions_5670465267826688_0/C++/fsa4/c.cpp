#include <bits/stdc++.h>
#define fr(i, a, b) for(int i = (a), __ = (b); i < __; i++)
#define inf 0x3f3f3f3f
#define st first
#define nd second
#define eps 1e-9

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

char str[10100];
int arr[200000];

int mult(int aa, int bb){
	int a = abs(aa), b = abs(bb), ret;
	if(a == 1){
		if(b == 1){
			ret = 1;
		}else if(b == 2){
			ret = 2;
		}else if(b == 3){
			ret = 3;
		}else{
			ret = 4;
		}
	}else if(a == 2){
		if(b == 1){
			ret = 2;
		}else if(b == 2){
			ret = -1;
		}else if(b == 3){
			ret = 4;
		}else{
			ret = -3;
		}
	}else if(a == 3){
		if(b == 1){
			ret = 3;
		}else if(b == 2){
			ret = -4;
		}else if(b == 3){
			ret = -1;
		}else{
			ret = 2;
		}
	}else{
		if(b == 1){
			ret = 4;
		}else if(b == 2){
			ret = 3;
		}else if(b == 3){
			ret = -2;
		}else{
			ret = -1;
		}
	}
	
	if(aa < 0) ret = -ret;
	if(bb < 0) ret = -ret;
	return ret;
}

int converte(char c){
	if(c == 'i') return 2;
	if(c == 'j') return 3;
	return 4;
}

int main(){
	int t, caso = 1;
	scanf("%d", &t);
	
	while(t--){
		int L;
		ll x;
		scanf("%d %lld", &L, &x);
		
		//if(x >= 12){
		//	x = 8 + (x%4);
		//}
		
		scanf("%s", str);
		fr(i, 0, L) arr[i] = converte(str[i]);
		
		fr(i, 1, x+1){
			fr(j, 0, L){
				arr[i*L + j] = arr[j];
			}
		}
		
		int n = x*L, at = 1, ini, fim, achou = 0;
		
		fr(i, 0, n){
			at = mult(at, arr[i]);
			if(at == 2){
				ini = i+1;
				achou = 1;
				break;
			}
		}
		
		if(!achou){
			printf("Case #%d: NO\n", caso++);
			continue;
		}
		
		at = 1;
		achou = 0;
		for(int i = n-1; i >= 0; i--){
			at = mult(arr[i], at);
			if(at == 4){
				fim = i-1;
				achou = 1;
				break;
			}
		}
		
		if(!achou || ini > fim){
			printf("Case #%d: NO\n", caso++);
			continue;
		}
		
		at = 1;
		fr(i, ini, fim+1){
			at = mult(at, arr[i]);
		}
		
		if(at == 3){
			printf("Case #%d: YES\n", caso++);
		}else{
			printf("Case #%d: NO\n", caso++);
		}
	}

	return 0;
}

