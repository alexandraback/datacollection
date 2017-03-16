#include<stdio.h>
#include<algorithm>

using namespace std;

char str[15][110];
int seq[15];
bool chk[30];

int main() {

	int t, T;
	int n,i,j;
	bool value;
	int ans;
	char prev;

	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);

	scanf("%d", &T);
	for(t=1 ; t<=T ; t++) {
		scanf("%d", &n);
		for(i=0, ans=0 ; i<n ; i++) {
			seq[i]=i;
			scanf("%s", str[i]);
		}

		do {
			for(i=0,value=true ; i<='z'-'a' ; i++) chk[i]=false;
			for(i=0 ; i<n ; i++) {
				for(j=0 ; str[seq[i]][j] !=0 ; j++) {
					if(chk[str[seq[i]][j]-'a'] == false) {
						chk[str[seq[i]][j]-'a'] = true;
						prev=str[seq[i]][j];
					}
					else {
						if(prev != str[seq[i]][j])
							value = false;
						else
							prev = str[seq[i]][j];
					}

					if(value==false) break;
				}

				if(value==false) break;
			}

			if(value) ans++;
		} while(next_permutation(seq,seq+n));

		printf("Case #%d: %d\n", t, ans);
	}

	return 0;
}