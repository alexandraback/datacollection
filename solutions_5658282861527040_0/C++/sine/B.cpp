//#include <algorithm>
//#include <cassert>
//#include <cstring>
//#include <iostream>
//#include <string>
//#include <vector>
//#include <cmath>
//
//using namespace std;
//
//int mylg(int x)
//{
//	int i = 0;
//	while(x)
//	{
//		i ++;
//		x = x << 1;
//	}
//	return i;
//}
//
//int main()
//{
//	int T, prob=1;
//	for (cin >> T; T--;)
//	{
//		cout << "Case #" << prob++ << ": ";
//
//		int a, b, k;
//		__int64 ans = 0;
//		cin >> a >> b >> k;
//		
//		a --; b --; k --;
//
//		int la, lb, lk, i;
//		char sa[35], sb[35], sk[35];
//		memset(sa, 0, sizeof(sa));
//		memset(sb, 0, sizeof(sb));
//		memset(sk, 0, sizeof(sk));
//		la = mylg(a);
//		lb = mylg(b);
//		lk = mylg(k);
//		int p;
//		if(la>lb) p=la;
//		else p=lb;
//		if(lk>p) p=lk;
//		i = p;
//		while(i --) 
//		{
//			if(a) 
//			{
//				sa[i] = a & 1;
//				a=a<<1;
//			}
//			else sa[i]='0';
//		}
//		i = p;
//		while(i --) 
//		{
//			if(b)
//			{
//				sb[i] = b & 1;
//				b=b<<1;
//			}
//			else sb[i]='0';
//		}
//		i = p;
//		while(i --) 
//		{
//			if(k) 
//			{
//				sk[i] = k & 1;
//				k=k<<1;
//			}
//			else sk[i]='0';
//		}
//
//		
//		
//		while(p--)
//		{
//			
//		}
//
//		cout << endl;
//	}
//
//	return 0;
//}

#include <stdio.h>

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B.out", "w", stdout);

	int t, cas;
	int a, b, k, i, j, ans;
	scanf("%d", &t);
	for(cas=1; cas<=t; cas++)
	{
		scanf("%d%d%d", &a, &b, &k);
		ans=0;
		for(i=0; i<a; i++)
			for(j=0; j<b; j++)
				if((i & j)<k) ans++;
		printf("Case #%d: %d\n", cas, ans);
	}

	return 0;
}