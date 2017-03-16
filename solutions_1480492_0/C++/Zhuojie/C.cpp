#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

const double eps=1e-8;

class node{
public:
	double l,r;
	int car;
	vector<node*> lj;
	node* fa;
	int num,pos;
	node* father(){return fa==this?this:fa=fa->father();}

	node(double l,double r,int car,int pos):l(l),r(r),car(car),pos(pos){
		fa=this;
		num=0;
	}

	void print(){
		printf("%d %d %.2lf %.2lf %d\n",car,pos,l,r,num);
	}
};

int num=0;
int len=0;
node* nodelist[10000];

void add(node* a,node *_a, node *b, node *_b){
	a->lj.push_back(b);
	_a->lj.push_back(_b);
	b->lj.push_back(a);
	_b->lj.push_back(_a);
}

void addedge(int i,int j,double l,double r){
	node*a = new node(l,r,i,1);
	node *_a=new node(l,r,i,-1);
	node *b=new node(l,r,j,1);
	node *_b=new node(l,r,j,-1);
	nodelist[len++]=a;
	nodelist[len++]=_a;
	nodelist[len++]=b;
	nodelist[len++]=_b;
	add(a,_a,_b,b);
}

void merge(node*a,node*b){
	node*af= a->father();
	node*bf= b->father();
	if (af==bf) return;
	af->fa=bf;
	bf->l=min(af->l,bf->l);
	bf->r=max(af->r,bf->r);
}

bool dfs(node*now,node*tar,double limit){
	if (now->num==num) return false;
	now->num=num;
	if (now->l>limit) return false;
	if (now==tar) return true;


	for (int i=0;i<now->lj.size();++i)
		if (dfs(now->lj[i],tar,limit))
			return true;
	return false;
}

bool solve(double t){
	for (int i=0;i<len;i+=2){
		++num;
		if (dfs(nodelist[i],nodelist[i+1],t))
			return false;
	}
	return true;
}

int T,I=0,n;
char c[100];
int s[100],p[100];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		len=0;
		for (int i=0;i<n;++i){
			scanf(" %c%d%d",&c[i],&s[i],&p[i]);
		}
		for (int i=0;i<n;++i)
			for (int j=i+1;j<n;++j){
				if (s[i]==s[j]){
					if (abs(p[i]-p[j])<5){
						addedge(i,j,0,50000);
					}
				}
				else{
					double l=(p[j]-p[i]-5)*1.0/(s[i]-s[j]);
					double r=(p[j]-p[i]+5)*1.0/(s[i]-s[j]);
					if (l>r) swap(l,r);
					if (l<-1) l=-1;
					if (r>50000) r=50000;
					if (r<-eps)
						continue;
					if (l>r+eps)
						continue;
					addedge(i,j,l,r);
				}
			}
		for (int i=0;i<len;i+=2)
			for (int j=i+2;j<len;j+=2){
				if (nodelist[i]->car == nodelist[j]->car &&
					nodelist[i]->l + eps < nodelist[j]->r &&
					nodelist[j]->l + eps < nodelist[i]->r){

					add(nodelist[i],nodelist[i+1],nodelist[j],nodelist[j+1]);
				}

				if (nodelist[i]->l<-eps && nodelist[j]->l<-eps){
					if (c[nodelist[i]->car]==c[nodelist[j]->car])
						add(nodelist[i],nodelist[i+1],nodelist[j],nodelist[j+1]);
					else
						add(nodelist[i],nodelist[i+1],nodelist[j+1],nodelist[j]);
				}
			}

		double l=0,r=30000;
		while (r-l>eps){
			double mid = (l+r)/2;
			if (solve(mid)) l=mid;
			else r=mid;
		}
		printf("Case #%d: ",++I);
		if (l>15000)
			puts("Possible");
		else
			printf("%.8lf\n",l);
		for (int i=0;i<len;++i)
			delete nodelist[i];
	}
}
