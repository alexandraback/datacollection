#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
int x,y,cnt=0, dx[]={1,0,-1,0}, dy[]={0, 1, 0, -1};
char ch[]={'E', 'N', 'W','S'};
map<pair<int,int> ,pair<int, string> > st,nst;
/*
void pre(){
	st[make_pair(0,0)] = make_pair(0,"");
	for(int i=1; i<50; i++){
		fprintf(stderr, "%d",i);
		nst = st;
		//cout<<endl<<i<<endl<<endl;
		for(map<pair<int,int> ,pair<int, string> >::iterator it = nst.begin(); it!=nst.end(); it++){
			pair<int,int> p = it->first;
			int last = (it->second).first;
			string s = (it->second).second;
			if(last==i-1){
				//cout<<p.first<<" "<<p.second<<": "<<s<<endl;
				for(int d=0; d<4; d++){
					pair<int,int> np = make_pair(p.first+dx[d]*i, p.second+dy[d]*i);
					if(!st.count(np))
						st[np] = make_pair(i,s+ch[d]);
				}
			}
		}
	}
}*/
void input(){
	scanf("%d%d",&x,&y);
}
void solve(){
	printf("Case #%d: ",++cnt);
	int cc=1;
	for(int i=0; i<abs(x); i++){
		if(0<=x){
			printf("WE");
		}else{
			printf("EW");
		}
	}
	for(int i=0; i<abs(y); i++){
		if(0<=y){
			printf("SN");
		}else{
			printf("NS");
		}
	}
	printf("\n");
}
int main ()
{
	freopen("B-small-attempt1.in", "r",stdin);
	freopen("B-small-attempt1.out","w", stdout);
	//pre();
	int zz;
	cin>>zz;
	while(zz--){
		input();
		solve();
	}
	return 0;
}

/*
4
2 2
2 1
1 4
1 1 1 1
2 4
2 1 1 6
10 4
25 20 9 100
*/
