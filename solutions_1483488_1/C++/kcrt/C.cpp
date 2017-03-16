/*	@file
 * 	FILENAME - FILEDESCRIPTION
 *		Programmed by kcrt <kcrt@kcrt.net>
 *
 *	Revision : SVN : $Rev$
 *	LastChanged : $Date$
 *
 * 	Since DATE-
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <list>
using namespace std;


int main(){

	int T;

	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		int ret = 0;
		int a, b;
		scanf("%d %d", &a, &b);
		for(int n = a; n <= b - 1; n++){
			list<int> memo_m;
			char astr[256];
			int astrlen;
			sprintf(astr, "%d", n);
			astrlen = strlen(astr);
			for(int j = 0; j < astrlen - 1; j++){
				char f = astr[0];
				memmove(astr, astr + 1, astrlen - 1);
				astr[astrlen - 1] = f;
				int m = atoi(astr);
				if(n < m && m <= b){
					if(count(memo_m.begin(), memo_m.end(), m)){
						// memorized
					}else{
						//printf("(%d,%d)\n", n, m);
						ret++;
						memo_m.push_back(m);
					}
				}
			}
		}
		printf("Case #%d: %d\n", i + 1, ret);
	}

}


