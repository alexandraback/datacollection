#include<iostream>
#include<sstream>
#include<cstring>
using namespace std;

char rep[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	cin>>T;
	string s;
	getline(cin,s);
	for(int _T=1;_T<=T;_T++){
		string orig;	
		getline(cin,orig);
		for(int i=0;i<orig.size();i++){
			if(orig[i]!=' '){
				orig[i]=rep[orig[i]-'a'];
			}
		}
		cout<<"Case #"<<_T<<": "<<orig<<endl;
	}
	return 0;
}