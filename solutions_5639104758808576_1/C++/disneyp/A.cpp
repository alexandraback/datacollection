#include <iostream>
#include<string>
using namespace std;
int a[10010];
string s;
int main()
{
	freopen("A.in","r",stdin);
	freopen("A.txt","w",stdout);
	int t,n,now,total;
	int M;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> n >> s;
		M=0;
		for(int j=0;j<=n;j++) a[j]=s[j]-'0';
		now =a[0];
		total=0;
		for(int j=1;j<=n;j++)
		{
			if(now == 0)
			{
				total++;
			}
			now--;
			now = max(now, 0);
			now+=a[j];
		}
		cout << "Case #" << i+1 << ": " << total << endl;
		
	}
}