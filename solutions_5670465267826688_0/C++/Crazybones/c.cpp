#include <cstdlib>
#include <set>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <sstream>
#include <vector>
#include <functional>
#include <algorithm> 
#include <stack>
#include <queue>
#include<map>
using namespace::std;
const int Max = 10010;
int Case;
int f[Max];
int b[Max];
char st[Max];
int table[1010][1010];

void init(){
	int i = 'i'; int j = 'j'; int k = 'k';
	table[1][1] = 1; table[1]['i'] = 'i'; table[1]['j'] = 'j'; table[1]['k'] = 'k';
	table['i'][1] = 'i'; table[i][i] = -1; table[i][j] = k; table[i][k] = -j;
	table['j'][1] = 'j'; table[j][i] = -k; table[j][j] = -1; table[j][k] = i;
	table[k][1] = k; table[k][i] = j; table[k][j] = -i; table[k][k] = -1;
}

int trans(int i,int j){
	if (i*j > 0)return table[abs(i)][abs(j)];
	else return -1 * table[abs(i)][abs(j)];
}


int main(){
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("output2.txt", "w", stdout);
	scanf("%d", &Case);
	init();
	for(size_t z = 1; z <=Case; z++)
	{
		int L;
		long long X;
		cin >> L >> X;
		cin >> st;
		f[0] = st[0];
		bool res=true;
		for (size_t k= 1; k < L; k++)
		{
			f[k] = trans(f[k - 1],st[k]);
		}
		b[L - 1] = st[L-1];
		for (int k = L-2; k >=0; k--)
		{
			b[k] = trans(st[k], b[k + 1]);
		}
		if (f[L - 1] == 1)res = false;
		else if (f[L - 1] == -1 && X % 2 == 0)res = false;
		else if (f[L - 1] != -1 && X % 4 != 2)res = false;
		else{
			long long iP=L*(X%4)+10;
			long long kP=-1;
			long long four = 4;
			for (long long i = 0; i < L*min(X,four); i++)
			{
				long long ro = i /L;
				long long cRo=1;
				while (ro--){
					cRo = trans(cRo,f[L - 1]);
				}
				if (trans(cRo,f[i%L])=='i'){
					iP = i;
					break;
				}
			}
			for (long long i = L*X-1; i >=L*X-L*min(X,four); i--)
			{
				long long ro = (L*X-1-i)/L;
				long long cRo = 1;
				while (ro--){
					cRo = trans(b[0],cRo);
				}
				if (trans(b[i%L],cRo) == 'k'){
					kP = i;
					break;
				}
			}
			if (iP < kP)res = true;
			else res = false;
		}
		if (res)printf("Case #%d: YES\n",z);
		else printf("Case #%d: NO\n", z);
	}
}
