#include <iostream>
using namespace std;

int m[4][4] = {{0,1,2,3},{1,0,3,2},{2,3,0,1},{3,2,1,0}};
int d[4][4] = {{1,1,1,1},{1,-1,1,-1},{1,-1,-1,1},{1,1,-1,-1}};

int test(int L,int X,int *s)
{
	int tot = 0;
	int sign = 1;
	for(int i=0;i<L;i++)
	{
		sign *= d[tot][s[i]];
		tot = m[tot][s[i]];
	}
	int fBlock = -1;
	int fLoc = -1;
	int ct = 0;
	int cs = 1;
	for(int i=0;i<min(4,X);i++)
	{
		for(int j=0;j<L;j++)
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
	int sBlock = -1;
	int sLoc = -1;
	ct = 0, cs = 1;
	for(int i=fBlock;i<min(fBlock+5,X);i++)
	{
		for(int j=0;j<L;j++)
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
	for(int i=0;i<(X%4);i++)
	{
		cs *= sign;
		cs *= d[ct][tot];
		ct = m[ct][tot];
	}
	if((cs==-1)&&(ct==0))
		return 1;
	return 0;
}

int A[10000];
char s[10000];

int main()
{
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\input.txt","r",stdin);
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\output.txt","w",stdout);
	ios::sync_with_stdio(0);
	int T;
	cin >> T;
	int L,X;
	for(int i=0;i<T;i++)
	{
		cin >> L >> X >> s;
		for(int i=0;i<L;i++)
		{
			if(s[i]=='i') A[i] = 1;
			if(s[i]=='j') A[i] = 2;
			if(s[i]=='k') A[i] = 3;
		}
		if(test(L,X,A))
			cout << "Case #" << i+1 << ": YES\n";
		else
			cout << "Case #" << i+1 << ": NO\n";
	}
}