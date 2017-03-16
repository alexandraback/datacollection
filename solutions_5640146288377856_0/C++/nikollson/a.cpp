#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>

using namespace std;

#define reps(i,f,n) for(int i=f;i<int(n);i++)
#define rep(i,n) reps(i,0,n)
#define pb push_back

const int INF = 1000000000;

int r,c,w;
void input(){
	cin>>r>>c>>w;
}


bool validmasu(vector<int>& masu){
	
	
	rep(i,c-w+1){
		bool valid = true;
		rep(j,c){
			bool in = i<=j && j<i+w;
			
			if(in){
				if(masu[j]==2)valid=false;
			}
			if(!in){
				if(masu[j]==1)valid=false;
			}
		}
		
		if(valid)return true;
	}
	return false;
}


int saiki(vector<int>& masu);
int saiki2(vector<int>& masu){
	
	int res = -1;
	rep(i,masu.size()){
		if(masu[i]==-1){
			
			masu[i]=1;
			if(validmasu(masu)) res = max(res, saiki(masu));
			
			masu[i]=2;
			if(validmasu(masu)) res = max(res, saiki(masu));
			
			masu[i]=-1;
		}
	}
	
	return res;
}

int saiki(vector<int>& masu){
	
	int cnt = 0;
	int onecnt = 0;
	rep(i,masu.size()){
		if(masu[i]!=0)cnt++;
		if(masu[i]==1)onecnt++;
	}
	
	int res = INF;
	
	if(onecnt>=w){
		res=cnt;
	}else{
		rep(i,masu.size()){
			if(masu[i]==0){
				masu[i]=-1;
				res = min(res, saiki2(masu));
				masu[i]=0;
			}
		}
	}
	
	
	return res;
}

int solve(){
	vector<int> masu(c);
	return saiki(masu)*r;
}

int main(){
	int T;
	cin>>T;
	reps(i,1,T+1){
		input();
		printf("Case #%d: %d\n",i, solve());
	}
}