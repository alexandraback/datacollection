#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <queue>
#include <limits>
#include <map>
#include <math.h> 

using namespace std;

bool solve(int casenr);

int main(){
	int cases;
	bool ans;
	scanf("%d", &cases);

	for(int i=0; i<cases; i++){
		solve(i+1);
	}
	return 0;
}

bool solve(int casenr){
	int guests, index;
	pair<double, int> ptmp;
	double tmp, best = -1.0, curr, total = 1.0;
	
	scanf("%d", &guests);
	vector<double> values;
	vector<double> cuts(guests, 1.0);
	priority_queue<pair<double, int> > q;

	for(int i=0; i<guests; i++){
		scanf("%lf", &tmp);
		values.push_back(tmp);
		if(tmp > best)
			best = tmp;
		ptmp.first=tmp;
		ptmp.second=i;
		q.push(ptmp);
	}

	/*printf("%d ", guests);
	for(int i=0; i<guests; i++){
		printf("%d ", int(values[i]));
	}
	printf("\n");*/
	int run = 100000;
	while(run--){
		ptmp = q.top();
		q.pop();

		//printf("%lf %d\n", ptmp.first, ptmp.second);
		if(ptmp.first<=2.0)
			break;
		index = ptmp.second;
		curr = cuts[index];
		curr++;
		tmp = values[index]/curr;

		if(q.size()){
			curr = max(tmp, q.top().first);
		}else
			curr = tmp;

		if(best > curr+total){
			best = curr+total;
			//printf("%lf\n", best);
		}

		ptmp.first = tmp;
		cuts[index]++;
		q.push(ptmp);
		total+=1.0;
	}
	printf("Case #%d: ", casenr);
	printf("%d\n", int(ceil(best)));
	return true;
}
