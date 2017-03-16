#include <bits/stdc++.h>

using namespace std;


int Reverse(int n){
	int ans = 0;
	while(n){
		ans *=10;
		ans += n%10;
		n/=10;
	}
	return ans;
}

map<long long ,long long>memo;
long long solve(long long n){
	if(n == 1)return 1;
	if(memo.find(n) != memo.end()){
		return memo[n];
	}

	long long &ret = memo[n];

	ret = solve(n-1)+1;

	if(n%10==1){
		int tmp = Reverse(n);
		if(tmp < n){
			ret = min(ret , solve(tmp)+1);
		}
	}
	return ret;
}

vector<int> stps1,stps2;
void Build(int n){
	if(n == 1)return ;
	int ret = solve(n-1)+1;
	int ret2 =1<<30;
	if(n%10==1){
		int tmp = Reverse(n);
		if(tmp != n){
			ret2 = solve(tmp)+1;
		}
	}

	if(ret < ret2){
		stps1.push_back(n-1);
		Build(n-1);
	}else{
		stps1.push_back(Reverse(n));
		Build(Reverse(n));
	}
	return ;
}



int solve_fast(long long n){
	int ans = 1;
	while(n != 1){

		if(n%10==1){
			int tmp = Reverse(n);
			if(tmp < n) n = tmp , stps2.push_back(tmp);
			else n--, stps2.push_back(n);
		}else n--, stps2.push_back(n);

		ans++;
	}
	return ans;
}


long long my_ans(long long n){
	long long ans = 1;
	while(n!=1){
		stringstream ss;
		ss<<n;
		string s;
		ss>>s;
		int sz = s.size();
		if( (n%10!=0) and n > 10 ){

			int md = (sz+1)/2;
			string tmp = "" ;
			for(int i=md;i<sz;i++){
				tmp += s[i];
				s[i] = '0';
			}
			ss.clear();
			ss<<tmp;
			long long num;
			ss>>num;
			s[sz-1]='1';
			ss.clear();
			ss<<s;
			long long tp;
			ss>>tp;
			long long cp = tp;
			tp = Reverse(tp);
			if(tp < n)n = tp,ans += num-(cp==tp);
			else n--,ans++;
		}else {
			n--,ans++;
		}
	}
	return ans;
}

int main(){
	freopen("in.in","rt",stdin);
	freopen("out.out","wt",stdout);
	int t;
	cin>>t;
	int cs = 0;
	while(t--){
		int n ;
		cin>>n;
		cout<<"Case #"<<++cs<<": ";
		cout<<my_ans(n)<<endl;
	//	cout<<res << " " << solve(i)<<endl;
//		int ans = solve(i);
//		int res = my_ans(i);
//		if(ans != res){
//			cout<<ans<<" " << res<<  " " << i << endl;
//		}
	}
//	Build(3324);
//	solve_fast(3324);
//	cout<<solve(3324)<<" " << solve_fast(3324)<<endl;
//	for(int i=0;i<(int)stps1.size();i++){
//		cout<<stps1[i]<<" " << stps2[i]<<endl;
//	}

	//cout<<solve(3324) << " " << my_ans(3324)<<endl;
}








//int calc_mask(int msk ,int r,int c,int n){
//	vector<vector<bool> > vec (r , vector<bool>(c,0) );
//	for(int i=0;i<r;i++){
//		for(int j=0;j<c;j++){
//			int bit = j + c*i;
//			if(msk & (1<<bit)){
//				vec[i][j] = 1;
//				n--;
//			}
//		}
//	}
//	if(n!=0)return (1<<30);
//	int cnt = 0;
//	for(int i=0;i<r;i++){
//		for(int j=1;j<c;j++){
//			cnt += vec[i][j] & vec[i][j-1];
//		}
//	}
//
//	for(int i=1;i<r;i++)
//		for(int j=0;j<c;j++)
//			cnt += vec[i-1][j] & vec[i][j];
//	return cnt;
//}
//
//
//int main(){
//	freopen("in.in","rt",stdin);
//	freopen("out.out","wt",stdout);
//	int ans;
//	int t,r,c,n,cs=0;
//	cin>>t;
//	while(t--){
//		cs++;
//		cin>>r>>c>>n;
//		ans = 1<<30;
//		for(int msk=0;msk<(1<<(r*c));msk++){
//			ans = min(ans ,calc_mask(msk,r,c,n));
//		}
//		printf("Case #%d: %d\n",cs,ans);
//	}
//
//}
//
