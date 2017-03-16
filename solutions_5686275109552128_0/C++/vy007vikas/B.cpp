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
int freq[1100];
set <int> myset;

int func(){
	int answer = *myset.rbegin(),cnt = 0,x,temp,temp2,temp3,temp4,var;
	while(cnt<=answer){
		answer = min(answer,cnt+*myset.rbegin());
		x = *myset.rbegin();
		if(x==1)	break;
		myset.erase(x);
		var = 2;temp3 = 99999;
		if(!myset.empty())		temp4 = *myset.rbegin();
		else					temp4 = 0;
		for(int b=2;b<=sqrt(x)+1 && b<=x;b++){
			temp = x/b;
			if(x%b!=0)		temp++;
			temp2 = max(temp,temp4) + freq[x]*(b-1);
			if(temp2<temp3){
				temp3 = temp2;
				var = b;
			}
		}
		//cout<<" == "<<answer<<" "<<var<<endl;
		myset.insert(x/var);freq[x/var]+=((var - (x%var))*freq[x]);
		myset.insert((x/var) + (x%var));freq[(x/var) + (x%var)]+=((x%var)*freq[x]);
		cnt+=((var-1)*freq[x]);
		freq[x] = 0;
	}
	return answer;
}

int main(){
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("Bout.out", "w", stdout);
	int t,ttt = 0;
	cin>>t;
	while(t--){
		cin>>n;
		//cout<<" --- "<<endl<<n<<endl;
		int x;
		myset.clear();
		for(int a=0;a<1100;a++)		freq[a] = 0;
		for(int a=0;a<n;a++){
			cin>>x;
			//cout<<x<<" ";
			freq[x]++;
			myset.insert(x);
		}
		//cout<<endl;
		cout<<"Case #"<<++ttt<<": "<<func()<<endl;
	}
	return 0;
}