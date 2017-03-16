#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream fi("input.txt");
	ofstream fo("output.txt");
	
	int t;
	fi>>t;
	for (int i=0; i<t; i++)
	{
		int a, b;
		fi>>a>>b;
		
		int r = 0;
		bool *c = new bool[b-a+1];
		for (int j=0; j<b-a+1; j++)
		{
			c[j] = false;
		}
		
		// find the length of a
		int l = 1;
		int aa = a;
		while (aa / 10 != 0)
		{
			l *= 10;
			aa /= 10;
		}
		
		for (int n=a; n<b; n++)
		{
			if (!c[n - a])
			{
				int sr = 0;
				int ld = n % 10;
				int fd = n / 10;

				//cout<<"n = "<<n<<endl;
				int ll = l;
				while (ll / 10 != 0)
				{
					int m = fd + l * ld;
					if (ld != 0)
					{
						if (m == n)
						{
							break;
						}
													
						if ((a <= m) && (m <= b))
						{
							sr++;
							c[m-a] = true;
							//cout<<'('<<n<<", "<<m<<')'<<endl;
							//fo<<'('<<n<<", "<<m<<')'<<endl;
						}
					}
					ld = m % 10;
					fd = m / 10;
					ll /= 10;
				}		
				r += (sr + 1) * sr / 2;
			}
		}
		fo<<"Case #"<<i+1<<": "<<r<<endl;
		cout<<"Case #"<<i+1<<": "<<r<<endl;
	}
	
	return 0;
}