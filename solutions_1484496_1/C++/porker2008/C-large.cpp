#include <iostream>
#include <map>
using namespace std;

long long num[501];

long long pow2[40];

int main()
{
	pow2[0] = 1;
	for(int i=1;i<40;i++)
		pow2[i] = pow2[i-1]<<1;
	int T;
	cin >> T;
	for(int c=1;c<=T;c++)
	{
		map<long long, long long> v;
		printf("Case #%d:\n",c);
		int N;
		long long a,b;
		bool has = false;
		cin >> N;
		for(int i=0;i<N;i++)
			cin >> num[i];
		N = 20;
		for(long long i=0;i<pow2[N];i++)
		{
			long long sum = 0;
			long long temp = i;
			for(int j=0;j<N;j++)
			{
				if(temp%2)
					sum += num[j];
				temp/=2;
			}
			if(v.find(sum)==v.end())
				v[sum] = i;
			else
			{
				a = v[sum];
				b = i;
				has = true;
				goto end;
			}
		}
end:
		if(has)
		{
			bool bg = true;
			for(int j=0;j<N;j++)
			{
				if(a%2)
				{
					if(bg) bg = false;
					else putchar(' ');
					cout << num[j];
				}
				a/=2;
			}
			putchar(10);
			bg = true;
			for(int j=0;j<N;j++)
			{
				if(b%2)
				{
					if(bg) bg = false;
					else putchar(' ');
					cout << num[j];
				}
				b/=2;
			}
			putchar(10);
		}
		else
			printf("Impossible\n");
	}
}
