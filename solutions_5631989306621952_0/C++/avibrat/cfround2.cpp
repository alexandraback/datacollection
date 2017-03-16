#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ALL(x) x.begin(),x.end()

int main(int argc, char const *argv[])
{
	freopen("ins.txt","r",stdin);
	freopen("outs.txt","w",stdout);
	int t;
	cin >> t;
	int ctr = 1;
	while(t--){
		cout << "Case #"<<ctr<<": ";
		string s;
		cin >> s;
		deque<char> ans;
		int n = s.length();
		for(int i = 0 ; i < n ;i++){
			if(!i)
				ans.pb(s[i]);
			else
			{
				char xx = ans.front();
				if(s[i] >= xx)
					ans.push_front(s[i]);
				else
					ans.push_back(s[i]);
			}
		}
		for(int i = 0 ; i < ans.size();i++)
			cout << ans[i];
		cout << "\n";
		ctr++;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}