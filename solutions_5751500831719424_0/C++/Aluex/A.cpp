#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char res[101];
char * simplify(char *s, int a[101][101], int index)
{
	//char res[101];
	int rescount = 0;
	res[0] = s[0]; a[0][index]=1;
	for(int i=1;i<strlen(s);++i)
		if(s[i-1]!=s[i])
		{
			res[++rescount] = s[i];
		}
		else ++a[rescount][index];
	res[++rescount] = 0;
	return res;
}
inline int abs(int x)
{
	return x<0?-x:x;
}
int main()
{
	int N;
	cin >> N;
	for(int delta=1;delta<=N;++delta)
	{
		cout << "Case #" << delta << ": ";
		char std[101], tmp[101];
		int n,a[101][101];
		memset(a, 0, sizeof(a));
		cin >> n;
		bool exitFlag = false;
		for(int i=0;i<n;++i)
		{
			cin >> tmp;
			char *p = simplify(tmp, a, i);
			if(i==0)
				strcpy(std, p);
			else
				if(strcmp(p, std))
				{
					exitFlag=true;
				}
		}
		if(exitFlag)
		{
			cout << "Fegla Won" << endl;
		}
		else
		{
			int currentAns=0;
			for(int k=0;k<strlen(std);++k)
			{
				sort(a[k], a[k]+n);
				int goal = a[k][n>>1];
				for(int i=0; i < n;++i)
					currentAns+=abs(a[k][i] - goal);
			}
			cout << currentAns << endl;
		}
	}
	return 0;

}