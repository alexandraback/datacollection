#include <iostream>
#include <vector>
using namespace std;

int num[20];

int main()
{
	int T;
	cin >> T;
	for(int c=1;c<=T;c++)
	{
		vector<int> *v = new vector<int>[2000000];
		printf("Case #%d:\n",c);
		int N;
		int a,b;
		bool has = false;
		cin >> N;
		for(int i=0;i<N;i++)
			cin >> num[i];
		for(int i=0;i<=1048575;i++)
		{
			int sum = 0;
			int temp = i;
			for(int j=0;j<20;j++)
			{
				if(temp%2)
					sum += num[j];
				temp/=2;
			}
			v[sum].push_back(i);
			if(v[sum].size()>1)
			{
				a = v[sum][0];
				b = v[sum][1];
				has = true;
				goto end;
			}
		}
end:
		if(has)
		{
			bool bg = true;
			for(int j=0;j<20;j++)
			{
				if(a%2)
				{
					if(bg) bg = false;
					else putchar(' ');
					printf("%d",num[j]);
				}
				a/=2;
			}
			putchar(10);
			bg = true;
			for(int j=0;j<20;j++)
			{
				if(b%2)
				{
					if(bg) bg = false;
					else putchar(' ');
					printf("%d",num[j]);
				}
				b/=2;
			}
			putchar(10);
		}
		else
			printf("Impossible\n");
		delete[] v;
	}
}
