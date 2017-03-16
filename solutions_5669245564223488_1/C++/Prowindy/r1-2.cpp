

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <string.h>
        
using namespace std;

const int MOD = 1000000007;

int checkType(string str, char c){
	int n = str.length();
	int i;
	for (i = 0;i < n; i++)
	if (str[i]!=c)
		break;
	if (i==n) return 2;
	if (i==0){
		// can be 0
		for (i = n-1;i >=0;i --)
			if (str[i]!=c)
				break;
		if (i==n-1) {
			for (i = 0;i <n; i++)
				if (str[i]==c) return 3;
			return 4;
		}
		for ( ; i>=0 ;i--)
			if (str[i]==c)
				return -1;
		return 0;
	}else {
		//can be 1
		for ( ; i< n; i++)
		if (str[i]==c)
			return -1;
		return 1;
	}
}
int father[200];
int getf(int x){
	return father[x]==x?x:(father[x]  = getf(father[x]));
}
int Union(int a, int b){
	if (a==b) return 1;
	int fa = getf(a), fb = getf(b);
	if (fa==fb) return 0;
	father[fa] = fb;
	return 1;
}
int arr[200];
string str[200];
int N;
int main(){
	int tt ,i;
	scanf("%d",&tt);
	for (int tcas = 1; tcas <= tt; tcas ++){
		scanf("%d",&N);
		for (i = 0;i < N; i++)
			cin>>str[i];
		long long ans = 1;
		for ( i =0;i < N;i ++)
			father[i] = i;
		int fail  =0;
		for (char c = 'a'; c<='z'&&!fail; c++){
			int A = -1, B = -1, C = 0;
			int one = -1;
			int have_cnt = 0;
			for (i = 0;i < N;i ++)
			{
				int tmp = checkType(str[i], c);
				if (tmp==-1) fail = 1;
				if (tmp==3) have_cnt ++;
				if (tmp==0){
					if (A==-1) A = i;
					else fail = 1;
					one = i;
				}
				if (tmp==2){
					arr[C++] = i;
					one = i;
				}
				if (tmp==1){
					if (B==-1) B = i;
					else fail = 1;
					one = i;
				}
			}
			if (have_cnt>1) fail = 1;
			if (one!=-1&&have_cnt>0) fail = 1;
			if (one!=-1){
				for (i = 1;i <=C;i ++)
					ans*=i, ans%=MOD;
				for (i = 0;i < C;i ++)
					if (!Union(arr[i], one))
						fail = 1;
				if (A!=-1) {
					if (!Union(one, A))
						fail = 1;
				}
				if (B!=-1) {
					if (!Union(one, B))
						fail = 1;
				}
			}
		}
		int tot = 0;
		int mark[200];
		memset(mark,0,sizeof(mark));
		for (i = 0; i< N; i++)
			mark[getf(i)] = 1;
		for (i = 0;i <N; i++)
		if (mark[i])
			tot++;
		for (i = 1;i <= tot; i++){
			ans*=i , ans%=MOD;
		}
		printf("Case #%d: ", tcas);
		if (fail) ans = 0;
		cout<<ans<<endl;
	}
}
			
			
			
			
			
			
			
			
			
			
			
			
			