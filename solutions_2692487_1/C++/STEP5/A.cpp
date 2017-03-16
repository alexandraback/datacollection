#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 123;

int arr[MAXN];
int A, N;

int main()
{
    ios_base::sync_with_stdio(0);

    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
	{
		cin>>A>>N;
		for(int i=0; i<N; i++)cin>>arr[i];
		sort(arr, arr+N);
		int minsol = N;
		int nowsize = A, nowop = 0;
		if(!(A==1 && arr[0]>=1))
		{
			for(int i=0; i<N; i++)
			{
				while(nowsize<=arr[i])
				{
					nowop++;
					nowsize += nowsize - 1;
				}
				nowsize += arr[i];
				minsol = min(minsol, nowop + (N-i-1));
			}
		}
		cout<<"Case #"<<t<<": "<<minsol<<endl;
	}

    return 0;
}
