//#pragma warning(disable:4996)
//#include<stdio.h>
//#include<algorithm>
//#include<vector>
//#include<time.h>
//#include<iostream>
//#include<string>
//using namespace std;
//string s[100];
//int a[10];
//int n;
//int visit[10];
//int v[255];
//int count2;
//void dfs(int x)
//{
//	if (x == n + 1)
//	{
//		memset(v, 0, sizeof(v));
//		bool f = true;
//		char ch= 'X';
//		memset(v, 0, sizeof(v));
//		for (int i = 1; i < n; ++i)
//		{
//
//			string st;
//			st = s[a[i]];
//			for (int j = 0; j < st.length(); ++j)
//			{
//				if (st[j] == ch)continue;
//				else 
//				{
//					if (v[st[j]]) return;
//					(v[st[j]] = true);
//					ch = st[j];
//				}
//			}
//		}
//		count2++;
//		return;
//		
//	}
//	for (int i = 0; i < n; ++i)
//	{
//		if (!visit[i])
//		{
//			visit[i] = true;
//			a[x] = i;
//			dfs(x + 1);
//			a[x] = 0;
//			visit[i] = false;
//		}
//	}
//}
//int main()
//{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	int T;
//	scanf("%d", &T);
//	for (int z = 0; z < T; ++z)
//	{
//		count2 = 0;
//		cin >> n;
//		for (int i = 0; i < n; ++i)
//			cin >> s[i];
//		dfs(1);
//		cout <<"Case #"<<z<<": "<< count2<<endl;
//
//		
//	}
//}