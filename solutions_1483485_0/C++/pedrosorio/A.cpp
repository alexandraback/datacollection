#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

char arr[]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main() {
	int T;
	cin >> T;
  string s;
  getline(cin,s);
	for(int c=1;c<=T;c++) {
    getline(cin,s);
    for(int i=0;i<s.size();i++) {
      if(s[i]>='a' && s[i]<='z')
        s[i] = arr[s[i]-'a'];
    }
		cout << "Case #" << c << ": " << s << endl;
	}
	return 0;
}
