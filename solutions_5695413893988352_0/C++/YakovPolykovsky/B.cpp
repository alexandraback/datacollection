
//g++ -o A A.cpp

//g++ -Wl,--stack,16777216 -o A A.cpp


//#include <bits/stdc++.h>
//using namespace std;

#include <iostream>
using std::cin;
using std::cout;
using std::string;
using std::endl;

#include <algorithm> 
using std::sort;
using std::min;
using std::max;
using std::pair;
//pair <int,int> data[100];sort(data,data+100);

#include <math.h>
//sqrt(123.123)
//ceil(0.12)=1
//pow(x,2)=x^2

#include<cstdio>
//printf()

#include <map>
using std::map;
//map <string,int> x;

#include <stdlib.h>
//abs(-123);

#include <vector>
using std::vector;
//vector<int> x;
//x.push_back(0);x.push_back(1);cout<<x[0]<<' '<<x[1];
//x[0]=100;
//x.pop_back();
//vector<int> x(10);     ==>   x[0]==x[1]==...=x[9]==0 default
//x.push_back(100);      ==>   x[10]=100; 
//vector<int> x(10,3);   ==>   x[0]==x[1]==...==x[9]==3;
//vector<int> y(x);      ==>   y[0]==y[1]==...==y[9]==3;
//cout<<x.size();        ==>   10
//x.reserve(4)           ==>   (memory alloc 4) && !(size+=4 don't change size) 

#include <queue>
using std::queue;

#include <deque>
using std::deque;

/*
int gcd(int a, int b)
{ 
    \\O(log(max(a,b)))
    int t;
    while(b!=0)
    {
        t=a%b;
        a=b;
        b=t;
    }
    return a;
    
}
*/

/*
long long C(int x,int y)
{
    long long answer=1;
    int i;
    if(y>x-y)
    {
        y=x-y;
    }
    for(i=1;i<=y;i++)
    {
        answer*=(x+1-i);
        answer/=i;
    }
    return answer;
}

*/

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
	
	string s1,s2;
	cin>>s1>>s2;
	int n=s1.size();
	int num1=0;
	int num2=0;
	int best =10000;
	int cur;
	if (n==1){
		if(s1[0]=='?' && s2[0]=='?'){
			num1=num2=0;
		}
		else if(s1[0]=='?' && s2[0]!='?'){
			num1=num2=s2[0]-'0';
		}
		else if(s1[0]!='?' && s2[0]=='?'){
			num1=num2=s1[0]-'0';
		}
		else{
			num1=s1[0]-'0';
			num2=s2[0]-'0';
		}
		cout<<num1<<' '<<num2;
	}
	
	else if(n==3){
		int answer1[3]={-1,-1,-1};
		int answer2[3]={-1,-1,-1};
		for(int i=0;i<3;i++){
			if(s1[i]!='?'){
				answer1[i]=s1[i]-'0';
			}
			if(s2[i]!='?'){
				answer2[i]=s2[i]-'0';
			}
		}
		
		for(int a=0;a<10;a++){
			for(int b=0;b<10;b++){
				for(int c=0;c<10;c++){
					for(int d=0;d<10;d++){
						for(int e=0;e<10;e++){
							for(int f=0;f<10;f++){
								if(
									(a!=answer1[0] && answer1[0]!=-1)
									||(b!=answer1[1] && answer1[1]!=-1)
									||(c!=answer1[2] && answer1[2]!=-1)
									||(d!=answer2[0] && answer2[0]!=-1)
									||(e!=answer2[1] && answer2[1]!=-1)
									||(f!=answer2[2] && answer2[2]!=-1)
									){
										continue;
									}
								int n1=100*a+10*b+c;
								int n2=100*d+10*e+f;
								int cur=abs(n1-n2);
								if(cur<best){
									best =cur;
									num1=n1;
									num2=n2;
								}							
							}
						}
					}
				}			
			}
		}



		if(num1<10){
			cout<<0<<0<<num1<<' ';
		}else if(num1<100){
			cout<<0<<num1<<' ';
		}else{cout<<num1<<' ';}	
		
			if(num2<10){
			cout<<0<<0<<num2;
		}else if(num2<100){
			cout<<0<<num2;
		}else{cout<<num2;}	
		
	}
	
	else if(n==2){
		int answer1[2]={-1,-1};
		int answer2[2]={-1,-1};
		for(int i=0;i<2;i++){
			if(s1[i]!='?'){
				answer1[i]=s1[i]-'0';
			}
			if(s2[i]!='?'){
				answer2[i]=s2[i]-'0';
			}
		}
		
		for(int a=0;a<10;a++){
			for(int b=0;b<10;b++){
				
					for(int d=0;d<10;d++){
						for(int e=0;e<10;e++){
							
								if(
									(a!=answer1[0] && answer1[0]!=-1)
									||(b!=answer1[1] && answer1[1]!=-1)
									
									||(d!=answer2[0] && answer2[0]!=-1)
									||(e!=answer2[1] && answer2[1]!=-1)
									
									){
										continue;
									}
								int n1=10*a+b;
								int n2=10*d+e;
								int cur=abs(n1-n2);
								if(cur<best){
									best =cur;
									num1=n1;
									num2=n2;
								}							
							}
						
					
				}			
			}
		}
		if(num1<10){
			cout<<0<<num1<<' ';
		}else{cout<<num1<<' ';}	
		if(num2<10){
			cout<<0<<num2;
		}else{cout<<num2;}	

	}
	
	printf("\n");
  }
  return 0;
}
