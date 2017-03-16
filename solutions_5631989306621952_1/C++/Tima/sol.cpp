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
char s[N],t[N];
int n;
deque <char> st;

int main () {
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	scanf("%d\n",&T);
	for(int tt=1;tt<=T;tt++){
		printf("Case #%d: ",tt);
		scanf("%s",s);
		n = strlen(s);
		int ok = 0;
		for(int i=0;i<n;i++){
			if(st.empty() || (st.front() < s[i] || (st.front() == s[i] && ok == 1))) st.push_front(s[i]);
			else{
				st.push_back(s[i]);
			}	
			if(!ok && i > 0){
				if(st.front() > st.back()) ok = 1;
				if(st.back() > st.front()) ok = 2;
			}
		}
		int m = 0;
		while(!st.empty()){
			t[m++] = st.front();
			st.pop_front();
		}
		printf("%s\n",t);
		for(int i=0;i<m;i++) t[i] = ' ';
	}

return 0;
}