#include <iostream>
#include <iomanip>
#include <cmath>
#include <set>
#include <queue>
#include <sstream>
#include <fstream>
using namespace std;


/*
int main()
{
	ifstream cin;
	ofstream cout;
	cin.open("in.in");
	cout.open("out.out");
	int n;
	cin>>n;
	for (int i = 1; i <=n; i++)
	{
		int c, l,p;
		cin>>c;
		cin>>l;
		queue<int> a[1001];
		for (int i = 0; i < l; i++)
		{
			cin>>p;
			a[p].push(i+1);
		}
		int x,y;
		for (int i = 1; i  < 1001; i++)
		{
			if (a[i].size() == 0) continue;
			x = a[i].front();
			a[i].pop();
			if (a[c-i].size() >0)
			{
				y = a[c-i].front();
				break;
			}
		}
		if (x > y) swap(x,y);
		cout<<"Case #"<<i<<": "<<x<<" "<<y<<endl;
	}
}


int main()
{
	ifstream cin;
	ofstream cout;
	cin.open("in.in");
	cout.open("out.out");
	int n;
	cin>>n;
	cin.ignore();
	for (int i = 1; i <=n; i++)
	{
		string l;
		getline(cin, l);
		stringstream ss;
		ss<<l;
		vector<string> w;
		string wo;
		while (ss>>wo)
		{
			w.push_back(wo);
		}
		reverse(w.begin(), w.end());
		cout<<"Case #"<<i<<": "<<w[0];
		for (int i = 1; i < w.size(); i++)
			cout<<" "<<w[i];
		cout<<endl;
	}
}


int main()
{
	ifstream cin;
	ofstream cout;
	cin.open("in.in");
	cout.open("out.out");
	int n;
	cin>>n;
	cin.ignore();
	pair<int,int> mp[256];
	mp['a'] = make_pair(2,1);
	mp['b'] = make_pair(2,2);
	mp['c'] = make_pair(2,3);
	mp['d'] = make_pair(3,1);
	mp['e'] = make_pair(3,2);
	mp['f'] = make_pair(3,3);
	mp['g'] = make_pair(4,1);
	mp['h'] = make_pair(4,2);
	mp['i'] = make_pair(4,3);
	mp['j'] = make_pair(5,1);
	mp['k'] = make_pair(5,2);
	mp['l'] = make_pair(5,3);

	mp['m'] = make_pair(6,1);
	mp['n'] = make_pair(6,2);
	mp['o'] = make_pair(6,3);
	mp['p'] = make_pair(7,1);
	mp['q'] = make_pair(7,2);
	mp['r'] = make_pair(7,3);
	mp['s'] = make_pair(7,4);
	mp['t'] = make_pair(8,1);
	mp['u'] = make_pair(8,2);
	mp['v'] = make_pair(8,3);
	mp['w'] = make_pair(9,1);
	mp['x'] = make_pair(9,2);
	mp['y'] = make_pair(9,3);
	mp['z'] = make_pair(9,4);
	mp[' '] = make_pair(0,1);
	for (int i = 1; i <=n; i++)
	{
		string l;
		getline(cin, l);
		cout<<"Case #"<<i<<": ";
		int prv = -1;
		for (int j = 0; j < l.size(); j++)
		{
			if (mp[l[j]].first == prv) cout<<' ';
			for (int k = 0; k < mp[l[j]].second; k++) cout<<mp[l[j]].first;
			prv = mp[l[j]].first;
		}
		cout<<endl;
	}
}


int main()
{
	ifstream cin;
	ofstream cout;
	cin.open("in.in");
	cout.open("out.out");
	int n;
	cin>>n;
	for (int i = 1; i <=n; i++)
	{
		int sz;
		cin>>sz;
		vector<long long> v1(sz),v2(sz);
		for (int j = 0; j < sz; j++)
			cin>>v1[j];
		for (int j = 0; j < sz; j++)
			cin>>v2[j];
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		reverse(v1.begin(), v1.end());
		long long r = 0;
		for (int j = 0; j < sz; j++)
			r += v1[j]*v2[j];
		cout<<"Case #"<<i<<": "<<r<<endl;
	}
}


int main()
{
	ifstream cin;
	ofstream cout;
	cin.open("in.in");
	cout.open("out.out");
	int n;
	cin>>n;
	for (int i = 1; i <=n; i++)
	{
		int N,M;
		cin>>N>>M;
		vector<set<int> > un(M);
		vector<int> ma(M,-1);
		vector<vector<int> > lk(N);
		vector<bool> tk(N);
		bool ok = true;
		queue<int> q;
		for (int j = 0; j < M; j++)
		{
			int t;
			cin>>t;
			for (int k = 0; k < t; k++)
			{
				int x,y;
				cin>>x>>y;
				if (y == 1) ma[j] = x-1;
				else
				{
					lk[x-1].push_back(j);
					un[j].insert(x-1);
				}
			}
			if (un[j].empty())
				q.push(ma[j]);
		}
		while (!q.empty() && ok)
		{
			int m = q.front();
			q.pop();
			if (tk[m]) continue;
			tk[m] = true;
			for (int j = 0; j < lk[m].size(); j++)
			{
				un[lk[m][j]].erase(m);
				if (un[lk[m][j]].empty())
				{
					if (ma[lk[m][j]] == -1)
					{
						ok = false;
						break;
					}
					else
						q.push(ma[lk[m][j]]);
				}
			}
		}
		cout<<"Case #"<<i<<":";
		if (!ok)
		{
			cout<<" IMPOSSIBLE"<<endl;
		}
		else
		{
			for (int j = 0; j < N; j++)
			{
				if (tk[j]) cout<<" 1";
				else
					cout<<" 0";
			}
			cout<<endl;
		}
	}
}


	int main()
{

	ifstream cin;
	ofstream cout;
	cin.open("in.in");
	cout.open("out.out");

	int t;
	cin>>t;
	for (int i=0; i < t; i++)
	{
		int x,y;
		cin>>x;
		int a[4][4];
		int b[4][4];
		for (int j = 0; j < 4; j++) for (int k = 0; k < 4; k++) cin>>a[j][k];
		cin>>y;
		int aa[4];
		for (int j = 0; j < 4; j++) aa[j] = a[x-1][j];
		for (int j = 0; j < 4; j++) for (int k = 0; k < 4; k++) cin>>b[j][k];
		int bb[4];
		for (int j = 0; j < 4; j++) bb[j] = b[y-1][j];
		int cnt = 0;
		int val = -1;
		for (int j = 0; j < 4; j++) for (int k = 0; k < 4; k++)
		{
			if (aa[j] == bb[k])
			{
				cnt++;
				val = aa[j];
			}
		}
		cout<<"Case #"<<i+1<<": ";
		if (cnt > 1)
		{
			cout<<"Bad magician!"<<endl;
		}
		else if (cnt == 1)
			cout<<val<<endl;
		else
			cout<<"Volunteer cheated!"<<endl;

	}
	system("pause");
}


	int main()
{
	
	ifstream cin;
	ofstream cout;
	cin.open("in.in");
	cout.open("out.out");
	
	int t;
	cin>>t;
	for (int i=0; i < t; i++)
	{
		double rt = 2.0;
		double c,f,x;
		cin>>c>>f>>x;
		double mn = x/rt;
		double cst = 0;
		for (int j = 0; j < 10000000; j++)
		{
			cst += c/rt;
			rt += f;
			if (mn > cst + (x/rt))
				mn = cst + (x/rt);
			else
				break;
		}
		cout<<"Case #"<<i+1<<": ";
		cout<<fixed<<setprecision(8)<<mn<<endl;
	}
	system("pause");
}


	int main()
{
	
	ifstream cin;
	ofstream cout;
	cin.open("in.in");
	cout.open("out.out");

	int t;
	cin>>t;
	for (int i=0; i < t; i++)
	{
		int r,c,m;
		cin>>r>>c>>m;
		if (r == 1 && c == 1)
		{
			cout<<"Case #"<<i+1<<":"<<endl<<'c'<<endl;
		}
		else if (r == 1)
		{
			if (c-m < 2)
			{
				cout<<"Case #"<<i+1<<":"<<endl<<"Impossible"<<endl;
				continue;
			}
			cout<<"Case #"<<i+1<<":"<<endl<<'c';
			for (int j = 0; j < c-m-1; j++)
			{
				cout<<'.';
			}
			for (int j = 0; j < m; j++)
			{
				cout<<'*';
			}
			cout<<endl;
		}
		else if (c == 1)
		{
			if (r-m < 2)
			{
				cout<<"Case #"<<i+1<<":"<<endl<<"Impossible"<<endl;
				continue;
			}
			cout<<"Case #"<<i+1<<":"<<endl<<'c'<<endl;
			for (int j = 0; j < r-m-1; j++)
			{
				cout<<'.'<<endl;
			}
			for (int j = 0; j < m; j++)
			{
				cout<<'*'<<endl;
			}
		}
		else
		{
			if (r*c - m < 4)
			{
				cout<<"Case #"<<i+1<<":"<<endl<<"Impossible"<<endl;
				continue;
			}
			cout<<"Case #"<<i+1<<":"<<endl;
			for (int j = 0; j < r; j++)
			{
				for (int k = 0; k < c; k++)
				{
					if (j==0 && k == 0) cout<<'c';
					else if (r*j+k < r*c-m)
						cout<<'.';
					else
						cout<<'*';
				}
				cout<<endl;
			}
		}
	}
	system("pause");
}
	*/

