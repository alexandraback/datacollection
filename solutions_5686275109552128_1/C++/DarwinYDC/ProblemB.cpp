#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;
int plate[1001];

int planstartAt(int plate[], int number){
	int sum = 0;
	for (int i=number+1; i<=1000; i++){
		sum += ((i-1)/number)*plate[i];
	}
	return sum+number;
}

int fastest_plan(int plate[]){
	int quickest = 1001;
	for (int i=1; i<1000; i++){
		quickest = min(quickest, planstartAt(plate, i));
	}
	return quickest;
}

int main(){
	int T;
	cin>>T;
	for (size_t i=0; i<T; i++){
		int n;
		cin>>n;
		memset(plate, 0, sizeof(plate));
		for (int j=0; j<n; j++){
			int d;
			cin>>d;
			plate[d]++;		
		}
		cout<<"Case #"<<i+1<<": "<<fastest_plan(plate) <<endl;
	}
}