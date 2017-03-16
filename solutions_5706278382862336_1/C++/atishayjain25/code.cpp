#include<iostream>
#include<stdio.h>
using namespace std;

int isPowerOfTwo(long long n)
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

long long gethcf(long long firstNum, long long secondNum)
{
    while (firstNum != 0 && secondNum != 0)
     {
         if (firstNum > secondNum)
         {
            firstNum %= secondNum;
         }
         else
         {
            secondNum %= firstNum;
         }
     }

     if (firstNum == 0)
     {
         return secondNum;
     }
     else
     {
         return firstNum;
     }
}

int main()
{
	int t;
	long long p,q, result, hcf;
	cin>>t;
	for(int cases=1; cases <= t; cases++)
	{
		scanf("%lld/%lld", &p, &q);
		hcf = gethcf(p,q);
		p = p/hcf;
		q = q/hcf;
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
