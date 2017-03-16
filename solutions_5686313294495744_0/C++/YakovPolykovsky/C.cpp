
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
	
	int n;scanf("%d",&n);
	
	map <string,int> x1;
	map <string,int> x2;
	vector<string> first;
	vector<string> second;
	
	string data1[1000];
	string data2[1000];
	

	
	for(int i=0;i<n;i++){
		cin>>data1[i]>>data2[i];
		x1[data1[i]]++;
		x2[data2[i]]++;
		if(x1[data1[i]]==1){
			first.push_back(data1[i]);
		}
		if(x2[data2[i]]==1){
			second.push_back(data2[i]);
		}
	}
	int up1=first.size();
	int up2=second.size();
	
	
	int canTake=1;
	for(int i=0;i<n;i++){
		canTake*=2;
	}
	int answer=0;
	int take[16]={0,};
	for(int i=0;i<canTake;i++){
		int cur=i;
		int cur_answer=0;
		for(int j=0;j<n;j++){
			take[j]=cur%2;
			cur/=2;
			cur_answer+=take[j];
		}
		vector<string> t1;
		vector<string> t2;
		for(int j=0;j<n;j++){
			if(take[j]==0){
				int flag=0;
				for(int q=0;q<t1.size();q++){
					if(t1[q]==data1[j]){
						flag=1;
					}
				}
				if(flag==0){
					t1.push_back(data1[j]);
				}
				flag=0;
				for(int q=0;q<t2.size();q++){
					if(t2[q]==data2[j]){
						flag=1;
					}
				}
				if(flag==0){
					t2.push_back(data2[j]);
				}
			}
		}
		if(t1.size()==first.size() && t2.size()==second.size() && cur_answer>answer)answer=cur_answer;
		
		
	}
	cout<<answer;
	

	
	printf("\n");
  }
  return 0;
}
