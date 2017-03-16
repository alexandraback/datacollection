#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

#define FOR(i,f,t) for(int i=f; i<t; i++)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define pb push_back
#define ri(x) scanf("%d", &x)
#define rii(x,y) scanf("%d %d", &x, &y)
#define SYNC ios_base::sync_with_stdio(false)

typedef long long ll;

#define MAXN 104

char a[MAXN];
char ch(char c){
	return c=='+'?'-':'+';
}

int main(){
	int TC; ri(TC);
	FOR(tc,1,TC+1){
		ms(a,0);
		scanf("%s",a);
		int N = strlen(a), ans=0;
		while(N>0){
			if(a[N-1]=='+'){
				N--;
			}else{
				ans++;
				if(a[0]=='-'){
					FOR(i,0,N/2){
						a[i] = ch(a[i]);
						a[N-1-i] = ch(a[N-1-i]);
						swap(a[i], a[N-1-i]);
					}
					if(N%2) a[N/2] = ch(a[N/2]);
				}else{
					FOR(i,0,N){
						if(a[i]=='+')
							a[i] = '-';
						else
							break;
					}
				}
			}
		}
		printf("Case #%d: %d\n", tc, ans);
	}
	
}

