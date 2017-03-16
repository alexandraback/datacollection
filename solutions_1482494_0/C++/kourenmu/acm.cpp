#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 2001;

class combine{
public:
	int star;
	int order;
	combine(){
	}
	combine(int s, int o){
		star = s;
		order = o;
	}
};

bool operator<(const combine & x, const combine & y){
	return x.star < y.star;
}

bool al[MAX];

int main(){
	freopen("test.txt", "r", stdin);
	freopen("result.txt", "w", stdout);

	int T, N, result, hasComplete, hasStar;
	int tmpA, tmpB, orderA, orderB;
	vector<combine> a, b;

	cin>>T;
	for(int i = 1; i <= T; i++){
		cin>>N;
		hasComplete = 0;
		result = 0;
		hasStar = 0;

		orderA = 0;
		orderB = 0;
		a.clear();
		b.clear();
		memset(al, 0, sizeof(al));

		for(int i = 0; i < N; i++){
			cin>>tmpA>>tmpB;
			a.push_back(combine(tmpA, i));
			b.push_back(combine(tmpB, i));
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		combine tA, tB;
		while(true){
			if(orderA < a.size())
				tA = a.at(orderA);
			tB = b.at(orderB);
			if(tB.star > hasStar && orderA >= a.size()){
				result = -1;
				break;
			}
			else if(tB.star > hasStar && orderA < a.size() && tA.star > hasStar){
				result = -1;
				break;
			}
			else if(tB.star <= hasStar){
				orderB++;
				hasComplete++;
				result++;
				if(al[tB.order]){
					hasStar++;
				}
				else{
					al[tB.order] = true;
					hasStar += 2;
				}
				if(hasComplete == N){
					break;
				}
			}
			else{
				if(!al[tA.order]){
					al[tA.order]= true;
					hasStar++;
					result++;
				}
				orderA++;
			}
		}

		if(result == -1){
			cout<<"Case #"<<i<<": "<<"Too Bad"<<endl;
		}
		else{
			cout<<"Case #"<<i<<": "<<result<<endl;
		}
	}

	return 0;
}
