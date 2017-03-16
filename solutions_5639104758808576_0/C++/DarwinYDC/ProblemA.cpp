#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int people_needed(int level, string s){
	int sum = 0;
	int need = 0;
	for (size_t i=0; i<=level; i++){
		int j = s[i]-'0';
		if (j!=0 && i>sum){
			need += i-sum;
			sum = i;
		}
		sum += j;	
	}
	return need;
}

int main(){
	int N;
	string s;
	cin>>N;
	for (size_t i=0; i<N; i++){
		int level;
		string s;
		cin>>level>>s;
		cout<<"Case #"<<i+1<<": "<<people_needed(level, s)<<endl;
	}
}