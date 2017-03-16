#include<iostream>
#include<map>
#include<string>
#include<set>
#include<sstream>
#include<cmath>
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
			set<int>s;
			
			int keta = log10( i );
			for( int j=0;j<keta;++j ){
				int tmp = pow(10,j+1);
				
				int _left = i / tmp;
				int _right= i % tmp;
				int tmp2 = _right * pow( 10,keta-j ) + _left;
				
				if( i<tmp2 && tmp2<=b )s.insert(tmp2);
				
				//printf("%d=> %d%d %d\n",i,_right,_left,tmp2);
			}
			ans+= s.size();
		}
		printf("Case #%d: %d\n",_case+1,ans);
	}
	return 0;
}
