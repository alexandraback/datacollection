#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;


//class mycomparison
//{
//public:
//	bool operator() (int lhs, int rhs) const
//	{
//		return lhs > rhs;
//	}
//};  //ascending order


bool isvowel(char c){
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		return true;
	}
	return false;
}


long long f(string name, int n){   // n is no. of consec. consonants required
	
	int cont_found = 0; //no of cons. consonants encountered
	int last_index = 0;   //inclusive
	long long total = 0;
	
	
	for (int i=0; i<name.length(); i++) {
		//printf("i = %d\n",i);
		if (isvowel(name[i])) {
			cont_found = 0;
		}
		else {
			cont_found++;
			if (cont_found == n) {
				int to_left = i+1-n-last_index;
				int to_right = name.length() - (i+1);
				total+= 1+to_left*(to_right+1)+to_right;
				//printf("to_left,right, total  == %d,%d %lld\n",to_left,to_right,total);
				last_index = i+2-n;
				cont_found = n-1;
			}
		}
	}
	return total;
	
}

int main ()
{
	int no_testcases;
	scanf("%d", &no_testcases);
	
	
	for (int i=0; i<no_testcases; i++) {
		string name;
		int n;
		char namechar[1000000];
		
		scanf("%s",&namechar[0]);
		name = namechar;
		scanf("%d",&n);
		
		long long answer = f(name,n);
		
		printf("Case #%d: %lld\n",i+1,answer);
		
		
	}
	
	return 0;
}