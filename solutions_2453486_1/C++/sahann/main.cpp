//#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;
ifstream cin ("A-Large.in");
ofstream cout("A-Large.out");
int tst1(string s){
	if(count(s.begin(),s.end(),'T')+count(s.begin(),s.end(),'X') == 4) return 0;
	if(count(s.begin(),s.end(),'T') + count(s.begin(),s.end(),'O')==4) return -1;
	if(count(s.begin(),s.end(),'.')!=0) return -2;
	return -3;
}

int tst(vector <string> vs){
	char x;
	int mx = -1000;
	for(int i=0;i<4;i++){
		string s;
		for(int j=0;j<4;j++){
			s+=vs[i][j];			
		}
		mx = max(mx,tst1(s));
	}
	for(int i=0;i<4;i++){
		string s;
		for(int j=0;j<4;j++){
			s+=vs[j][i];			
		}
		mx = max(mx,tst1(s));
	}
	string s;
	for(int i=0;i<4;i++){
		s+=vs[i][i];		
	}
	mx = max(mx,tst1(s));
	s.clear();
	for(int i=0;i<4;i++)
		s+=vs[i][3-i];
	mx = max(mx,tst1(s));
	return mx;
}

int main(){
	int T;
	cin >> T;
	for(int t=0;t<T;t++){
		string s;
		vector <string> vs;
		for(int i=0;i<4;i++) { cin >> s; vs.push_back(s);}
		int ret = tst(vs);
		if(ret==0){
			cout <<"Case #" << t+1 << ": " << "X won" << endl;
		}
		else if (ret ==-1){
			cout <<"Case #" << t+1 << ": " << "O won" << endl;
		}
		else if(ret == -2){
			cout <<"Case #" << t+1 << ": " << "Game has not completed" << endl;
		}
		else if(ret == -3){
			cout <<"Case #" << t+1 << ": " << "Draw" << endl;
		}

	}
	return 0;
}