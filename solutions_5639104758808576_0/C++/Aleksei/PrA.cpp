#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <list>
#include <queue>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int t;
		cin>>t;
		string s;
		cin>>s;
		int rez = 0;
		int total = 0;
		for(int i=0; i<=t; i++){
			int cur = s[i]-'0';
			if(i-total>0){
				rez+=(i-total);
				total+=(i-total);
			}
			total+=cur;
		}
		cout<<"Case #"<<testnum+1<<": "<<rez<<endl;
	}
	return 0;
}
