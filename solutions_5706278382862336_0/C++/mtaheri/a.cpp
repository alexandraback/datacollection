#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<List>
#include<vector>
#include<queue>
#include<set>
#include<math.h>

using namespace std;
#define pii pair<int,int>
#define pid pair<int,double>
#define pqType int

class PQComp
{public:
	bool operator()(pqType& a,pqType& b)
	{return a>b;}
};

template<class type>
int comp(const void* pa,const void*pb)
{
	type a=*(type*)pa;type b=*(type*)pb;
	if(a<b)return -1;
	if(a>b)return 1;
	return 0;
}

_int64 bmm(_int64 a,_int64 b)
{
	if(b==0)return a;
	return bmm(b,a%b);
}

int main()
{
	fstream fin("a.in",fstream::in);
	fstream fout("a.out",fstream::out);
	cin.rdbuf(fin.rdbuf());
	cout.rdbuf(fout.rdbuf());

	int T;
	cin>>T;
	for(int t=0;t<T;t++)
	{
		cout<<"Case #"<<t+1<<": ";
		_int64 P,Q;
		char c;
		cin>>P>>c>>Q;
		if(P>Q)
		{
			cout<<"impossible"<<endl;
			continue;
		}
		_int64 cc=bmm(P,Q);
		P/=cc;
		Q/=cc;
		int l=0;
		int minl=1000000;
		while(Q>1)
		{
			if(Q%2!=0)
			{
				cout<<"impossible"<<endl;
				break;
			}
			Q/=2;
			l++;
			if(l>40)
			{
				cout<<"impossible"<<endl;
				break;
			}
			if(P>=Q)
			{
				minl=min(minl,l);
				P-=Q;
			}
		}
		if(P==1)
			minl=min(minl,l+1);
		if(Q==1)
			cout<<minl<<endl;
	}
	return 0;
}