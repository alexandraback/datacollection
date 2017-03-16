//============================================================================
// Name        : CODE_JAM.cpp
// Author      : Tran Quang Trung
// Version     :
// Copyright   : Copy Right by Tran Quang Trung
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
using namespace std;
#define cin fin
#define cout fout
ifstream fin("in.txt");
ofstream fout("out.txt");
int main() {
	long long T;
	long long r, t;
	long long sum, cnt, rs;
	cin>>T;
	for(int count=1;count<=T;count++){
		cin>>r>>t;
		sum=0;cnt=1;rs=0;
		sum+=(r+cnt)*(r+cnt)-(r+cnt-1)*(r+cnt-1);
		while(sum<=t){
			rs++;
			cnt+=2;
			sum+=(r+cnt)*(r+cnt)-(r+cnt-1)*(r+cnt-1);
		}
		cout<<"Case #"<<count<<": "<<rs<<endl;
	}
}