int main()
{
	
	ifstream cin;
	ofstream cout;
	cin.open("in.in");
	cout.open("out.out");
	
	int t;
	cin>>t;
	for (int i = 1; i <= t; i++)
	{
		int n;
		cin>>n;
		vector<double> a(n);
		vector<double> b(n);
		for (int j= 0; j < a.size(); j++) cin>>a[j];
		for (int j= 0; j < a.size(); j++) cin>>b[j];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		set<double> s;

		int z = 0;
		for (int j = 0; j < n; j++)
		{
			s.insert(b[j]);
		}
		for (int j = 0; j < n; j++)
		{
			set<double> ::iterator in = s.upper_bound(a[j]);
			if (in==s.end())
			{
				z++;
				s.erase(s.begin());
			}
			else
				s.erase(in);
		}
		int y = 0;
		for (int k=0; k < n; k++)
		{
			set<double> s2;
			int yy = 0;
			for (int j = k; j < n; j++)
			{
				s2.insert(a[j]);
			}
			for (int j = 0; j < n-k; j++)
			{
				set<double> ::iterator in = s2.upper_bound(b[j]);
				if (in==s2.end())
				{
					s2.erase(s2.begin());
				}
				else
				{
					yy++;
					s2.erase(in);
				}
			}
			y = max(yy,y);
		}
		cout<<"Case #"<<i<<": "<<y<<" "<<z<<endl;
	}
	system("pause");
}