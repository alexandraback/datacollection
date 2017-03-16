#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 

using namespace std;


int main(){
	freopen("A-small-practice.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int i,j;
	int num,num1,num2;
	int t,n,s,p;
	int *ti;
	int maxNum=0;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		maxNum=0;
		scanf("%d",&n);
		scanf("%d",&s);
		scanf("%d",&p);
		ti=new int[n];
		for(j=0;j<n;j++)
		{
			scanf("%d",&num);
			ti[j]=num;
			num1=ti[j]/3;
			num2=ti[j]%3;
			if(num1>=p)
				maxNum++;
			else if(num2==0 && s>0 && (p-num1)==1 && num>0)
			{	maxNum++;s--;}
			else if(num2==1 && (p-num1)==1)
			{	maxNum++;	 }
			else if(num2==2 && (p-num1)==1)
			{	maxNum++;	 }
			else if(num2==2 && s>0 &&(p-num1)==2)
			{	maxNum++;s--;}
			else
				;
		}
		printf("Case #%d: %d\n", i,maxNum);
		delete[] ti;
	}
	return 0;
}






















