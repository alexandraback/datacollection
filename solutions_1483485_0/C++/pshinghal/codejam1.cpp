#include<iostream>
#include<string>

using namespace std;

string alpha = "yhesocvxduiglbkrztnwjpfmaq", curr;

int main(){
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);
	int tc;
	cin>>tc;
	getline(cin, curr);
	for(int i = 1; i <= tc; i++){
		getline(cin, curr);
		cout<<"Case #"<<i<<": ";
		for(int j = 0; j < curr.size(); j++){
			if(curr[j] == ' ')
				cout<<' ';
			else
				cout<<alpha[(int) curr[j] - (int) 'a'];
		}
		cout<<endl;
	}
	return 0;
}
