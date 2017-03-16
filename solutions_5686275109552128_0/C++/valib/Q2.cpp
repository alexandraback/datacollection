// Q2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int minimal_min(int D, vector<int>& P){
	sort(P.begin(), P.end(), greater<int>());
	int result=P[0];
	for(int thre=P[0]; thre>=2; thre--){
		int tmp=0;
		for(int i=0; i<D&&P[i]>thre; i++){
			tmp+=P[i]/thre;
			if(P[i]%thre==0) tmp--;
		}
		tmp+=thre;
		if(tmp<result) result=tmp;
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("D://Practice//B-small-attempt0.in", "r", stdin);
    freopen("D://Practice//B-small-attempt0.out", "w", stdout);

	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++){
		int D;
		cin>>D;
		vector<int> P(D);
		for(int j=0; j<D; j++) cin>>P[j];
		cout<<"Case #"<<i+1<<": "<<minimal_min(D,P)<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

