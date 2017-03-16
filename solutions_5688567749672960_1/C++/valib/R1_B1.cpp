// R1_B1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void num_vec(long long n, vector<int>& vec){
	long long tmp=n;
	while(tmp){
		vec.push_back(tmp%10);
		tmp/=10;
	}
}

vector<int> fun_w(){
	vector<int> vr;
	for(int i=0; i<14; i++){
		if(i==0) vr.push_back(1);
		else if(i==1) vr.push_back(10);
		else vr.push_back(vr[i-1]+pow(double(10), i/2)+pow(double(10),i-i/2)-1);
		//cout<<vr[i]<<endl;
	}
	return vr;
}

long long fun_ans(long long n){
	vector<int> vec;
	num_vec(n, vec);
	vector<int> v_tmp=fun_w();
	long long count=0;
	count+=v_tmp[vec.size()-1];
	long long tmp=0, i=vec.size()-1;
	//cout<<count<<endl;
	for(int j=0;j<vec.size()/2; j++,i--){
		tmp+=pow(double(10),j)*vec[i];
	}
	//cout<<tmp<<endl;
	if(!(tmp==1||tmp==0)) tmp++;
	for(int j=0;j<=i;j++){
		//cout<<vec[j]<<endl;
		tmp+=pow(double(10),j)*vec[j];
		//cout<<tmp<<endl;
	}
	//cout<<tmp<<endl;
	tmp--;
	count+=tmp;
	return count;
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("D://Practice//A-large.in", "r", stdin);
    freopen("D://Practice//A-large.out", "w", stdout);

	int cases=0;
	cin>>cases;
	for(int i=0; i<cases; i++){
		long long n;
		cin>>n;
		long long r1;
		if(n==1) r1=1;
		else if(n%10==0) r1 = fun_ans(n-1)+1;
		else r1=fun_ans(n);
		cout<<"Case #"<<i+1<<": "<<r1<<endl;
	}
	//cout<<fun_ans(199); 

	fclose(stdin);
	fclose(stdout);
	system("PAUSE");
	return 0;
}

