#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<map>
#include<set>
using namespace std;
typedef long long lli;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

#define tr(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)

int main() {
	freopen("A-small-attempt0.in", "r", stdin); freopen("A-small.out", "w", stdout);
	//freopen("A-large.in", "r", stdin); freopen("A-large.out", "w", stdout);
	int a,n,t,ans;
	set<char> vow;
	vow.insert('a');
	vow.insert('e');
	vow.insert('i');
	vow.insert('o');
	vow.insert('u');

	string s;
	scanf("%d\n",&t);
		//getline(cin,s);
	for(int j=1;j<=t;j++) {
		cin>>s;
		scanf("%d",&n);

		//cout<<s<<" yo"<<n<<endl;
		ans=0;

		int k=s.size();
		int num;
		for(int i=0;i<k;i++) {
			num=0;
			int l;
			for(l=i;l<k;l++) {
				if(vow.find(s[l])==vow.end()) {
					num++;
					if(num==n)
						break;
					}
				else
					num=0;
				}
			if(num==n)
				ans+=k-l;
			}

		printf("Case #%d: %d\n",j,ans);
		}

	return 0;
	}
