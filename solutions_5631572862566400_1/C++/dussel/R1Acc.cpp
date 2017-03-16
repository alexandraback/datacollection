/* attention to overflow */
#include <bits/stdc++.h>

#define dump(x) cerr<< #x << " = " << x <<endl
#define ALL(container) (container).begin(),(container).end()

using namespace std;
const int INF = 1 << 25;
void io() { cin.tie(0); ios::sync_with_stdio(false);}
template <class S,class T> ostream& operator<<(ostream& os, const pair <S,T> &s){return os<<'('<<s.first<<','<<s.second<<')';}
/*printf("%.9Lf\n",cf);*/
const int MOD = 1000000007;
const double EPS=1e-8;

string cs(int n){ return "Case #"+to_string(n)+": "; }

int result(vector <int>& f){
	int size=f.size();
	//loop
	int length=1;
	for(int i=0;i<size;i++){
		int cnt=1;
		int j;
		for(j=f[i];j!=i && cnt<size;j=f[j],cnt++){}
		if(j==i) length=max(length,cnt);
	}
	//cout<<length<<endl;

	//chain
	bool ok[1010]={0};
	for(int i=0;i<size;i++){
		if(i==f[f[i]]){
			ok[i]=1;
			ok[f[i]]=1;
		}
	}
	//cerr<<ok[0]<<ok[1]<<ok[2]<<ok[3]<<endl;

	vector <int> tmp(size,0);
	for(int i=0;i<size;i++){
		int cnt=1;
		int now=i;
		while(cnt<size+1){
			if(ok[now]){
				tmp[now]=max(tmp[now],cnt);
				break;
			}
			now=f[now];
			cnt++;
		}
	}
	//for(int i=0;i<size;i++) cerr<<tmp[i]<<endl;
	length=max(length,accumulate(tmp.begin(),tmp.end(),0));


	return length;
}

int main() {
	io();
	int T;
	cin>>T;
	for(int t=1;t<=T;t++){
		int N;
		cin>>N;
		vector <int> f(N);
		for(int i=0;i<N;i++){
			cin>>f[i];
			f[i]--;
		}

		cout<<cs(t)<<result(f)<<endl;
	}


	return 0;
}
