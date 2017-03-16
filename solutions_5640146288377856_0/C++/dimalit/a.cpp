/*
 * b.cpp
 *
 *  Created on: May 10, 2015
 *      Author: dimalit
 */

#include <iostream>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <sstream>
using namespace std;

namespace A{

int R,C,W;

int one_test(){
	cin >> R >> C >> W;

	int x;

	for(int i=1;;i++){
		if(i*W > C){
			x = i-1;
			break;
		}
	}

	return x*R;
}

int main(){
	int T;
	cin >> T;

	for(int t=0; t<T; t++){
		cout << "Case #" << (t+1) << ": " << one_test() << endl;
	}

	return 0;
}// main

}

int main(){
	freopen("a_small.in", "rb", stdin);
	freopen("a_small.out", "wb", stdout);
	return A::main();
	//B::test_ceiling();
	return 0;
}
