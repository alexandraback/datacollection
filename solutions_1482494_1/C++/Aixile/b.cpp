# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <string>
# include <cmath>
# include <vector>
# include <algorithm>
# define INF 0x7FFFFFFF
# define REP(i,n) for(int i=0;i<n;i++)
# define REP1(i,n) for(int i=1;i<=n;i++)
# define CLR(i,x) memset(i,x,sizeof(i))
# define For(i,a,b)  for(int i=a;i<=b;i++)
# define vi vector<int>
# define it iterator
# define pb push_back
# define ALL(i,a) i=a.begin();i!=a.end();i++
using namespace std;

typedef long long int64;
void setIO(string name){
	string is=name+".in";
	string os=name+".out";
	freopen(is.c_str(),"r",stdin);
	freopen(os.c_str(),"w",stdout);
}

int n,ans,now;
struct lv{
	int l1,l2,sim;
	lv(int l1_=0,int l2_=0,int sim_=0):l1(l1_),l2(l2_),sim(sim_){}
};
vector <lv> q;
bool operator<(const lv &a,const lv &b){
	if(a.l2!=b.l2)	return a.l2<b.l2;
	return a.l1<b.l1;
}

bool try_lv2_0(){
	vector<lv>::it nn=q.begin();
	for(int i=0;i<q.size();i++,nn++){
		if(q[i].sim==0&&q[i].l2<=now){
			now+=2;
			ans++;
			q.erase(nn);
			return 1;
		}
	}
	return 0;
}
bool try_lv2_1(){
	vector<lv>::it nn=q.begin();

	for(int i=0;i<q.size();i++,nn++){
		if(q[i].sim==1&&q[i].l2<=now){
			now++;ans++;
			q.erase(nn);
			return 1;
		}
	}
	return 0;
}
bool try_lv1(){
	for(int i=q.size()-1;i>=0;i--){
		if(q[i].sim==0&&q[i].l1<=now){
			now++;ans++;
			q[i].sim=1;
			return 1;
		}
	}
	return 0;
}

void work(){
	q.erase(q.begin(),q.end());
	scanf("%d",&n);
	REP1(i,n){
		int a,b;
		scanf("%d %d",&a,&b);
		q.pb(lv(a,b,0));
	}
	sort(q.begin(),q.end());
	ans=now=0;
	while(!q.empty()){
		if(!try_lv2_0())
			if(!try_lv2_1())
				if(!try_lv1()){
					cout<<"Too Bad"<<endl;
					return;
				}
	}
	cout<<ans<<endl;
}

int main(){
	setIO("b");int casen;scanf("%d",&casen);
	REP1(i,casen)	printf("Case #%d: ",i),work();
	return 0;
}
