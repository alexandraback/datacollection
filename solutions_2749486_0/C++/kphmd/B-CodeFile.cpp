#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

void solve();
void runCase();

char nm[] = "NESW";
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int cx,cy,cs,cd,cl;
int x,y,s,d,l;
int X,Y;

#define mp make_pair

void runCase()
{
	scanf("%d %d",&X,&Y);
	s = 0; d = -1; l = 1; x = 0; y = 0;
	map< pair<int,pair<int,int> > , int > visit;
	set<pair<pair<int,pair<int,int> >, pair<int,int> > > que;
	set<pair<pair<int,pair<int,int> >, pair<int,int> > >::iterator ite;
	que.insert(mp(mp(s,mp(d,l)),mp(x,y)));
	
	while(!que.empty()) {
		ite = que.begin();
		cs = ite->first.first;
		cd = ite->first.second.first;
		cl = ite->first.second.second;
		cx = ite->second.first;
		cy = ite->second.second;
		
		que.erase(ite);
		visit[mp(cl,mp(cx,cy))] = cd;
		
		//printf("%d %d %d\n", cx , cy , cl);
		if(cx==X && cy==Y) {
			break;
		}
		
		for(d=0; d < 4; d++) {
			x = cx + dx[d] * cl;
			y = cy + dy[d] * cl;
			s = cs + 1;
			l = cl + 1;
			if(visit.count(mp(l,mp(x,y)))==0) que.insert(mp(mp(s,mp(d,l)),mp(x,y)));
		}
	}
	
	x = X; y = Y; l = cl;
	int nxt = visit[mp(l,mp(x,y))];
	d = nxt;
	
	//	printf("%d %d %c %d\n", x , y ,nm[d], l);
	string res;
	int i = 0;
	res+= nm[d];
	while(1) {
		if(d<0) break;
		l-=1;
		x -= dx[d]*l;
		y -= dy[d]*l;
		nxt = visit[mp(l,mp(x,y))];
		d = nxt;
		if(d<0) break;
	//printf("%d %d %c %d\n", x , y ,nm[d], l);
		i++;
		res+= nm[d];
	}
	//cout << res << endl;
	reverse(res.begin(),res.end());
	
	printf("%s\n",res.c_str());
	
	x=0; y = 0, l = 1;
	for(i = 0; i < res.length(); i++) {
		if(res[i]=='N') d=0;
		if(res[i]=='E') d=1;
		if(res[i]=='S') d=2;
		if(res[i]=='W') d=3;
		x += dx[d] * l;
		y += dy[d] * l;
		l++;
	}
	
	if(x!=X || y!=Y) {
		printf("%d %d",x,y);cout << "incorrect" << endl;
	}
	
}

void runSample()
{
	string input;

	char buf[501] = {0};
	cin.getline(buf,501);

	input = buf;


	printf("%s\n",input.c_str());
}

void solve()
{
	int n;
	scanf("%d",&n);
	getchar();

	for(int i = 0; i < n; i++) {
		printf("Case #%d: ",i+1);
		runCase();
		//runSample();
	}
}

int main()
{
	solve();
	return 0;
}
