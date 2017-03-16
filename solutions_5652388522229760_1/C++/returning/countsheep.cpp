#include <iostream>
#include <queue>  
#include <vector>   
#include <set>
#include <utility>
#include <math.h>       /* atan */
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <stack>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
#define foreach(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846 
long double diff = 1e-10;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void update(unordered_set<int> &set_number, ull input){
	while(input>0){
		set_number.insert(input%10);
		input = input/(ull)10;
	}
}
ull cal(ull input){
	unordered_set<int> occurred;
	ull cur = 0;
	for(ull i=1; i<10000000000LL; i++){
		if(cur > cur+input)
			cout<<"overflow"<<endl;
			
		cur = cur + input;
		
		update(occurred, cur);
		if(occurred.size() >= 10)
			return cur;
	}
	cout<<"SSSSSSSSHIIIIIIIITTTTTTTTTTT"<<endl;
}

int main(int argc, char** argv) {
	int T;
	cin>>T;
	foreach(itest, T){
		ull N;
		cin>>N;
		if(N==0)
			cout<<"Case #"<<itest+1<<": INSOMNIA"<<endl;
		else
			cout<<"Case #"<<itest+1<<": "<<cal(N)<<endl;
	}
	return 0;
}
