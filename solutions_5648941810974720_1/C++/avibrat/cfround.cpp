#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define ALL(x) x.begin(),x.end()
#define TEST int t;scanf("%d",&t);while(t--)

int main(int argc, char const *argv[])
{
	freopen("ins.txt","r",stdin);
	freopen("outs.txt","w",stdout);
	int t;
	cin >> t;
	for(int a = 1 ; a <= t ; a++)
	{
		int x;
		cout << "Case #" << a<<": ";
		vector<int> ans;
		string s;
		cin >> s;
		vector<int> arr(26,0);
		for(int i = 0 ; i < s.length() ; i++)
			arr[s[i] - 'A']++;
		for(int i = 0 ,x=arr[25]; i < x ; i++){
			arr['Z' - 'A']--;
			arr['E'- 'A']--;
			arr['R'-'A']--;
			arr['O'-'A']--;
			ans.pb(0);
		}
		for(int i = 0,x=arr['G'-'A'];i < x ; i++){
			arr['E'-'A']--;
			arr['I'-'A']--;
			arr['G'-'A']--;
			arr['H'-'A']--;
			arr['T'-'A']--;
			ans.pb(8);
		}
		for(int i = 0,x=arr['W'-'A']; i < x ; i++){
			arr['T'-'A']--;
			arr['W'-'A']--;
			arr['O'-'A']--;
			ans.pb(2);
		}
		for(int i = 0,x=arr['U'-'A'];i<x ; i++){
			arr['F'-'A']--;
			arr['O'-'A']--;
			arr['U'-'A']--;
			arr['R'-'A']--;
			ans.pb(4);
		}
		for(int i = 0,x= arr['X'-'A'];i < x ; i++){
			arr['S'-'A']--;
			arr['I'-'A']--;
			arr['X'-'A']--;
			ans.pb(6);
		}
		for(int i = 0 ,x=arr['H' - 'A'];i < x ; i++){
			arr['T'-'A']--;
			arr['H'-'A']--;
			arr['R'-'A']--;
			arr['E'-'A']-=2;
			ans.pb(3);
		}
		for(int i = 0,x= arr['O' - 'A']; i < x ; i++){
			arr['O'-'A']--;
			arr['N'-'A']--;
			arr['E'-'A']--;
			ans.pb(1);
		}
		for(int i = 0,x=arr['F' - 'A']; i < x ; i++){
			arr['F'-'A']--;
			arr['I'-'A']--;
			arr['E'-'A']--;
			arr['V'-'A']--;
			ans.pb(5);
		}
		for(int i = 0,x=arr['S' - 'A']; i < x ; i++){
			arr['S'-'A']--;
			arr['N'-'A']--;
			arr['E'-'A']-=2;
			arr['V'-'A']--;
			ans.pb(7);
		}
		for(int i = 0,x= arr['I' - 'A']; i < x ; i++){
			arr['N'-'A']-=2;
			arr['I'-'A']--;
			arr['E'-'A']--;
			ans.pb(9);
		}
		sort(ALL(ans));
		for(int i =0 ; i < ans.size() ; i ++)
			cout << ans[i];
		cout << "\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
