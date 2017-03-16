#include <iostream>
#include <set>
using namespace std;

int A[1000];
int N;
multiset<int,greater<int> > S;
int test()
{
	int best = 100000000;
	int cur;
	for(int i=1;i<=1000;i++)
	{
		cur = 0;
		for(int j=0;j<N;j++)
			if(A[j]>i)
				cur += ((A[j]+i-1)/i)-1;
		if((cur+i) < best)
			best = cur+i;
	}
	return best;
}

int B[1000];
int brute(int n,int *a)
{
	int best = 1000000000;
	int x;
	bool isz;
	int K = n;
	for(int t=0;t<(1<<10);t++)
	{
		K = n;
		for(int i=0;i<K;i++)
			B[i] = a[i];
		for(int m=0;m<10;m++)
		{
			if(t&(1<<m))
			{
				for(int i=0;i<K;i++)
					if(B[i]>0)
						B[i]--;
			}
			else
			{
				int h = 0;
				for(int i=1;i<K;i++)
					if(B[i]>B[h])
						h = i;
				x = B[h];
				B[h] = x/2;
				B[K++] = x-(x/2);
			}
			isz = 1;
			for(int i=0;i<K;i++)
				if(B[i])
					isz = 0;
			if(isz)
				best = min(best,m+1);
		}
	}
	return best;
}

int main()
{
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\input.txt","r",stdin);
	freopen("C:\\Users\\Dhruv\\Desktop\\Programs\\Cpp Files\\output.txt","w",stdout);

	int T;
	cin >> T;
	for(int i=0;i<T;i++)
	{
		cin >> N;
		for(int j=0;j<N;j++)
			cin >> A[j];
		cout << "Case #" << i+1 << ": " << test() << "\n";
	}
}