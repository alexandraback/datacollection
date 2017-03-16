/* Problem	: Problem C. Fair and Square
** Time		:
** Algorithm:
**/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define MOD 1000000007
#define MAXN 1000005
#define st first
#define nd second
#define read(x) scanf("%d",&x)
#define rep(i,a,b) for(int i = a ; i <= b ; ++i)
typedef long long int64;
int64 A,B;
vector<string> number;
int answer = 0;
bool palin(int64 x){
	string a = "";
	while(x){
		a = char(x%10+'0') + a;
		x /= 10;
	}
	for(int i = 0 , j = a.size() - 1 ;i < j ; ++i,--j){
		if ( a[i] != a[j] ){
			return false;
		}
	}
	return true;
}
string toString(int64 x){
	string res = "";
	while(x){
		res = char(x%3+'0')+ res;
		x/=3;
	}
//	cout << "rev " << res << endl;
//	res.reserve();
//	cout << "revd " << res << endl;
	return res;
}
int64 toInt64(string str){
	int64 res = 0;
	for(int i = 0 ; i < str.size() ; ++i){
		res = res * 10 + (str[i] - '0');
	}
	return res;
}
string reserve(string a){
	for(int i = 0 , j = a.size() - 1 ; i < j ; ++i,--j){
		swap(a[i],a[j]);
	}
	return a;
}
int main (int argc, char const* argv[]){
	freopen("C-large-1.in","r",stdin);
	freopen("C-large-1.out","w",stdout);
	int T; read(T);
	rep(t,1,T){
		cin>>A>>B; int answer = 0;
		int prv = -1; number.clear();
		for(int i = 1, out = 0 ;!out; ++i){
			string nxt = toString(i);
			if ( nxt.size() != prv ){
				if ( !number.empty() ){
//					rep(k,0,number.size()-1){
//						cout << number[k] << endl;
//					}
					//even
					rep(k,0,number.size()-1){
						int64 num = toInt64(number[k]+reserve(number[k]));
	//					cout << num << endl;
						if ( num > B / num ){
							out = 1; break;
						}
						if ( num * num < A ){
							continue;
						}
						if ( palin(num*num) ){
							++answer;
						}
					}
					if ( out ) break;
					//odd
					rep(k,0,number.size()-1){
						rep(o,0,2){
							int64 num = toInt64(number[k]+char(o+'0')+reserve(number[k]));
							if ( num > B / num ){
								out = 1; break;
							}
							if ( num * num < A ){
								continue;
							}
							if ( palin(num*num) ){
								++answer;
							}
						}
					}
					if ( out ) break;
				}
				number.clear();
				number.push_back(nxt);
				prv = nxt.size();
			}else{
				number.push_back(nxt);
			}
		}
		
		if ( A <= 9 && 9 <= B) ++answer;
		if ( A <= 4 && 4 <= B) ++answer;
		if ( A <= 1 && 1 <= B) ++answer;
		printf("Case #%d: %d\n",t,answer);
	}
	return 0;
}

/* DOAN Minh Quy - mquy.doan@gmail.com */
