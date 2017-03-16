#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>
using namespace std;
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)<(b))?(b):(a))
#define ABS(x) (((x)<0)?(-(x)):(x))
#define SQR(x) ((x)*(x))
#define LL long long

bool isVowel(char c){
	if((c=='a')||(c=='e')||(c=='i')||(c=='o')||(c=='u')){
		return true;
	}
	return false;
}
int solve(const char *s, int len, int n){
	int total=0;
	for(int i=0;i<len;++i){
		for(int j=i;j<len;++j){
			int cnt=0;
			bool ok=false;
			for(int k=i;k<=j;++k){
				if(!isVowel(s[k])){
					++cnt;
				}else{
					cnt=0;
				}
				if(cnt>=n){
					ok=true;
					break;
				}
			}
			if(ok){
				++total;
			}
		}
	}
	return total;
}
int main(int argc, char *argv[]){
	int T;
	cin>>T;
	for(int c=1;c<=T;++c){
		string s;
		int n;
		cin>>s>>n;
		cerr<<s<<" "<<n<<endl;
		int sol=solve(s.c_str(), s.size(), n);
		printf("Case #%d: %d\n", c, sol);
	}
	return 0;
}

