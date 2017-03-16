#include <bits/stdc++.h>
using namespace std;
int freq[27],ans[11];
string X[]={
	"ZERO",
	"ONE",
	"TWO",
	"THREE",
	"FOUR",
	"FIVE",
	"SIX",
	"SEVEN",
	"EIGHT",
	"NINE"
};
void dec(int i,int x){
	for(int j = 0;j < X[i].length(); j++){
		freq[X[i][j]-'A']-=x;
	}
}
void solve(){
	string s;
	cin>>s;
	memset(freq,0,sizeof(freq));
	memset(ans,0,sizeof(ans));
	for(int i = 0;i < s.length(); i++){
		freq[s[i]-'A']++;
	}
	/*for(int i = 0;i < 26; i++){
		cout<<freq[i]<<" "<<(char)(i+'A')<<endl;
	}*/
	ans[0]+=freq['Z'-'A'];
	dec(0,freq['Z'-'A']);
	ans[6]+=freq['X'-'A'];
	dec(6,freq['X'-'A']);
	ans[2]+=freq['W'-'A'];
	dec(2,freq['W'-'A']);
	ans[8]+=freq['G'-'A'];
	dec(8,freq['G'-'A']);
	ans[7]+=freq['S'-'A'];
	dec(7,freq['S'-'A']);
	ans[5]+=freq['V'-'A'];
	dec(5,freq['V'-'A']);
	ans[4]+=freq['F'-'A'];
	dec(4,freq['F'-'A']);
	ans[3]+=freq['T'-'A'];
	dec(3,freq['T'-'A']);
	ans[1]+=freq['O'-'A'];
	dec(1,freq['O'-'A']);
	ans[9]+=freq['I'-'A'];
	/*for(int i = 0;i < 10; i++){
		cout<<i<<" "<<ans[i]<<endl;
	}*/
	string t="";
	for(int i = 0;i < 10; i++){
		for(int j = 0;j < ans[i]; j++){
			t+=(i+'0');
		}
	}
	cout<<t<<endl;

}
int main(int argc, char const *argv[])
{
	freopen("./input.txt","r",stdin);
	freopen("./output.txt","w",stdout);
	int t;
	cin>>t;
	for(int i = 1;i <=t; i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}	