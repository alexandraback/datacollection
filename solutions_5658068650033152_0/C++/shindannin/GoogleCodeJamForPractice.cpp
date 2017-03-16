// topcoder.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include <stdio.h>
#include <tchar.h>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;

static const double EPS = 1e-9;
inline int ROUND(double x) { return (int)(x+0.5); }
inline bool ISINT(double x) { return fabs(ROUND(x)-x)<EPS; }
inline bool ISEQUAL(double x,double y) { return fabs(x-y)<EPS; }
template<class T> void amin(T &a, T v) { if (a > v) a = v; }
template<class T> void amax(T &a, T v) { if (a < v) a = v; }
#define INRANGE(x,a,b) ((a)<=(x)&&(x)<=(b))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define SZ(a) ((int)a.size())
#define NG (-1)
#define BIG (987654321)

#if 1

void nuru_bfs(vector< vector <int> >& vs, const int y, const int x, const int from, const int to)
{
	queue < pair <int, int> > q;
	q.push(make_pair(y,x));
	while (!q.empty())
	{
		pair <int, int> now = q.front();
		const int ny = now.first;
		const int nx = now.second;
		q.pop();

		if(vs[ny][nx]==from)
		{
			vs[ny][nx]=to;

			if(ny+1<=SZ(vs)-1)
			{
				q.push(make_pair(ny+1,  nx));
			}
			if(ny-1>=0)
			{
				q.push(make_pair(ny-1,  nx));
			}
			if(nx+1<=SZ(vs[0])-1)
			{
				q.push(make_pair(ny,  nx+1));
			}
			if(nx-1>=0)
			{
				q.push(make_pair(ny,  nx-1));
			}
		}
	}
	return;
}

bool test(int H, int W, int K, int S)
{
	const int MASU = H*W;
	int ryouchi = 0;

	vector< vector <int> > vs(H, vector <int> (W,0));
	
	for (int i = 0; i < 1<<MASU; ++i)
	{
		for (int y = 0; y < H; ++y)
		{
			for (int x = 0; x < W; ++x)
			{
				vs[y][x]=0;
			}
		}

		int default_num = 0;
		for (int k = 0; k < MASU; ++k)
		{
			if(i & (1<<k))
			{
				int y = k/W;
				int x = k%W;
				vs[y][x]=1;
				default_num++;
			}
		}

		if(default_num!=S) continue;

		for(int y=0;y<H;y++)
		{
			nuru_bfs(vs, y, 0, 0, 2);
			nuru_bfs(vs, y, W-1, 0, 2);
		}

		for(int x=0;x<W;x++)
		{
			nuru_bfs(vs, 0,   x, 0, 2);
			nuru_bfs(vs, H-1, x, 0, 2);
		}

		int num = 0;

		for (int y = 0; y < H; ++y)
		{
			for (int x = 0; x < W; ++x)
			{
				if(vs[y][x]==0 || vs[y][x]==1)
				{
					num++;
				}
			}
		}

		if(num>=K)
		{
			return true;
		}
	}

	return false;
}

int main(){

	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);


	int T;
	scanf("%d",&T);

	for (int testcase = 1; testcase<=T; ++testcase)
	{
		int H,W,K;
		scanf("%d %d %d",&H,&W,&K);


		for (int s = 1; s <= K; ++s)
		{
			if( test(H,W,K,s))
			{
				fprintf(stderr,"Case #%d: %d\n",testcase,s);
				printf("Case #%d: %d\n",testcase,s);
				break;
			}

		}
	}

	return 0;
}




#elif 1

// vectorの重複している要素をけずる
template<class T> 
void unique_erase( T& v )
{
	v.erase(unique(v.begin(),v.end()),v.end());
}

int main(){

	freopen("_google_code_jam_input.txt","r",stdin);
	freopen("_google_code_jam_output.txt","w",stdout);


	int T;
	scanf("%d",&T);

	for (int testcase = 1; testcase<=T; ++testcase)
	{
		int N;
		scanf("%d",&N);

		vector <string> vs;
		for (int k = 0; k < N; ++k)
		{
			char str[100000];
			scanf("%s",str);
			string s(str);
			s += string(1,k+'0');
			vs.push_back(s);
		}

		ll num = 0;
		sort(vs.begin(),vs.end());
		do
		{
			string s;
			string memo;
			for (int i = 0; i < N; ++i)
			{
				s += vs[i].substr(0,SZ(vs[i])-1);
			}
			memo = s;
			unique_erase(s);

			map <char, int> mp;
			bool dame = false;
			for (int i = 0; i < SZ(s); ++i)
			{
				mp[s[i]]++;
				if(mp[s[i]]>=2)
				{
					dame = true;
					break;
				}
			}

			if(!dame)
			{
				num++;
			}

			// BEGIN CUT HERE
//			cout << " s=" << s << " memo=" << memo << " dame=" << dame << endl;
			// END CUT HERE


		} while(next_permutation(vs.begin(),vs.end()));


		fprintf(stderr,"Case #%d: %lld\n",testcase,num);
		printf("Case #%d: %lld\n",testcase,num);
	}
}



#else

void split1(const string& str, vector<string>& out, const char splitter=' ')
{
	out.clear();
	string::size_type st = 0;
	string::size_type next = 0;
	string tmp = str;
	do
	{
		next=tmp.find(splitter,st); // tmp.find_first_of("+-",st); 複数の文字で分けたいとき
		string word = tmp.substr(st,next-st);
		if(word.length()>=1) // 空文字列ありのときは消す
		{
			out.push_back(word);
		}
		st = next+1;
	} while(next!=string::npos);
}

ll gcd(ll x, ll y)
{
	if(x==0) return y;
	if(y==0) return x;

	ll t;

	while(y!=0)
	{
		t = x%y;
		x = y;
		y = t;
	}
	return x;
}

ll leftest(ll A)
{
	for(ll i=62;i>=0;i--)
	{
		if(A & (1LL<<i))
		{
			return i;
		}
	}

	return -1;
}	


int main(){

     freopen("_google_code_jam_input.txt","r",stdin);
	 freopen("_google_code_jam_output.txt","w",stdout);


	 int T;
	 scanf("%d",&T);

	 for (int testcase = 1; testcase<=T; ++testcase)
	 {
		 char str[10000];
		 scanf("%s",str);

		 vector <string> vs;
		 split1(string(str), vs, '/');

		 ll P, Q;
		 {
			 stringstream ss(vs[0]);
			 ss >> P;
		 }


		 {
			 stringstream ss(vs[1]);
			 ss >> Q;
		 }

		 ll g = gcd(P, Q);

		 P /= g;
		 Q /= g;

		 if( (Q & (Q-1LL))!=0)
		 {
			 fprintf(stderr,"Case #%d: impossible\n",testcase);
			 printf("Case #%d: impossible\n",testcase);
		 }
		 else
		 {
			 ll best = leftest(Q)-leftest(P);

			 fprintf(stderr,"Case #%d: %lld\n",testcase,best);
			 printf("Case #%d: %lld\n",testcase,best);
		 }

	 }

	 return 0;
}

#endif