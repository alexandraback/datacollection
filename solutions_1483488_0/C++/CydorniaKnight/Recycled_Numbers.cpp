#include<iostream>
using namespace std;

int sum[2000001] = {0};
int ind[2000001] = {0};
int pow10[9];
int ptr;
int A,B;


void init()
{
	int i;
	pow10[0]=1;
	for(i=1;i<9;++i)
	{
		pow10[i] = pow10[i-1] * 10;
	}
	for(i=0;i<2000001;++i)
	{
		sum[i] = 0;
		ind[i] = 0;
	}
	ptr = 1;
}

int get_pairs_num(const int& n)
{
	return (n*(n-1))>>1;
}

int get_index(const int&n)
{
	if(ind[n]) return ind[n];

	int n_10 = 0;
	int lshift_10[10] = {0};
	int i,tmp;
	lshift_10[0] = n;
	while(lshift_10[n_10]){
		lshift_10[n_10+1] = lshift_10[n_10]/10;
		++n_10;
	}

	for(i=1;i<n_10;++i)
	{
		tmp = n%pow10[i]*pow10[n_10-i]+lshift_10[i];
		if(tmp>=A&&tmp<=B){
			if(ind[tmp]){
				ind[n] = ind[tmp];
				return ind[n];
			}
		}
	}

	ind[n] = ++ptr;

	return ind[n];
}

int solve(int a, int b)
{
	init();
	A=a;
	B=b;

	int ret=0,i,num,index;

	for(num=a;num<=b;++num)
	{
		++sum[get_index(num)];
	}

	for(i=1;i<=ptr;++i)
	{
		ret+=get_pairs_num(sum[i]);
	}

	return ret;
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);

	int T,ti,a,b;
	scanf("%d",&T);
	for(ti=1;ti<=T;++ti)
	{
		scanf("%d%d",&a,&b);
		printf("Case #%d: %d\n", ti, solve(a,b));
	}
	//system("pause");
	return 0;
}