#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<cstring>
#include<ext/hash_set>
using namespace std;
using namespace __gnu_cxx;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

namespace __gnu_cxx
{
        template<> struct hash< std::string >
        {
                size_t operator()( const std::string& x ) const
                {
                        return hash< const char* >()( x.c_str() );
                }
        };
}

vector<string> d;
hash_set<string> d2;

string s;
int m[4010][7];
int calc(int pos,int dist){
	dist=min(dist,5);
	if(m[pos][dist]>-1)return m[pos][dist];
	if(pos==s.size())return 0;
	int ans=1000000;
	for(int len=1;pos+len<=s.size()&&len<=10;len++){
		string cur=s.substr(pos,len);
//		cout<<cur<<endl;
		if(d2.count(cur))ans=min(ans,calc(pos+len,dist+len));//,cout<<pos<<" "<<dist<<" "<<cur<<endl;
		FOR(i,len)if(dist+i>=5){
			char tmp=cur[i];
			cur[i]='?';
		  if(d2.count(cur))ans=min(ans,calc(pos+len,len-i)+1);//,cout<<pos<<" "<<dist<<" "<<cur<<endl;
			for(int j=i+5;j<len;j++){
				char tmp2=cur[j];
				cur[j]='?';
		    if(d2.count(cur))ans=min(ans,calc(pos+len,len-j)+2);//,cout<<pos<<" "<<dist<<" "<<cur<<endl;
				cur[j]=tmp2;
			}
			cur[i]=tmp;
		}
	}
	return m[pos][dist]=ans;
}
void solve(){
	cin>>s;
	memset(m,-1,sizeof(m));
	cout<<calc(0,5)<<endl;
}

main(){
	FILE *dict=fopen("dictionary.txt","r");
	char buf[1000];
	int m=0;
	while(fscanf(dict," %s",buf)==1){
		string s=buf;
		d.push_back(s);
		d2.insert(s);
		FOR(i,s.size()){
			string s2=s;
			s2[i]='?';
			d2.insert(s2);
		}
		FOR(i,s.size())for(int j=0;i-j>=5;j++){
			string s2=s;
			s2[i]='?';
			s2[j]='?';
			d2.insert(s2);
		}
	}
//	cout<<m<<endl;

  int C;cin>>C;
  for(int c=1;c<=C;c++){ 
    cout<<"Case #"<<c<<": ";
		solve();
  }
}
