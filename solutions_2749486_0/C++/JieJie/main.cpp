#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <stack>
#include <vector>

#define FOR(i,s,e) for (int i=(s); i<(e); i++)
#define FOE(i,s,e) for (int i=(s); i<=(e); i++)
#define FOD(i,s,e) for (int i=(s)-1; i>=(e); i--)
#define CLR(a,x) memset(a, x, sizeof(a))
#define SIZE(v) ((int)(v).size())
#define FOREACH(i,v) for(typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
typedef long long ll;
using namespace std;

int x,y;
string state;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
char dir[4]={'E','W','N','S'};
const int MAXIDX=5000;
bool a[MAXIDX][MAXIDX];
const int SHIFT=2500;
const int KK=2;
int count;
void go(int step, int curx, int cury){
	if (step>500)	return;
	FOR(i,0,4){
		if (a[SHIFT+x][SHIFT+y])	return;
		int nx=curx+dx[i]*step, ny=cury+dy[i]*step;
		
		//	if ((nx<SHIFT-abs(KK*x)) || (nx>SHIFT+abs(KK*x)) || ny<0 || ny>=MAXIDX)	continue;
		if (nx<0 || nx>=MAXIDX || ny<0 || ny>=MAXIDX)	continue;
		//if ((nx<SHIFT-abs(KK*x)) || (nx>SHIFT+abs(KK*x)) || (ny<SHIFT-abs(KK*y)) || (ny>SHIFT+abs(KK*y)))	continue;

		if (!a[nx][ny]){
			a[nx][ny]=true;
			if ((nx==SHIFT+x)&&(ny==SHIFT+y)){
				cout<<state + dir[i]<<endl;
				return;
			}
			state += dir[i];
			go(step+1, nx, ny);
			state.pop_back();
			if (a[SHIFT+x][SHIFT+y])	return;
		}
	}	
}

void solve(){
	CLR(a,false);
	cin>>x>>y;
	state="";
	int xx=abs(x);
	int sum=0;
	FOE(i,1,xx-1){
		sum+=i;
		cout<<"N";
	}
	if (xx==0){}
	else {
		if (x<0)	cout<<"W";
		else cout<<"E";
	}
	if (y==sum){}
	else if (y>sum){
		FOE(i,1,y-sum)	cout<<"NS";
	}
	else{
		FOR(i,1,sum-y)	cout<<"SN";
	}
	cout<<endl;
	a[SHIFT][SHIFT]=true;
	//go(1,0+SHIFT,0+SHIFT);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("B-small-attempt0.in", "rt", stdin);
	//freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	int t;
	cin>>t;
	FOR(i,0,t){
		cout<<"Case #"<<i+1<<": ";
		solve();
	}
	return 0;
}
