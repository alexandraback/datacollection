#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <cstdio>
#include <cmath>

using namespace std;
int v[135];
int ch[11]={};

int main(){
	int p,a,b,c,n,m,k,i,j,T,r;
	cin >> T;
	for (p = 1; p <= T; p++)
	{
		cin >> r >> n >> m >> k;
		printf("Case #%d:\n", p);
		for (i = 0; i < r; i++)
		{
			for (j = 0; j < k; j++)
				cin>>ch[j];
			for (j = 0;j<130;j++)
				v[j]=0;
			for (a=2;a<=m;a++)
				for (b=2;b<=m;b++)
					for (c=2;c<=m;c++)
					{
						v[1]=1;
						v[a]=1;
						v[b]=1;
						v[c]=1;
						v[a*b]=1;
						v[b*c]=1;
						v[a*c]=1;
						v[a*b*c]=1;
						for (j = 0;j < k;j++)
							if (v[ch[j]] == 0)
								break;
						if (j == k)
						{
							cout<<a<<b<<c;
							a=b=c=m+1;
						}
					}
			cout << endl;
		}

	}
	return 0;
}

