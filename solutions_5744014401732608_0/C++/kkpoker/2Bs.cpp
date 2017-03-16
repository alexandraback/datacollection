#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int N =55;
long long b,m;

/*
2 12
3 123 13 
4 1234 124 134 14  2(n-2)
5 12345 1235 1245 1345 125 135 145 15//8   
6 123456 12346 12356 12456 13456 1236 1246 1256 1346 1356 1456 126 136 146 156 16//16 ¿³12ÊÇ8 ¿³13ÊÇ4  
*/
int map[N][N];

int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("B-small-attempt2.out","w",stdout); 
	int T;
	cin>>T;
	for(int xx=1;xx<=T;xx++)
	{
		cin>>b>>m;
		memset(map,0,sizeof(map));
		printf("Case #%d: ",xx);
		long long p=(1<<(b-2));
		if(m>p ) {cout<<"IMPOSSIBLE\n";continue;}
		else 
			cout<<"POSSIBLE\n";
		
		for(int i=1;i<=b;i++)
		for(int j=i+1;j<=b;j++)
			map[i][j]=1;
		long long tt=p-m;
		//cout<<tt<<endl;
		for(int i=0;i<=b-2;i++)
		{
			int x=1<<i;
			if(x&tt)
				map[1][b-i-1]=0;
		}

		for(int i=1;i<=b;i++)
		{
		for(int j=1;j<=b;j++)
			cout<<map[i][j];
		cout<<endl;}
		
	}
	return 0;
}
/*
100
5 4
2 1
4 20
2 12
6 2
6 1
5 15
5 7
3 2
3 15
6 3
5 8
2 13
5 1
3 11
2 9
6 11
2 16
5 16
3 13
5 6
2 8
3 17
6 12
6 9
6 13
2 17
5 19
3 16
3 4
2 4
4 7
5 5
3 6
5 17
6 16
4 4
6 5
4 5
3 1
4 3
6 6
2 10
6 19
5 10
4 11
6 14
2 11
5 20
3 7
2 15
3 3
3 20
2 19
6 20
2 3
4 8
5 9
3 8
2 5
4 9
5 18
4 6
4 15
3 14
4 17
4 1
4 19
3 5
5 12
4 12
5 3
6 7
4 10
5 13
3 19
3 10
3 18
2 7
2 18
4 2
6 17
6 18
5 2
3 12
4 14
2 20
5 14
4 13
4 16
5 11
4 18
6 10
2 6
6 8
3 9
6 4
2 14
2 2
6 15

*/

