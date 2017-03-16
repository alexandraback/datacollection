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

long long l,x;
string baap = "1ijk";
string str,tempstr;
pair < int,int > arr[4][4];

int findInd(char ch){
	for(int a=0;a<baap.size();a++)		if(baap[a]==ch)		return a;
	return 0;
}

bool func(){
	int a = 0,answer = 0,isNeg = 0;
	bool isi = false, isj = false, isk = false;
	for(;a<str.size();a++){
		isNeg ^= arr[answer][findInd(str[a])].S;
		answer = arr[answer][findInd(str[a])].F;
		if(isNeg==0 && answer==1){
			a++,answer = 0;
			isi = true;
			break;
		}
	}
	for(;a<str.size();a++){
		isNeg ^= arr[answer][findInd(str[a])].S;
		answer = arr[answer][findInd(str[a])].F;
		if(isNeg==0 && answer==2){
			a++,answer = 0;
			isj = true;
			break;
		}
	}
	for(;a<str.size();a++){
		isNeg ^= arr[answer][findInd(str[a])].S;
		answer = arr[answer][findInd(str[a])].F;
		if(isNeg==0 && answer==3){
			a++,answer = 0;
			isk = true;
			break;
		}
	}
	for(;a<str.size();a++){
		isNeg ^= arr[answer][findInd(str[a])].S;
		answer = arr[answer][findInd(str[a])].F;
	}
	x %= 4;
	while(x--){
		for(a=0;a<tempstr.size();a++){
			isNeg ^= arr[answer][findInd(tempstr[a])].S;
			answer = arr[answer][findInd(tempstr[a])].F;
		}
	}
	if(isi && isj && isk && answer==0 && isNeg==0)		return 1;
	else												return 0;
}

void build(){
	for(int a=0;a<4;a++)	arr[0][a] = mp(a,0),arr[a][0] = mp(a,0);
	arr[1][1] = mp(0,1),arr[1][2] = mp(3,0),arr[1][3] = mp(2,1);
	arr[2][1] = mp(3,1),arr[2][2] = mp(0,1),arr[2][3] = mp(1,0);
	arr[3][1] = mp(2,0),arr[3][2] = mp(1,1),arr[3][3] = mp(0,1);
}

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C.out", "w", stdout);
	build();
	int t,ttt = 0;
	cin>>t;
	while(t--){
		cin>>l>>x;
		cin>>tempstr;
		str = "";
		int lll;
		if(x<=18)		lll = x;
		else			lll = 18;
		for(int a=1;a<=lll;a++){
			str += tempstr;
		}
		x -= lll;
		if(func()){
			cout<<"Case #"<<++ttt<<": YES"<<endl;
		} else {
			cout<<"Case #"<<++ttt<<": NO"<<endl;
		}
	}
	return 0;
}