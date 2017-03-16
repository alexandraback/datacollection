/*
 * APiox.cpp
 *
 *  Created on: 10 maj 2015
 *      Author: KAMIL
 */
#include <iostream>
#include <cstdlib>

using namespace std;

int solve(int rr, int cc, int ww){
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
		return moves;
}

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
		cout<<"Case #"<<i+1<<": "<<solve(rr, cc, ww)<<endl;
	}
	return 0;
}

