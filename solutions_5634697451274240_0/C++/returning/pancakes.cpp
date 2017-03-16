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
int N; //N is glabal variable
ull revert(ull n, int len){
	ull r = 0;
    for(int i = 0; i < len; i++){
        r <<= 1;
        r += n & 1;
        n >>= 1;
    }
    return r;
}
ull dummy = 9223372036854775807LL;
int cal(ull input){
	queue<ull> strQueue;
	if(input == 0)
		return 0;
	//cout<<"input "<<input<<endl;
	
	strQueue.push(input);
	strQueue.push(dummy);
	
	int level = 0;
	
	set<ull> toVisit;
	toVisit.insert(input);
	
	while(strQueue.empty() == false){
		ull curV = strQueue.front();
		strQueue.pop();

		if(curV==dummy){
			strQueue.push(dummy);
			level++;
			continue;
		}
		
		//cout<<"top is "<<curV<<endl;
		if(curV == 0)
			return level;
			
		ull rightV = 0;
		for(int i = 0; i<N; i++){
			//we move from ith from right to left
			ull reverse = revert(~curV, N-i);
			
			ull newV = reverse * (1<<i) + rightV;
			
			//cout<<"new "<<reverse<<":"<<i<<":"<<rightV<<":"<<newV<<endl;

			if(toVisit.find(newV) == toVisit.end()) {
				toVisit.insert(newV);
				strQueue.push(newV);
			}

			rightV = ( (curV%2) <<i) + rightV ; //*2 + curV%2;
			curV = curV/(ull)2;
			
			//if(newV == 0)
				//return level;
		}
		//cout<<"break"<<endl;
	}
	return level;
}

ull translate(string &input){
	ull retV = 0;
	for(int i=0; i<input.length(); i++){
		if(input[i]=='+')
			retV = retV*2 + 0;
		else
			retV = retV*2 + 1;
	}
	return retV;
}

int main(int argc, char** argv) {
	int T;
	cin>>T;
	cin.ignore();
	foreach(itest, T){
		string inputStr;
		getline(cin, inputStr);
		ull input = translate(inputStr);
		N = inputStr.length(); //global variable
		cout<<"Case #"<<itest+1<<": "<<cal(input)<<endl;
	}
	return 0;
}
