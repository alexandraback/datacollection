//Utsav Jain
//
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <sstream>
#include <set>
#include <map>
#include <fstream>
#include <stdlib.h>
using namespace std;

#define FOR(i,a,b) for(int i= (int )a ; i < (int )b ; ++i) 
#define REV(i,a,b) for(int i= (int )a ; i >= (int)b ; --i)
#define REP(i,a) FOR(i,0,a)
#define INF 1000000000
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define present(container, element) (container.find(element) != container.end()) 
#define cpresent(container, element) (find(all(container),element) != container.end())
#define tr(container,it) for(typeof(container.begin()) it=container.begin(); it!=container.end(); it++)
#define minheap(t) priority_queue< t,vector<t>,greater<t> >
#define maxheap(t) priority_queue<t>
#define pb push_back
#define ii pair<int,int>
#define ss pair<string,string>
#define F first
#define S second
#define seive(n) vector<int> prime(n+1,1);for(int i=2;i*i<n;i++) if(prime[i])  for(int j=i+i;j<n;j+=i) prime[j]=0;
#define gcd __gcd

int main(int argc,char *argv[])
{
	int t;
	scanf("%d",&t) ;
	for (int r = 1; r <= t ; r++) {
		long long int p,q ;
		char c ;
		cin >> p >> c >> q ;
		long long int g = gcd(p,q) ;
		p = p/g ;
		q = q/g ;
		int l = log2((double)q) ;
		if (pow(2,l) != q) { 
			printf("Case #%d: impossible\n",r) ;
			continue ;
		}
		int cnt = 1; 
		while ( p < q/2) {
			q /= 2 ;
			cnt++ ;
		}
		printf("Case #%d: %d\n",r,cnt) ;
	}

	return 0;
}
