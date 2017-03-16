#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull reverse(ull x)
{
	ull r = 0;
	while (x % 10 == 0)
		x /= 10;
	while (x)
	{
		r *= 10;
		r += x % 10;
		x /= 10;
	}
	return r;
}

ull f(ull x)
{
	if (x == 0)
		return 0;
	else
	{
		if ((reverse(x) < x) && (x % 10))
			return 1 + min(f(x- 1), f(reverse(x)));
		else
			return  1 + f(x - 1);
	}
}

int len(ull x)
{
	int ans = 0;
	while (x)
	{
		x /= 10;
		++ans;
	}
	return ans;
}

ull suf(int x)
{
	ull ans = 1;
	while (x)
	{
		--x;
		ans *= 10;
	}
	return ans;
}

int main()
{
	ofstream output;
	ifstream input;
	input.open("input.txt");
	output.open("output.txt");

	//	FILE * input;
	//	input = fopen("input.txt","r");

	int T;

	//	fread(&n, sizeof(int), 1, input);cout<<n<<endl; char cc=getchar();

	input >> T;// cout<<n<<endl;
	//cin >> T;

/*	ull N = 1000001;
	int* a = new int[N];
	//int* a = (int*)malloc(sizeof(int)*N);
	

	//cout << N;
	
	a[0] = 0;
	

	
	for (ull i = 1; i < N; ++i)
	{
		if ((reverse(i) < i) && (i%10))
			a[i] = 1 + min(a[i - 1], a[reverse(i)]);
		else
			a[i] = 1 + a[i - 1];
	}
	//system("pause");
*/
	ull x,y;
	ull ans;
	for (int t = 0; t < T; ++t)
	{
		input >> x;
		//cin >> x;
		y = x;
		//output << "Case #" << t + 1 << ": " << a[x] << endl;

		ans = 0;
		while (x)
		{
			if (x % 10 == 0)
			{
				x--;
				ans++;
			}

			if (len(x)>1){
				ans += (x%suf(len(x) / 2) - 1);
				x = x - (x%suf(len(x) / 2) - 1);
				if (x != reverse(x))
				{
					x = reverse(x);
					++ans;
				}
			}
			
			if (x == reverse(x))
			{
				if (x > 1)
				{
					x -= 2;
					ans+=2;
				}
				else
				{
					++ans;
					break;
				}
			}

		}

		//cout << a[y] << ' ' << ans<<endl;
		output << "Case #" << t + 1 << ": " << ans << endl;
		
	}

	input.close();
	output.close();
	//	system("pause");
	return 0;
}
