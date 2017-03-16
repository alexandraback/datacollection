#include<bits/stdc++.h>
using namespace std;

// ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE

// E = 0 + 1 + 3 + 3 + 7 + 7 + 8 + 9
// F = 4 + 5
// I = 6 + 9 + 5

// 0 = Z
// 2 = W
// 7 = V
// 6 = X
// 8 = G
// 4 = U

// 

int main(){
	int T;
	cin>>T;
	for(int k=1; k<=T; k++){
		string s;
		cin>>s;
		map<char, int> n;
		for(char c:s){
			n[c-'A'+'a']++;
		}
		vector<int> d(10, 0);
		d[0]=n['z'];
		d[2]=n['w'];
		d[6]=n['x'];
		d[7]=n['s']-d[6];
		d[8]=n['g'];
		d[4]=n['u'];
		d[5]=n['f']-d[4];
		d[9]=n['i']-d[6]-d[5]-d[8];
		d[3]=n['r']-d[0]-d[4];
		d[1]=n['o']-d[0]-d[2]-d[4];
		cout<<"Case #"<<k<<": ";
		for(int i=0; i<=9; i++){
			for(int j=0; j<d[i]; j++)
				cout<<i;
		}
		cout<<endl;
	}
	return 0;
}
		
