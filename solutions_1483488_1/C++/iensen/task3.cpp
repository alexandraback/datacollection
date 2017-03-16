#include<iostream>
#include<unordered_set>

using namespace std;
bool was[2000005][8];
int count_digits(int a)
{
	int ans=0;
	while(a>0)
	{
		++ans;
		a/=10;
	}
	return ans;
}
int main()
{
	
	freopen("D:\\gcj\\C-large.in","r",stdin);
	freopen("D:\\gcj\\C-large.out","w",stdout);
	int tests;
	int ten_powers[10];
	ten_powers[0]=1;
	for(int i=1;i<10;i++)
	{
		ten_powers[i]=ten_powers[i-1]*10;
	}
	cin>>tests;
	for(int test=0;test<tests;test++)
	{
		__int64 pairs=0;
		int A,B;
		memset(was,0,sizeof(was));
		cin>>A>>B;
		for(int i=A;i<=B;i++)
		{
			int digits=count_digits(i);
			if(was[i][digits])continue;
			unordered_set<int> cur;
			int number=i;
			for(int j=0;j<digits;j++)
			{
				if(number>=A && number<=B)
				{
				 cur.insert(number);
				 was[number][digits]=true;
				}
				number=number/10+number%10*ten_powers[digits-1];
			}
			int sc[11];
			int scidx=0;
			for(unordered_set<int>::iterator it=cur.begin();it!=cur.end();it++)
			{
				sc[scidx++]=*it;
			}
			for(int i1=0;i1<scidx;i1++)
			{
				for(int j1=i1+1;j1<scidx;j1++)
				{
					if(sc[i1]>=ten_powers[digits-1] || sc[j1]>=ten_powers[digits-1])++pairs;
				}
			}
		}
		cout << "Case #" << test+1 << ": " << pairs << endl;
	}
}