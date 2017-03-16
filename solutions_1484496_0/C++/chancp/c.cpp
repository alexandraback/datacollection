
//Problem C. 

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <cmath>

using namespace std;

int n;
int s[20];
int c[20];
int found;
int level;
int set1[20];
int set2[20];
int i1,i2;
int sum1,sum2;

void compute(){
	if (sum1==sum2) {
		found=1;
		return;
	}
	if (level>=n) return;
	if (abs(sum1-sum2)>c[level]) return;

	set1[i1]=s[level]; sum1+=s[level]; level++; i1++;
	compute();
	if (found) return;
	level--; i1--; sum1-=s[level]; 

	set2[i2]=s[level]; sum2+=s[level]; level++; i2++;
	compute();
	if (found) return;
	level--; i2--; sum2-=s[level]; 

	level++;
	compute();
	level--;
}

int main(){
	int t;
	int i,j,k;

	cin>>t;
	for (i=0;i<t;i++){
		cin>>n;
		for (j=0;j<n;j++) cin>>s[j];

		sort(s,s+n);
		c[n-1]=s[n-1];
		for (j=n-2;j>=0;j--) c[j]=c[j+1]+s[j];
		
		found=0;
		level=1;
		i1=1;i2=0;
		sum1=s[0];sum2=0;
		set1[0]=s[0];

		compute();

		if (!found) cout<<"Case #"<<(i+1)<<": Impossible"<<endl;
		else {
			cout<<"Case #"<<(i+1)<<":"<<endl;
			for (j=0;j<i1;j++) {
				if (j>0) cout<<" ";
				cout<<set1[j];
			}
			cout<<endl;
			for (j=0;j<i2;j++) {
				if (j>0) cout<<" ";
				cout<<set2[j];
			}
			cout<<endl;

			//printf("sum1: %d sum2: %d\n",sum1,sum2);
		}
	}
}
