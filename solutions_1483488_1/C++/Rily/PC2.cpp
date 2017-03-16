#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

int digitlimit[11]={0,
1,10,100,1000,10000,
100000,1000000,10000000,100000000,1000000000};

int testdigit(int num){
	int digit=0;
	for(int i=0;i<11;i++){
		if(num>=digitlimit[i])digit=i;
		else break;
	}
	return digit;
}

int circ(int num,int len){
	return (num%10)*digitlimit[len]+int(num/10);
}

int countdiff(int num,int len,int ub){
	int tmp=num;
	vector<int> v;
	for(int i=1;i<len;i++){
		int shiftnum=circ(tmp,len);
		tmp=shiftnum;
		if((shiftnum>num)&&(shiftnum<=ub)){
			v.push_back(shiftnum);
			// printf("shiftnum %d\n",shiftnum);
		}
	}
	sort(v.begin(),v.end());
	vector<int>::iterator iter = unique(v.begin(), v.end());
	v.erase(iter, v.end());

	return v.size();
}

int mycount(int start,int end){
	int count=0;
	int currlen=testdigit(start);
	int currlimit;
	currlimit=digitlimit[currlen];

	for(int i=start;i<=end;i++){
		if(i%currlimit==0){
			currlen=testdigit(start);
			currlimit=digitlimit[currlen];
		}
		// cout << "currlimit" << currlimit << endl;

		count+=countdiff(i,currlen,end);
	}
	return count;
}

void run(){
	int N;
	char str[10000];
	int start,end;
	int result;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		printf("Case #%d: ",i+1);
		scanf("%d %d",&start,&end);
		result=mycount(start,end);
		printf("%d\n",result);
	}
}


int main(int argc,char** argv){
	run();
	return 0;
}
