#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define For(i,n) for (i=0; i<int(n); i++)
#define ForR(i,n) for (i=int(n)-1; i>=0; i--)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x < 0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }

const int INF = (int)1e9;
const LD EPS = 1e-9;
const LD PI = acos(-1.0);

#define DEBUG 0

int input[100][7];
int main()
{
	//files
	freopen("in.in","r",stdin);
		if (!DEBUG)
			freopen("out.txt","w",stdout);
	//vars
	int tt,TT;
	//testcase loop
	scanf("%d",&TT);
		For(tt,TT)
		{
			//init
			printf("Case #%d:\n",tt+1);
			//input
			int R,N,M,K;
			scanf("%d%d%d%d",&R,&N,&M,&K);
			int i,j;
			For(i,R)
			{
				For(j,K)
				{
					scanf("%d",&input[i][j]);
				}
			}
			For(i,R)
			{
				bool has5=false;
				For(j,K)
				{
					if(input[i][j]%5==0) {has5=true;break;}
				}
				bool has3=false;
				For(j,K)
				{
					if(input[i][j]%3==0) {has3=true;break;}
				}
				bool has4=false;
				For(j,K)
				{
					if(input[i][j]%4==0) {has4=true;break;}
				}
				bool has2=false;
				For(j,K)
				{
					if(input[i][j]%2==0) {has2=true;break;}
				}
				vector<int> res;
				res.clear();
				if(N==1)
				{
					if(has5){printf("5\n");continue;}
					if(has3){printf("3\n");continue;}
					if(has4){printf("4\n");continue;}
					else{printf("2\n");continue;}
				}
				int contain[200];
				memset(contain,0,sizeof(contain));
				For(j,K)
					for(int sm=2;sm<126;sm++){
						if(input[i][j]%sm==0)
							contain[sm]=1;
					}
				//		contain[input[i][j]]++;
				if(has5) res.push_back(5);
				if(has3) res.push_back(3);
				int remain=N-res.size();
				if((contain[8]>0)&&(remain<3)){res.push_back(4);res.push_back(2);remain-=2;}
				if(has4&&(remain==1)) {res.push_back(4); remain--;}
				if((contain[16]>0)&&(remain>0)) {res.push_back(4); remain--;}
				if((!has4)&&(has2)) {res.push_back(2); remain--;}
				if(has2)
				{
					bool tx=false;
					for(int h=0;h<res.size();h++)
					{
						if(res[h]%2==0) tx=true;
					}
					if(!tx)
					{
						res.push_back(2); remain--;
					}
				}
				//while(remain>0)
				{
					if((contain[125]) &&(remain>0)) {
						res.push_back(5);
						remain--;
					}
					if((contain[27]) &&(remain>0)) {
						res.push_back(3);
						remain--;
					}
					if((contain[25]) &&(remain>0)) {
						res.push_back(5);
						remain--;
					}
					if((contain[9]) &&(remain>0)) {
						res.push_back(3);
						remain--;
					}
				}
				//if((contain[8]>0)&&(remain>2)){res.push_back(4);res.push_back(2);remain-=2;}
				if(has4&&(remain==1)) {res.push_back(4); remain--;}
				if((contain[16]>0)&&(remain>0)) {res.push_back(4); remain--;}
				while(remain>0)
				{
					res.push_back(2);
					remain--;
				}
				for(int h=0;h<res.size();h++)
				{
					printf("%d",res[h]);
				}
				printf("\n");



			}
			
		}
	return(0);
}