#include<iostream>
#include<map>
#include<sstream>

using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		
		int x,y;
		cin>>x>>y;
		int count=0;
		for(int j=x;j<=y;j++){
		map<int,int> m;        
	        	string s,ans="";	
			stringstream out;
			int wq;
			out << j;
			out >> s;
			for(int k=1;k<s.size();k++) {
				ans=s.substr( (s.size()-k),k) + s.substr(0,(s.size()-(k)));
			        stringstream o;
			        o << ans;
			        o >> wq;
			        if(wq <= y && wq > j ) if(m[wq]==0) count++,m[wq]=1;
			}	
		}
		cout<<"Case #"<<i<<": "<<count<<endl;
	}
	return 0;
}
