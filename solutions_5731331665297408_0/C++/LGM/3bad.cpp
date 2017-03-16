// /\||/\||
//
//
//////////////////////
// Program: 
// Written By Alireza Farhadi (LGM)
//////////////////////
#include <bits/stdc++.h>

using namespace std;

#if ( _WIN32 || __WIN32__ )
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

#define show(x) ldo(cl,cerr<<((#x))<<" = "<<((x))<<" "<<endl)
#define bit(a,b) (((a)>>(b))&1)
#define FE(i, c) for(auto i = ((c)).begin(); i != ((c)).end(); i++)
#define get(x,i) (get<((i))>(((x))))
#define ALL(x) ((x)).begin(),((x)).end()
#define Mt make_tuple
#define gcd __gcd
#define endl '\n'
#define bcnt(x) ((__builtin_popcount(x)))
#define bcntll(x) ((__builtin_popcountll(x)))
#define sz(x) ((int((x).size())))
#define sqr(x) ((((x))*((x))))
#define fx(x) fixed<<setprecision(x)
#define fl endl<<flush
#define list _list
#define ldo(l,x) {(l).lock(); x; (l).unlock();}

template<class T> inline void smn(T &a,const T &b){if(b<a) a=b;}
template<class T> inline void smx(T &a,const T &b){if(b>a) a=b;}
template<class T> inline T _rev(const T & a){T _=a; reverse(_.begin(),_.end()); return _;}


/*
ifstream fin(".in");
ofstream fout(".out");
#define cin fin
#define cout fout
*/

int Main();
int main()
{
	ios_base::sync_with_stdio(false);
	cout<<fixed<<setprecision(10);
	return Main();
}

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pie;
typedef pie pii;
typedef tuple<int,int,int> trip;
typedef complex<double> point;

const double eps=1e-8;
const ld leps=1e-14;


typedef mutex lck;

lck cl,ac;

atomic_int active;
const int MAXT=8;
condition_variable _p;
atomic_bool isrun;
int _size;
struct container {int id; thread runner; lck *_il,*_ol; container() { _il=new lck(),_ol=new lck(); _il->lock();_ol->lock();}};

const int MN=100;

struct thread_block:container
{
	vector <int> list[MN];
	bool visited[MN];
	int n,m;
	string code[MN];
	string bst;
	void input()
	{
		cin>>n>>m;
		for (int i=0;i<n;i++) cin>>code[i];
		for (int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b; a--; b--;
			list[a].push_back(b);
			list[b].push_back(a);
		}
	}
	void bt(vector<int> p,string c,int no)
	{
		if (no==n)
		{
			if (bst=="" || bst>c)
				bst=c;
			return ;
		}
		if (p.size()>1)
		{
			vector <int> _=p;
			_.pop_back();
			bt(_,c,no);
		}
		int v=p.back();
		for (int & x:list[v]) if (visited[x]==0)
		{
			visited[x]=1;
			vector <int> _=p;
			_.push_back(x);
			bt(_,c+code[x],no+1);
			visited[x]=0;
		}
	}
	void solve()
	{
		memset(visited,0,sizeof(visited));
		for (int i=0;i<n;i++)
		{
			visited[i]=1;
			bt(vector<int> {i},code[i],1);
			visited[i]=0;
		}
	}
	void output()
	{
		cout<<"Case #"<<id+1<<": "<<bst<<endl;
	}
};

vector<thread_block> threads;

void run(int id,thread_block& th)
{
	th.id=id;
	ldo(ac,active++);
	isrun=true;
	ldo(*th._il,ldo(cl,th.input()));
	if (id+1<_size) threads[id+1]._il->unlock();
	th.solve();
	ldo(ac,active --; _p.notify_one());
	ldo(*th._ol,ldo(cl,th.output(); cout<<flush;));
	if (id+1<_size) threads[id+1]._ol->unlock();
}
int Main()
{
	int &t=_size,id=0;
	active=0;
	isrun=true;
	cin>>t;
	threads.resize(t);
	if (t>0) threads[0]._il->unlock(),threads[0]._ol->unlock();
	for (auto & x:threads)
	{
		while (!isrun) ;
		unique_lock<lck> l(ac);
		if (active>=MAXT) _p.wait(l);
		else l.unlock();
		isrun=false;
		x.runner=thread(run,id++,std::ref(x));
	}
	for (auto & x:threads)
		x.runner.join();
	return 0;
}
