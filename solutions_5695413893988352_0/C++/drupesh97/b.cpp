#include <bits/stdc++.h>
#define ll long long
#define X first
#define Y second
using namespace std;
ll to(string s){
	ll ans = 0;
	for(int i = 0;i < s.length(); i++){
		ans = ans*10 + (s[i] - '0');
	}
	return ans;
}
void solve(){
	string c,j;
	cin>>c>>j;
	vector<int> one,two;
	vector<int> allone,alltwo;
	string t;
	queue<pair<string,int> > q;
	q.push({"",-1});
	//cout<<"THIS "<<q.size()<<"\n";
	while(!q.empty()){
		string t = q.front().X;
		int in = q.front().Y+1;
		q.pop();
		//cout<<t<<" "<<in<<" "<<q.size()<<endl;
		if(t.length() == c.length()){
			allone.push_back(to(t));
			continue;
		}
		if(c[in]!='?'){
			q.push({t+c[in],in});
		}
		else{
			for(int i = 0;i < 10; i++){
				q.push({t+char(i+'0'),in});
			}
		}
	}
	//cout<<"Done ";
	q.push({"",-1});
	while(!q.empty()){
		string t = q.front().X;
		int in = q.front().Y;
		in++;
		q.pop();
		if(t.length() == j.length()){
			alltwo.push_back(to(t));
			continue;
		}
		if(j[in]!='?'){
			q.push({t+j[in],in});
		}
		else{
			for(int i = 0;i < 10; i++){
				q.push({t+char(i+'0'),in});
			}
		}
	}

	/*cout<<"ALLones \n";
	for(int i = 0;i < allone.size(); i++){
		cout<<allone[i]<<endl;
	}
	cout<<"ALLtwos \n";
	for(int i = 0;i < alltwo.size(); i++){
		cout<<alltwo[i]<<endl;
	}*/
	sort(alltwo.rbegin(),alltwo.rend());
	int diff = 1000000000;
	int x;
	int ans,ans2;
	for(int i = 0;i < alltwo.size(); i++){
		for(int l = 0;l < allone.size(); l++){
			x = abs(allone[l]-alltwo[i]);
			if(	x < diff){
				diff = x;
				ans = alltwo[i];
				ans2 = allone[l];
			}
			if(x == diff){
				if(allone[l] < ans2){
					ans2 = allone[l];
					ans = alltwo[i];
				}
				if(allone[l] == ans2 && alltwo[i] < ans){
					ans2 = allone[l];
					ans = alltwo[i];
				}
			}
		}
	}
	//cout<<ans2<<" "<<ans<<"\n";
	string o="";
	while(ans2){
		o+=(char)(ans2%10 + '0');
		ans2/=10;
	}
	while(o.length()!=c.length())o+='0';
	reverse(o.begin(), o.end());
	cout<<o<<" ";
	o="";
	while(ans){
		o+=(char)(ans%10 + '0');
		ans/=10;
	}

	while(o.length()!=j.length())o+='0';
	reverse(o.begin(), o.end());
	cout<<o<<endl;
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