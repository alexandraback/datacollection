#include<iostream>
#include<string.h>
#include<vector>
#include<stdio.h>
#include<algorithm>

using namespace std;
int A, N;
int arr[105];
int v[105];
long long solve(long long start, long long a, int idx)
{
	int ans = 0x3f3f3f3f;
	long long t = a+start-1;
	bool f = false;
	int i;
	for(i = idx; i < N; ++i)
	{
		if(t > arr[i])
		{
			t+=arr[i];
			f = true;
		}
		else if(t != start)
		{
			ans = solve(t, t, i)+1;	
			break;
		}
		else
			break;
	}
	if(i == N)
		return 1;
	return min(ans,N-idx);
	
}
int main()
{
	freopen("D:\\ACM\\zj\\codejam\\A-large.in","r",stdin);
    freopen("D:\\ACM\\zj\\codejam\\1out.txt","w",stdout);
    
    int T;
    cin>>T;
    long long ans;
    int caseid = 1;
    while(T--)
    {
    	cin>>A>>N;
    	long long t = A;
    	memset(v, 0, sizeof(v));
    	for(int i = 0; i < N; ++i)
    	{
    		cin>>arr[i];
    	}
    	sort(arr, arr+N);
    	int idx;
		for(idx = 0; idx < N; ++idx)
		{
			if(arr[idx] < t)
				t+=arr[idx];
			else
				break;
		}
		if(idx == N)
			ans = 0;
		else
		{
			ans = solve(t, t, idx);
		}
		cout<<"Case #"<<caseid<<": "<<ans<<endl;
		caseid++;
    }
	return 0;
}
