#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
#define rep(i,s,t) for(int i=int(s); i<int(t); i++)
#define mst(A,k) memset(A,k,sizeof(A))

char str[1005];
string ans;

int main() {
	freopen("A-small-attempt0.in","r",stdin); 
	freopen("ans.txt","w",stdout); 

	int T;
	scanf("%d", &T);
	rep(cas, 0, T)
	{
		scanf("%s", str);
		ans.clear();
		int l = strlen(str);
		ans += str[0];
		rep(i, 1, l)
		{
			if(str[i] >= ans[0]) ans = str[i] + ans;
			else ans = ans + str[i];
		}
		cout<<"Case #"<<cas + 1<<": "<<ans<<"\n";
	}
	return 0;
}

