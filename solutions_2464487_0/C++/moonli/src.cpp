#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<sstream>
#include<fstream>

using namespace std;

typedef long long ll;

ll getVal(ll r, ll n){
	return (2*r+4-3 + 2*r+4*n-3)*n/2;
}


ll calc(ll r, ll t){
	
	ll start = 1;
	ll end = 2;
	while(start<end){
		ll endVal = getVal(r, end);
		if(endVal == t) return end;
		if(endVal < t){
			start = end;
			end *= 2;
			continue;
		}
		
		int mid = (start+end)/2;
		
		ll midVal = getVal(r, mid);
		if(midVal>=t){
			if(end == mid) return start;
			end = mid;
			continue;
		}

		if(start == mid) return start;
		start = mid;
	}

	return end;
}


int main(int argc, char* argv[]){
	if(argc!=2){
		printf("%s input_file\n", argv[0]);
		return 0;
	}

	fstream file(argv[1]);
	char line[1024];

	file.getline(line, 1024);

	int T = atoi(line);

	for(int c=1;c<=T;c++){
		file.getline(line, 1024);

		stringstream ss(line);
		ll r, t;
		ss>>r>>t;
	
		ll ret = calc(r,t);

		cout<<"Case #"<<c<<": "<<ret<<endl;
	}

	return 0;
}
