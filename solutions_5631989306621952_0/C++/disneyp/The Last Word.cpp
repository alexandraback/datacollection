#include <iostream>

using namespace std;
string s;
string a[100];
int mark[10000];
int main() {
	freopen("A.in","r",stdin);
	freopen("B.txt","w",stdout);
	int t;
	cin >> t;
	for(int ii=0;ii<t;ii++) {
		cin >> s;
		int k = s.size();
		for(int i=0;i<26;i++) a[i].clear();
		for(int i=0;i<1000;i++) mark[i]= 0;
		for(int i=25;i>=0;i--) {
			for(int j=k-1;j>=0;j--) {
				int st = -1;
				if(s[j] == 'A' + i) {
					if(mark[j] == 0) {
						mark[j] = 1;
						st = j;
					}
				}
				if(st == -1) continue;
				for(int aa = st+1; aa < k; aa++) {
					if(mark[aa] == 0) mark[aa] = -1;
				}
			}
		}
		string ans;
		for(int i=0;i<k;i++) {
			if(mark[i] == 1) ans = s[i] + ans;
			else ans = ans + s[i];
		}
		cout << "Case #" << ii+1 << ": " << ans << endl;
		
		
	}
	
}