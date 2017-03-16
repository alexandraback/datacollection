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

int x,r,c;

string func(){
	if((r*c)%x!=0)				return "RICHARD";
	if(x==1 || x==2)			return "GABRIEL";
	if(x>=8)					return "RICHARD";
	if(max(r,c)<x || min(r,c)<x-1)		return "RICHARD";
	return "GABRIEL";
}

int main(){
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("Dout.out", "w", stdout);
	int t,ttt = 0;
	cin>>t;
	while(t--){
		cin>>x>>r>>c;
		cout<<"Case #"<<++ttt<<": "<<func()<<endl;
	}
	return 0;
}