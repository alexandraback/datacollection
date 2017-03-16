//Author : pakhandi
//
using namespace std;

#include <bits/stdc++.h>

#define wl(n) while(n--)
#define fl(i,a,b) for(i=a; i<b; i++)
#define rev(i,a,b) for(i=a; i>=b; i--)

#define si(n) scanf("%d", &n)
#define sll(l) scanf("%lld",&l)
#define ss(s) scanf("%s", s)
#define sc(c) scanf("%c", &c)
#define sd(f) scanf("%lf", &f)

#define pi(n) printf("%d\n", n)
#define pll(l) printf("%lld\n", l)
#define ps(s) printf("%s\n", s)
#define pc(c) printf("%c\n", c)
#define pd(f) printf("%lf\n", f)

#define debug(x) cout<<"\n#("<<x<<")#\n"
#define nline printf("\n")

#define mem(a,i) memset(a,i,sizeof(a))

#define MOD 1000000007
#define ll long long int
#define u64 unsigned long long int

#define mclr(strn) strn.clear()
#define ignr cin.ignore()
#define PB push_back
#define SZ size
#define MP make_pair
#define fi first
#define sec second

int sttoi(string str1, int limit)
{
	int i;
	int t = 1;
	int ret = 0;
	rev(i,limit - 1, 0)
	{
		ret = ret + ( int(str1[i] - '0') * t );
		t *= 10;
	}
	return ret;
}

bool mark[2][20];

int l[6];

pair<string,string> ans;

string str1, str2;

int main()
{
	int i, j;

	int cases;
	int caseNo = 1;

	cin>>cases;

	wl(cases)
	{
		cin>>str1>>str2;

		mem(mark,0);

		int m = str1.SZ();
		m = 3 - m;


		int limit = str1.SZ();

		while( limit < 3 )
		{
			str1 = "0" + str1;
			str2 = "0" + str2;
			limit++;
		}

		//cout<<sttoi("020",3); nline;

		fl(i,0,limit)
		{
			if(str1[i] == '?')
				mark[0][i] = 1;
			if(str2[i] == '?')
				mark[1][i] = 1;
		}

		/*fl(i,0,limit)
		{
			cout<<mark[0][i]<<" ";
		}
		nline;

		fl(i,0,limit)
		{
			cout<<mark[1][i]<<" ";
		}
		nline;*/

		int minDiff, minA, minB;

		minDiff = minA = minB = INT_MAX;

		fl(l[0],0,10)
		{
			fl(l[1],0,10)
			{
				fl(l[2],0,10)
				{
					fl(l[3],0,10)
					{
						fl(l[4],0,10)
						{
							fl(l[5],0,10)
							{
								fl(i,0,limit)
								{
									if(mark[0][i])
									{
										str1[i] = char(l[i] + '0');
									}
								}

								fl(i,0,limit)
								{
									if(mark[1][i])
									{
										str2[i] = char(l[i + 3] + '0');
									}
								}

								//cout<<str1<<" "<<str2; nline;

								int a = sttoi(str1, limit);
								int b = sttoi(str2, limit);

								if(abs(a - b) < minDiff)
								{
									//cout<<str1<<" "<<str2<<" : ";
									//cout<<a<<" "<<b; nline;
									ans = MP(str1, str2);
									minDiff = abs(a - b);
									//cout<<abs(a - b); nline;
								}
								else if(abs(a - b) == minDiff)
								{
									//cout<<"&"<<a<<" "<<b; nline;
									if(str1 < ans.first)
									{
										ans = MP(str1, str2);
									}
									else if(str1 == ans.first)
									{
										if(str2 < ans.second)
										{
											ans = MP(str1, str2);
											//b = minB;
										}

									}
								} 
							}
						}
					}
				}
			}
		}

		/*fl(i,m,limit)
		{
			if(mark[0][i] && mark[1][i])
				ans.first[i] = ans.second[i] = '0';
			else
				break;
		}*/

		cout<<"Case #"<<caseNo<<": ";
		caseNo++;

		fl(i,m,limit)
		{
			cout<<ans.first[i];
		}
		cout<<" " ;
		fl(i,m,limit)
			cout<<ans.second[i];
		nline;
		
		//break;
	}



	return 0;
}
/*
	Powered by Buggy Plugin
*/
