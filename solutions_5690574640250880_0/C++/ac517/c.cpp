#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <time.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <queue>
#include <iomanip>

using namespace std;

#define FOR(i,a,b)  for(int i = (a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define S           size()
#define PB          push_back
#define ALL(a)      a.begin(),a.end()
#define MP          make_pair
#define V           vector
#define VI          V < int > 
#define VVI         V < VI >
#define VVVI		V < VVI >
#define VL			V < long long > 
#define VVL			V < VL >
#define VD          V < double >
#define VVD			V < VD >
#define VF          V < float >
#define VS			V < string >





string check1(int R, int C, int M)
{
	stringstream simp;
	simp << "Impossible" << endl; //<< " R=" << R << " C=" << C << " M=" << M << endl;
	//handle special cases
	if(R*C==M) return simp.str();
	
	if(R*C-1==M)
	{
		stringstream ss;
		ss<<'c';
		REP(i,C-1) ss<<'*';
		ss<<endl;
		REP(i,R-1)
		{
			REP(j,C)
			{
				ss << '*';
			}
			ss << endl;
		}
		return ss.str();
	}
	
	if(M==0)
	{
		stringstream ss;
		ss<<'c';
		REP(i,C-1) ss<<'.';
		ss<<endl;
		REP(i,R-1)
		{
			REP(j,C)
			{
				ss << '.';
			}
			ss << endl;
		}
		return ss.str();
	}
	
	if(R>C && (M%C)==0 && (R-2)*C>=M)
	{
		stringstream ss;
		//ss << "SPECIAL BREW M=" << M << " R = " << R << " C = " << C <<endl;
		ss << 'c';
		REP(i,C-1)
		{
			ss << '.';
		}
		ss<<endl;
		REP(i,R-1-(M/C))
		{
			REP(j,C)
			{
				ss<<'.';
			}
			ss<<endl;
		}
		REP(i,R-(R-(M/C)))
		{
			REP(j,C)
			{
				ss<<'*';
			}
			ss<<endl;
		}
		return ss.str();
	}
	
	if( C>R && (M%R)==0 && (C-2)*R>=M)
	{
		stringstream ss;
		//ss << "SPECIAL BREW M=" << M << " R = " << R << " C = " << C <<endl;
		ss << 'c';
		REP(i,C-1-(M/R))
		{
			ss << '.';
		}
		REP(i,(M/R))
		{
			ss<<'*';
		}
		ss<<endl;
		REP(i,R-1)
		{
			REP(j,C)
			{
				if(j<C-(M/R))
					ss<<'.';
				else
					ss<<'*';
			}
			ss<<endl;
		}
		return ss.str();
	}
	
	//onto placing bombs
	VS b;
	REP(i,R)
	{
		string r = "";
		REP(j,C)
		{
			r+='.';
		}
		b.PB(r);
	}
	
	b[0][0]='c';
	int bombs = M;

	int m=R-1,n=C-1;
	//b[m][n]='*';
	//--bombs;
	bool nochange = false;
	while(bombs>0 && (n>1 || m>1) && !nochange)
	{
		//cout <<"LINE:" <<__LINE__ << bombs << " " << n << " " << m << endl;
		nochange=true;
		if(n>1 && (bombs>m || bombs<=m-1))
		{
		//cout <<"LINE:" <<__LINE__ << bombs << " " << n << " " << m << endl;
			for(int i=m;i>=0 && bombs>0;--i)
			{
			//cout <<"LINE:" <<__LINE__ << bombs << " " << n << " " << m << endl;
				if(b[i][n]=='.')
				{
					b[i][n]='*';
					--bombs;
				}
			}
			--n;
			nochange=false;
		}
		//cout <<"LINE:" <<__LINE__ << bombs << " " << n << " " << m << endl;
		if(m>1 && (bombs>n || bombs<=n-1))
		{
		//cout <<"LINE:" <<__LINE__ << bombs << " " << n << " " << m << endl;
			for(int i=n;i>=0 && bombs>0;--i)
			{
			//cout <<"LINE:" <<__LINE__ << bombs << " " << n << " " << m << endl;
				if(b[m][i]=='.')
				{
					b[m][i]='*';
					--bombs;
				}
			}
			--m;
			nochange=false;
		}
		//cout <<"LINE:" <<__LINE__ << bombs << " " << n << " " << m << endl;
		
		if(nochange && bombs>0)
		{
			if(n>1)
			{
				for(int i=m;i>=2 && bombs>0;--i)
				{
					if(b[i][n]=='.')
					{
						b[i][n]='*';
						--bombs;
					}
				}
				--n;
				nochange=false;
			}
			
			if(m>1)
			{
				for(int i=n;i>=2 && bombs>0;--i)
				{
					if(b[m][i]=='.')
					{
						b[m][i]='*';
						--bombs;
					}
				}
				--m;
				nochange=false;
			}
		}
			
			
	}
	
	//if(bombs>0) return simp.str();

	//save a copy
	VS res = b;
	
	//bfs check
	queue<pair<int,int>> q;
	q.push(MP(0,0));
	int cnt = 0;
	set<pair<int,int>> s;
	s.insert(MP(0,0));
	while(!q.empty())
	{
		pair<int,int> p = q.front();
		q.pop();
		int i = p.first, j=p.second;
		++cnt;
		if(!((j+1<C && b[i][j+1]=='*') ||
		   (i+1<R && b[i+1][j]=='*') ||
		   (i+1<R && j+1<C && b[i+1][j+1]=='*') ||
		   (i-1>=0 && b[i-1][j]=='*') ||
		   (i-1>=0 && j+1<C && b[i-1][j+1]=='*'))) 
		{	
			if(j+1<C && s.find(MP(i,j+1))==s.end())
			{
				q.push(MP(i,j+1));
				s.insert(MP(i,j+1));
			}
			if(i+1<R && j+1<C && s.find(MP(i+1,j+1))==s.end())
			{
				q.push(MP(i+1,j+1));
				s.insert(MP(i+1,j+1));
			}
			if(i+1<R && s.find(MP(i+1,j))==s.end())
			{
				q.push(MP(i+1,j));
				s.insert(MP(i+1,j));
			}
		}
	}
	
	if(cnt==R*C-M)// || true)
	{
		stringstream ss;
		//if(cnt!=R*C-M) ss << ">>>>IMPOSSIBLE<<<<<" << " M= " << M << " left = " << bombs << endl;
		REP(i,res.S)
		{
			ss << res[i] << endl;
		}
		return ss.str();
	}
		
	return simp.str();

}





int main(int argc, char** argv)
{
	int n;
	++argv;
	ifstream in(*argv);
	
	in >> n;
	VS res;
	int R,C,M;
	REP(i,n)
	{
		in >> R >> C >> M;
		res.PB(check1(R,C,M));
	}
				
	
	stringstream ss;
	REP(i,res.S)
	{
		ss << "Case #" << i+1 << ":" << endl << res[i];
	}
	
	cout << ss.str();




}


