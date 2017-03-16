#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

int a[3000];

int main()
{
  freopen("b.in","r",stdin);
  freopen("b.out","w",stdout);
  int t;
  cin >> t;
  for (int i =0;i < t; i++)
    {
      int n;
      cin >> n;
      memset(a,0,sizeof(a));
      for (int j = 0; j < 2*n-1; j++)
	for (int k = 0; k < n; k++)
	  {
	    int x;
	    cin >> x;
	    a[x] = a[x] + 1;
	  }
	  cout << "Case #" << i+1<< ":";
      for (int i = 0; i < 3000; i++)
	if (a[i] % 2 == 1) cout << " " << i;
      cout << endl;
    }
}
