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
#define foreach(i, n) for (ull i = 0; i < (ull)(n); i++)
#define PI 3.14159265358979323846 
long double diff = 1e-10;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string toStr(ull input, int &size){
	string retV;
	if(input>0)
	while(input>0){
		if(input %2 == 1)
			retV += "1";
		else
			retV += "0";
		input = input/(ull)2;
		size++;
	}
	else{
		retV = "0";
		size = 1;
	}
	reverse(retV.begin(), retV.end());
	return retV;
}

int main(int argc, char** argv) {
	int T;
	cin>>T;
	int N; int J;
	cin>>N; cin>>J;
	//N is even, so
	int N1 = N/2;
	//the N1-1 th bit is 1
	//we calculate all the combinations that have form 1 x x x 1, where the 1st 1 is the highest N1 th bit. 
	//so we calculate all the numbers between 0 to k^(N1-2)-1. Suppose it is M
	//then the number is (M+k^(N1-1)+1)*(k^N1+1);
	//when N=16, N1=8, N1-2=6. 2^6=64>50, can beat the J numbers.
	//when N=32, N1=16, N1-2=14, 2^14>500, can easily beat the J numbers. 
	
	cout<<"Case #1:"<<endl;
	
	ull MRange = (ull)1<<(N1-2);
	vector<ull> baseN1(9, 1);
	for(ull base = 2; base<=10; base++){
		ull b = 1;
		for(int i=1; i<=N1; i++){
			b *= base;
		}
		baseN1[base-2] = b;
	} 

	for(ull itest=0; itest<MRange; itest++){
		if(itest+1>J)
			break;
		int size = 0;
		string str = toStr(itest,size);
		string zeros(N1-2-size, '0');
		
		string output = "1"+zeros+str+"11"+zeros+str+"1";
		cout<<output<<" ";
		
		vector<ull> result(9, 1);
		for(int base=2; base<=10; base++){
			cout<<baseN1[base-2]+(ull)1<<" ";
			result[base-2] = baseN1[base-2]+(ull)1;
		}
		cout<<endl;

/*		
		vector<ull> originalN(9,1);
		for(ull base=2; base<=10; base++){
			ull number = 0;
			for(int i=output.length()-1; i>=0; i--){
				if(output[i] == '1')
					number = number*base + 1;
				else
					number = number*base ;
			}
			originalN[base-2] = number;
			cout<<number<<" ";
		}
		cout<<endl;
		
		for(int base = 2; base<10; base++){
			if(originalN[base-2] % result[base-2] != 0)
				cout<<"wrong anser!!!"<<endl;
		}
*/		
	}


	return 0;
}
