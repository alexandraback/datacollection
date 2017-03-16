#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cmath>

using namespace std;

#define INTMAX 0x7FFFFFFF
#define LONGMAX 0x7FFFFFFFFFFFFFFF

set<char> let;
map<char, int> app;
string keyboard,target;
int K,L,S;
int k;

double bananas(){
	for(int i=0; i<L; i++){
		if(let.find(target[i])==let.end())
			return 0.0;
	}
	double E = 0;
	int max = 0;
	for(int i = 0; i<pow(K,S) ; i++){
		int val = i;
		string s;
		for(int j=0; j<S; j++){
			s.push_back(keyboard[val%K]);
			val = val/K;
		}
		int num = 0;
		for(int j=0; j<=S-L; j++){
			bool check = true;
			for(int k=0; k<L; k++){
				if(s[j+k]!=target[k]){
					check = false;
					break;
				}
			}
			if(check)
				num++;
		}
		if(num>max)
			max=num;
		E = E + num;
	}
	E = E/pow(K,S);
	E = max - E;
	return E;
}

int main(){
	int T;
	cin>>T;
	for(int i=1; i<=T; i++){
		cin>>K>>L>>S;
		cin>>keyboard;
		cin>>target;
		if((!(K==keyboard.size()))||(!(L==target.size()))){
			cout<<"something is wrong";
			return 0;
		}
		for(int j=0; j<K; j++){
			if(let.insert(keyboard[j]).second)
				app[keyboard[i]]=1;
			else
				app[keyboard[i]]++;
		}
		k=let.size();
		cout<<"Case #"<<i<<": ";
		printf("%0.8lf",bananas());
		if(i!=T)
			cout<<"\n";
	}
}