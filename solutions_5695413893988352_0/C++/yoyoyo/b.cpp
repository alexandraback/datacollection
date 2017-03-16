#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

void solve()
{
	char c[20], j[20];
	int cn[20] = {0};
	int jn[20] = {0};
	scanf("%s%s", c, j);
	int l = strlen(c);

	for(int i = 0; i < l; i++){
		if(c[i] == '?')
			cn[i] = -1;
		else
			cn[i] = c[i] - '0';
		if(j[i] == '?')
			jn[i] = -1;
		else
			jn[i] = j[i] - '0';
	}

	int f = 0;
	for(int i = 0; i < l; i++){
		if(cn[i] == -1 && jn[i] == -1){
			cn[i] = 0;
			jn[i] = 0;
		}
		else if(cn[i] == jn[i])
			continue;
		else{
			f = i;
			break;
		}
	}
	if(f != l-1){
		if(cn[f] > jn[f]){
			for(int i=f;i<l;i++){
				if(cn[i]==-1 && jn[i]==-1){cn[i]=0;jn[i]=9;break;}
				if(cn[i]==-1)cn[i]=jn[i];
				if(jn[i]==-1)jn[i]=cn[i];
			}
		}
		else{
			for(int i=f;i<l;i++){
				if(cn[i]==-1 && jn[i]==-1){cn[i]=9;jn[i]=0;}
				if(cn[i]==-1)cn[i]=jn[i];
				if(jn[i]==-1)jn[i]=cn[i];
			}
		}
	}

	cout << " ";
	for(int i =0;i<l;i++)cout<<cn[i];
	cout << " ";
	for(int i =0;i<l;i++)cout<<jn[i];

}

int main(void)
{
	int T;
	cin >> T;
	for(int tt = 1; tt <= T; tt++)
	{
		printf("Case #%d:", tt);
		solve();
		printf("\n");
	}
}