#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <list>
#include <math.h>
#include <cstring>
#include <complex>
using namespace std;

#define rep(i,start,m) for(int i=(int)(start);i<(int)(m);i++)
#define showarray(array,m) for(int sa_i=0;sa_i<(int)(m);sa_i++) cout << array[sa_i] <<" "; cout << endl;
#define showvector(array) for(int sa_i=0;sa_i<(int)(array.size());sa_i++) cout << array[sa_i] << " "; cout << endl;
stringstream ss;
#define cast(a,b) ss.clear(); ss<<a; ss>>b; ss.clear();
#define rev(s) (string((s).rbegin(), (s).rend()))
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl;
#define clr(a) memset((a), 0, sizeof(a))
const int INF = 999999;

int dx[] = {-1,0,1,0,1,1,-1,-1};
int dy[] = {0,-1,0,1,1,-1,1,-1};

template<class T>
int pyfind(const vector<T> &vect, const T &targ){
	for(int i=0;i<vect.size();i++){
		if(vect[i] == targ) return i;
	}
	return -1;
}

int T,n;
int a[2000],b[2000];
int mindepth;
bool used[2000][2];
vector<vector<pair<int, int> > > canusedic; //canusedic[x]で、x個星をもったときにいける面を記述

void showvectorpair(vector<pair<int,int> > &vec){
	rep(i,0,vec.size()){
		cout << vec[i].first << "," << vec[i].second << " " ;
	}
	cout << endl;
}

void remove(vector<pair<int,int> > &vec, int x){
	vector<pair<int,int> > ::iterator itr = vec.begin();
	rep(i,0,x){
		itr++;
	}
	vec.erase(itr);
}

void remove1(vector<int> &vec, int x){
	vector<int> ::iterator itr = vec.begin();
	rep(i,0,x){
		itr++;
	}
	vec.erase(itr);
}


void dfs(vector<int> canuse1, vector<int> canuse2, int star, int getstar, int depth, vector<pair<int,int> > hist){
	int tmpstar,x,y,tx,ty;
	vector<int> tmpcanuse1,tmpcanuse2;
	vector<pair<int,int> > tmphist;
	//cout << "hist:";
	//showvectorpair(hist);
	//cout << "rem:" ; showvectorpair(canuse);
	//showvector(canuse1); showvector(canuse2);
	
	//finish
	if(getstar==n){
		//if(depth<mindepth) showvectorpair(hist);
		mindepth = min(depth,mindepth);
		return;
	}
	
	//枝刈り
	if(depth>=mindepth) return;
	
	//canuse2があれば、そちらを優先的に使う。順番は関係ない
	if(not canuse2.empty()){
		tmpstar = star;
		tmphist = hist;
		rep(i,0,canuse2.size()){ //使えるだけ使ってstarを増やす
			depth++;
			x = canuse2[i];
			if(used[x][0]) tmpstar = tmpstar+1;
			else tmpstar = tmpstar+2;
			used[x][1]=true; used[x][0]=true;
			tmphist.push_back(make_pair(x,1));
		}
		//次のcanuseの作成
		tmpcanuse1 = canuse1;
		tmpcanuse2.clear();
		rep(j,0,tmpstar-star){
			rep(i,0,canusedic[tmpstar-j].size()){
				tx = canusedic[tmpstar-j][i].first; ty = canusedic[tmpstar-j][i].second;
				if(ty==1){
					if(used[tx][1]) continue; //意味ないはずだけど
					tmpcanuse2.push_back(tx);
				}else{
					if(used[tx][1]) continue; //既に2が達成されていたら追加しない
					tmpcanuse1.push_back(tx);
				}
			}
		}
		dfs(tmpcanuse1, tmpcanuse2, tmpstar, getstar+canuse2.size(), depth, tmphist);
		//usedを元に戻す
		rep(i,0,canuse2.size()){
			x = canuse2[i];
			used[x][1]=false; used[x][0]=false;
		}
		return;
	}
	//canuse2がなければ、canuse1の値から貪欲に？
	int id,maxx=-1,rem;
	if(canuse1.empty()) return;
	rep(i,0,canuse1.size()){
		x = canuse1[i];
		if(used[x][1]) continue;
		//if(used[x][0]) continue; //多分いらない
		//y==0で、でも==1でも使える場合はcontinueする
		//if(b[x]<=star) continue; //多分いらない
		//if(used[x][1]) continue; //多分いらない
		if(maxx<b[x]){
			maxx=b[x];
			id=x;
			rem=i;
		}
	}
	if(maxx==-1) return;
	//最高のものから選ぶ
	tmpstar = star+1;
	remove1(canuse1,rem);
	tmpcanuse1 = canuse1;
	tmpcanuse2.clear();
	rep(i,0,canusedic[tmpstar].size()){
		tx = canusedic[tmpstar][i].first; ty = canusedic[tmpstar][i].second;
		if(ty==1){
			if(used[tx][1]) continue; //意味ないはずだけど
			tmpcanuse2.push_back(tx);
		}else{
			if(used[tx][1]) continue; //既に2が達成されていたら追加しない
			tmpcanuse1.push_back(tx);
		}
	}
	used[id][0]=true;
	tmphist = hist;
	tmphist.push_back(make_pair(id,0));
	dfs(tmpcanuse1, tmpcanuse2, tmpstar, getstar, depth+1, tmphist);
	used[id][0]=false;
	return;
		/*
		tmpstar = star+1;
		tmpcanuse = canuse; remove(tmpcanuse,i);
		rep(i,0,canusedic[tmpstar].size()){
			tmpcanuse.push_back(canusedic[tmpstar][i]);
		}
		tmphist = hist; tmphist.push_back(make_pair(x,y));
		used[x][y]=true;
		dfs(tmpcanuse, tmpstar, getstar, depth+1, tmphist);
		used[x][y]=false;
			
		}
		*/
}


