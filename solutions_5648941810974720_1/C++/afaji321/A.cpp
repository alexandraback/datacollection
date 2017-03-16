#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <utility>
#include <iostream>
using namespace std;
char s[99999];
int ct[999];
int res[10];


void clears(string s, int c){
	int N = s.size();
	for (int i=0;i<N;i++)
		ct[s[i]] -=c;
}

int main() {
	int T = 0;
	int tt = 1;
	scanf("%d",&T);
	while (T--){
		printf("Case #%d: ",tt++);

		memset(ct,0,sizeof ct);
		memset(res,0,sizeof res);

		scanf("%s",s);
		int N = strlen(s);
		for (int i=0;i<N;i++){
			ct[s[i]]++;
		}

		res[4] = ct['U'];
		clears("FOUR",res[4]);

		res[0] = ct['Z'];
		clears("ZERO",res[0]);

		res[2] = ct['W'];
		clears("TWO",res[2]);

		res[1] = ct['O'];
		clears("ONE",res[1]);

		res[3] = ct['R'];
		clears("THREE",res[3]);

		res[5] = ct['F'];
		clears("FIVE",res[5]);

		res[6] = ct['X'];
		clears("SIX",res[6]);
		res[7] = ct['V'];
		clears("SEVEN",res[7]);
		
		res[8] = ct['G'];
		clears("EIGHT",res[8]);
		res[9] = ct['N']/2;

		for (int i=0;i<=9;i++) {
			for (int j=0;j<res[i];j++)
				printf("%d",i);
		}
		printf("\n");
	}

}
/*
zero (z)
one (o) "after 4"
two (w)
three (r)
four (u)
five (f) after 4
six (x)
seven (v) after 5
eight (g)
nine (n last)
*/
