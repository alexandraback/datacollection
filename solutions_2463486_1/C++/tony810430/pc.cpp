#include<stdio.h>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

int T,cnt;
long long A,B;
vector<long long> v;


bool ispalin(long long n)
{
	stack<int> s;
	queue<int> q;
	for( ; n > 0LL; n/=10 ){
		s.push(n%10);
		q.push(n%10);
	}
	while( !s.empty() && !q.empty() ){
		if( s.top() != q.front() )	return false;
		s.pop(); q.pop();
	}
	return true;
}

void dfs(int lv,int down,long long n)
{
	if( lv == down ){
		if( ispalin(n) && ispalin(n*n) )
			v.push_back(n*n);
	}else{
		for( int i = lv==0?1:0; i < 3; i++ )
			dfs(lv+1,down,n*10+i);
	}
}

int main()
{
	freopen("C-large-1.in","r",stdin);
	freopen("pc-tmp.out","w",stdout);


	v.push_back(1LL);
	v.push_back(4LL);
	v.push_back(9LL);
	for( int i = 2; i <= 8; i++ )
		dfs(0,i,0LL);
	scanf(" %d",&T);
	for( int cas = 1; cas <= T; cas++ ){
		scanf(" %I64d %I64d",&A,&B);
		cnt = 0;
		for( int i = 0; i < v.size(); i++ )
			if( A <= v[i] && v[i] <= B )
				cnt++;
		printf("Case #%d: %d\n",cas,cnt);
	}

	return 0;
}
