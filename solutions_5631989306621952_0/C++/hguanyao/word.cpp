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

string cal(string input){
	int len = input.length();
	if(len <= 1)
		return input;
	char max = input[0];
	int index = 0;
	for(int i=1; i<len; i++){
		if(input[i]>=max){
			max = input[i];
			index = i;
		}
	}
	
	string retV(1, max);
	string first = input.substr(0, index);
	string second = input.substr(index+1, len-index-1+1);
	return retV+cal(first)+(second);
}
int main(int argc, char** argv) {
	int T;
	cin>>T;
	cin.ignore();
	foreach(itest, T){
		string input;
		getline(cin, input);
		string output = cal(input);
		cout<<"Case #"<<itest+1<<": "<<output<<endl;
	}
	return 0;
}
