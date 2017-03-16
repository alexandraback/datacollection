#include<iostream>
#include <utility>
#include <vector>
#include <cmath>

long long dp[1000001];


using namespace std;

void takeInputAndProcess()
{
	int N;
	cin >> N;
	cout << dp[N];
}

int rev(int N)
{
     int r = 0;
     while(N!=0)
     {
	int p = N%10;
	r = (r*10)+p;
	N = N/10;
     }
    return r;
}
bool digcount(int r, int i)
{
	int p=0;
	while(r !=0)
	{
		r = r/10;
		p++;
	}
	while(i !=0)
	{
		i = i/10;
		p--;
	}
	return p == 0;
}
void process()
{
	for(int i=0;i<1000001;i++)
		dp[i] = 0;
	dp[1] = 1;
	
	for(int i=2;i<1000001;i++)
	{
	      int r = rev(i);
	      if(r < i && digcount(r,i))
		dp[i] = min(dp[r],dp[i-1])+1;
	      else
		dp[i] = dp[i-1]+1;
	}
}

int main()
{
	int T;
	cin >> T;
	process();
	for(int i=1;i<=T;i++)
	{
	   cout << "Case #" << i << ": " ;
            takeInputAndProcess();
            cout << endl;
	}
	return 0;
}
