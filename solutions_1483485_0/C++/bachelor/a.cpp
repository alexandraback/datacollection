#include <iostream>
#include <vector>
#include <string>

using namespace std;

char tran[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 
	'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	string str;
	int T;
	cin>>T;
	cin.ignore();
	for(int tt = 1; tt <= T; ++tt){
		getline(cin, str);
		for(int i = 0; i < str.length(); ++i){
			if(isalpha(str[i])){
				//cout<<str[i]<<' '<<tran[str[i] - 'a']<<endl;
				str[i] = tran[str[i] - 'a'];
			}
		}
		cout<<"Case #"<<tt<<": "<<str<<endl;
	}
	
	return 0;
}	
