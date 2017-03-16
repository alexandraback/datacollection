#include <stdio.h>
#include <algorithm>
using namespace std;
int n,rep;
char mun[10005];
#define mp make_pair
#define status pair<int, char>
inline status trans(status p, char c){
	if(c=='1')
		return p;
	else if(p.second=='1')
		return mp(p.first,c);
	else if(p.second == c)
		return mp(-1 * p.first, '1');
	else if(p.second=='i' && c=='j')
		return mp(p.first, 'k');
	else if(p.second=='i' && c=='k')
		return mp(-1 * p.first, 'j');
	else if(p.second=='j' && c=='i')
		return mp(-1 *p.first, 'k');
	else if(p.second=='j' && c=='k')
		return mp(p.first, 'i');
	else if(p.second=='k' && c=='i')
		return mp(p.first, 'j');
	else if(p.second=='k' && c=='j')
		return mp(-1 * p.first, 'i');
}

bool check(){
	int now_idx = 0;
	status now_stat = mp(1,'1');
	// i phase
	int cnt = 10;
	while(1){
		if(rep<=0 || cnt<0) return false;
		now_stat = trans(now_stat, mun[now_idx]);
		now_idx++;
		if(now_idx>=n){
			rep--;
			cnt--;
			now_idx=0;
		}
		if(now_stat.first==1 && now_stat.second == 'i') break;
	}
	// j phase
	now_stat = mp(1,'1');
	cnt = 10;
	while(1){
		if(rep<=0 || cnt<0) return false;
		now_stat = trans(now_stat, mun[now_idx]);
		now_idx++;
		if(now_idx>=n){
			rep--;
			cnt--;
			now_idx=0;
		}
		if(now_stat.first==1 && now_stat.second == 'j') break;
	}
	// k phase
	if(rep<=0) return false;
	now_stat = mp(1,'1');
	for(;now_idx<n;now_idx++){
		now_stat = trans(now_stat, mun[now_idx]);
	}
	rep--;
	rep%=4;
	while(rep--){
		for(int i=0;i<n;i++){
			now_stat = trans(now_stat, mun[i]);
		}
	}

	if(now_stat.first==1 && now_stat.second=='k')
		return true;
	return false;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int testt;
	scanf("%d",&testt);
	for(int test=1;test<=testt;test++){
		scanf("%d %d",&n,&rep);
		scanf("%s",mun);

		if(check())
			printf("Case #%d: YES\n",test);
		else
			printf("Case #%d: NO\n", test);

	}
	return 0;
}
