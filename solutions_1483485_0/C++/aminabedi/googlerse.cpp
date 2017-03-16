//VERDICT:

#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#define pb push_back
#define mkp make_pair
#define foR(i,j,n) for(int i=j;i<n;i++)
#define error(x) cerr<<#x<<"="<<x<<endl;
#define stf(x) st.find(x)!=st.end()
#define X first
#define Y second
#define pii pair<int,int>
typedef long long ll;
using namespace std;
const int maxn=1000000,inf=1000000000,mod=1000003;
map<char,char> mp;
string a[3],b[3];
int main(){
	a[0]="our language is impossible to understand";
	a[1]="there are twenty six factorial possibilities";
	a[2]="so it is okay if you want to just give up";
	b[0]="ejp mysljylc kd kxveddknmc re jsicpdrysi";
	b[1]="rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	b[2]="de kr kd eoya kw aej tysr re ujdr lkgc jv";
	foR(i,0,3)
		foR(j,0,a[i].size())
			mp[b[i][j]]=a[i][j];
	mp['z']='q';
	mp['q']='z';
	int t;
	cin>>t;
	string s;
	getline(cin,s);
	foR(i,0,t){
		getline(cin,s);
		cout<<"Case #"<<i+1<<": ";
		foR(i,0,s.size())
			cout<<mp[s[i]];
		cout<<endl;
	}
	return 0;
}
