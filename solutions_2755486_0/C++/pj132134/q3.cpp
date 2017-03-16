#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;


struct attack {
public:
	long long strength;
	long long left;
	long long right;
	long long day;
	
};

class mycomparison
{
public:
	bool operator() (attack lhs, attack rhs) const
	{
		return lhs.day > rhs.day;
	}
};  //ascending order


long long strength_wall[301][2];   ///strength_wall[0] is at x = -100   ////2d index 0 is for discrete 1 is for continuous
long long wall_copy[301][2]; 

bool cansucceed(long long left,long long right,long long s){
	bool answer = false;
	for (int i=left; i<right; i++) {
		if (strength_wall[i][0]<s || strength_wall[i][1]<s) {
			answer = true;
		}
	}
	for (int i=left; i<=right; i++) {
		wall_copy[i][0] = max(wall_copy[i][0],s); 
		if (i!=right) {
			wall_copy[i][1] = max(wall_copy[i][1],s);
		}
	}
	return answer;
}

void build_wall_fromcopy(){
	for (int i=0; i<=300; i++) {
		strength_wall[i][0] = wall_copy[i][0];
		strength_wall[i][1] = wall_copy[i][1];
	}
}

int main ()
{
	int no_testcases;
	int LEFT = -150;
	
	scanf("%d", &no_testcases);
	
	
	
	for (int i=0; i<no_testcases; i++) {
		//printf("i = %d\n",i+1);
		for (int i1=0; i1<=300; i1++) {
			strength_wall[i1][0] = 0;
			strength_wall[i1][1] = 0;
			wall_copy[i1][0] = 0;
			wall_copy[i1][1] = 0;
		}
		
		priority_queue <attack, vector<attack>, mycomparison> attacks;
		
		int no_tribes;
		scanf("%d",&no_tribes);
		
		for (int j=0; j<no_tribes; j++) {
			
			long long di,ni,wi,ei,si,del_di,del_pi,del_si;
			scanf("%lld",&di);
			scanf("%lld",&ni);
			scanf("%lld",&wi);
			scanf("%lld",&ei);
			scanf("%lld",&si);
			scanf("%lld",&del_di);
			scanf("%lld",&del_pi);
			scanf("%lld",&del_si);
			attack temp;
			temp.strength = si;
			temp.left = wi-LEFT;
			temp.right = ei-LEFT;
			temp.day = di;
			//printf("day, left,right,s = %lld, %lld, %lld, %lld\n",temp.day,temp.left,temp.right,temp.strength);
			attacks.push(temp);
			
			long day=di,strength=si,distance_from_start = 0;
			for (int k=1; k<ni; k++) {
				di += del_di;
				day+=del_di;
				strength += del_si;
				distance_from_start += del_pi;
				attack temp;
				temp.strength = strength;
				temp.left = wi+distance_from_start-LEFT;
				temp.right = ei+distance_from_start-LEFT;
				
				temp.day = day;
				//printf("day, left,right,s = %lld, %lld, %lld, %lld\n",temp.day,temp.left,temp.right,temp.strength);
				attacks.push(temp);
			}
		}
		///all attack information is stored
		//printf("Attacks stored\n");
//		printf("No. of attacks = %ld\n",attacks.size());
		int no_attacks_succ = 0;
		
		int day = 0;
		
		while (attacks.size()!=0) {
			
			attack temp = attacks.top();
			day = temp.day;
			
			
			while (day == temp.day) {  ///resolve all attacks on that day
				temp = attacks.top();
				
				if (day != temp.day) {
					break;
				}
				attacks.pop();
				//printf("day, left,right,s = %lld, %lld, %lld, %lld\n",temp.day,temp.left,temp.right,temp.strength);
				
				//for (int kk=100; kk<108; kk++) {
//					printf("%lld ",strength_wall[kk]);
//				}
//				printf("\n");
				
				if (cansucceed(temp.left,temp.right,temp.strength)) {  ///this function will not build the wall
					//printf("success\n");
					no_attacks_succ++;
				}
				if (attacks.size()==0) {
					break;
				}
				
			}
			build_wall_fromcopy();
			
		}
		
		printf("Case #%d: %d\n",i+1,no_attacks_succ);
		
		
	}
	
	return 0;
}