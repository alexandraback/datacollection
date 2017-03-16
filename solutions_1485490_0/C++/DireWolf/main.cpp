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

ifstream myin("C-small-attempt1.in");
ofstream myout("C-small-attempt1.out");

long long int min(long long int a,long long int b){
	if(a>b) return b;
	return a;
}
typedef struct toy{
	long long int val;
	long long int number; 
}Toy;

Toy a[3];
Toy b[100];
long long int best=0;
bool found = false;
int n,m;

void search(int k,long long int res,int start){
	long long int resoult = res;
	if(k==n || start>=m){
		if(resoult > best || !found) {best = resoult; found = true;}
		return;
	}
	for(int i=0 ; i<2 ; i++){
		if(i==0){
			long long int counter = 0;
			for(int j=start ; j<m ; j++){
				if(b[j].val == a[k].val){
					long long int temp = min(b[j].number,a[k].number-counter);
					resoult+=temp;
					counter+=temp;
					if(b[j].number > temp){
						b[j].number-=temp;
						search(k+1,resoult,j);
						b[j].number+=temp;
					}
					else{
						search(k+1,resoult,j+1);
					}
					if(a[k].number == counter){
						j=m;
					}
					
				}
			}
			//resoult-=counter;
		}
		else{
			search(k+1,res,start);
		}
	}
}
void main2(){
	myin >> n;
	myin >> m;
	found = false;
	for(int i=0 ; i<n; i++){
		myin >> a[i].number >> a[i].val;
	}
	for(int i=0 ; i<m; i++){
		myin >> b[i].number >> b[i].val;
	}
	search(0,0,0);
	if(found)
	myout << best;
	else{
		myout << "0";
	}
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