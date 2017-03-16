#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<sstream>
#include<fstream>
#include<iomanip>
#include<ctime>
#include<complex>
#include<functional>
#include<climits>
#include<cassert>
#include<iterator>
using namespace std;



#define MAX 100002
int t;
char buf[MAX];

string s;
deque<char> ans;

int main(){
	cin >> t;
	int tt = 0;
	while (t--){
		tt++;
		scanf("%s", buf);
		s = buf;
		ans.clear();
		ans.push_back(s[0]);
		for (int i = 1; i < s.size(); i++){
			if (ans.front() <= s[i]){
				ans.push_front(s[i]);
			}
			else{
				ans.push_back(s[i]);
			}
		}
		s.clear();
		for (int i = 0; i < ans.size(); i++){
			s.push_back(ans[i]);
		}
		printf("Case #%d: ", tt);
		printf("%s", s.c_str());
		puts("");
	}
	return 0;
}