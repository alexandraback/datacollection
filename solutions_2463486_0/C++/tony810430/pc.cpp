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

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("pc.out","w",stdout);

	for( long long i = 1LL; i <= 10000LL; i++ )
		if( ispalin(i) && ispalin(i*i) )
			v.push_back(i*i);
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
