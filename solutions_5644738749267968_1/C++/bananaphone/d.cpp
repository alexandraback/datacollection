#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void doprob(int index){
	int num;
	cin >> num;
	vector<double> a(num);
	vector<double> b(num);
	int i;
	double read;
	for(i=0; i<num; ++i){
		cin >> read;
		a[i] = read;
	}
	for(i=0; i<num; ++i){
		cin >> read;
		b[i] = read;
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int alpha = 0, beta = 0;
	int k;
	int bpt = 0;
	for(k=0; k<num; ++k){
		while(b[bpt] < a[k] && bpt < num){
			bpt++;
		}
		if(bpt < num){
			beta++;
			bpt++;
		}
		else{
			break;
		}
	}
	beta = num - beta;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	bpt = 0;
	int apt = 0;
	while(bpt < num){
		while(b[bpt] > a[apt] && bpt < num){
			bpt++;
		}
		if(bpt < num){
			alpha++;
			apt++;
		}
		bpt++;
	}
	cout << "Case #" << index << ": " << alpha << " " << beta << endl;
}



int main(){
	int cases;
	cin >> cases;
	int i;
	for(i=1; i <= cases; ++i){
		doprob(i);
	}
	return 0;
}
