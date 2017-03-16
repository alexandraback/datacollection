#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <iostream>
#include <sstream>
#include <string>

#include <algorithm>
#include <vector>
#include <list>

using namespace std;

int N;

list< pair<int,int> > ab;
list< pair<int,int> >::iterator lastgood;
	
int sum;
int cnt;

bool consume2() {
	bool ret=false;
	
	list<pair<int,int> >::iterator it=ab.begin();
	for (it=ab.begin();it!=ab.end();) {
		if (it->first<=sum) {
			sum+=1;
			if (it->second!=-1) {
				sum+=1;
			}
			it=ab.erase(it);
			cnt++;
			continue;
		}
		if (it->second!=-1&&it->second<=sum) lastgood=it;
		++it;
	}
	
	lastgood=ab.end();
	for (it=ab.begin();it!=ab.end();) {
		if (it->second!=-1&&it->second<=sum) lastgood=it;
		++it;
	}
	return true;
}

bool consume1() {
	if (lastgood==ab.end()) return false;
	lastgood->second=-1;
	sum++;
	cnt++;
	return true;
}


int main() {
	int T;
	double res;
	cin>>T;
	int cas=0;
	
	while (cas++<T) {
		cin>>N;
		ab.clear();
		for (int i=0;i<N;i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			ab.push_back(make_pair(b, a));
		}
		
		ab.sort();
		
		sum=0;
		cnt=0;
		while (sum<N*2) {
			consume2();
			if (!consume1()) break;
		}
		
		if (sum<N*2) {
			printf("Case #%d: Too Bad\n", cas);
		} else {
			printf("Case #%d: %d\n", cas, cnt);
		}
	}
	
    return 0;
}
