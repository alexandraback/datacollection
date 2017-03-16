#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	int nt = 0;
	while(++nt <= t)
	{
		
		long long int a,b;
		cin >>a >> b;
		long long int z = b-a+1;
		vector<int> A(z,0);
		int count = 0;
		for(int i = 0;i < z;i++)
		{
			if(A[i] == 0)
			{
				int ta = i+a;
				int tp = 0;
				int p = 1,nd = 1;
				while(p*10 < ta)
				{	
					p *= 10;
					nd += 1;
				}
				for(int j = 0;j < nd;j++)
				{
					ta = (ta/p)+(ta%p)*10;
					if(a <= ta && ta <= b)
					{
						if(A[ta-a] == 0)
						{
							tp += 1;
							A[ta-a] = 1;
						}
					}
				}
				count += (tp*(tp-1))/2;
			}
			
		}
		cout << "Case #" << nt << ": ";
		cout << count << endl;
	}
	return 0;
}
