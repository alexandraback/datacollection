#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string.h>
#include <string>
#include <set>
#include <queue>
#include <cstdlib>
#include <fstream>
#include <map>
#include <sstream>
#include <iterator>
#include <bitset>
#include <cctype>
#include <cmath>
#include <functional>
#include <iomanip>
#include <list>
#include <numeric>
#include <stack>
#include <utility>
#include <conio.h>
using namespace std;
#define ll long long


bool is_nvowel(char c) {
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return false;
	return true;
}

void main1() {
	int t;
	cin>>t;
	string s;
	for(int z=0; z<t; z++) {
		printf("Case #%d: ",(z+1));
		cin>>s;
		int p;
		cin>>p;
		ll n = s.length();
		//cou't<<s<<" "<<n<<" "<<p<<endl;
		ll start = 0;
		ll ans = 0;
		int tot = 0;
		for(int i=0; i<n; i++) {
			if(is_nvowel(s[i])) tot++;
			else tot = 0;
			if(tot>=p) {
				ans+=(((ll)(i-p+1-start+1))*((ll)(n-1-i+1)));
				start = i-p+2;
			}
		}
		printf("%lld\n",ans);
	}
}



void main2() {


}


void main3() {



}



int main() {
	freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	main1();




	//printf("Program End\n");
	//_getch();
	return 0;
}