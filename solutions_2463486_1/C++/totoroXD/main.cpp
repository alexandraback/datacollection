#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<string>
#include<utility>
using namespace std;
vector<pair<long long,long long> > pals;
int cnt;
long long a,b;
bool cmp(pair<long long,long long> a, pair<long long, long long> b){
	return a.first<b.first;
}
bool is_pal(long long k){
	int dig[22],len;
	for(len=0; 0<k; len++,k/=10){
		dig[len]=k%10;
	}
	for(int i=0; i<len; i++)
		if(dig[i] != dig[len-1-i])return 0;
	return 1;
}
void pre(){
	for(long long i=1; i<=10000000; i++){
		if(is_pal(i) && is_pal(i*i)){

			pals.push_back(make_pair(i*i,i));
			//printf("%I64d %I64d\n",i*i,i);
		}
	}
}
void input()
{
	cin>>a>>b;
}
void solve()
{

	cout<<"Case #"<<cnt+1<<": "<<upper_bound(pals.begin(), pals.end(), make_pair(b,b),cmp)-lower_bound(pals.begin(), pals.end(), make_pair(a,0),cmp)<<endl;
}
int main ()
{
	freopen("C-large-1.in","r",stdin);
	freopen("xddd.out","w",stdout);
	pre();
	int zz;
	scanf("%d",&zz);
	for(cnt=0; cnt<zz; cnt++){
		input();
		solve();
	}
}
/*
3 3
2 1 2
1 1 1
2 1 2
5 5
2 2 2 2 2
2 1 1 1 2
2 1 2 1 2
2 1 1 1 2
2 2 2 2 2
3 9
2 1 2 2 2 2 2 1 2
2 2 2 2 2 2 2 1 2
2 2 1 1 2 2 2 2 1
6 8
2 2 2 2 2 2 1 1
2 2 2 2 2 2 1 1
1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1
2 2 2 2 2 2 1 1
1 1 1 1 1 1 1 1
6 8
1 2 1 1 2 2 2 2
2 2 2 2 1 2 1 2
1 2 2 2 2 2 2 2
2 2 1 2 2 2 2 2
2 2 2 2 2 1 2 2
2 2 2 2 1 2 2 2
3 9
2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 2 2 2
2 2 2 2 2 2 1 2 2
*/
