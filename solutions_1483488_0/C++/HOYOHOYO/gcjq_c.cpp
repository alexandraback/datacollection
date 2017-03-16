#include<iostream>
#include<map>
#include<string>
#include<set>
#include<sstream>
using namespace std;

typedef long long ll;
inline ll toInt(const string& s) {ll v; istringstream sin(s);sin>>v;return v;}
template<class T>inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

int main(){
	int T;
	cin >> T;
	
	int a,b;
	string sa,sb,tmp;
	
	for( int _case=0;_case<T;++_case ){
		int ans = 0;
		cin >> a >> b;
		
		for( int i=a;i<=b;++i ){
			sa = toString(i);
			set<int>s;
			
			for( int j=1;j<sa.size();++j ){
				if( sa[j] != '0' ){
					tmp = sa.substr( j ) + sa.substr(0,j);
					ll ltmp = toInt(tmp);
					
					if( ltmp > i && ltmp <= b ){
						s.insert(ltmp);
						//cout << sa <<"=>"<< tmp << endl;
					}
				}
			}
			ans+= s.size();
		}
		printf("Case #%d: %d\n",_case+1,ans);
	}
					
					
				
				
			
			
			
			
		
		
		
		
	
	
	return 0;
}
