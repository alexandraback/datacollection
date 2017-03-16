#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#define sz(a) int((a).size())
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define Rep(i,j,k) for (int i=(j); i<=(k); i++)
#define Repd(i,j,k) for (int i=(j); i>=(k); i--)
#define ALL(c) (c).begin(),(c).end()
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SUM(a) accumulate(all(a),string())
#define online1
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;

char t[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main(){
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	
	string s;int T; cin>>T;getline(cin,s);
	Rep(_,1,T){
		string s;
		getline(cin,s);
		Rep(i,0,s.size()-1)
			if (s[i]>='a' && s[i]<='z')
				s[i]=t[s[i]-'a'];
			else
				s[i]=' ';
		cout<<"Case #"<<_<<": "<<s<<endl;
	}	

    return 0;
}
