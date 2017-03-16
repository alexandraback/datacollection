#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

const long long MAX = 100000;
char chs[MAX];

int map[5][5] = 
{
	0, 0, 0, 0, 0,
	0, 1, 2, 3, 4,
	0, 2, -1, 4, -3,
	0, 3, -4, -1, 2,
	0, 4, 3, -2, -1
};

int c2d( char x)
{
	if(x=='1')
	{
		return 1;
	}
	return x-'i'+2;
}


bool solve()
{
	long long L, X;
	cin>>L>>X;
	scanf("%s", chs);
	int pre = 1;
	int val = 1;
	int flag = 0;
	if(X>12)
		X = X%4+8;
	for( long long i=0; i<X; ++i)
	{
		for( long long j=0; j<L; ++j)
		{
			val = map[val][c2d(chs[j])];
			if(val<0)
			{
				val = abs(val);
				pre *= -1;
			}

			if(flag==0&&val==2&&pre==1)
			{
				flag=1;
			}
			else if(flag==1&&val==4&&pre==1)
			{
				flag =2;
			}
			else if(i==X-1&&j==L-1&&flag==2&&val==1&&pre==-1)
			{
				flag =3;
			}
		}
	}
	return flag==3;
}

int main()
{
	//freopen("sample.txt", "r", stdin);
	//freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-large.in", "r", stdin);
	FILE * p; p = fopen ("result_large.txt","w"); 
	int N;
	cin>>N;
	for( int i=0; i<N; ++i)
	{
		bool flag = solve();
		fprintf(p, "Case #%d: %s\n", i+1, flag?"YES":"NO");
	}
	return 0;
}