/*
void dfs(vector<pair<int,int> > canuse, int star, int getstar, int depth, vector<pair<int,int> > hist){
	int tmpstar,x,y,tx,ty;
	vector<pair<int,int> > tmpcanuse,tmphist;
	//showvectorpair(hist);
	//cout << "rem:" ; showvectorpair(canuse);
	//finish
	if(getstar==n){
		//if(depth<mindepth) showvectorpair(hist);
		mindepth = min(depth,mindepth);
		return;
	}
	
	//枝刈り
	if(depth>=mindepth) return;
	
	rep(i,0,canuse.size()){
		x = canuse[i].first; y = canuse[i].second;
		if(used[x][y]) continue;
		if(y==0){
			//y==0で、でも==1でも使える場合はcontinueする
			if(b[x]<=star) continue;
			if(used[x][1]) continue;
			tmpstar = star+1;
			tmpcanuse = canuse; remove(tmpcanuse,i);
			rep(i,0,canusedic[tmpstar].size()){
				tmpcanuse.push_back(canusedic[tmpstar][i]);
			}
			tmphist = hist; tmphist.push_back(make_pair(x,y));
			used[x][y]=true;
			dfs(tmpcanuse, tmpstar, getstar, depth+1, tmphist);
			used[x][y]=false;
		}else{
			if(used[x][0]) tmpstar = star+1;
			else tmpstar = star+2;
			tmpcanuse = canuse;remove(tmpcanuse,i);
			rep(j,0,tmpstar-star){
			rep(i,0,canusedic[tmpstar-j].size()){
				tmpcanuse.push_back(canusedic[tmpstar-j][i]);
			}
			}
			tmphist = hist; tmphist.push_back(make_pair(x,y));
			used[x][y]=true;
			dfs(tmpcanuse, tmpstar, getstar+1, depth+1,tmphist);
			used[x][y]=false;
		}
	}
}
*/

void solve(){
	mindepth = INF;
	vector<pair<int,int> > canuse,hist;
	canusedic.clear(); canusedic.resize(2100);
	rep(id,0,n){
		canusedic[a[id]].push_back(make_pair(id,0));
		canusedic[b[id]].push_back(make_pair(id,1));
	}
	canuse.clear();
	vector<int> canuse1,canuse2;
	rep(i,0,canusedic[0].size()){
		//canuse.push_back(canusedic[0][i]);
		if(canusedic[0][i].second==1){
			canuse2.push_back(canusedic[0][i].first);
		}else{
			canuse1.push_back(canusedic[0][i].first);
		}
	}
	//showvectorpair(canuse);
	
	clr(used);
	hist.clear();
	dfs(canuse1,canuse2,0,0,0,hist);
	//dfs(canuse,0,0,0,hist);
	if(mindepth==INF) {cout << "Too Bad" << endl; return;}
	cout << mindepth << endl;
}

int main () {
	freopen("/Users/katsuma/c++/input.txt","rt",stdin);
	freopen("/Users/katsuma/c++/B-small-attempt2.in","rt",stdin);
	//freopen("/Users/katsuma/c++/B-large.in","rt",stdin);
	freopen("/Users/katsuma/c++/B-small-attempt2out.txt","wt",stdout);
	//freopen("/Users/katsuma/c++/B-largeout.txt","wt",stdout);
	cin >> T;
	rep(t,0,T){
		cout << "Case #" << t+1 << ": " ; 
		cin >> n;
		rep(i,0,n){
			cin >> a[i] >> b[i];
		}
		solve();
	}
}








