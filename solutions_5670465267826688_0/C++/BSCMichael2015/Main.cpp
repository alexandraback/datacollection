#include<iostream>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<string>
#include<random>
#include<fstream>
#include<cmath>
#include<cctype>
#include<functional>
#include<iomanip>
#include<bitset>

using namespace std;


#define input cin
#define output cout

int matrix[4][4]={0,1,2,3,1,0,3,2,2,3,0,1,3,2,1,0};
bool neg[4][4]={false,false,false,false,false,true,false,true,false,true,true,false,false,false,true,true};

int L,X;
string s;
pair<bool,int> LB[10000];
pair<bool,int> LE[10000];

pair<bool,int> mul(pair<bool,int> &a,pair<bool,int> &b)
{
	return pair<bool,int>(a.first^b.first^neg[a.second][b.second],matrix[a.second][b.second]);
}
int main()
{
	ifstream input("C:\\Test\\C-small-attempt0.in");
    ofstream output("C:\\Test\\C-small-attempt0.out",ios::trunc);
	int testN;
	input>>testN;
	for(int caseN=1;caseN<=testN;caseN++)
	{
		cin>>L>>X>>s;
		
		LB[0]=pair<bool,int>(false,s[0]-'h');
		
		for(int i=1;i<L;i++)
		{
			LB[i]=mul(LB[i-1],pair<bool,int>(false,s[i]-'h'));
		}

		pair<bool,int> product(false,0);
		for(int i=0;i<X%4;i++)
		{
			product=mul(product,LB[L-1]);
		}

		if(product==pair<bool,int>(true,0))
		{
			LE[L-1]=pair<bool,int>(false,s[L-1]-'h');
		
			for(int i=L-2;i>=0;i--)
			{
				LE[i]=mul(pair<bool,int>(false,s[i]-'h'),LE[i+1]);
			}

			bool found=false;
			if(X==1)
			{
				for(int i=0;i<L&&!found;i++)
				{
					if(LB[i]!=pair<bool,int>(false,1)) continue;
					for(int j=i+2;j<L;j++)
					{
						if(LE[j]==pair<bool,int>(false,3)) {found=true;break;}
					}
				}
			}
			else
			{
				pair<bool,int> p[4];
				p[0]=pair<bool,int>(false,0);
				for(int i=1;i<4;i++) p[i]=mul(p[i-1],LB[L-1]);
				for(int m=0;m<4&&!found;m++)
				{
					for(int n=0;n<4&&!found;n++)
					{
						
						if(m+n>X-2) continue;
						for(int i=0;i<L&&!found;i++)
						{
							if(mul(p[m],LB[i])!=pair<bool,int>(false,1)) continue;
							for(int j=0;j<L;j++)
							{
								if(mul(p[n],LE[j])==pair<bool,int>(false,3)) {found=true;break;}
							}
						}
					}
				}
			}

			if(found) output<<"Case #"<<caseN<<": "<<"YES"<<endl;
			else output<<"Case #"<<caseN<<": "<<"NO"<<endl;

		}
		else
		{
			output<<"Case #"<<caseN<<": "<<"NO"<<endl;
		}
       
		

		
	}
	cin>>testN;
	return 0;
}
	


