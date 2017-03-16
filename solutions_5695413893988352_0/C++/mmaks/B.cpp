#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll sttoi(string s1, ll limit)
{
	ll t = 1;
	ll ret = 0;
	for(int i=limit-1;i>=0;i--) {
		ret = ret + ( int(s1[i] - '0') * t );
		t *= 10;
	}
	return ret;
}

bool mark[2][20];
ll l[6];

pair<string,string> ans;

string s1, s2;

int main() {
	freopen("inBs.txt", "r", stdin);
	freopen("outBs.txt", "w", stdout);
	ll t;
	cin>>t;

	for(int cases = 1; cases <= t; cases ++) {

		cin>>s1>>s2;
		memset(mark, 0, sizeof(mark));
		ll m = s1.size();
		m = 3 - m;
		ll limit = s1.size();

		while( limit < 3 )
		{
			s1 = "0" + s1;
			s2 = "0" + s2;
			limit++;
		}

		//cout<<sttoi("020",3); nline;

		for(int i=0;i<limit;i++)
		{
			if(s1[i] == '?')
				mark[0][i] = 1;
			if(s2[i] == '?')
				mark[1][i] = 1;
		}

		ll minDiff, minA, minB;

		minDiff = minA = minB = INT_MAX;

		for(l[0] = 0;l[0] < 10; l[0]++) {
			for(l[1] = 0;l[1] < 10; l[1]++)
			{
				for(l[2] = 0;l[2] < 10; l[2]++)
				{
					for(l[3] = 0;l[3] < 10; l[3]++)
					{
						for(l[4] = 0;l[4] < 10; l[4]++)
						{
							for(l[5] = 0;l[5] < 10; l[5]++)
							{
								for(int i=0;i<limit;i++)
								{
									if(mark[0][i])
									{
										s1[i] = char(l[i] + '0');
									}
								}

								for(int i=0;i<limit;i++)
								{
									if(mark[1][i])
									{
										s2[i] = char(l[i + 3] + '0');
									}
								}
								ll a = sttoi(s1, limit);
								ll b = sttoi(s2, limit);
								if(abs(a - b) < minDiff)
								{
									ans = make_pair(s1, s2);
									minDiff = abs(a - b);
									//cout<<abs(a - b); nline;
								}
								else if(abs(a - b) == minDiff)
								{
									//cout<<"&"<<a<<" "<<b; nline;
									if(s1 < ans.first)
									{
										ans = make_pair(s1, s2);
									}
									else if(s1 == ans.first)
									{
										if(s2 < ans.second)
										{
											ans = make_pair(s1, s2);
										}

									}
								} 
							}
						}
					}
				}
			}
		}

		cout<<"Case #"<<cases<<": ";

		for(int i=m;i<limit;i++)
		{
			cout<<ans.first[i];
		}
		cout<<" " ;
		for(int i=m;i<limit;i++)
			cout<<ans.second[i];
		cout<<"\n";
		
	}



	return 0;
}