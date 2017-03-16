#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

struct level1{
	int value;
	int id;
	int tmp;
}star1[1000];

struct level2{
	int value;
	int id;
}star2[1000];

bool tag[1000];

int cmp1(level1 &a, level1 &b){
	if(a.value == b.value) return a.tmp>b.tmp;
	return a.value<b.value;
}

int cmp2(level2 &a, level2 &b){
	return a.value<b.value;
}

int main(int argc, char** argv){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B.out","w",stdout);
	int T;
	scanf("%d",&T);
	int i,j,n;
	int result;
	int earn;
	bool bad;
	int s1, s2;
	for(i=1; i<=T; i++){
		scanf("%d",&n);
		for(j=0; j<n; j++){
			scanf("%d%d",&star1[j].value,&star2[j].value);
			star1[j].tmp = star2[j].value;
			star1[j].id = star2[j].id = j;
			tag[j] = false;
		}
		sort(star1, star1+n,cmp1);
		sort(star2, star2+n,cmp2);
		earn = 0;
		result = 0;
		bad = false;
		s1 = s2 = 0;
		while(true){
			if(s2 == n){
				break;
			}
			if(star2[s2].value <= earn){
				if(tag[star2[s2].id] == false){
					earn += 2;
					tag[star2[s2].id] = true;
				}
				else{
					earn++;
				}
				result++;
				s2++;
			}
			else if(star1[s1].value <= earn){
				if(tag[star1[s1].id] == true){
					s1++;
				}
				else{
					tag[star1[s1].id] = true;
					result++;
					earn++;
					s1++;
				}
			}
			else{
				bad = true;
				break;
			}
		}
		if(bad){
			printf("Case #%d: Too Bad\n",i);
		}
		else{
			printf("Case #%d: %d\n",i,result);
		}

	}
	return 0;
}