#include<stdio.h>
#include<vector>
#define ZERO 500000
#define MAXDAY 700000
using namespace std;
int hi[1000000];
typedef struct {
	int w;
	int e;
	int s;
}s_event;
vector<s_event> event[MAXDAY];
int n;
int main(){
	int t;
	scanf("%d",&t);
	for(int e = 0; e < t ; e++ ){
		scanf("%d",&n);
		for(int i = 0; i < MAXDAY ; i++ ) event[i].clear();
		for(int i = 0; i < 1000000 ; i++ ) hi[i] = 0;
		for(int i = 0 ; i < n ;i++ ){
			int di ;
			int ni, wi,ei,si,ddi,dpi,dsi;
			scanf("%d %d %d %d %d %d %d %d",&di,&ni,&wi,&ei,&si,&ddi,&dpi,&dsi);
			for(int j = 0 ; j < ni ; j++ ){
				s_event test;
				test.w = wi+j*dpi;
				test.e = ei+j*dpi-1;
				test.s = si+j*dsi;
				event[di+j*ddi].push_back(test);
			}
		}
		int ans = 0;
		for(int k = 0 ; k < MAXDAY ; k++ ){
			for(int i = 0 ; i < event[k].size() ; i++ ){
				int chk = 0;
				int wi,ei,si;
				wi = event[k][i].w;
				ei = event[k][i].e;
				si = event[k][i].s;
				for(int j = wi ;j <= ei ; j++ ){
					if( hi[j+ZERO] < si ){ chk = 1; break; }
				}
				if( chk ) ans++;
			}
			for(int i = 0 ; i < event[k].size() ; i++ ){
				int wi,ei,si;
				wi = event[k][i].w;
				ei = event[k][i].e;
				si = event[k][i].s;
				for(int j = wi ; j <= ei ; j++ ){
					if( hi[j+ZERO] < si ) hi[j+ZERO] = si;
				}
			}
		}
		printf("Case #%d: %d\n",e+1,ans);
	}
}


				


