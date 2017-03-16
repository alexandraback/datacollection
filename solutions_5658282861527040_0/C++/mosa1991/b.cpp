#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int main()
{
	int T,A,B,K;
	cin >> T;
	for(int i=0;i<T;i++)
	{
		cin >> A >> B >> K;
		cout << "Case #" <<i+1 << ": ";
		int count = 0;
		for(int j=0;j<A;j++)
		{
		   for(int k=0;k<B;k++)
	           {
			int r= j&k;
			if(r<K)
			  count++;
                   }
		}
		cout << count << endl;
	}
	return 0;
}
