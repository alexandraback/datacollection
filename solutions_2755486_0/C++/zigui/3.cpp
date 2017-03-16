#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>

struct attack{
	int w,e,s,d;
	attack(){}
	attack(int w,int e,int s,int d):w(w),e(e),s(s),d(d){}
	bool operator<(const attack &l)const{
		return d<l.d;
	}
};

std::vector<attack> list;
int arr[2][100005];
int* wall;
int n;

void input()
{
	list.clear();
	wall=arr[1];
	int i,j;
	int cnt,d,p,s;
	attack pp;
	for(i=-99999;i<100000;i++)wall[i]=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d%d%d%d%d%d",&pp.d,&cnt,&pp.w,&pp.e,&pp.s,&d,&p,&s);
		for(j=1;j<=cnt;j++){
			list.push_back(pp);
			pp.d+=d; pp.w+=p; pp.e+=p; pp.s+=s;
		}
	}
	std::sort(list.begin(),list.end());
}

bool insert(attack p)
{
	int i;
	for(i=p.w;i<p.e;i++){
		if(wall[i]<p.s)return true;
	}
	return false;
}

void write(attack p)
{
	int i;
	for(i=p.w;i<p.e;i++){
		if(wall[i]<p.s)wall[i]=p.s;
	}
}

void solve()
{
	int i,j,p,ans=0;
	for(i=0;i<list.size();i=j){
		p=list[i].d;
		for(j=i;j<list.size();j++){
			if(p!=list[j].d)break;
			ans+=insert(list[j]);
		}
		for(j=i;j<list.size();j++){
			if(p!=list[j].d)break;
			write(list[j]);
		}
	}
	printf("%d\n",ans);
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,T;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		input();
		printf("Case #%d: ",t);
		solve();
	}
}