#include <iostream>
#include<memory.h>
#include <map>
#include <list>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <set>
using namespace std;

/*
int main()
{
	ifstream cin;
	cin.open("in.in");
	ofstream cout;
	cout.open("out.out");
	
	int T;
	cin>>T;
	for (int z = 1; z <= T; z++)
	{
		int n;
		cin>>n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin>>a[i];
		int mxDec = 0;
		int sm = 0;
		for (int i = 1; i < n; i++)
		{
			mxDec = max(mxDec, a[i-1]-a[i]);
			sm += max(0, a[i-1]-a[i]);
		}
		int sm2 =0;
		for (int i = 1; i < n; i++)
		{
			sm2 += min(mxDec, a[i-1]);
		}
		cout<<"Case #"<<z<<": "<<sm<<" "<<sm2<<endl;
	}
}


int main()
{

	ifstream cin;
	cin.open("in.in");
	ofstream cout;
	cout.open("out.out");
	
	int T;
	cin>>T;
	for (int z = 1; z <= T; z++)
	{
		int B, N;
		cin>>B>>N;
		vector<long long> b(B);
		for (int i = 0; i < B; i++) cin>>b[i];		
		long long lo = 0;
		long long hi = 100000000000000ll;
		long long md;
		while (lo <= hi)
		{
			md = (lo+hi)/2;
			long long sm = 0;
			for (int i = 0; i < B; i++)
			{
				sm += md/b[i];
				sm++;
			}
			if (sm < N)
			{
				lo = md+1;
			}
			else
				hi = md-1;
		}
		long long sm = 0;
		vector<pair<int, int> > r;
		int mxSt = 0;
		for (int i = 0; i < B; i++){
			sm += lo/b[i];
			sm++;
			int start = lo-(lo%b[i]);
			r.push_back(make_pair(start, i+1));
		}
		long long dif = sm-N;
		dif++;
		sort(r.begin(), r.end());
		
		cout<<"Case #"<<z<<": "<<r[r.size()-dif].second<<endl;
	}
}


typedef double T;
double INF = 1e100;
const double EPS = 1e-12;

struct PT { 
  double x, y; 
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator + (const PT &p)  const { return PT(x+p.x, y+p.y); }
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
  PT operator * (double c)     const { return PT(x*c,   y*c  ); }
  PT operator / (double c)     const { return PT(x/c,   y/c  ); }
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }
double cross(PT p, PT q)   { return p.x*q.y-p.y*q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")"; 
}

// rotate a point CCW or CW around the origin
PT RotateCCW90(PT p)   { return PT(-p.y,p.x); }
PT RotateCW90(PT p)    { return PT(p.y,-p.x); }
PT RotateCCW(PT p, double t) { 
  return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t)); 
}

// project point c onto line segment through a and b
PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b-a,b-a);
  if (fabs(r) < EPS) return a;
  r = dot(c-a, b-a)/r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b-a)*r;
}


// determine if point is on the boundary of a polygon
bool PointOnPolygon(const vector<PT> &p, PT q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(ProjectPointSegment(p[i], p[(i+1)%p.size()], q), q) < EPS)
      return true;
    return false;
}

T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

#ifdef REMOVE_REDUNDANT
bool between(const PT &a, const PT &b, const PT &c) {
  return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
#endif

void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) >= 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) <= 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
  
#ifdef REMOVE_REDUNDANT
  if (pts.size() <= 2) return;
  dn.clear();
  dn.push_back(pts[0]);
  dn.push_back(pts[1]);
  for (int i = 2; i < pts.size(); i++) {
    if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
    dn.push_back(pts[i]);
  }
  if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
    dn[0] = dn.back();
    dn.pop_back();
  }
  pts = dn;
#endif
}

int main()
{

	ifstream cin;
	cin.open("in.in");
	ofstream cout;
	cout.open("out.out");
	
	int T;
	cin>>T;
	for (int z = 1; z <= T; z++)
	{
		int N;
		cin>>N;
		vector<PT> a(N);
		for (int i = 0; i < N; i++) cin>>a[i].x>>a[i].y;
		int r[100] = {0};
		for (int i = 1; i < (1<<N); i++)
		{
			int sz = 0;
			vector<PT> sub;
			for (int j = 0; j < N; j++)
			{
				if (i&(1<<j)) {
					sz++;
					sub.push_back(a[j]);
				}
			}
			ConvexHull(sub);
			for (int j = 0; j < N; j++)
			{
				if (PointOnPolygon(sub, a[j]))
				{
					r[j] = max(r[j], sz);
				}
			}
		}
		cout<<"Case #"<<z<<":"<<endl;
		for (int i = 0; i < N; i++)
		{
			cout<<N-r[i]<<endl;
		}
	}
}


int main()
{
	double pi = 3.1415926535897932384626;
	double A;
	cin>>A;
	A/=pi;
	cout<<fixed<<setprecision(15)<<2*sqrt(A)<<endl;
}


int main()
{
	string a, b;
	cin>>a>>b;
	int cnt = 0;
	if (a.size() == b.size())
	{
		string A = "";
		string B = "";
		for (int i = 0; i < a.size(); i++)
		{
			if (i%2==0)
			{
				A += '4';
				B += '7';
			}
			else
			{
				A += '7';
				B += '4';
			}
		}
		if (A >= a && A <= b)
			cnt++;
		if (B >= a && B <= b)
			cnt++;
	}
	else
	{
		string A = "";
		string B = "";
		for (int i = 0; i < a.size(); i++)
		{
			if (i%2==0)
			{
				A += '4';
				B += '7';
			}
			else
			{
				A += '7';
				B += '4';
			}
		}
		if (A >= a)
			cnt++;
		if (B >= a)
			cnt++;
		
		A = "";
		B = "";
		for (int i = 0; i < b.size(); i++)
		{
			if (i%2==0)
			{
				A += '4';
				B += '7';
			}
			else
			{
				A += '7';
				B += '4';
			}
		}
		if (A <= b)
			cnt++;
		if (B <= b)
			cnt++;
	}
	int dif = max(0, (int)b.size() - (int)a.size() - 1);
	cnt += dif*2;
	cout<<cnt<<endl;
}


int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin>>a[i];
	sort(a.begin(), a.end());
	int e;
	long long r = 0;
	for (int i = 0; i < n; i++)
	{
		e = i+2;
		for (int j = i+1; j < n; j++)
		{
			while (e < n && (a[e] < a[i]+a[j])) e++;
			r += max(0ll, (long long)(e-1-j));
		}
	}
	cout<<r<<endl;
}


int main()
{
	int n;
	long long P;
	cin>>n>>P;
	vector<pair<int, int> > a(n);
	for (int  i = 0; i < n; i++) cin>>a[i].first>>a[i].second;
	sort(a.begin(), a.end());
	long long P2 = a[0].second;
	int cnt = 0;
	if (P2 > P) cnt++;
	for (int i = 1; i < n; i++)
	{
		P2 = max(0ll, P2-(a[i].first-a[i-1].first));
		P2 += a[i].second;
		if (P2 > P) cnt++;
	}
	cout<<cnt<<endl;
}


int main()
{
	int n;
	cin>>n;
	priority_queue<long long> q;
	for (int i = 0; i < n; i++)
	{
		int x;
		cin>>x;
		q.push(-x);
	}
	long long mx = 0;
	while (!q.empty())
	{
		long long f = -q.top();
		q.pop();
		mx = max(mx, f);
		long long s = -1;
		if (!q.empty())
		{
			s = -q.top();
			if (f == s)
			{
				q.pop();
				q.push(-(f+s));
//				cout<<f+s<<endl;
			}
		}
	}
	cout<<mx<<endl;
}


int main()
{
	int n, m;
	cin>>n>>m;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin>>a[i];
	priority_queue<pair<long long, int> > q;
	vector<int> r;
	for (int i = 0; i < n; i++)
	{
		q.push(make_pair(-a[i], -i));
	}
	while (r.size() < 1000001)
	{
		pair<long long, int> f = q.top();
		q.pop();
		int in = -f.second;
		r.push_back(in);
		f.first -= a[in];
		q.push(f);
	}
	vector<int> b[1000001];
	for (int i = 0; i < r.size(); i++)
	{
		b[r[i]].push_back(i);
	}
	while (m--)
	{
		int c, i, j;
		cin>>c>>i;
		if (c == 2)
		{
			cin>>j;
			cout<<b[i-1][j-1]+1<<endl;
		}
		else
		{
			cout<<r[i-1]+1<<endl;
		}
	}
}


int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> l(n);
	vector<int> r(n);
	int mxIn = 0;
	
	for (int i = 0;i < n; i++)
	{
		cin>>a[i];
		if (a[i] > a[mxIn])
		{
			mxIn = i;
		}
	}
	int in = (mxIn+1)%n;
	stack<pair<int, int> > q;
	q.push(make_pair(mxIn, a[mxIn]));
	while (in != mxIn)
	{
		int h = a[in];
		while (!q.empty() && q.top().second <= h) q.pop();
		if (q.empty())
		{
			l[in] = -1;
		}
		else
		{
			l[in] = q.top().first+1;
		}
		q.push(make_pair(in, a[in]));
		in = (in+1)%n;
	}
	l[in] = r[in] = -1;
	while (!q.empty()) q.pop();
	in = (mxIn-1);
	if (in < 0) in = n-1;
	q.push(make_pair(mxIn, a[mxIn]));
	while (in != mxIn)
	{
		int h = a[in];
		while (!q.empty() && q.top().second <= h) q.pop();
		if (q.empty())
		{
			r[in] = -1;
		}
		else
		{
			r[in] = q.top().first+1;
		}
		q.push(make_pair(in, a[in]));
		in--;
		if (in < 0) in = n-1;
	}
	for (int i = 0; i < n; i++) cout<<l[i]<<" "<<r[i]<<endl;
}


long long gcd(long long a, long long b)
{
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main()
{
	int n;
	cin>>n;
	vector<pair<long long, long long> > a(n);
	for (int i = 0; i < n; i++)
	{
		cin>>a[i].first>>a[i].second;
	}
	vector<int> b(n, 0);
	vector<vector<int> > tk(n, vector<int> (n, 0));
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			long long A, B, C;
			A = a[i].second-a[j].second;
			B = a[j].first-a[i].first;
			C = a[i].first*a[j].second - a[j].first*a[i].second;
			
			vector<int> cnt;
			for (int k = 0; k < n; k++)
			{
				long long r = A*a[k].first + B*a[k].second + C;
				if (r == 0) cnt.push_back(k);
			}
			if (tk[cnt[0]][cnt[1]]) continue;
			tk[cnt[0]][cnt[1]]++;
			b[cnt.size() - 1]++;
		}
	}
	for (int i = 1;i < n; i++) cout<<b[i]<<" ";
	cout<<endl;
}


int main()
{
	int d, m;
	cin>>d>>m;
	int pw = pow(10, d);
	map<string, int> mp;
	vector<pair<int, string> > a;
	for (int i = 0; i < pw; i++)
	{
		stringstream ss;
		ss<<i;
		string s;
		ss>>s;
		s = string(d-s.size(), '0')+s;
		int sm = 0;
		for (int j = 0; j < d; j++) sm += s[i]-'0';
		a.push_back(make_pair(sm, s));
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < a.size(); i++) mp[a[i].second] = i;
	while (m--)
	{
		char com;
		string s;
		int num;
		cin>>com;
		if (com == 1)
		{
			cin>>num;
			cout<<a[num].second;
		}
		else
		{
			cin>>s;
			cout<<mp[s]<<endl;
		}
	}
}


int main()
{
	int n;
	scanf("%d",&n);
	
	set<pair<int, int> > a[3];
	for (int i = 0; i < n; i++)
	{
		int x;
		scanf("%d",&x);
		pair<int, int> key = make_pair(x, x%3);
		a[x%3].insert(make_pair(x,i+1));
	}
	int cur = 0;
	vector<int> res;
	for (int i = 0; i < n; i++)
	{
		if (a[cur%3].empty())
		{
			printf("Impossible\n");
			return 0;
		}
		set<pair<int, int> > :: iterator it = a[cur%3].upper_bound(make_pair(cur, n+1));
		
		if (it == a[cur%3].begin())
		{
			printf("Impossible\n");
			return 0;
		}
		it--;
		pair<int, int> el = *it;
		a[cur%3].erase(it);
		cur = el.first;
		res.push_back(el.second);
		cur++;
	}
	printf("Possible\n");
	for (int i = 0; i < n; i++) printf("%d ", res[i]);
	printf("\n");
	
}


int main()
{
	int n;
	long long A;
	cin>>n>>A;
	long long sm = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin>>a[i];
		sm += a[i];
	}
	for (int i =0; i < n; i++)
	{
		long long s2 = sm-a[i];
		int up = max(0ll, a[i]-(A-(n-1)));
		int down = max(0ll, min(A-s2-1, (long long)a[i]));
		cout<<up+down<<endl;
	}
}


long long gcd(long long a, long long b)
{
	if (b==0) return a;
	return gcd(b,a%b);
}

int main()
{
	int n;
	cin>>n;
	long long mx = 0;
	long long g=0;
	for (int i = 0; i < n; i++)
	{
		long long x;
		cin>>x;
		mx = max(x, mx);
		g = gcd(x, g);
	}
	long long newN = mx/g;
	newN-= n;
	if (newN%2==0)
	{
		cout<<"Bob"<<endl;
	}
	else
	{
		cout<<"Alice"<<endl;
	}
}


map<pair<pair<int, int>,pair<int, int> >, int> dp;
vector<string> mp;
int sol(int i, int msk, int a, int b)
{
	int n = mp.size();
	int t = i%2;
	if (i == 2*n-2) return a-b;
	pair<pair<int, int>,pair<int, int> > st = make_pair(make_pair(i,msk), make_pair(a,b));
	if (dp.count(st)) return dp[st];
	int A[26]={0};
	for (int k = 0; k < n; k++)
	{
		int ki = i-k;
		if (ki >= n || ki < 0) continue;
		if (!(msk&(1<<k))) continue;
		int x, y;
		x = ki+1;
		y = k;
		if (x < n)
		{
			A[mp[x][y]-'a'] |= (1<<y);
		}
		
		x = ki;
		y = k+1;
		if (y < n)
		{
			A[mp[x][y]-'a'] |= (1<<y);
		}
	}
	int mx = -1000000;
	int mn = 1000000;
	for (int j = 0; j < 26; j++)
	{
		if (A[j] > 0)
		{
			int r = sol(i+1, A[j], a+(j==0), b + (j==1));
			mx = max(mx, r);
			mn = min(mn, r);
		}
	}
	if (i%2==1)
	{
		return dp[st] = mx;
	}
	else
	{
		return dp[st] = mn;
	}
}

int main()
{
	int n;
	cin>>n;
	mp = vector<string> (n);
	for (int i = 0; i < n; i++) cin>>mp[i];
	int r = sol(0, 1, mp[0][0]=='a', mp[0][0] == 'b');
	if (r > 0) cout<<"FIRST"<<endl;
	else if (r == 0) cout<<"DRAW"<<endl;
	else cout<<"SECOND"<<endl;
}


int main()
{
	vector<int> a(1000001, 0);
	int n, k;
	scanf("%d %d",&n,&k);
	int x;
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&x);
		a[x]++;
	}
	for (int i = 1; i < 1000001; i++) a[i] += a[i-1];
	int mx = 1;
	for (int i = 2; i < 1000001; i++)
	{
		int sm = 0;
		for (int j = i; j < 1000001; j+=i)
		{
			sm += a[min(min(j+k, j+i-1), 1000000)]-a[j-1];
		}
		if (sm == n)
		{
			mx = i;
		}
	}
	cout<<mx<<endl;
}


int main()
{
	int k,d;
	cin>>k>>d;
	k--;
	if (d==0 && k > 0)
	{
		cout<<"No solution"<<endl;
		return 0;
	}
	if (d < k%9) d+= 9;
	for (int i = 0;i < k; i++) cout<<1;
	cout<<d-k%9<<endl;
}


int main()
{
	long long c1,c2,c3,c4;
	cin>>c1>>c2>>c3>>c4;
	int n, m;
	cin>>n>>m;
	long long sm = 0;
	long long tot = 0;
	for (int i = 0; i < n; i++)
	{
		int x = 0;
		cin>>x;
		tot += min(c1*x, c2);
		sm += x;
	}
	tot = min(tot, c3);
	
	long long tot2 = 0;
	for (int i = 0; i < m; i++)
	{
		int x = 0;
		cin>>x;
		tot2 += min(c1*x, c2);
	}
	tot2 = min(tot2, c3);
	cout<<min(tot+tot2, c4)<<endl;
}


class st
{
	public:
	int x,y,z;
	st()
	{
		x = -1;
		y = -1;
		z = -1;
	}
};

int shift;
bool valid(st c)
{
	int xs = c.x+shift;
	if (xs >= 0 && xs < 300000 && c.y < 18) return true;
	return false;
}
int main()
{
	int X;
	cin>>X;
	queue<st> q;
	vector<vector<vector<st> > > tk(300000, vector<vector<st> >(18, vector<st>(2, st())));
	st cur, cur2;
	int cnt = 0;
	int fr = 0;
	shift = 131072;
	int x,y,z;
	st first;
	first.x=first.y=0;
	first.z=1;
	q.push(first);
	tk[shift][0][1].y = -2; 
	while (!q.empty())
	{
		cur = q.front();
		q.pop();
		if (cur.x == X)
		{
			x = cur.x;
			y = cur.y;
			z = cur.z;
			break;
		}
		if (cur.z)
			cur2.x = cur.x + (1<<cur.y);
		else
			cur2.x = cur.x - (1<<cur.y);
		cur2.y = cur.y+1;
		cur2.z = cur.z;
		if (valid(cur2) && tk[cur2.x+shift][cur2.y][cur2.z].y == -1)
		{
			q.push(cur2);
			tk[cur2.x+shift][cur2.y][cur2.z] = cur;
		}
		cur2.x = cur.x;
		cur2.y = 0;
		cur2.z = 1-cur.z;
		if (valid(cur2) && tk[cur2.x+shift][cur2.y][cur2.z].y == -1)
		{
			q.push(cur2);
			tk[cur2.x+shift][cur2.y][cur2.z] = cur;
		}
	}
	string s= "";
	while (y >= 0)
	{
		st par = tk[x+shift][y][z];
		if (par.x == x)
		{
			s += 'R';
		}
		else s += 'A';
		x = par.x;
		y=par.y;
		z=par.z;
	}
	reverse(s.begin(), s.end());
	cout<<s.size() - 1<<endl;
	cout<<s.substr(1, s.size() - 1)<<endl;
}
*/

int N;
int main()
{
	ifstream cin;
	ofstream cout;
	cin.open("in.in");
	cout.open("out.out");
	int T;
	cin>>T;
	for (int z = 1; z <= T; z++)
	{
		cin>>N;
		queue<pair<int,int> > q;
		q.push(make_pair(0, 0));
		vector<bool> tk(1000001, false);
		int r = -1;
		while (!q.empty())
		{
			pair<int, int> cur = q.front();
			q.pop();
			if (cur.first == N)
			{
				r = cur.second;
				break;
			}
			if (cur.first > 1000000 || tk[cur.first]) continue;
			q.push(make_pair(cur.first+1, cur.second+1));
			tk[cur.first] = true;
			int j = 0;
			int k = cur.first;
			while (k)
			{
				j*=10;
				j+= k%10;
				k/=10;
			}
			q.push(make_pair(j, cur.second+1));
		}
		cout<<"Case #"<<z<<": "<<r<<endl;
	}
}