#include "iostream"
#include "set"

using namespace std;

unsigned int count_recycle(int a,int b);
unsigned int count_one(int n,int a,int b);

set<int> pair;

int len2 = 1;
int main()
{
	freopen("1.out", "w", stdout);
	int i,j,k,t,n,id = 1,a,b;
	unsigned int res = 0;
	
	cin >> t;
	while(t--)
	{
		cin >>a >> b;
		
		int tmp = a;
		len2 = 1;
		while(tmp != 0)
		{
			len2 = len2 * 10;
			tmp = tmp / 10;
		}
		
		res= count_recycle(a,b);
		
		cout <<"Case #" << id++ <<": " << res / 2 << endl;
	}
}


unsigned int count_recycle(int a,int b)
{
	int i,j;
	unsigned int total = 0;
	for(i = a; i <= b; i++)
	{
		total += count_one(i,a,b);
	}
	
	return total;
}

void check(int a,int b)
{
	if(a % 1000 * 10 + a / 1000 != b && a % 100 * 100 + a / 100 != b && a % 10 * 1000 + a /10 != b)
		cout << a <<" " << b << endl;
}

unsigned int count_one(int n,int a,int b)
{
	int len = 1,t = n,i;
	unsigned int count = 0;

	len = len2 / 10;
	int len1 = 10;

	int stack[100] ;
	stack[count ++] = n;
	while(len != 1)
	{
		if(n % len == 0)
			break;
		if(n % len != 0)
		{
			t = ( n % len ) * len1 + n / len;

			if(t >= a && t <= b )
			{
				for(i = 0;i < count ;i++)
					if(stack[i] == t)
						break;
				if(i == count)
					stack[count ++] = t;	
			}
		}
		len = len / 10;
		len1 = len1 * 10; 
	}
	
	return count - 1;
}
