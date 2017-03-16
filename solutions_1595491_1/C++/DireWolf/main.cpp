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

#define upBound 3*wanted - 2
#define downBound (wanted != 1 ? (3*wanted - 4):1)

int main(){
	ofstream myout("B-large.out");
	ifstream myin("B-large.in");
	int t,suprise,wanted,n,point,count,resoult;
	myin >> t;
	for(int i=0 ; i<t ; i++){
		myout << "Case #" << i+1 << ": ";
		myin >> n >> suprise >> wanted;
		count = 0; resoult = 0;
		for(int j = 0 ; j < n ; j++){
			myin >> point;
			if(point >= upBound){ resoult++;}
			else if(point >= downBound){
				if(count < suprise) {resoult ++; count++;}
			}
		}
		myout << resoult;
		myout << endl;
	}
}