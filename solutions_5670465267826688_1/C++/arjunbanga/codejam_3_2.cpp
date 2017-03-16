#include<bits/stdc++.h>
using namespace std;
int arr[30][30];
int n;
string s;
int dp[10009][9][3][2];
vector<int> adj[1009];
set<int> ss;
set<int> ans;
int st;
int func(int ind, int num, int count, int neg)
{
	if(ind == n && num == 4 && count==2 && !neg) {
//		cout<<st<<"FGFGF"<<endl;
		ans.insert(st);
		return 1;
	}
	 if(ind == n) {
		if(neg) {
			num += 4;
		}
		if(ss.find(num*10 + count ) == ss.end()) {
			ss.insert(num*10 + count);
//			if(st == 80) 
		//		cout<<num*10+count <<" FGDFHGHFGHFG"<<endl;
			adj[st].push_back(num*10 + count);
		}
		return 1;
	}
		
	else if(ind == n)	
		return 0;
	if(dp[ind][num][count][neg] != -1)
		return dp[ind][num][count][neg];
	int nn = s[ind] - 'i' +2;
	int neww = arr[num][nn];
	if(neww == 2 && count == 0 && !neg) {
			return dp[ind][num][count][neg] =func(ind+1, 1, 1, 0) | func(ind+1, 2, 0, 0);
	}else if(neww == 6 && count == 0 && neg) {
			return dp[ind][num][count][neg] =func(ind+1, 1, 1, 0)|func(ind+1, 2, 0, 0);
	}
	if(neww == 3 && count == 1 && !neg) {
		return dp[ind][num][count][neg] = func(ind+1, 1, 2, 0)|func(ind+1, 3, 1, 0);	
	}
	if(neww == 7 && count == 1 && neg) {
		return dp[ind][num][count][neg]=  func(ind+1, 1, 2, 0)|func(ind+1, 3, 1, 0);
	}
	else {
		int flag;
		if(neg) {
			if(neww > 4) {
				flag = 0;
			}else
				flag = 1;
		}
		else {
			if(neww>4)
				flag = 1;
			else
				flag = 0;
		}
		int gg = neww;
		if(gg > 4) {
			gg = gg-4;
		}
		return dp[ind][num][count][neg] = func(ind+1, gg, count, flag);
	}
}
map<set<int>, int > sss;
int main()
{
	arr[1][1] = 1;
arr[1][2] = 2;
arr[1][3] = 3;
arr[1][4] = 4;
arr[2][1] = 2;
arr[2][2] = 5;
arr[2][3] = 4;
arr[2][4] = 7;
arr[3][1] = 3;
arr[3][2] = 8;
arr[3][3] = 5;
arr[3][4] = 2;
arr[4][1] = 1;
arr[4][2] = 3;
arr[4][3] = 6;
arr[4][4] = 5;
freopen("inp.in","r",stdin);

        freopen("outp.out","w",stdout);
	int t;
	cin>>t;
	for(int ca = 1; ca <= t; ca++) {
		for(int i = 0; i < 1000; i++)
			adj[i].clear();
		memset(dp, -1, sizeof(dp));
		sss.clear();
		long long int l, x;
		cin>>l>>x;
		cin>>s;
		ans.erase(ans.begin(), ans.end());
		n = s.length();
//		cout<<s<<endl;
		for(int i = 1; i <= 8; i++) {
			for(int cnt = 0; cnt <= 2; cnt++) {
				memset(dp, -1, sizeof(dp));
				 st = i*10+cnt;
					ss.erase(ss.begin(), ss.end());
					int gg = i;
					int flag = 0;
					if(i > 4) {
						gg = i-4;
						flag = 1;
					}
					func(0, gg, cnt, flag);
			}
		}
		set<int> se;
		set<int> seee;
		se.insert(10);
		se.insert(10);
		sss.insert(make_pair(se, 0));
		long long int j = 0;
		int flag1= 0;
		while(j < x-1) {
		//	cout<<j<<endl;
			for(set<int>:: iterator it = se.begin(); it != se.end(); it++) {
				int u = *it;
				for(int i = 0; i < adj[u].size(); i++) {
					int v = adj[u][i];
			//	cout<<v<<" ";
					seee.insert(v);
				}
			}
		//	cout<<endl;
			j++;
			if(sss.find(seee) == sss.end())
				sss.insert(make_pair(seee, j));
			else if(j != x-1 && !flag1) {
			long long int gg = sss[seee];
		//		cout<<gg<<endl;
				long long int fff = x - j -1;
				long long int ccc = fff/ (j-gg);
				j += ccc*(j-gg);
				flag1 = 1;
			}
			se = seee;
			seee.erase(seee.begin(), seee.end());
		}	
		int flag2 = 0;;
		for(set<int>::iterator it = se.begin(); it!= se.end(); it++) {
			int u = *it;
		//	cout<<u<<" jhjhg"<<endl;
			if(ans.find(u) != ans.end()) 
				flag2 = 1;
		}
		if(flag2) {
			cout<<"Case #"<<ca <<": "<<"YES"<<endl;
		}else {
			 cout<<"Case #"<<ca <<": "<<"NO"<<endl;
		}
	
	
	}
	return 0;
}
