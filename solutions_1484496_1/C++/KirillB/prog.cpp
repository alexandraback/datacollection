#include <stdio.h>
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cassert>
#include <string.h>
using namespace std;
#pragma comment(linker, "/STACK:50000000")

typedef vector<int> vi; 
#define sz(a) int((a).size()) 
#define all(c) (c).begin(),(c).end() 

string problem_name = "C-large(1)";

void init(){
	freopen((problem_name+".in").c_str(),"rt",stdin);
	freopen((problem_name+".out").c_str(),"wt",stdout);
}


int mas[555];

int res[555];
int ok=0;
vi a,b;
int n;
void checkres()
{
	a.clear();
	b.clear();
	for (int i=0;i<n;i++)
		if (res[i]==1) a.push_back(i+1); else
		if (res[i]==2) b.push_back(i+1);

	return ;
}

void go(int cur, long long sa, long long sb)
{	
	if (ok) return ;
	if (sa==sb && sa)
	{
		ok=1;
		checkres();
		return ;
	}
	if (cur>=n) return ;
	res[cur]=1;
	go(cur+1,sa+mas[cur],sb);
	res[cur]=2;
	go(cur+1,sa,sb+mas[cur]);
	res[cur]=0;
	go(cur+1,sa,sb);

}


int main() {

	init();

	int tst;
	scanf("%d\n",&tst);
	//for (int i=0;i<20;i++) printf("%d ",1<<i);
	//printf("\n");
	for (int cas=1;cas<=tst;cas++)
	{
		
		scanf("%d",&n);
		for (int i=0;i<n;i++)
			scanf("%d",&mas[i]);
		n=20;
		random_shuffle(mas,mas+500);
		ok=0;
		go(0,0,0);
			
	
		printf("Case #%d:\n",cas);
		if (!ok) printf("Impossible\n"); else  {
			for (int i=0;i<sz(a);i++) printf("%d ",mas[a[i]-1]);
			printf("\n");
			for (int i=0;i<sz(b);i++) printf("%d ",mas[b[i]-1]);
			printf("\n");
		}
		
		
	}

	
	

	return 0;
}