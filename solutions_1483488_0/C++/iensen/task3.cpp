#include<iostream>
#include<unordered_set>

using namespace std;
bool was[2000005][7];
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
	
	freopen("D:\\gcj\\C-small-attempt0.in","r",stdin);
	freopen("D:\\gcj\\C-small-attempt0.out","w",stdout);
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
			__int64 count1=cur.size();
			pairs+=count1*(count1-1)/2;
		}
		cout << "Case #" << test+1 << ": " << pairs << endl;
	}
}