#include<cctype>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<sstream>
#include<iostream>
#include<algorithm>
using namespace std;

const int MAXN=64;
const int Mod=9999991;
const int INF=0x3f3f3f3f;
const double eps=1e-8;

#define rep(i,st,ed) for (int i=st; i<ed; i++)

set<pair<int,int> > word;
string st;
int ca;
int f[MAXN][MAXN];
int p[MAXN];

pair<int,int> hash(string &st){
	int ret1=0,ret2=0;
	rep(i,0,st.size()) ret1=(ret1*129+st[i])%Mod,ret2=(ret2*131+st[i])%Mod;
	return make_pair(ret1,ret2);
}

void prepare(){
	ifstream in("dictionary.txt");
	string st;
	while (in>>st){
		word.insert(hash(st));
	}
	in.close();
}

void init(){
	cin>>st;
}

void update(int x, int y, string &st){
	string temp;
	if (word.count(hash(st))) f[x+st.size()][y]=min(f[x+st.size()][y],f[x][y]);
	rep(i,0,st.size()){
		if (x+i+1-y<5 && y!=0) continue;
		temp=st;
		for (int ch=97; ch<123; ch++) if (ch!=st[i]){
			temp[i]=ch;
			if (word.count(hash(temp))){
				f[x+st.size()][x+i+1]=min(f[x+st.size()][x+i+1],f[x][y]+1);
			}
		}
		temp=st;
		for (int j=i+4; j<st.size(); j++){
			for (int ch1=97; ch1<123; ch1++) if (ch1!=st[i])
				for (int ch2=97; ch2<123; ch2++) if (ch2!=st[j]){
					temp[i]=ch1; temp[j]=ch2;
					if (word.count(hash(temp))) f[x+st.size()][x+j+1]=min(f[x+st.size()][x+j+1],f[x][y]+2);
				}
		}
	}
}

int solve(){
	memset(f,0x3f,sizeof(f));
	f[0][0]=0;
	rep(i,0,st.size()) rep(j,0,i+1){
		if (f[i][j]==INF) continue;
		string temp="";
		rep(len,1,11){
			if (i+len-1>=st.size()) break;
			temp+=st[i+len-1];
			update(i,j,temp);
		}
	}
	int ret=INF;
	rep(i,0,st.size()+1) ret=min(ret,f[st.size()][i]);
	return ret;
}

int main(){
	ios::sync_with_stdio(0);
	prepare();
	cin>>ca;
	ofstream out("C.out");
	rep(i,0,ca){
		init();
		int temp=solve();
		out<<"Case #"<<i+1<<": "<<temp<<endl;
		cout<<"Case #"<<i+1<<": "<<temp<<endl;
	}
	return 0;
}
