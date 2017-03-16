#include<iostream>
#include<string>
#include<queue>

using namespace std;
int N;

struct ss{
	int d,n,w,e,s,dd,dp,ds;
	bool operator<(const ss& X) const
	{
		return d > X.d;
	}
};
int a[1000000];
int nxt[1000000];
int ok(ss st)
{
	for(int i=st.w;i<st.e;i++)
	{
		if( a[i] < st.s )
			return 1;
	}
	return 0;
}
int main()
{
	freopen("in.txt","rt",stdin);
	freopen("out_C.txt","wt",stdout);
	int TC;
	scanf("%d",&TC);
	for(int tc=1;tc<=TC;tc++)
	{
		cin>>N;
		ss st;
		priority_queue< ss > q;
		memset(a,0,sizeof(a));
		memset(nxt,0,sizeof(nxt));
		for(int i=0;i<N;i++)
		{
			cin >> st.d >> st.n >> st.w >> st.e >> st.s >> st.dd >> st.dp >> st.ds;
			st.w = st.w*2 + 10000;
			st.e = st.e*2 +10000;
			st.dp*=2;
			q.push( st );
		}
		int cd = 0;
		int res = 0;
		while( q.size() )
		{

			st = q.top();

			q.pop();
			if(st.d != cd )
				memcpy(a,nxt,sizeof(a));
			cd = st.d;
			res += ok(st);
			for(int i=st.w;i<st.e;i++)
			{
				nxt[i] = max(nxt[i],st.s);
			}
			st.n--;
			st.d += st.dd;
			st.w += st.dp;
			st.e += st.dp;
			st.s += st.ds;
			if( st.n > 0 )
				q.push(st);
		}
		cout<<"Case #"<<tc<<": "<<res<<endl;
	}
	return 0;
}