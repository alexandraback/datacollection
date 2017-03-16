#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>

using namespace std;
int K, L, S;
string k, o, word;

double Pk[300];

int maxi = -1;

double solve(const string &word){
	double res = 0.0;
	if( int(word.size()) == S){
		//prob of the word
		res = 1.0;
		for(int i=0;i<S;i++) res*=Pk[int(word[i])];
		//num of repetitions
		int rep = 0;
		for(int i = 0;i+L<=S;i++){
			if(word.substr(i,L) == o)
				rep++;
		} 
		maxi = max(maxi, rep); 
		//cout<<word<<" "<<" "<<rep<<" "<<res<<" "<<rep*res<<" "<<maxi<<endl;
		//return ceil(rep*res) - rep*res;
		return rep*res;
	}
	for(int i=int('A');i<=int('Z');i++){
		if(Pk[i] != 0.0){
			//word.push_back(char(i));
			res += solve(word+char(i));
			//word.erase(--(word.end()));
			//cout<<word+char(i)<<" "<<res<<endl;
		}	
	}
	return res;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(8);
	int kases; cin>>kases;
	for(int kase = 1;kase<=kases;kase++){
		cin>>K>>L>>S; 
		cin>>k>>o;
		maxi = -1;
		for(int i=int('A');i<=int('Z');i++) Pk[i] = 0.0;
		for(int i=0;i<K;i++)Pk[int(k[i])] += (1.0/double(K));
		//for(int i=0;i<K;i++) cout<<"Probability of "<<k[i]<<" "<<Pk[int(k[i])]<<endl;
		double res = solve("");
		cout<<"Case #"<<kase<<": "<<double(maxi)-res<<endl;
	}
}
