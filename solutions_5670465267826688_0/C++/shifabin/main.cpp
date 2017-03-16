#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int c[5][5] = { { 0, 0, 0, 0, 0 }, { 0,1,2,3,4 }, { 0,2,-1,4,-3 }, { 0,3,-4,-1,2 }, { 0,4,3,-2,-1 } };
long long n, m;
int a[50000];
int cat(int x)
{
	if (x == 1) 1;
	if (x == -1 && m % 2 == 1) return -1;
	if (x == -1 && m % 2 == 0) return 1;
	if (m % 2 == 1) return 0;
	if ((m / 2) % 2 == 1) return -1;
	return 1;
}
int abs(int x)
{
    if (x>0) return x;
    return -x;
}
int dog(int x, int y)
{
	if (x*y < 0) return -c[abs(x)][abs(y)];
	return c[abs(x)][abs(y)];
}
int _dog1(int x, int y)
{
	for (int i = -4; i <= 4; i++)
	{
		if (dog(x, i) == y) return i;
	}
	return 0;
}
int _dog2(int x, int y)
{
	for (int i = -4; i <= 4; i++)
	{
		if (dog(i, x) == y) return i;
	}
	return 0;
}
long long pig1()
{
	int t1, t2;
	long long ans,i,j;
	t1 = 1;
	for (i = 1; i <= n; i++)
		t1 = dog(t1, a[i]);
	t2 = 1;
	ans = n*m;
	for (i = 1; i <= n; i++)
	{
		t2 = dog(t2, a[i]);
		if (t2 == 2) return i;
		int t3 = _dog1(t2, t1);
		int t4 = dog(t3, t2);
		int tmp = t2;
		for (j = 1; j <= 16; j++)
		{
			tmp = dog(tmp, t4);
			if (tmp == 2 && j*n + i < ans) ans = j*n + i;
		}
	}
	return ans;
}
long long pig2()
{

	int t1, t2;
	long long ans,i,j;
	t1 = 1;
	for (i = 1; i <= n; i++)
		t1 = dog(t1, a[i]);
	t2 = 1;
	ans =-1;
	for (i = n; i >= 1; i--)
	{
		t2 = dog( a[i],t2);
		if (t2 == 4) return i;
		int t3 = _dog2(t2, t1);
		int t4 = dog(t2, t3);
		int tmp = t2;
		for (j = 1; j <= 16; j++)
		{
			tmp = dog(tmp, t4);
			if (tmp == 4 && n*m - (j*n + n-i) > ans) ans = n*m - (j*n + n-i);
		}
	}
	 return ans;
}
int main()
{
	freopen("333.txt", "r", stdin);
	freopen("222.txt", "w", stdout);
	int tt,t1,i;
	char x;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ii++)
	{
		scanf("%lld%lld", &n, &m);
		scanf("%c", &x);
		t1 = 1;
		for (i = 1; i <= n; i++)
		{
			scanf("%c", &x);
			if (x == 'i') a[i] = 2;
			if (x == 'j') a[i] = 3;
			if (x == 'k') a[i] = 4;
			t1 = dog(t1, a[i]);
		}
		t1 = cat(t1);
		if (t1 != -1)
		{
			printf("Case #%d: NO\n", ii);
			continue;
		}
		int t2=n*m+1,t3=0;
		t1=1;
		for(i=1;i<=n*m;i++)
        {
            t1=dog(t1,a[(i+n-1)%n+1]);
            if (t1==2)
            {
                t2=i;
                break;
            }
        }
        t1=1;
        for(i=n*m;i>=1;i--)
        {
            t1=dog(a[(i+n-1)%n+1],t1);
            if (t1==4)
            {
                t3=i;
                break;
            }
        }
		if (t2 + 1 < t3) printf("Case #%d: YES\n",ii);
		else
			printf("Case #%d: NO\n", ii);
	}
	return 0;
}
