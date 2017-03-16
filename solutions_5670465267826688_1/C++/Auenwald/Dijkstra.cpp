#include <iostream>
#include <string>
#include <vector>

using namespace std;

char mul[3][3]= {{'1','k','j'},{'k','1','i'},{'j','i','1'}};
int sig[3][3]= {{-1,1,-1},{-1,-1,1},{1,-1,-1}};

char mult(char a, char b){
	if(a=='1')
		return b;
	if(b=='1')
		return a;
	int x = a - 'i';
	int y = b - 'i';
	return mul[x][y];
}

int sign(char a, char b){
	if(a=='1'||b=='1')
		return 1;
	int x = a - 'i';
	int y = b - 'i';
	return sig[x][y];
}

vector<char> let;
long long L,X;
long long count;

bool search(char c){
	char now = '1';
	int snow = 1;
	while(!(now==c && snow==1)){
		if(count==L){
			if(X!=1){
				count=0;
				X--;
			}
			else
				return false;
		}
		snow = snow*sign(now,let[count]);
		now = mult(now,let[count]);
		count++;
	}
	return true;
}

bool testrest(){
	char now = '1';
	int snow = 1;
	while(!(count==L && X==1)){
		if(count==L && X!=1){
			count = 0;
			X--;
		}
		snow = snow*sign(now,let[count]);
		now = mult(now,let[count]);
		count++;
	}
	if(now=='1' && snow==1)
		return true;
	else
		return false;
}

int main(){
	int T;
	cin>>T;
	for(int i=1; i<=T; i++){
		bool yes = false;
		count = 0;
		cin>>L>>X;
		if(X>=12)
			X = 8 + (X%4);
		for(long long j=0; j<L; j++){
			char ch;
			cin>>ch;
			let.push_back(ch);
		}
		if(search('i')){
			if(search('j')){
				if(search('k')){
					if(testrest())
						yes = true;
				}
			}
		}
		let.clear();
		cout<<"Case #"<<i<<": ";
		if(yes)
			cout<<"YES";
		else
			cout<<"NO";
		if(i!=T)
			cout<<"\n";
	}
}