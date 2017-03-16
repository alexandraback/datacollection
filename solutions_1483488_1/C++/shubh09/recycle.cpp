#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

#define FOR(i,a,b)				for (int i=a;i<b;i++)
#define s(n)					scanf("%d",&n)
#define p(n)					printf("%d\n",n)
#define sd(n)					int n;scanf("%d",&n)

typedef long long ll;

//m>n,m<B
//ans might need to be stored in ll

int tenp[8]={1,10,100,1000,10000,100000,1000000,10000000};

int countDigits(int n)
{
	int count=0;
	while(n)
	{
		n/=10;
		count++;
	}
	return count;
}

bool in(vector <int> a,int n)
{
	FOR(i,0,a.size()) if (n==a[i]) return true;
	return false;
}

int main()
{
	//TAKE CARE NOT TO COUNT THE SAME PAIR TWICE 
	//(IN THE INPUT CASE 1111,2222 THE PAIR (1212,2121) GETS COUNTED TWICE.
	int t;
	s(t);
	int i;
	int a,b;
	ll count;
	vector <int> tarr;
	FOR(i,0,t)
	{
		count=0;
		s(a);s(b);
		int d=countDigits(a);//=countDigits(b), as given in input specifications
		FOR(k,a,b)//iterating for n
		{
			tarr.clear();
			FOR(j,1,d)//iterating for number of digits to be transferred to the front
			{
				int t1=tenp[j];
				int t2=k/t1;
				int t3=k%t1;//to be transferred
				//check if t3 contains leading zeroes
				if (countDigits(t3)==j)
				{
					int tm=(t3*(tenp[d-j]))+t2;
					if (tm>k && tm<=b && !in(tarr,tm)) {tarr.push_back(tm);/*printf("%d %d\n",k,tm);*/count++;}
				}
			}
		}
		printf("Case #%d: %lld\n",i+1,count);
	}
	return 0;
}
