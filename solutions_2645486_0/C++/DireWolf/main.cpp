//File: main.cpp
//Autor: Vukasin Rankovic
#pragma comment(linker, "/STACK:268435456")

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <map>
#include <bitset>
#include <math.h>
#include <stdio.h>
#include <limits.h>
#include <stack>

using namespace std;

ifstream myin("B-small-attempt0 (3).in");
ofstream myout("A-large.out");

int res,n,r,maxEnergy;
int costs[10];

int search(int engergy,int lv,int currentCost){
	if(lv==n-1){
		return currentCost+engergy*costs[lv];
	}
	int k = engergy + r - maxEnergy >0 ?engergy + r - maxEnergy:0;
	for(int i=k ; i<=engergy ;i++){
		int newEng = engergy-i+r > maxEnergy? maxEnergy:engergy-i+r;
		int ret = search(newEng,lv+1,currentCost+i*costs[lv]);
		if(res < ret){
			res = ret;
		}
	}
	return res;
}

void main2(){
	int e;
	myin >> e >> r >> n;
	maxEnergy = e;
	for(int i=0 ; i<n ; i++){
		myin >> costs[i];
	}
	res = 0;
	int r = search(e,0,0);
	myout << r;
}

//Multiple test cases
int main(){
	int t;
	myin >> t;
	for(int i=1 ; i<=t ; i++){
		myout << "Case #" << i << ": ";
		main2();
		myout << endl;
	}
}