#include <iostream>
#include <ctime>
#include <cstdio>
#include <algorithm>
#include <cstring>//memsetÐèÒª
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <deque>
#include <stack>
typedef long long ll;
using namespace std;
#define M 100000
ll pri[]={1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002};
int pp=39;
int ss[50];
bool check(ll x){
	int ps=0;
	while (x)
	{
		ss[ps++]=x%10;
		x/=10;
	}
	for (int i=0;i<ps/2;i++)
	{
		if (ss[i]!=ss[ps-1-i])
		{
			return false;
		}
	}
	return true;
}
void pre(){
	pp=0;
	for (ll i=1;i<=10000000;i++)
	{
		if (check(i)&&check(i*i))
		{
			pri[pp++]=i;
		}
	}
}
int find(double t){
	int l=0,r=pp,mid;
	while (l<r)
	{
		mid=(l+r)/2;
		if (pri[mid]>t)
		{
			r=mid;
		}else l=mid+1;
	}
	return l-1;
}
int find2(double t){
	int l=0,r=pp,mid;
	while (l<r)
	{
		mid=(l+r)/2;
		if (pri[mid]>=t)
		{
			r=mid;
		}else l=mid+1;
	}
	return l-1;
}
int main(){
	int tt,cas=1;
	scanf("%d",&tt);
	while (tt--)
	{
		double a,b;
		scanf("%lf%lf",&a,&b);
		double sa=sqrt(a),sb=sqrt(b);
		int l=find2(sa),r=find(sb);
		printf("Case #%d: %d\n",cas++,r-l);
	}
	return 0;
}