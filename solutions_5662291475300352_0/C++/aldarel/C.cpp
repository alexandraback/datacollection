/*
 * C.cpp
 *
 *  Created on: 2 maj 2015
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

int main(){
	int tests;
	cin>>tests;
	int *n= new int[tests], **d = new int*[tests], **h = new int*[tests], **m = new int*[tests];
	for(int i=0; i<tests; i++){
		cin>>n[i];
		d[i] = new int[n[i]];
		h[i] = new int[n[i]];
		m[i] = new int[n[i]];
		for(int j=0; j<n[i]; j++)
			cin>>d[i][j]>>h[i][j]>>m[i][j];
	}
	for(int i=0; i<tests; i++){
		int nn=n[i];
		int *dd = new int[nn];
		int *hh = new int[nn];
		int *mm = new int[nn];
		for(int j=0; j<nn; j++){
			dd[j]=d[i][j];
			hh[j]=h[i][j];
			mm[j]=m[i][j];
		}
		int result;
		if(nn==1){
			int firstPos = dd[0];
			int firstMin = mm[0];
			if(hh[0]==1){
				result = 0;
				cout<<"Case #"<<i+1<<": "<<result<<endl;
				continue;
			}
			if(hh[0]==2){
				int secondPos = dd[0];
				int secondMin = mm[0]+1;
				/*if(secondMin==0){
					result = 1;
					cout<<"Case #"<<i+1<<": "<<result<<endl;
					continue;
				}else{*/
					result = 0;
					cout<<"Case #"<<i+1<<": "<<result<<endl;
					continue;

			}
		}
		if(nn==2){
			int firstPos = dd[0];
			int firstMin = mm[0];
			int secondPos = dd[1];
			int secondMin = mm[1];
			if(dd[0]>dd[1]){
				firstPos = dd[1];
				firstMin = mm[1];
				secondPos = dd[0];
				secondMin = mm[0];
			}//first pos first on the circle
			if(firstMin>secondMin){//first is slower
				int firstToGo=360-firstPos;
				int secondToGo=720-secondPos;
				if((firstToGo*firstMin)>=(secondToGo*secondMin)){
					result = 1;
					cout<<"Case #"<<i+1<<": "<<result<<endl;
					continue;
				}
				else{
					result = 0;
					cout<<"Case #"<<i+1<<": "<<result<<endl;
					continue;
				}
			}
			if(firstMin==secondMin){
				result = 0;
				cout<<"Case #"<<i+1<<": "<<result<<endl;
				continue;
			}
			if(firstMin<secondMin){//first is Faster
				int firstToGo=720-firstPos;
				int secondToGo=360-secondPos;
				if((secondToGo*secondMin)>=(firstToGo*firstMin)){
					result = 1;
					cout<<"Case #"<<i+1<<": "<<result<<endl;
					continue;
				}else{
					result = 0;
					cout<<"Case #"<<i+1<<": "<<result<<endl;
					continue;
				}
			}

		}
		cout<<"Case #"<<i+1<<": "<<(-1)<<endl;
		continue;
		/*cout<<nn<<endl;
		for(int j=0; j<nn; j++)
			cout<<dd[j]<<" "<<hh[j]<<" "<<mm[j]<<endl;*/
	}

	return 0;
}


