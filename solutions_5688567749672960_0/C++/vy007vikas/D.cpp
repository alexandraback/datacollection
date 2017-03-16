//
//  A.cpp
//  CODE
//
//  Created by Vikas Yadav on 29/10/14.
//  Copyright (c) 2014 Vikas Yadav. All rights reserved.
//

#include <cstring>
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
#include <ctime>
#include <fstream>
#include <iterator>
#include <memory.h>
#include <cassert>

using namespace std;

#define pll pair < long long,long long >
#define pb push_back
#define mp make_pair
#define gc getchar_unlocked
#define F first
#define S second

#define MOD 1000000007
#define INF 999999
#define N 11234567
#define NN 212
#define VAL 20000
#define LN 18

int dp[N];

int rev(int no){
	int answer = 0;
	while(no>0){
		answer = answer*10 + no%10;
		no/=10;
	}
	return answer;
}

void build(){
	dp[1] = 1;
	for(int a=2;a<N;a++)		dp[a] = 9999999;
	for(int no=1;no<(N/10);no++){
		dp[no+1] = min(dp[no+1],dp[no]+1);
		dp[rev(no)] = min(dp[rev(no)],dp[no]+1);
	}
}

int main(){
	freopen("A-small.in", "r", stdin);
	freopen("A-out.out", "w", stdout);
	build();
	int t,ttt = 0;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		cout<<"Case #"<<++ttt<<": "<<dp[n]<<endl;
	}
	return 0;
}