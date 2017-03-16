#include <bits/stdc++.h>
#define fr(i,a,b) for(int i = (a); i < (b); ++i)
#define pb push_back

using namespace std;

int dx[]={1,0,1};
int dy[]={0,1,1};

char grid[8][8];

const char* s = "XO";

int main() {
	int tc; cin>>tc; ++tc;
	fr(_,1,tc) {
		printf("Case #%d: ",_);
		fr(i,0,4) fr(j,0,4) {
			cin>>grid[i][j];
		}
		bool aux = 0;
		fr(k,0,2) {
			fr(i,0,4) {
				bool ok=1;
				fr(j,0,4) {
					ok&=((grid[i][j]==s[k])||grid[i][j]=='T');
				}
				if(ok) {
					printf("%c won\n",s[k]);
					goto lol;
				}
			}
			fr(i,0,4) {
				bool ok=1;
				fr(j,0,4) {
					ok&=((grid[j][i]==s[k])||grid[j][i]=='T');;
				}
				if(ok) {
					printf("%c won\n",s[k]);
					goto lol;
				}
			}
			bool ok=1;
			fr(j,0,4) {
				ok&=((grid[j][j]==s[k])||grid[j][j]=='T');
			}
			if(ok) {
				printf("%c won\n",s[k]);
				goto lol;
			}
			ok=1;
			fr(j,0,4) {
				ok&=((grid[j][3-j]==s[k])||grid[j][3-j]=='T');
			}
			if(ok) {
				printf("%c won\n",s[k]);
				goto lol;
			}
		}
		aux = 0;
		fr(i,0,4) fr(j,0,4) {
			if(grid[i][j]=='.')aux=1;
		}
		if(aux)cout<<"Game has not completed\n";
		else cout<<"Draw\n";
		lol:;
	}
	return 0;
}
