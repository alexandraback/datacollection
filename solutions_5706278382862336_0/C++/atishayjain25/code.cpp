#include<iostream>
#include<stdio.h>
using namespace std;

int isPowerOfTwo(int n)
{
  if (n == 0)
    return 0;
  while (n != 1)
  {
    if (n%2 != 0)
      return 0;
    n = n/2;
  }
  return 1;
}

int main()
{
	int t;
	int p,q, den,result;
	cin>>t;
	for(int cases=1; cases <= t; cases++)
	{
		scanf("%d/%d", &p, &q);
		if(! isPowerOfTwo(q))
		{
			cout<<"Case #"<<cases<<": impossible"<<endl;
			continue;
		}
		result = 0;
		while(p<q)
		{
			p*=2;
			result++;
		}
		cout<<"Case #"<<cases<<": "<<result<<endl;
	}
}
