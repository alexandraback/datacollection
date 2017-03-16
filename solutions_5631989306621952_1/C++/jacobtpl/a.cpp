#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define ii pair<int,int>
#define mp make_pair
#define pb push_back
#define INF 1000000000
int tc,n;
char s[1005];
deque<char> d;
int main() {
	scanf("%d",&tc);
	for (int kk=1;kk<=tc;kk++) {
		scanf("%s",s);
		n=strlen(s);
		d.clear();
		d.pb(s[0]);
		for (int i=1;i<n;i++) {
			if (d.front()<s[i]) d.push_front(s[i]);
			else if (d.front()>s[i]) d.pb(s[i]);
			else {
				int x=0;
				for (int i=0;i<sz(d)-1;i++) {
					if (d[i]!=d[i+1]) {
						if (d[i]<d[i+1]) x=-1;
						else x=1;
						break;
					}
				}
				if (x>=0) d.push_front(s[i]);
				else d.pb(s[i]);
			}
		}
		printf("Case #%d: ", kk);
		for (int i=0;i<sz(d);i++) {
			printf("%c", d[i]);
		}
		printf("\n");
	}
}