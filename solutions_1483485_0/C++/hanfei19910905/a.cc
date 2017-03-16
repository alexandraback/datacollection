#include<iostream>
#include<cstdio>
#include<cassert>
#include<cstdlib>
#include<cstring>
using namespace std;
#define re(i,n) for(int i=0;i<n;i++)
#define re1(i,n) for(int i=1;i<=n;i++)
#define re2(i,n) for(int i=0;i<=n;i++)
#define re3(i,n) for(int i=1;i<n;i++)
#define clr(a,n) memset(a,n,sizeof(a))
#define debug(n) cout<<#n<<"="<<n<<endl
string a = "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
string tmp = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
char hash[26];
int main(){
	hash[25] = 'q';
	hash['q'-'a'] = 'z';
	assert(tmp.size()==a.size());
	re(i,tmp.size()) if(tmp[i]!=32) hash[tmp[i]-'a'] = a[i];
//	re(i,26) if(hash[i]) cout<<char (i+'a')<<" "<<hash[i]<<endl;
	int t; cin>>t;
	string x ;
	getline(cin,x);
	re1(oo,t){
		getline(cin,x);
		cout<<"Case #"<<oo<<": ";
		re(i,x.size()){
			if(x[i]<='z' && x[i]>='a')
				cout<<hash[x[i]-'a'];
			else cout<<x[i];
		}
		cout<<endl;
	}
}

