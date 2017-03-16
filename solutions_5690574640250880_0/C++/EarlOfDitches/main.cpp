//==================================
//==========   WARNING   ===========
//==================================
//===   Contains too many bugs   ===
//==================================

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <set>
#include <functional>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pr;
typedef pair<ll,ll> prl;

#define double long double

const ll mod7 = 1000000007;

#define NAME "C-small-attempt1"

char ans[51][51];

int dir[8][2] = {
	{0,1},{1,0},{-1,0},{0,-1},
	{1,1},{1,-1},{-1,1},{-1,-1}
};
int R,C,M;

int GETS(int i,int j)
{
	if(ans[i][j] == '.')
	{
		int cnt = 0;
		for(int k=0;k<8;++k)
		{
			if(i+dir[k][0]>=1 && i+dir[k][0]<=R &&
				j+dir[k][1]>=1 && j+dir[k][1]<=C && 
				ans[i+dir[k][0]][j+dir[k][1]] == '*')
				++cnt;
		}
		return cnt;
	}
	return 0;
}

void YESGETS(int i,int j)
{
	for(int k=0;k<8;++k)
	{
		if(i+dir[k][0]>=1 && i+dir[k][0]<=R &&
			j+dir[k][1]>=1 && j+dir[k][1]<=C && 
			ans[i+dir[k][0]][j+dir[k][1]] == '*')
			ans[i+dir[k][0]][j+dir[k][1]] = '.';
	}
}

int main()
{
    //freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    freopen(NAME".in","r",stdin); freopen(NAME".out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
    cin >> t;

	for(int Case=1;Case<=t;++Case)
	{
		cout << "Case #" << Case << ":\n";
		// Solution
		cin >> R >> C >> M;
		
		int FREE = R*C-M;
		for(int i=1;i<=R;++i)
			for(int j=1;j<=C;++j)
				ans[i][j] = '*';

		bool FAIL = false;
		if(FREE==1)
		{
			ans[1][1] = 'c';
		}
		else if(R==1)
		{
			ans[1][1] = 'c';
			for(int i=0;i<C-M-1;++i)
				ans[1][2+i] = '.';
		}
		else if(C==1)
		{
			ans[1][1] = 'c';
			for(int i=0;i<R-M-1;++i)
				ans[2+i][1] = '.';
		}
		else if(R==2)
		{
			if(FREE&1 || FREE==2)
			{
				FAIL = true;
			}
			else
			{
				ans[1][1] = 'c';
				ans[2][1] = ans[1][2] = ans[2][2] = '.';
				for(int i=0;i<(FREE-4)/2;++i)
				{
					ans[1][3+i] = ans[2][3+i] = '.';
				}
			}
		}
		else if(C==2)
		{
			if(FREE&1 || FREE==2)
			{
				FAIL = true;
			}
			else
			{
				ans[1][1] = 'c';
				ans[2][1] = ans[1][2] = ans[2][2] = '.';
				for(int i=0;i<(FREE-4)/2;++i)
				{
					ans[3+i][1] = ans[3+i][2] = '.';
				}
			}
		}
		else
		{
			if(FREE<4)
			{
				FAIL = true;
			}
			else if(FREE&1)
			{
				if(FREE<9)
				{
					FAIL = true;
				}
				else
				{
					for(int i=1;i<=3;++i)
						for(int j=1;j<=3;++j)
							ans[i][j] = '.';
					ans[1][1] = 'c';
					FREE-=9;
					while(FREE)
					{
						if(FREE&1)
						{
							bool makeit = false;
							for(int i=1;i<=R && !makeit;++i)
							{
								for(int j=1;j<=C && !makeit;++j)
								{
									if(GETS(i,j)==1)
									{
										YESGETS(i,j);
										FREE-=1;
										makeit = true;
									}
								}
							}
							if(!makeit)
							{
								FAIL = true;
								break;
							}
						}
						else
						{
							bool makeit = false;
							for(int i=1;i<=R && !makeit;++i)
							{
								for(int j=1;j<=C && !makeit;++j)
								{
									if(GETS(i,j)==2)
									{
										YESGETS(i,j);
										FREE-=2;
										makeit = true;
									}
								}
							}
							if(!makeit)
							{
								for(int i=1;i<=R && !makeit;++i)
								{
									for(int j=1;j<=C && !makeit;++j)
									{
										if(GETS(i,j)==1)
										{
											YESGETS(i,j);
											FREE-=1;
											makeit = true;
										}
									}
								}
								if(!makeit)
								{
									FAIL = true;
									break;
								}
							}
						}
					}
				}
			}
			else
			{
				for(int i=1;i<=2;++i)
					for(int j=1;j<=2;++j)
						ans[i][j] = '.';
				ans[1][1] = 'c';
				FREE-=4;
				while(FREE)
				{
					if(FREE&1)
					{
						bool makeit = false;
						for(int i=1;i<=R && !makeit;++i)
						{
							for(int j=1;j<=C && !makeit;++j)
							{
								if(GETS(i,j)==1)
								{
									YESGETS(i,j);
									FREE-=1;
									makeit = true;
								}
							}
						}
						if(!makeit)
						{
							FAIL = true;
							break;
						}
					}
					else
					{
						bool makeit = false;
						for(int i=1;i<=R && !makeit;++i)
						{
							for(int j=1;j<=C && !makeit;++j)
							{
								if(GETS(i,j)==2)
								{
									YESGETS(i,j);
									FREE-=2;
									makeit = true;
								}
							}
						}
						if(!makeit)
						{
							for(int i=1;i<=R && !makeit;++i)
							{
								for(int j=1;j<=C && !makeit;++j)
								{
									if(GETS(i,j)==1)
									{
										YESGETS(i,j);
										FREE-=1;
										makeit = true;
									}
								}
							}
							if(!makeit)
							{
								FAIL = true;
								break;
							}
						}
					}
				}
			}
		}

		if(FAIL)
		{
			cout << "Impossible";
			//cout << " " << M;
			cout << "\n";
		}
		else
		{
			for(int i=1;i<=R;++i)
			{
				for(int j=1;j<=C;++j)
				{
					cout << ans[i][j];
				}
				cout << "\n";
			}
		}

		// ends
		//cout << endl;
	}

    return 0;
}