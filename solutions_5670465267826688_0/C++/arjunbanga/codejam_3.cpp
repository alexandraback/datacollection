#include<bits/stdc++.h>
using namespace std;
int arr[30][30];
int n;
string s;
int dp[10009][10][5][3];
int func(int ind, int num, int count, int neg)
{
//	cout<<ind<<" "<<num<<" "<<count<<" "<<neg<<endl;
	if(ind == n && num == 4 && count == 2&&!neg)
		return 1;
	else if(ind == n)	
		return 0;
	if(dp[ind][num][count][neg] != -1)
		return dp[ind][num][count][neg];
	int nn = s[ind] - 'i' +2;
//	cout<<nn<<endl;
	int neww = arr[num][nn];
//	cout<<neww<<endl;;
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
		memset(dp, -1, sizeof(dp));
		int l, x;
		cin>>l>>x;
		cin>>s;
		string res = "";
		for(int i = 1; i <= x; i++) {
			res += s;
		}
		s = res;
		n = s.length();
//		cout<<s<<endl;
		if(func(0, 1, 0, 0)) {
			cout<<"Case #"<<ca<<": "<<"YES"<<endl;
		}else {
			 cout<<"Case #"<<ca<<": "<<"NO"<<endl;
		}
	}
	return 0;
}
