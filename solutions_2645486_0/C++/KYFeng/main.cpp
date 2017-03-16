#include<iostream>
#include<math.h>
#include<vector>
using std::vector;
using std::sqrt;
using std::cin;
using std::cout;
using std::endl;
void prob1(){
	long long t, r, testCase;
	cin>>testCase;
	for(int i=0; i<testCase; i++){
		cin>>r>>t;
		long long n = (long long)sqrt((double)t/2);
		if(n > r)n=n-r;
		else n=0;
		long long bound = (long long)sqrt((double)t/4);
		//cout<<n<<" "<<bound<<endl;
		long long tmp;
		for(tmp = n; tmp<bound; tmp++){
			//cout<<tmp<<": "<<2*tmp*r+2*tmp*tmp-tmp<<" "<<t<<endl;
			if(2*tmp*r+2*tmp*tmp-tmp > t){
				tmp = tmp-1;
				break;
			}
			if(2*tmp*r+2*tmp*tmp-tmp == t){
				break;
			}
		}
		cout<<"Case #"<<1+i<<": "<<tmp<<endl;
	}
}
int computeGain(vector<int> values, int eventNo, int currentE, int E, int R, int gain, int& max){
	int newGain=0;
	if(eventNo >= values.size()){
		if(gain > max){
			max = gain;
		}
		return gain;
	}
	for(int i=0; i<=currentE; i++){
		newGain = gain + i*values[eventNo];
		int newE = currentE - i + R;
		if(newE > E)newE = E;
		computeGain(values, eventNo+1, newE, E, R, newGain, max);
	}
}
void prob2(){
	int testCase, E, R, N;
	cin>>testCase;
	for(int co=0; co<testCase; co++){
		cin>>E>>R>>N;
		vector<int> values;
		for(int i=0; i<N; i++){
			int v;
			cin>>v;
			values.push_back(v);
		}
		int gain=0;
		computeGain(values, 0, E, E, R, 0, gain);
		cout<<"Case #"<<co+1<<": "<<gain<<endl;

	}
}
int main(){
	prob2();
}