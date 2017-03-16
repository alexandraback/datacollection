#include <bits/stdc++.h>
using namespace std;

string s;
string cs[]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

int res[100],cnt[1000];

void del(int x) {
	for(int i=0;i<cs[x].size();i++) cnt[cs[x][i]]-=res[x];
}

void gan(int x,char ch) {
	res[x]=cnt[ch];
	del(x);
}

int main() {
	freopen("input.inp","r",stdin);
	freopen("output.out","w",stdout);
	int test;
	scanf("%i\n",&test);
	for(int dem=1;dem<=test;dem++) {
		printf("Case #%i: ",dem);
		getline(cin,s);
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<s.length();i++) ++cnt[s[i]];
		memset(res,0,sizeof(res));
		gan(0,'Z');
		gan(2,'W');
		gan(6,'X');
		gan(7,'S');
		gan(5,'V');
		gan(4,'U');
		gan(3,'R');
		gan(1,'O');
		gan(8,'T');
		gan(9,'I');
		for(int i=0;i<10;i++) 
			while (res[i]>0) {
				printf("%i",i);
				--res[i];
			}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}