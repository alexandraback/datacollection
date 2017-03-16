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

int n,m;
double cor[110000],p[110000];
double cal0(){
	return cor[n]*(m-n+1)+(1-cor[n])*(m-n+1+m+1);
}
double cal1(int ti){
	return cor[n-ti]*(ti+m-(n-ti)+1)+(1-cor[n-ti])*(ti+m-(n-ti)+1+m+1);
}
double cal2(){
	return 1+1+m;
}

void work(){
	scanf("%d %d",&n,&m);
	cor[0]=1;
	REP1(i,n)	scanf("%lf",p+i),cor[i]=cor[i-1]*p[i];
	double ans=1e10;
	ans=min(ans,cal0());
	REP1(i,n)	ans=min(ans,cal1(i));
	ans=min(ans,cal2());
	printf("%.8lf\n",ans);
}

int main(){
	setIO("a");
	int casen;scanf("%d",&casen);
	//cout<<casen<<endl;
	//return 0;
	REP1(i,casen)	printf("Case #%d: ",i),work();
	return 0;
}
