#include <iostream>
#include <vector>
#include <utility>
#include <map>
using namespace std;

int soln(int a)
{
     int count = 0;
     int k = a;
     vector<int> arr(10,0);
     while(true)
     {
	int b = k;
	while(b != 0)
	{
		int r = b%10;
		if(arr[r] == 0)
		{
		   count++;
		   arr[r] = 1;
		}
		b = b/10;
	}

	if(count == 10)
	   return k;
	k = k+a;
     }
}

int main() {
	int n,m;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		cin >> m;
		cout << "Case #" << i+1 << ": ";
		if(m == 0)
		{
		   cout << "INSOMNIA" << endl;
		   continue;
		}
		int ans = soln(m);
		cout << ans << endl;
		
	}
	return 0;
}
