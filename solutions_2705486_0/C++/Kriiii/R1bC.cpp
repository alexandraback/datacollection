#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;

int node;
map<char, int> go[1126000];
bool ter[1126000];

char mail[4040]; int len;
void input()
{
	scanf ("%s",mail+1);
	for (len=0;mail[len+1];len++);
}

int D[4040][5];

void trav(int l, int dif, int up, int pos)
{
	if (dif > 4) dif = 4;
	if (ter[pos]){
		D[l][dif] = min(D[l][dif],up);
	}
	if (l == len) return;
	int i; map<char,int>::iterator I;
	for (I=go[pos].begin();I!=go[pos].end();I++){
		if (mail[l+1] == I->first){
			trav(l+1,dif+1,up,I->second);
		}
		else{
			if (dif >= 4){
				trav(l+1,0,up+1,I->second);
			}
		}
	}
}

int proc()
{
	int i,j,s;
	for (i=1;i<=len;i++) for (j=0;j<5;j++) D[i][j] = len;
	for (j=0;j<5;j++) D[0][j] = 0;
	for (i=1;i<=len;i++){
		for (j=0;j<5;j++){
			trav(i-1,j,D[i-1][j],0);
		}
	}

	int ans = len;
	for (j=0;j<5;j++) if (ans > D[len][j]) ans = D[len][j];
	return ans;
}

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);
	FILE *dic = fopen ("dic.txt","r");
	char S[100]; int x = 0;
	while (~fscanf (dic,"%s",S)){
		int start = 0,i;

		for (i=0;S[i];i++){
			if (!go[start].count(S[i])) go[start][S[i]] = ++node;
			start = go[start][S[i]];
		}
		if (x < i) x = i;
		ter[start] = 1;
	}

	int Test,Case=1;
	scanf ("%d",&Test); while (Test--){
		input();
		printf ("Case #%d: %d\n",Case++,proc());
	}

	return 0;
}