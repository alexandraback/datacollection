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
#define N 112345
#define NN 212
#define VAL 20000
#define LN 18

int n;
string str;

long long func(){
	long long answer = 0,temp = 0,x;
	for(int a=0;a<str.size();a++){
		x = str[a] - '0';
		if(temp < a){
			answer += (a - temp);
			temp = a;
		}
		temp += x;
	}
	return answer;
}

int main(){
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-out.out", "w", stdout);
	int t,ttt = 0;
	cin>>t;
	while(t--){
		cin>>n>>str;
		cout<<"Case #"<<++ttt<<": "<<func()<<endl;
	}
	return 0;
}