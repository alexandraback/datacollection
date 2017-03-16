#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip> 
#include <complex> 
#include <string>
#include <vector> 
#include <list>
#include <deque> 
#include <stack> 
#include <queue> 
#include <set>
#include <map>
#include <bitset>
#include <functional>
#include <utility>
#include <algorithm> 
#include <numeric> 
#include <typeinfo> 
#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <cmath>
#include <climits> 
#include <ctime>
using namespace std;

typedef __int64 ll;
typedef pair<int,int> P;

vector<string> ss;
int dp[500000];

int main(void){
	ifstream ifs("dic.txt");
	string str;
	for(int i=0;i<521196;i++){
		ifs >> str;
		ss.push_back(str);
	}
	int t;
	scanf("%d",&t);
	for(int test=1;test<=t;test++){
		cin >> str;
		for(int i=0;i<=501;i++)dp[i]=999999;
		dp[0]=0;
		for(int k=0;k<str.size();k++){
			for(int i=0;i<521196;i++){
				int mc=0;
				for(int j=0;j<ss[i].size();j++){
					if(str.size()<=k+j)mc+=5000;
					else if(ss[i][j]!=str[k+j])mc++;
				}
				if(mc<5)dp[k+ss[i].size()]=min(dp[k]+mc,dp[k+ss[i].size()]);
			}
		}
		printf("Case #%d: %d\n",test,dp[str.size()]);
	}
	return 0;
}