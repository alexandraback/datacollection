#include<iostream>
#include<map>
#include<math.h>
#include<vector>
#include<string>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef vector<int>::iterator iv;
typedef map<string,int>::iterator im;
#define rep(i, n) for(i=0; i<n; i++)

struct dd
{
	int a, b;
	bool f;
};


int rt;
bool cmp(dd q, dd w)
{
	int a = (rt>=q.b) + (!q.f&&rt>=q.a);
	int b = (rt>=w.b) + (!w.f&&rt>=w.a);
	if(a != b)
		return a>b;
	a = q.f? q.b:q.a;
	b = w.f? w.b:w.a;
	if(q.f != w.f)
		return q.f > w.f;
	if(!q.f)
		return q.b > w.b;
	return a < b;
}

int main()
{
	int t, c;
	dd a, v[1000];
	cin >> t;
	rep(c, t)
	{
		rt=0;
		int n, i, j;
		cin >> n;
		rep(i, n)
		{
			cin >> v[i].a >> v[i].b;
			v[i].f=0;
		}
		int ans=0, kk=0;
		for(i=0; i<n;)
		{
			sort(v+i, v+n, cmp);
			a=v[i];
			//cout<<v[i].a << ' ' << v[i].b << ' ' << v[i].f << endl;
			if(rt >= a.b)
				ans++, rt+=(a.f ? 1:2), i++;
			else if(!a.f && rt >= a.a)
				ans++, rt++, v[i].f=1;
			else
			{
				kk=1;
				break;
			}
		}
		if(!kk)
			printf("Case #%d: %d\n", c+1, ans);
		else
			printf("Case #%d: Too Bad\n", c+1);
	}
}
