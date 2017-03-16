#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <cstring>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define vi vector <int>
#define ld long double
#define pii pair<int, int>
using namespace std;    
const int N = int(3e5), mod = int(1e9)  + 7;
int T;
int s[N];
map <string,int> ma;
int a[20];
ll res;
char t[N];

int get(int n,int m){
	ll res = 0;
	for(int i=1;i<=32;i++){
		res = (res * n + s[i]) % m;
	}
	return res % m;
}

bool check(){
	memset(a,-1,sizeof(a));
	for(int i=2;i<=10;i++){
		for(int j=2;j<=1000;j++){
			if(get(i,j) == 0){
				a[i] = j;
				break;
			}	
		}
	}
	for(int i=2;i<=10;i++){
		if(a[i] == -1) return 0;
	}
	return 1;
}

int main () {
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	srand(time(0));
	int cnt = 0;
	int n = 32;
	printf("Case #1:\n");
	while(cnt < 500){
		string cur = "";
		s[1] = s[32] = 1;
		t[1] = t[32] = '1';
		cur += t[1];
		for(int i=2;i<=31;i++){
			s[i] = rand() & 1;
			t[i] = char(s[i] + '0');
			cur += t[i];
		}
		cur += t[32];
		if(ma.count(cur)) continue;
		ma[cur] = 1;
		if(check()){
			cnt++;
			printf("%s ",t+1);
			for(int i=2;i<=10;i++){
				printf("%d",a[i]);
				if(i == 10) puts("");
				else printf(" ");
			}
		}
	}
return 0;
}