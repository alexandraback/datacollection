#include <cstdio>
#include <set>

using namespace std;

set<pair<int, int> >st;

const int po[]={1,10,100,1000,10000,100000,1000000,10000000};
int A,B;
inline int len(int a)
{
	if(a<10)	return 1;
	if(a<100)	return 2;
	if(a<1000)	return 3;
	if(a<10000)	return 4;
	if(a<100000)	return 5;
	if(a<1000000)	return 6;
	return 7;
}
inline void ok(int a)
{
	int l=len(a),b,mod;
	for(int i=1;i<l;i++)
	{
		mod=a%po[i];
		b=a/po[i]+mod*po[l-i];
		if(b>a && b<=B)	st.insert(make_pair(a,b));
	}
}
int main(void)
{
	int t;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++)
	{
		st.clear();
		scanf("%d%d",&A,&B);
		for(int i=A;i<B;i++)	ok(i);
		printf("Case #%d: %d\n",cas,st.size());
	}
	return 0;
}
