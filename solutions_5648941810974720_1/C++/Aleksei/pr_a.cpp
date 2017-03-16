#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		string s;
		cin>>s;
		int digits[10] = {0,0,0,0,0,0,0,0,0,0};
		int chars[255] = {0,};
		int n = s.size();
		for(int i=0; i<n; i++){
			chars[s[i]-'A']++;
		}
		if(chars['Z'-'A']>0){
			int num = chars['Z'-'A'];
			assert(chars['E'-'A']>=num);
			assert(chars['R'-'A']>=num);
			assert(chars['O'-'A']>=num);
			digits[0]+=num;
			chars['Z'-'A']-=num;
			chars['E'-'A']-=num;
			chars['R'-'A']-=num;
			chars['O'-'A']-=num;
		}
		if(chars['W'-'A']>0){
			int num = chars['W'-'A'];
			assert(chars['T'-'A']>=num);
			assert(chars['O'-'A']>=num);
			digits[2]+=num;
			chars['T'-'A']-=num;
			chars['W'-'A']-=num;
			chars['O'-'A']-=num;
		}
		if(chars['U'-'A']>0){
			int num = chars['U'-'A'];
			assert(chars['F'-'A']>=num);
			assert(chars['O'-'A']>=num);
			assert(chars['R'-'A']>=num);
			digits[4]+=num;
			chars['F'-'A']-=num;
			chars['O'-'A']-=num;
			chars['U'-'A']-=num;
			chars['R'-'A']-=num;
		}
		if(chars['X'-'A']>0){
			int num = chars['X'-'A'];
			assert(chars['S'-'A']>=num);
			assert(chars['I'-'A']>=num);
			digits[6]+=num;
			chars['S'-'A']-=num;
			chars['I'-'A']-=num;
			chars['X'-'A']-=num;
		}
		if(chars['G'-'A']>0){
			int num = chars['G'-'A'];
			assert(chars['E'-'A']>=num);
			assert(chars['I'-'A']>=num);
			assert(chars['H'-'A']>=num);
			assert(chars['T'-'A']>=num);
			digits[8]+=num;
			chars['E'-'A']-=num;
			chars['I'-'A']-=num;
			chars['G'-'A']-=num;
			chars['H'-'A']-=num;
			chars['T'-'A']-=num;
		}
		if(chars['O'-'A']>0){
			int num = chars['O'-'A'];
			assert(chars['N'-'A']>=num);
			assert(chars['E'-'A']>=num);
			digits[1]+=num;
			chars['O'-'A']-=num;
			chars['N'-'A']-=num;
			chars['E'-'A']-=num;
		}
		if(chars['T'-'A']>0){
			int num = chars['T'-'A'];
			assert(chars['H'-'A']>=num);
			assert(chars['R'-'A']>=num);
			assert(chars['E'-'A']>=2*num);
			digits[3]+=num;
			chars['T'-'A']-=num;
			chars['H'-'A']-=num;
			chars['R'-'A']-=num;
			chars['E'-'A']-=num;
			chars['E'-'A']-=num;
		}
		if(chars['F'-'A']>0){
			int num = chars['F'-'A'];
			assert(chars['I'-'A']>=num);
			assert(chars['V'-'A']>=num);
			assert(chars['E'-'A']>=num);
			digits[5]+=num;
			chars['F'-'A']-=num;
			chars['I'-'A']-=num;
			chars['V'-'A']-=num;
			chars['E'-'A']-=num;
		}
		if(chars['S'-'A']>0){
			int num = chars['S'-'A'];
			assert(chars['E'-'A']>=2*num);
			assert(chars['V'-'A']>=num);
			assert(chars['N'-'A']>=num);
			digits[7]+=num;
			chars['S'-'A']-=num;
			chars['E'-'A']-=num;
			chars['V'-'A']-=num;
			chars['E'-'A']-=num;
			chars['N'-'A']-=num;
		}
		if(chars['I'-'A']>0){
			int num = chars['I'-'A'];
			assert(chars['N'-'A']>=2*num);
			assert(chars['E'-'A']>=num);
			digits[9]+=num;
			chars['N'-'A']-=num;
			chars['I'-'A']-=num;
			chars['N'-'A']-=num;
			chars['E'-'A']-=num;
		}
		for(int i=0; i<255; i++){
			assert(chars[i]==0);
		}
		cout<<"Case #"<<testnum+1<<": ";
		for(int i=0; i<10; i++){
			for(int j=0; j<digits[i]; j++) cout<<i;
		}
		cout<<endl;
	}
	return 0;
}
