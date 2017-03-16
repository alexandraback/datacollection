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
	//freopen("A-small-attempt0.in", "r", stdin); freopen("test.out", "w", stdout);
	freopen("A-large.in", "r", stdin); freopen("A-large.out", "w", stdout);
	int a,n,t,ans;//A[1000005];
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
		//memset(A,0,sizeof A);
		ans=0;
		list<int> l;

		int k=s.size();
		int num=0;
		for(int i=0;i<k;i++) {
			if(vow.find(s[i])==vow.end()) {
				num++;
				if(num>=n) {
					//cout<<i<<" "<<num<<" "<<i+1-n<<endl;
					l.push_back(i+1-n);
					}
				}
			else
				num=0;
			}
		list<int>::iterator it=l.begin();
		for(int i=0;i<k && it!=l.end();i++) {
			if(i<(*it))
				ans+=k-(i+n-1)-((*it)-i);
			else {
				ans+=k-(i+n-1);
				it++;
				}
			}

		printf("Case #%d: %d\n",j,ans);
		}

	return 0;
	}
