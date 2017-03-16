
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
#include <climits>
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

void recur(string s1, string s2, int same, int index, string &n1,string &n2, LL &finalDiff\
		,string r1, string r2){
	if(index==s1.length()){
		LL thisDiff = abs(stoll(r1)-stoll(r2));
		// PRINT2(r1,r2)
		if (thisDiff< finalDiff){
			finalDiff = thisDiff;
			n1 = r1;
			n2 = r2;
		}
		return;
	}
	if(same==1){
		if(s1[index]!='?'){
			r1 = r1+s1[index]; 
		}else{
			r1 = r1+'0';
		}
		if(s2[index]!='?'){
			r2 = r2+s2[index]; 
		}else{
			r2 = r2+'9';
		}
		recur(s1,s2, same, index+1, n1,n2, finalDiff, r1,r2);
	}
	else if(same==2){
		if(s1[index]!='?'){
			r1 = r1+s1[index]; 
		}else{
			r1 = r1+'9';
		}
		if(s2[index]!='?'){
			r2 = r2+s2[index]; 
		}else{
			r2 = r2+'0';
		}
		recur(s1,s2, same, index+1, n1,n2, finalDiff, r1,r2);
	}else{
		if(s1[index]=='?' && s2[index]=='?'){
			// r1 = r1+ ''
			recur(s1,s2,0,  index+1, n1,n2, finalDiff, r1+'0', r2+'0');
			recur(s1,s2,2, index+1, n1,n2, finalDiff, r1+'0', r2+'1');
			recur(s1,s2,1, index+1, n1,n2, finalDiff, r1+'1', r2+'0');
		}else if(s1[index]=='?'){
			if(s2[index]!= '0'){
				char newDig = ((s2[index]-'0')-1)+'0';
				// r1 = r1+ newDig;
				recur(s1,s2,2, index+1, n1,n2, finalDiff, r1+newDig, r2+s2[index]);
			}
			recur(s1,s2,0, index+1, n1,n2, finalDiff, r1+s2[index], r2+s2[index]);
			if(s2[index]!= '9'){
				char newDig = ((s2[index]-'0')+1)+'0';
				recur(s1,s2,1, index+1, n1,n2, finalDiff, r1+newDig, r2+s2[index]);
			}
		}else if(s2[index] =='?'){
			if(s1[index]!= '0'){
				char newDig = ((s1[index]-'0')-1)+'0';
				// r1 = r1+ newDig;
				recur(s1,s2,1, index+1, n1,n2, finalDiff, r1+s1[index], r2+newDig);
			}
			recur(s1,s2,0, index+1, n1,n2, finalDiff, r1+s1[index], r2+s1[index]);
			if(s1[index]!= '9'){
				char newDig = ((s1[index]-'0')+1)+'0';
				recur(s1,s2,2, index+1, n1,n2, finalDiff, r1+s1[index], r2+newDig);
			}
		}else{
			// same = (s1[index] > s2[index])?1:2;
			if(s1[index]>s2[index]){
				same = 1;
			}else if(s1[index]<s2[index]){
				same=2;
			}else{
				same =0;
			}
			recur(s1,s2,same, index+1, n1,n2, finalDiff, r1+s1[index], r2+s2[index]);
		}
	}	
	// if(s1[index] != '?' && s2[index] != '?')
	// int n1 = 

}
int main(){
	int T;
	cin>>T;
	int tests = 1;
	while(T--){
		string s1, s2,r1,r2, n1, n2;
		cin>>s1>>s2;
		LL finalDiff = LLONG_MAX;
		recur(s1,s2,0,0,n1,n2,finalDiff, r1,r2);
		cout<<"Case #"<<tests<<": "<<n1<<" " << n2<<"\n";
		tests++;
	}

}
