#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;


int testcase(){
	int D;
	cin >> D;
	int best;
	vector<int> howm(11,0);
	for(int i=0; i<D; i++){
		int t;
		cin >>t;
		if (t > best) best = t;
		howm[t]++;
	}
	
	vector<int> howm2= howm;
	int howmanyspl =0;
	for(int i=10; i>=0; i--){
		if(best >i+howmanyspl) 
			best =i+howmanyspl;
		howm[i/2]+= howm[i];
		howm[i-i/2]+= howm[i];
		howmanyspl+=howm[i];
	}
	
	howmanyspl = howm2[9];
	howm2[6] += howm2[9];
	howm2[3] += howm2[9];
	howm2[9] =0;
	for(int i=10; i>=0; i--){
		if(best >i+howmanyspl) 
			best =i+howmanyspl;
		howm2[i/2]+= howm2[i];
		howm2[i-i/2]+= howm2[i];
		howmanyspl+=howm2[i];
	}
	return best;
}


int main(){
	int nb;
	cin >>nb;
	for(int i=0; i<nb; i++)
		cout << "Case #"<<i+1<<": "<< testcase()<<endl;;
	return 0;
}
