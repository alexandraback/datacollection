#include <iostream>
#include <vector>
#include <algorithm>

#pragma comment(linker, "/STACK:16777216")

using namespace std;

int my_min(int a, int b){return (a<b)?a:b;}

int get(const vector<int> & a, int A, int i)
{
	while(true)
	{
		if(i==a.size())
			return 0;
		else if((A==1) && (a[i]>=1))
			return a.size()-i;
		else if(A>a[i])
			A += a[i++];
		else
			return my_min(1+get(a, A+A-1, i), a.size()-i);
	}
}

int solve()
{
	int A, N;
	cin>>A>>N;
	vector<int> a(N);
	for(int i=0; i<N; ++i)
		cin>>a[i];
	sort(a.begin(), a.end());

	return get(a, A, 0);
}

int main()
{
	int Tests;
	cin>>Tests;

	for(int test_case = 1; test_case<=Tests; ++test_case)
	{
		cout<<"Case	#"<<test_case<<": "<<solve()<<endl;
	}

	return 0;
}