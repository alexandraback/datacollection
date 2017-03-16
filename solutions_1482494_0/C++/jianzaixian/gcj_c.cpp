//============================================================================
// Name        : gcj_A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "string.h"
#include "stdio.h"
#include "queue"
#define N 1005
#define M 40
using namespace std;
int flag1[N],flag2[N];
struct point {
	int id;
	int star;
	int anther;
	friend bool operator<(point n1, point n2) {
		if(n1.star!=n2.star)
		return n1.star > n2.star;
		else return n1.anther<n2.anther;
	}
};

struct pp{
	int id;
	int star;
	friend bool operator<(pp n1, pp n2) {
			return n1.star > n2.star;
		}
};

int main() {
	//freopen("A-small-attempt0.in","r",stdin);
	freopen("a.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		int n;
		scanf("%d", &n);
		int tempA, tempB;
		priority_queue<point> first;
		priority_queue<pp>second;
		point temp;
		pp tttt;
		memset(flag1, 0, sizeof(flag1));
		memset(flag2, 0, sizeof(flag2));
		for (int j = 0; j < n; ++j) {
			scanf("%d%d", &tempA, &tempB);
			temp.id = j;
			temp.star = tempA;
			temp.anther=tempB;
			first.push(temp);
			tttt.id = j;
			tttt.star = tempB;
			second.push(tttt);
		}
		int num=0;
		int now = 0;
		while(true){
			bool flag =false;
			pp tt = second.top();
			if(tt.star<=now){
				if(flag1[tt.id]){
					now+=1;
				}else{
					now+=2;
				}
				num++;
				flag2[tt.id]=1;
				flag=true;
				second.pop();
				if(second.empty()){
					break;
				}
			}else{
				if(first.empty()){
					break;
				}
				point sqh=first.top();
				while(!first.empty()&&flag2[sqh.id]){
					first.pop();
					sqh = first.top();
				}
				if(first.empty())break;
				if(sqh.star<=now){
					now+=1;
					flag =true;
					flag1[sqh.id]=1;
					num++;
					first.pop();
				}

			}
			if(!flag)break;
		}
		if(!second.empty()){
			printf("Case #%d: Too Bad\n", i + 1);
		}else{
		printf("Case #%d: %d\n", i + 1, num);
		}
	}
	return 0;
}
