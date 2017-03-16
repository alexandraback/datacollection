#include<iostream>
#include<string>
#include<sstream>
using namespace std;

const int maxl = 1000001;

string str;
int n;
int dp[3][maxl];
int cntdp[2][maxl];
int v[maxl];

int main(){
	freopen("input.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int ncase;
	cin >> ncase;
	
	for(int icase = 1; icase <= ncase; icase++){
		cout<<"Case #"<<icase<<": ";
		cin >> str;
		cin >> n;
		
		int len = str.length();
		int t = 0;
		int p = 0;
		
		memset(dp, 0,sizeof(dp));
		for(int i = 0; i < len; i++)
			if(str[i] == 'a' || str[i] == 'e' || str[i] == 'o' || str[i] == 'u' || str[i] == 'i'){
				dp[t][i] = 0;
				cntdp[p][i] = 0;
				v[i] = 0;
			}
			else{
				dp[t][i] = 1>=n ? 1:0;
				cntdp[p][i] = 1;
				v[i] = 1;
			}
		
		t = 3;
		for(int l = 2; l <= len; l++){
			t++;
			int t_0 = t%3;
			int t_1 = (t-1)%3;
			int t_2 = (t-2)%3;
			p = 1-p;
			for(int i = 0; i + l <= len; i++){
				cntdp[p][i] = v[i+l-1]>0 ? cntdp[1-p][i] + v[i+l-1] : 0;
				if(cntdp[p][i] >= n || dp[t_1][i] > 0) dp[t_0][i] = 1;
				dp[t_0][i] += dp[t_1][i] + dp[t_1][i+1] - dp[t_2][i+1];
			}
			/*for(int i = 0; i < len; i++)
				cout<< dp[t_0][i] <<" ";
			cout<<endl;*/
		}
		cout << dp[t%3][0] << endl;
	}
}