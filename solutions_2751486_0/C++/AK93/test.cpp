#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <limits.h>
#include <queue>
#include <cstring>

using namespace std;
typedef long long ll;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int test;
	cin>>test;
	for(int t=0; t<test; t++){
		string str;
		int n;
		cin>>str>>n;
		int res=0;
		for(int i=0; i<str.size(); i++){
			bool ch=false;
			int buf=0;
			for(int j=i; j<str.size(); j++){
				if(str[j] != 'a' && str[j] != 'e' && str[j] != 'i' && str[j] != 'o' && str[j] != 'u'){
					buf++;
				}
				else{
					if(buf < n)
						buf=0;
				}
				if(buf >= n)
					res++;
			}
		}


		printf("Case #%d: %d\n", t+1, res);
	}
	return 0;
}
