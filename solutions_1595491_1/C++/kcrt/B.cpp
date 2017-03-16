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
#include <string>
#include <algorithm>
#include <list>
using namespace std;

list<string> split(string str, string delim) {
	list<string> result;
	int cutAt;
	while( (cutAt = str.find_first_of(delim)) != str.npos )
	{
		if(cutAt > 0)
		{
			result.push_back(str.substr(0, cutAt));
		}
		str = str.substr(cutAt + 1);
	}
	if(str.length() > 0)
	{
		result.push_back(str);
	}
	return result;
}


int main(){

	int T;

	scanf("%d", &T);
	for(int i = 0; i < T; i++){
		int N, S, p;
		int ret = 0;
		scanf("%d %d %d", &N, &S, &p);
		for(int j = 0; j < N; j++){
			int sum;
			scanf("%d", &sum);
			if( p == 1 && sum == 0){
				// do nothing
			}else if( sum >= p * 3 - 2){
				ret++;
			}else if ( sum >= p * 3 - 4 ){
				if(S){
					ret++;
					S--;
				}
			}
		}
		printf("Case #%d: %d\n", i+1, ret);
	}

}


