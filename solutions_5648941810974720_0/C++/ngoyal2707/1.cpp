
// Author: ngoyal2707

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <cstdlib>
#include <map>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define FORALL(i,a,b)               for(decltype(a) i=a;i<b;i++)
#define FORALLR(i,a,b)               for(decltype(a) i=a;i>=b;i--)
#define FOREACH(v, c)               for( decltype( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define FOREACHR(v, c)               for( decltype( (c).rbegin()) v = (c).rbegin();  v != (c).rend(); ++v)
#define PRINT1(x) cout<<"Passed Argument is:  "<<x<<"\n";
#define PRINT2(x,y) cout<<"1st value:  "<<x<<"\t2st value:  "<<y<<"\n";
#define PRINT3(x,y,z) cout<<"1st value:  "<<x<<"\t2st value:  "<<y<<"\t3st value:  "<<z<<"\n";
#define PRINT4(x,y,z,w) cout<<"1st value:  "<<x<<"\t2st value:  "<<y<<"\t3st value:  "<<z<<"\t4th value:  "<<w<<"\n";
#define PRINTEACH(v) FOREACH(it,v){ cout<<*it<<"\t"; } cout<<"\n";
#define PRINTEACH2(v) FOREACH(it,v){ FOREACH(it1,it){ cout<<*it1<<"\t"; } cout<<"\n"};
#define ALL(a)                      a.begin(), a.end()
#define IN(a,b)                     ( (a).find(b) != (a).end())
#define SIZE(a)                       ((int)(a.size()))
#define PRESENT(v,c)				((v).find(c)!=(v).end())
#define FIND(v,c)					v.find(c)-v.begin()
#define make_pair MP

using namespace std;
typedef long long int LL;
typedef long int L;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<string> vs;
typedef vector<long> vl;
typedef vector<vector<long>> vvl;
typedef vector<long long int> vll;
typedef vector<vector<long long int>> vvll;
typedef vector<pair<int,int>> vpi;
typedef vector<pair<LL,LL>> vpll;


int main(){
	int T;
	cin>>T;
	int testCase = 1;
	while(T--){
		string str;
		cin>>str;
		vi charCount(26,0);
		FORALL(i,0,str.length()){
			charCount[str[i]-'A']++;
		}
		vi result(10,0);

		// int zs = charCount[str[i]-'Z']
		// if(zs>0){
		// 	charCount[str[i]-'Z'] -=zs;
		// 	charCount[str[i]-'E'] -=zs;
		// 	charCount[str[i]-'R'] -=zs;
		// 	charCount[str[i]-'O'] -=zs;
		// 	result[0] = zs;
		// }
		// if(charCount[str[i]-'W']>0){
		// 	charCount[str[i]-'T'] -=zs;
		// 	charCount[str[i]-'W'] -=zs;
		// 	charCount[str[i]-'0'] -=zs;
		// 	result[0] = zs;
		// }
		// PRINTEACH(charCount)
		// PRINTEACH(result)
		std::vector<string> digits = {"ZERO","SIX", "SEVEN", "FIVE","TWO",\
						"FOUR","THREE","EIGHT","ONE", "NINE"};
		vi order = {0,6,7,5,2,4,3,8,1,9};
		FORALL(i,0,digits.size()){
			int min1 = 10000;
			// if(i==0)
			vi digitCount(26,0);
			FORALL(j,0,digits[i].length()){
				digitCount[digits[i][j]-'A']++;
			}
			FORALL(j,0,26){
				// int charMy =1;
				if(digitCount[j]>0)
					min1 = min(min1, charCount[j] / digitCount[j]);
			}
			if(min1>0){
				FORALL(j,0,digits[i].length()){
					// min1 = min(min1, charCount[i][j]);
					charCount[digits[i][j]-'A']-=min1;
				}
			}
			// PRINT1(min1)
			result[order[i]]+=min1;
		}
		cout<<"Case #"<<testCase<<": ";
		string final;
		FORALL(i,0,result.size()){
			// PRINT1(result[i])
			while(result[i]){
				char newOne = i+'0';
				final = final+newOne;
				// PRINT1(result[i])
				result[i]--;
			}
		}
		cout<<final<<"\n";
		testCase++;
	}
}
