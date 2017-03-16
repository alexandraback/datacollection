#include<iostream>
#include<algorithm>
using namespace std;
const double eps = 0.000001;
struct type
{
	int index;
	double v;
};
bool cmp(type a,type b)
{
	return a.v<b.v;
}
bool cmp_i(type a,type b)
{
	return a.index<b.index;
}
type m[1000];
int N;
double X;

bool check(double yi,int num)
{
	double V=m[num].v+yi*X/100.0;
	double last=100.0-yi,yj;
	for(int i=1;i<=N;i++)
	{
		if(i==num) continue;
		if(m[i].v<=V)
		{
			yj=(V-m[i].v)*100.0/X;
			if(last<yj) return true;
			last-=yj;
		}
	}
	return false;
}
double bs(double l,double r,int num)
{
	double my=(l+r)/2.0;
	if(r-l<eps) return my;
	if(check(my,num)) return bs(l,my,num);
	return bs(my,r,num); // my не подходит!!!
}
void solve(int T)
{
	int i;
	scanf("%d",&N);
	for(i=1,X=0.0;i<=N;i++) 
	{
		scanf("%lf",&m[i].v);
		m[i].index=i;
		X+=m[i].v;
	}
	printf("Case #%d: ",T); 
	for(i=1;i<=N;i++) printf("%.6lf ",bs(0.0,100.0,i));
	printf("\n");
}

int main()
{
	int i,T;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	for(i=1;i<=T;i++) solve(i);
	return 0;
}