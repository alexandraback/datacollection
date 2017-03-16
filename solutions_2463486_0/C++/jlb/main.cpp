#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctype.h>
#include <string.h>

using namespace std;

bool test(int num){
	vector<int> strNum;
	while(num!=0){
		strNum.push_back(num%10);
		num/=10;
	}
	bool flag=true;
	int i,j;
	for(i=0,j=strNum.size()-1;i<j;i++,j--){
		if(strNum[i]!=strNum[j]){
			flag=false;
			break;
		}
	}
	return flag;
}

int main(int argc,char** argv){
	int caseNum;
	int low,high;
	int pairNum;
	cin>>caseNum;
	for(int num=0;num<caseNum;num++){
		cin>>low>>high;
		int sqLow,sqHigh;
		sqLow=ceil(sqrt(low));
		sqHigh=floor(sqrt(high));
		pairNum=0;
		for(int i=sqLow;i<sqHigh+1;i++){
			if(test(i)&&test(i*i)){
				pairNum++;
			}
		}
		cout<<"Case #"<<num+1<<": "<<pairNum<<endl;
	}
	return 0;
}