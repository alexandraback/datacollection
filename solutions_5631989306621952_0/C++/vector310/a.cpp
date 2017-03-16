#include<iostream>
#include<cstdio>
#include<cstring>
#define rep(i, l, r) for(int i = l; i <= r; ++i)
using namespace std;
char s[1010];
char t[1010];
char s1[1010];
char s2[1010];
bool cmp(char *s1, char *s2, int n){
	rep(i, 1, n)
		if(s1[i] != s2[i]) return s1[i] > s2[i];
	return 0;
}
int main(){
	//freopen("in.txt","r",stdin);
	//freopen("out2.txt","w",stdout);
	int cas;
	cin >> cas;
	rep(Cas, 1, cas){
		scanf("%s",s + 1);
		int n = strlen(s + 1);
		t[1] = s[1];
		rep(i, 2, n){
			rep(j, 1, i - 1){
				s1[j + 1] = t[j];
				s2[j] = t[j];
			}
			s1[1] = s[i];
			s2[i] = s[i];
			if(cmp(s1, s2, i)){
				for(int j = i - 1; j >= 1; --j)
					t[j + 1] = t[j];
				t[1] = s[i];
			}
			else t[i] = s[i];
		}
		printf("Case #%d: ",Cas);
		rep(i, 1, n) putchar(t[i]);
		printf("\n");
	}
	return 0;
} 
