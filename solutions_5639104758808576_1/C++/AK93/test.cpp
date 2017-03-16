#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <ctime>
#include <hash_map>

using namespace std;
typedef long long ll;

int main(){
	freopen("A-large(1).in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test_count;
	cin>>test_count;
	for(int test=0; test<test_count; test++){
		int a;
		string str;
		int res = 0;
		int cnt = 0;
		cin>>a>>str;
		for(int i=0; i<str.size(); i++){
			int numb = str[i] - '0';
			if(numb == 0)
				continue;
			if(cnt >= i)
				cnt += numb;
			else{
				int buf = i - cnt;
				res += buf;
				cnt = i;
				cnt += numb;
			}
		}
		cout<<"Case #"<<test + 1<<": "<<res<<"\n";
	}
    return 0;
}
