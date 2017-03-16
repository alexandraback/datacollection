/*
 * =====================================================================================
 *
 *       Filename:  1.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/12/2013 17:03:48
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
#define N 100
int n;
int isCon(char cc){
	if(cc != 'a' && cc != 'e' && cc != 'i' && cc != 'o' && cc != 'u')
		return 1;
	else 
		return 0;
}
int jj(char *ss, int start, int end){
	for(int tmpstart = start; tmpstart <= end - n + 1; tmpstart++){
		int tmpfound =  1;
		for(int i = 0; i < n; i++){
			if(!isCon(ss[tmpstart + i])){
				tmpfound = 0;
				break;
			}
		}
		if(tmpfound == 1)
			return 1;
	}
	return 0;
}
int main(){
	int ncase;
	cin>>ncase;
	for(int nn  = 1; nn <= ncase; nn++){
		char ss[N + 10];
		int l, result = 0;
		cin>>ss>>n;
		l = strlen(ss);
		for(int start = 0; start < l; start++){
			for(int end = start; end < l; end++){
				if(end - start + 1>= n && jj(ss,start,end)){
					result++;	
				}
			}
		}
		printf("Case #%d: %d\n",nn, result);
	}
	return 0;
}
