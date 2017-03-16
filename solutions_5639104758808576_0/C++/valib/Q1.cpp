// Q1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int minimal_aud(int max_s, vector<int> &tmp){
	int result=0;
	int count=tmp[0];
	for(int i=1; i<max_s+1; i++){
		if(count<i){
			result+=i-count;
			count+=tmp[i]+(i-count);
		}
		else count+=tmp[i];
	}
	return result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("D://Practice//A-small-attempt1.in", "r", stdin);
    freopen("D://Practice//A-small-attempt1.out", "w", stdout);

	int cases=0;
	cin>>cases;
	for(int i=0; i<cases; i++){
		string str;
		int max_s;
		cin>>max_s>>str;
		vector<int> tmp;
		for(int j=0; j<max_s+1; j++) tmp.push_back(str[j]-'0');
		cout<<"Case #"<<i+1<<": "<<minimal_aud(max_s,tmp)<<endl;
	}

	fclose(stdin);
	fclose(stdout);
	system("PAUSE");
	return 0;
}

