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
#define N 105
#define NN 212
#define VAL 20000
#define LN 18

double dp[N][N][N];
int arr[N];
int states[N][30];
double freq[26];
double answer;
int k,l,s,nnnn;
string keypad;
string pattern;

void build_automata(){
	arr[0] = 0,arr[1] = 0;
	for(int a=2;a<=l;a++){
		int b = arr[a-1];
		for(;;){
			if(pattern[b]==pattern[a-1]){
				arr[a] = b+1;
				break;
			}
			if(b==0){
				arr[a] = 0;
				break;
			}
			b = arr[b];
		}
	}
}

int getNextState(int M, int state, int x){
	if (state < M && x == pattern[state])
		return state+1;
 
	int ns, i;
	for (ns = state; ns > 0; ns--)
	{
		if(pattern[ns-1] == x)
		{
			for(i = 0; i < ns-1; i++)
			{
				if (pattern[i] != pattern[state-ns+1+i])
					break;
			}
			if (i == ns-1)
				return ns;
		}
	}
 
	return 0;
}

void build_states(){
	for(int a=0;a<30;a++)		states[0][a] = 0;
	states[0][pattern[0]-'A'] = 1;
	for(int a=1;a<=l;a++){
		for(int b=0;b<26;b++){
			//states[a][b] = states[lps][b];
			states[a][b] = getNextState(l, a, b+'A');
		}/*
		states[a][pattern[a]-'A'] = a+1;
		if(a<l){
			lps = states[lps][pattern[a]-'A'];
		}*/
	}
}

void func(){
	for(int a=0;a<N;a++)for(int b=0;b<N;b++)for(int c=0;c<N;c++)	dp[a][b][c] = 0.0;
	dp[0][0][0] = 1.0;
	for(int a=0;a<s;a++){
		for(int b=0;b<=nnnn;b++){
			for(int c=0;c<=l;c++){
				for(int x=0;x<26;x++){
					if(states[c][x]==l){
						//cout<<c<<" "<<x<<" U";
						dp[a+1][b+1][states[c][x]] += (dp[a][b][c]*(freq[x]/double(k)));
					} else {
						//cout<<c<<" "<<x<<"Y";
						dp[a+1][b][states[c][x]] += (dp[a][b][c]*(freq[x]/double(k)));
					}
				}
			}
		}
	}
}

void find_ans(){
	answer = 0.0;
	for(int a=0;a<nnnn;a++){
		double prob = 0.0;
		for(int b=0;b<=l;b++){
			prob += dp[s][a][b];
		}
		answer += (prob*(double(nnnn-a)));
	}
}

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("B-out2.out", "w", stdout);
	int t,ttt = 0;
	cin>>t;
	while(t--){
		cin>>k>>l>>s;
		cin>>keypad;
		cin>>pattern;
		answer = 0.0;
		bool flag = true;
		bool tfreq[26][2];
		for(int a=0;a<26;a++){
			tfreq[a][0] = 0;tfreq[a][1] = 0;
			freq[a] = 0;
		}
		for(int a=0;a<l;a++)		tfreq[pattern[a]-'A'][0] = true;
		for(int a=0;a<k;a++)		tfreq[keypad[a]-'A'][1] = true,freq[keypad[a]-'A']+= 1.0;
		for(int a=0;a<26;a++){
			if(tfreq[a][0] && !tfreq[a][1])		flag = false;
		}
		if(!flag || s<l){
			cout<<"Case #"<<++ttt<<": ";
			printf("%.9f\n", answer);
			continue;
		}
		build_automata();
		build_states();
		nnnn = 1 + (s-l)/(l-arr[l]);
		//cout<<"++++    "<<nnnn<<endl;
		func();
		find_ans();
		cout<<"Case #"<<++ttt<<": ";
		printf("%.9f\n", answer);
	}
	return 0;
}