// codejam.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include<iostream>
#include<string>
#include<fstream>
#include<math.h>
using namespace std;

bool a[2000001];

int len(int num){
	int count=1;
	while(num>=10){
		num/=10;
		count++;
	}
	return count;
}
int change(int num ,int slen,int len){
	int a,b;
	a=(num/((int)pow(10.0f,len-slen)));
	b=(num%((int)pow(10.0f,len-slen)));
	b*=pow(10.0f,slen);
	return a+b;
}

int main(){
	ifstream in;
	in.open("in");
	ofstream out;
	out.open("out");
	int t;
	in>>t;
	for(int j=0;j<t;j++){
		int n,m,count=0;
		in>>n>>m;
		for(int i=n;i<=m;i++) a[i]=false;
		for(int i=n;i<=m;i++){
			if(true){
				a[i]=true;
				int tempLen=len(i);
				int tempcount=0;
				for(int k=1;k<tempLen;k++){
					int tempk=change(i,k,tempLen);
					if(tempk>i&&tempk<=m&&!a[tempk]){
						a[tempk]=true;
						tempcount++;
					}
				}
				tempcount=tempcount*(tempcount+1)/2;
				count+=tempcount;
			}
		}
		out<<"Case #"<<j+1<<": "<<count<<endl;
	}
	in.close();
	out.close();
	return 0;
}