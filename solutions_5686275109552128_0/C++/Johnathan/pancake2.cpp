#include <iostream>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define PI pair<int,int>


struct classcomp {
  bool operator() (const PI& lhs, const PI& rhs) const
  {return lhs.first > rhs.first;}
};
bool cmp(PI a, PI b){
	return (a.first > b.first);
}

int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int n,t,d,cat;
	cin >> t;
	n = 0;
	while ((n++) < t){
		cin >> d;
		if (d == 0)
		{
					cout << "Case #" << n << ": 0" << endl;
					continue;
		}
		vector<int> diner;
		for (int i = 0; i < d; i++){
			cin >> cat; 
			diner.push_back(cat);
		}
		int minTime = 10000;

		for (int max = 1 ; max <= 1000; max++){
			int curTime = 0;
			for (int i = 0; i < diner.size(); i++){
				curTime += (diner[i] /max) ;
				if (diner[i] % max == 0)
					curTime --;
			}
			curTime += max;
			if (curTime < minTime)
				minTime = curTime;
		}
			//cout << "past : " << past << " x.first  " << x.first << endl;
			cout << "Case #" << n << ": " << minTime<< endl;
	}
	return 0;
}