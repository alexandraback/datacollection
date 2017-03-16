#include <iostream>
#include <set>
using namespace std;

int t,a,b,num,num2,tedad,tul,tavan[100];
set<int> tr;
int main()
{
	cin >> t;
	tavan[0]=1;
	for (int i=1;i<=8;i++)
		tavan[i]=tavan[i-1]*10;
	for (int i=1;i<=t;i++)
	{
		tedad=0;
		cin >> a >> b;
		for (int j=a;j<=b;j++)
		{
			tr.clear();
			num=j;
			tul=0;
			while (num>0)
			{
				tul++;
				num/=10;
			}
			num=j;
			num2=num;
			for (int k=1;k<tul;k++)
			{
				int num3=num2;
				num2=(num3/10)+(tavan[tul-1]*(num3%10));
			//	cout << num2 << ' ' << num << endl;
				if (num2<j && (num2>=a && num2<=b))
				{
					if (tr.find(num2)==tr.end())
						tedad++;
					tr.insert(num2);
				}
			}
		}
		cout <<"Case #"<<i<<": "<< tedad << endl;
	}
	return 0;
}
