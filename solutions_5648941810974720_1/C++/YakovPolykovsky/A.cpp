
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
	
	string s;cin>>s;
    int n=s.size();
	int data[300]={0,};
	for(int i=0;i<n;i++){
		data[s[i]]++;
	}
	int answer[10]={0,};
	
	answer[0]=data['Z'];
	data['E']-=data['Z'];
	data['R']-=data['Z'];
	data['O']-=data['Z'];
	data['Z']=0;
	
	answer[2]=data['W'];
	data['T']-=data['W'];
	data['O']-=data['W'];
	data['W']=0;
	
	answer[4]=data['U'];
	data['F']-=data['U'];
	data['R']-=data['U'];
	data['O']-=data['U'];
	data['U']=0;
	
	answer[5]=data['F'];
	data['I']-=data['F'];
	data['E']-=data['F'];
	data['V']-=data['F'];
	data['F']=0;
	
	answer[6]=data['X'];
	data['I']-=data['X'];
	data['S']-=data['X'];
	data['X']=0;
	
	answer[7]=data['S'];
	data['E']-=2*data['S'];
	data['V']-=data['S'];
	data['N']-=data['S'];
	data['S']=0;
	
	answer[1]=data['O'];
	data['N']-=data['O'];
	data['E']-=data['O'];
	data['O']=0;
	
	answer[3]=data['R'];
	data['E']-=2*data['R'];
	data['T']-=data['R'];
	data['H']-=data['R'];
	data['R']=0;
	
	answer[8]=data['G'];
	answer[9]=data['N']/2;
	
	for(int i=0;i<10;i++){
		for(int j=0;j<answer[i];j++){
			cout<<i;
		}
	}
	
	printf("\n");
  }
  return 0;
}
