#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cstring>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
#define Z 1000000007
int n;
vector<int> perm;
string str[100];
inline bool chk(){
	int last[26]={},at=0;
	memset(last, -1, sizeof(last));
	for (int i=0; i<n; ++i) {
		for (int j=0; j<str[perm[i]].size(); ++j,++at) {
			if (last[str[perm[i]][j]-'a']>=0&&at-last[str[perm[i]][j]-'a']>1) {
				return false;
			}
			last[str[perm[i]][j]-'a']=at;
		}
	}
	return true;
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int iT=1; iT<=T; ++iT) {
		long ans=0;
		perm.clear();
		scanf("%d",&n);
		for (int i=0; i<n; ++i) {
			cin >> str[i];
			perm.push_back(i);
		}
		
		do{
			if (chk()) {
				++ans;
				if (ans>=Z) {
					ans-=Z;
				}
			}
		} while (next_permutation(perm.begin(), perm.end()));
		
		printf("Case #%d: %ld\n",iT,ans%Z);
	}
    return 0;
}