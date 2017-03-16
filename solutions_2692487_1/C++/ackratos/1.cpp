/*
 * =====================================================================================
 *
 *       Filename:  1.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/05/2013 00:13:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cong Zhao (), zhaocong89@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP make_pair

#define FF(i,n) for(int(i)=0;(i)<(n);(i)++)
#define FOR(i,l,h) for(int(i)=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define CC(n,what) memset(n,what,sizeof(n))
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;
vector<int>mosize;
int absort(int ccsize, int addtimes){
	int i = 0;
	for(i = 0; i < mosize.size();){
		if(ccsize > mosize[i]){
			ccsize += mosize[i];
			i++;
		}
		else{
			if(addtimes > 0){
				addtimes--;
				ccsize += (ccsize - 1);
			}
			else{
				break;
			}
		}
	}
	return mosize.size() - i;
}
int main(){
	int ncase;
	scanf("%d", &ncase);
	for(int nn = 1; nn <= ncase; nn++){
		int currsize = 0;
		int nmo = 0;
		scanf("%d%d", &currsize, &nmo);
		mosize.clear();
		for(int i = 0; i < nmo; i++){
			int tmp = 0;
			scanf("%d", &tmp);
			mosize.push_back(tmp);
		}
		sort(mosize.begin(), mosize.end());
		int result = nmo;
		for(int tt = 0; tt <= nmo - 1; tt++){
			if(tt >= result)
				break;
			int tmpresult = tt + absort(currsize, tt);	
			result = min(tmpresult, result);
		}
		printf("Case #%d: %d\n", nn, result);
	}
	return 0;
}
