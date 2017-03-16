#include <iostream>
using namespace std;
int main()
{
int testcases;
int n;
int answer;
int flag;
int k;
int l;
char a[101][101];
cin >> testcases;
	for (int i=0;i<testcases;i++)
	{
	cin >> n;
	for (int j=0;j<n;j++)
	{
		cin >> a[j];
	}
	k=0;
	l=0;
	answer=0;
	flag=0;
	while (a[0][k]!='\0' || a[1][l]!='\0')
	{
		if (a[0][k]==a[1][l])
		{
		k++;
		l++;
		}
		else if (a[1][l]==a[1][l-1] && a[1][l-1]==a[0][k-1])
		{
		l++;
		answer++;
		}
		else if (a[0][k]==a[0][k-1] && a[0][k-1]==a[1][l-1])
		{
		k++;
		answer++;
		}
		else
		{
			flag=1;
			break;
		
		}
	
	}
	if (flag==0) cout <<"Case #"<<i+1<<": "<<answer<<"\n";
	else cout <<"Case #"<<i+1<<": Fegla Won\n";

	}




}
