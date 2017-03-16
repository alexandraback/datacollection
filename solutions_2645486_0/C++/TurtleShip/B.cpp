#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

typedef long long ll;

int V[15];
int N;// the number of activities planned for the day
int E; // The maximum (and initial) amount of energy
int R; // the amount you regain each activity

int getRes(int en, int idx) {
	if(idx == N) return 0;

	int res = 0;
	for(int i=0; i <= en; i++) {
		res = max(res, V[idx]*i + getRes(min(en-i+R,E), idx+1));
	}
	return res;
}
int main()
{
	int T;
	cin>>T;

	int idx = 0;
	int res = 0;
	

	while((++idx) <= T) {


		
		cin>>E>>R>>N;
		for(int i=0; i < N; i++)
			cin>>V[i];

		/*
		N = 10 is small enough.
		You either do it or not.

		*/
		res = getRes(E, 0);
		cout<<"Case #"<<idx<<": "<<res<<endl;


	}
	
    return 0;

}