#include <iostream>
using namespace std;

long long m[4][4] = {{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};
long long d[4][4] = {{1,1,1,1},{1,-1,1,-1},{1,-1,-1,1},{1,1,-1,-1}};

long long test(long long L,long long X,long long *s)
{
	long long tot = 0;
	long long sign = 1;
	for(long long i=0;i<L;i++)
	{
		sign *= d[tot][s[i]];
		tot = m[tot][s[i]];
	}
	long long fBlock = -1;
	long long fLoc = -1;
	long long ct = 0;
	long long cs = 1;
	for(long long i=0;i<min(4LL,X);i++)
	{
		for(long long j=0;j<L;j++)
		{
			cs *= d[ct][s[j]];
			ct = m[ct][s[j]];
			if((cs==1)&&(ct==1))
			{
				fBlock = i;
				fLoc = j;
				break;
			}
		}
		if(fBlock != -1)
			break;
	}
	if(fBlock == -1)
		return 0;
	long long sBlock = -1;
	long long sLoc = -1;
	ct = 0, cs = 1;
	for(long long i=fBlock;i<min(fBlock+5LL,X);i++)
	{
		for(long long j=0;j<L;j++)
		{
			if((fBlock==i)&&(j<=fLoc)) continue;
			cs *= d[ct][s[j]];
			ct = m[ct][s[j]];
			if((cs==1)&&(ct==2))
			{
				sBlock = i;
				sLoc = j;
				break;
			}
		}
		if(sBlock != -1)
			break;
	}
	if(sBlock == -1)
		return 0;
	ct = 0,cs = 1;
	for(long long i=0;i<(X%4);i++)
	{
		cs *= sign;
		cs *= d[ct][tot];
		ct = m[ct][tot];
	}
	if((cs==-1)&&(ct==0))
		return 1;
	return 0;
}

long long A[10000];
char s[10000];

int main()
{
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\input.txt","r",stdin);
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\output.txt","w",stdout);
	ios::sync_with_stdio(0);
	long long T;
	cin >> T;
	long long L,X;
	for(long long i=0;i<T;i++)
	{
		cin >> L >> X >> s;
		for(long long j=0;j<L;j++)
		{
			if(s[j]=='i') A[j] = 1;
			if(s[j]=='j') A[j] = 2;
			if(s[j]=='k') A[j] = 3;
		}
		if(test(L,X,A))
			cout << "Case #" << i+1 << ": YES\n";
		else
			cout << "Case #" << i+1 << ": NO\n";
	}
}