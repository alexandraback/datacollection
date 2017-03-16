#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 1005
void RI(){}
template<typename... T>
void RI( int& head, T&... tail ) {
    scanf("%d",&head);
    RI(tail...);
}
using namespace std;
typedef long long LL;
int t,n;
char in[M];
string sub(int l,int r)
{
	if(l>r) return "";

	string re = "";
	REP(i,l,r) re+=in[i];
	return re;
}
string ans(int l,int r)
{
	if(l>r) return "";
	int pos=l;
	REP(i,l+1,r) if(in[i]>=in[pos]) pos=i;

	return in[pos] + ans(l,pos-1) + sub(pos+1,r);
}
int main()
{
	string out;
	RI(t);
	REP(tt,1,t)
	{
		scanf("%s", in+1);
		n = strlen(in+1);
		
		out = ans(1,n);
		printf("Case #%d: %s\n",tt,out.c_str());
	}
	return 0;
}

