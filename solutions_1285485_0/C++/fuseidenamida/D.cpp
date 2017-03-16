#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<set>
#include<cmath>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define EPS (1e-8)
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int h,w;
int d;
char buf[50][50];
int main(){
	int t;scanf("%d",&t);
	REP(setn,t){
		scanf("%d%d%d",&h,&w,&d);
		REP(i,h) scanf("%s",buf[i]);
		int sx,sy;
		REP(i,h) REP(j,w) if(buf[i][j]=='X'){
			sx=j;sy=i;
			buf[i][j]='.';
		}
		set<pi> done;
		int res=0;
		for(int i=-d;i<=d;++i) for(int j=-d;j<=d;++j){
			if(i*i+j*j>d*d) continue;
			int g=__gcd(i,j);
			g=abs(g);
			if(g==0) continue;
			pi ins=mp(i/g,j/g);
			if(done.count(ins)) continue;

			double px=i,py=j;
			double cx=sx+0.5,cy=sy+0.5;
			
			double rest=sqrt((double)(i*i+j*j));
			
			py/=rest;px/=rest;
			int fail=0;
			while(rest>EPS){
				double scale=rest;
				if(fmod(cx+EPS,1.0)>2*EPS){
					if(abs(px)>EPS){
						if(px<0) scale=min(scale,-fmod(cx,1.0)/px);
						else scale=min(scale,(1.0-fmod(cx,1.0))/px);
					}
				}else scale=0;
				if(fmod(cy+EPS,1.0)>2*EPS){
					if(abs(py)>EPS){
						if(py<0) scale=min(scale,-fmod(cy,1.0)/py);
						else scale=min(scale,(1.0-fmod(cy,1.0))/py);
					}
				}else scale=0;
				cx+=scale*px;
				cy+=scale*py;
				rest-=scale;
				if(rest<EPS) break;
				
				if(fmod(cx+EPS,1.0)<=2*EPS && fmod(cy+EPS,1.0)>2*EPS){
					int x=cx+EPS,y=cy;
					if(px>0){
						if(buf[y][x]=='#'){
							px=-px;
						}
					}else{
						if(buf[y][x-1]=='#'){
							px=-px;
						}
					}
				}else if(fmod(cx+EPS,1.0)>2*EPS && fmod(cy+EPS,1.0)<2*EPS){
					int x=cx,y=cy+EPS;
					if(py>0){
						if(buf[y][x]=='#'){
							py=-py;
						}
					}else{
						if(buf[y-1][x]=='#'){
							py=-py;
						}
					}
				}else if(fmod(cx+EPS,1.0)<2*EPS && fmod(cy+EPS,1.0)<2*EPS){
					int x=cx+EPS,y=cy+EPS;
					if(px<0 && py<0){
						if(buf[y-1][x-1]=='#'){
							if(buf[y-1][x]=='#' && buf[y][x-1]=='#'){
								px=-px;py=-py;
							}else if(buf[y-1][x]=='#'){
								py=-py;
							}else if(buf[y][x-1]=='#'){
								px=-px;
							}else{
								fail=1;break;
							}
						}
					}else if(px>0 && py<0){
						if(buf[y-1][x]=='#'){
							if(buf[y-1][x-1]=='#' && buf[y][x]=='#'){
								py=-py;px=-px;
							}else if(buf[y-1][x-1]=='#'){
								py=-py;
							}else if(buf[y][x]=='#'){
								px=-px;
							}else{
								fail=1;break;
							}
						}
					}else if(px<0 && py>0){
						if(buf[y][x-1]=='#'){
							if(buf[y-1][x-1]=='#' && buf[y][x]=='#'){
								py=-py;px=-px;
							}else if(buf[y-1][x-1]=='#'){
								px=-px;
							}else if(buf[y][x]=='#'){
								py=-py;
							}else{
								fail=1;break;
							}
						}
					}else if(px>0 && py>0){
						if(buf[y][x]=='#'){
							if(buf[y-1][x]=='#' && buf[y][x-1]=='#'){
								py=-py;px=-px;
							}else if(buf[y-1][x]=='#'){
								px=-px;
							}else if(buf[y][x-1]=='#'){
								py=-py;
							}else{
								fail=1;break;
							}
						}
					}
				}
				cx+=px*1e-3;
				cy+=py*1e-3;
				rest-=1e-3;
			}
			if(fail) continue;
			if(abs(cx-sx-0.5)<EPS && abs(cy-sy-0.5)<EPS){
				++res;
				done.insert(ins);
			}
		}
		printf("Case #%d: %d\n",setn+1,res);
	}

				


				
	return 0;
}



