#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<sstream>
#include<fstream>
#include<map>

typedef long long ll;

using namespace std;

ll E,R,N;
vector<ll> values;

map<pair<ll,ll>, ll> mem;

ll calc(ll e, ll p){
	if(p >= N) return 0;
	
	pair<ll,ll> c = make_pair<ll, ll>(e, p);
	if(mem.find(c) != mem.end()){
		return mem[c];
	}

	ll res = 0;
	for(ll i=0;i<=e;i++){
		ll tmp = i*values[p] + calc(min(e-i+R, E), p+1);
		if(tmp>res) res=tmp;
	}
		
	mem[c] = res;

	return res;
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
		ss>>E>>R>>N;

		file.getline(line, 1024);
		stringstream ss2(line);
		values.clear();

		for(int n=0;n<N;n++){
			ll tmp;
			ss2>>tmp;
			values.push_back(tmp);
		}
		
		mem.clear();
		
		ll ret = calc(E, 0);

		cout<<"Case #"<<c<<": "<<ret<<endl;
	}

	return 0;
}
