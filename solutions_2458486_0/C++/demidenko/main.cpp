#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<memory.h>
#include<cmath>
#include<ctime>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#define abs(x) ((x)<0?-(x):(x))
#define _max(x,y) ((x)<(y)?(y):(x))
#define _min(x,y) ((x)<(y)?(x):(y))
#define sqr(x) ((x)*(x))
#define getar(m,n) for(int _=0;_<n;++_) cin>>(m)[_];
#define forc(it,c) for(typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define fill(m,v) memset(m,v,sizeof(m))
#define random(x) ((rand()<<15^rand())%(x))
#define y1 stupid_cmath
#define y0 stupid_cmath_make_me_cry
#define tm stupid_ctime
typedef long long ll;
using namespace std;

int n,m;
int i,j,k,l;
bool d[(1<<20)+123];
int c[222];
vector<int> a[222];
vector<int> st;
int to[222];

int main(){
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	
	int tn,ti;
	scanf("%d",&tn);
	for(ti=1;ti<=tn;++ti){
		
		cin>>k>>n;
		for(i=0;i<n;++i) a[i].clear();
		fill(c,0);
		fill(to,0);
		fill(d,0);
		st.clear();
		
		for(i=0;i<k;++i){
			cin>>j; --j;
			st.push_back(j);
		}
		
		for(i=0;i<n;++i){
			cin>>to[i]>>l;
			--to[i];
			while(l--){
				cin>>j; --j;
				a[i].push_back(j);
			}
		}
		
		int M=1<<n;
		d[M-1]=true;
		for(m=M-2;m>=0;--m){
			fill(c,0);
			forc(it, st) c[*it]++;
			for(i=0;i<n;++i) if(m>>i&1){
				forc(it, a[i]) c[*it]++;
				c[to[i]]--;
			}
			
			for(i=0;i<n;++i) if(!(m>>i&1)){
				if(c[to[i]]>0) d[m]|=d[m|(1<<i)];
			}
		}
		
		cout<<"Case #"<<ti<<": ";
		if(!d[0]) cout<<"IMPOSSIBLE"; else{
			m=0;
			while(m!=M-1){
				fill(c,0);
				forc(it, st) c[*it]++;
				for(i=0;i<n;++i) if(m>>i&1){
					forc(it, a[i]) c[*it]++;
					c[to[i]]--;
				}
				
				for(i=0;i<n;++i) if(!(m>>i&1)){
					if(c[to[i]]>0 && d[m|(1<<i)]){
						m|=1<<i;
						cout<<i+1<<' ';
						break;
					}
				}
			}
		}
		cout<<endl;
	}
		
	
	
	return 0;
}
