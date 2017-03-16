#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>

using namespace std;

#define MAX 100005
#define ll long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

vector<string> vec[2];

void solve(string a, int i, int t){
	if(i == a.size()){
		vec[t].pb(a);
		return;
	}

	if(a[i] == '?'){
		for(int j=0 ; j<10 ; j++){
			a[i] = j + '0';
			solve(a, i+1, t);
		}
	} else {
		solve(a, i+1, t);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	int t, T=1;
	cin>>t;

	while(t--){
		string c, d;
		cin>>c>>d;

		vec[0].clear(), vec[1].clear();

		solve(c, 0, 0);
		solve(d, 0, 1);

		int diff, x, y;
		diff = x = y = 100000;

		string q, w;

		vector<string> one, two;
		one = vec[0], two = vec[1];
	
		for(int i=0 ; i<one.size() ; i++){
			for(int j=0 ; j<two.size() ; j++){
				int a, b;
				a = b = 0;
				for(int k=0 ; k<one[i].size() ; k++)
					a = a * 10 + one[i][k] - '0';
				for(int k=0 ; k<two[j].size() ; k++)
					b = b * 10 + two[j][k] - '0';
		
				if(abs(a-b)<diff){
					diff = abs(a-b), x = a, y = b;
					q = one[i], w = two[j];
				} else if(abs(a-b) == diff){
					if(a<x){
						x = a, y = b;
						q = one[i], w = two[j];
					} else if(a == x){
						if(b<y){
							q = one[i], w = two[j];
						}
					}
				}
			}
		}

		cout<<"Case #"<<T++<<": "<<q<<" "<<w<<"\n";
	}

	return 0;
}