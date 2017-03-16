#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include<iostream>
#include<fstream>
using namespace std;
#include <iostream>   
#include<algorithm>
#define INF 100000000    
using namespace std;  
const double PI = acos(-1.0);

int R, N, M, K;
int pro[10000];
template<class T> inline vector<pair<T,int> > factorize(T n)//NOTES:factorize(
  {vector<pair<T,int> > R;for (T i=2;n>1;){if (n%i==0){int C=0;for (;n%i==0;C++,n/=i);R.push_back(make_pair(i,C));}
   i++;if (i>n/i) i=n;}if (n>1) R.push_back(make_pair(n,1));return R;}
void guess()
{
	int num[10];
	int total = 0;
	int find = 0;
	//4 * K;
	memset(num, 0, sizeof(num));
	for (int i = 0;i < K;++i) {
		if(pro[i] == 1)continue;
		
		vector<pair<int, int> > tmp = factorize(pro[i]);
		for (int j = 0;j < tmp.size();++j) {
			num[tmp[j].first] += tmp[j].second;
			total += tmp[j].second;
			if(tmp[j].first == 2 && tmp[j].second %2 == 1) {
				find = 1;
			}
		}
	}
	int remain = 0;
	string s("");
	if(num[3] == 0 && num[2] == 0 && num[5] == 0) {
		s = s + string("2345");
		cout<<endl;
		return;
	}
	if(num[3] > 0 && num[2] == 0 && num[5] == 0){
		s = s + string("3333");
		cout<<s<<endl;
		return;
	}
	if(num[5] > 0 && num[2] == 0 && num[3] == 0){
		s = s + string("5555");
		cout<<s<<endl;
		return;
	}
	if(num[3] > 0) {
		s = s + string("3");
	} 
	if( num[5] > 0) {
		s = s + string("5");
	}
	if(find) {
		s = s + string("2");
	}
	
	if(num[3] > total / 4) {
		s = s + string("3");
	} 
	if(s.length() >= 4) {
		cout<<s<<endl;
		return;
	}
	if(num[3] >= total / 2) {
		s = s + string("3");
	}
	if(s.length() >= 4) {
		cout<<s<<endl;
		return;
	}
	if(num[5] >= total / 4) {
		s = s + string("5");
	}
	if(s.length() >= 4) {
		cout<<s<<endl;
		return;
	}
	if(num[5] >= total / 2) {
		s = s + string("5");
	}
	
	if(s.length() >= 4) {
		cout<<s<<endl;
		return;
	}
	if(!find) {
		s = s + string("4");
	}
	if(num[2] >= total / 3 * 2) {
		s = s + string("4");
	}
	if(s.length() >= 4) {
		cout<<s<<endl;
		return;
	}

	if(s.length() >= 4) {
		cout<<s<<endl;
		return;
	} else {
		if(num[2] > total / 3 * 2)
		{while(s.length() < 4) {
			
				s = s + string("4");
			
		}
		} else {
			while(s.length() < 4) {
			
				s = s + string("2");
			
		}
		}
		cout<<s<<endl;
		return;
	}

}
void solve()
{
	scanf("%d%d%d%d", &R, &N, &M, &K);

	for (int i = 1;i <= R;++i) {
		for (int j = 0;j < K;++j) {
			cin>>pro[j];
		}
		guess();
	}
}
int main()
{
	//freopen("data.txt", "r", stdin);
	freopen("C-small-1-attempt10.in", "r", stdin);
	freopen("C-small-1-attempt10.out", "w", stdout);
	//freopen("A-large.in", "r", stdin);
	//freopen("A-large.out", "w", stdout);
	int t = 0;
	scanf("%d", &t);

	for(int i = 0;i < t;++i) {
		cout<<"Case #"<<i + 1<<": "<<endl;
		solve();
	}
	return 0;
}