/*
 * A.cpp
 *
 *  Created on: 10 maj 2015
 *      Author: KAMIL
 */

#include <iostream>
#include <cstdlib>
#include <list>
#include <algorithm>
#include <cstddef>
#include <string>
#include <vector>
#include <sstream>
#include <utility>
using namespace std;

/**/
int main(){
	int t;
	cin>>t;
	int *r = new int[t], *c = new int[t], *w = new int[t];
	for(int i=0; i<t;i++)
		cin>>r[i]>>c[i]>>w[i];
	for(int i=0; i<t;i++){
		int rr=r[i];
		int cc=c[i];
		int ww=w[i];
		int moves = 0;
		int j;
		for(j=ww;j<cc;j+=ww){
			moves++;
		}
		if(cc==j)
			moves=rr*(moves+1)-1;
		else
			moves=rr*moves;
		moves++;//One bad guess
		moves+=ww-1;
		if(ww==1)
			moves = rr*cc;
		if(ww==cc)
			moves = rr+cc-1;
		cout<<"Case #"<<i+1<<": "<<moves<<endl;
	}
	return 0;
}


