#include<cstdio>
#include<vector>
#define PB push_back
using namespace std;
int t,test,k,l,s,mx;
char tab[110];
char L[110];
char curr[110];
vector<int> v;
double EW,p;
bool comp(int x){
	if(x+l-1>=s)
		return false;
	for(int i=0;i<l;++i)
		if(curr[x+i]!=L[i])
			return false;
	return true;
	}
int licz(){
	int ret = 0;
    for(int i=0;i<s;++i){
		if(comp(i))
			ret++;
		}
	return ret;
	}
void generuj(int x){
	if(x==s){
		int ret = licz();
		if(ret>mx)
			mx = ret;
		v.PB(ret);
		}
	else{
		for(int i=0;i<k;++i){
			curr[x] = tab[i];
			generuj(x+1);
			}
		}
	}
int main(){
	freopen("t.in","r",stdin);
	freopen("t.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		v.clear();
		mx = 0;
		EW = 0.0;
		++test;
		printf("Case #%d: ",test);
		scanf("%d%d%d",&k,&l,&s);
		for(int i=0;i<k;++i)
			scanf(" %c",&tab[i]);
		for(int i=0;i<l;++i)
			scanf(" %c",&L[i]);
		generuj(0);
		for(int i=0;i<v.size();++i){
			p = (double)(mx-v[i]);
			EW+= p;
			}
		EW/= (double)(v.size());
		printf("%.8lf\n",EW);
		}
	}
