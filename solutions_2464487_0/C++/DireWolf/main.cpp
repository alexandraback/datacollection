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

ifstream myin("A-small-attempt3.in");
ofstream myout("A-large.out");

void main2(){
	long long int t,r;
	myin >> r >> t;
	bool found = false;
	long long int left = 0;
	long long int right = (int)sqrt(t+10);
	long long int mid;
	while(!found){
		mid = (left+right+1)/2;
		if(log(mid)+log(2*r + 2*(mid-1) + 1) <= 18  && (mid*(2*r + 2*(mid-1)+1) <= t)){
			left = mid;		
		} 
		else{
			right = mid-1;
		}
		if(left >= right){
			found = true;
		}
	}
	myout << left;
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