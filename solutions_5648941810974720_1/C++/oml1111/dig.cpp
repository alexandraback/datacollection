#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define f first
#define s second
#define mp make_pair
using namespace std;


//Format: (identifying character, (number, letters of number) )
vector<pair<char, pair<char, string> > > number = 
					{	mp('Z', mp('0', "ZERO") ),
						mp('W', mp('2', "TWO") ),
						mp('U', mp('4', "FOUR") ),
						mp('X', mp('6', "SIX") ),
						mp('G', mp('8', "EIGHT") ),
						mp('O', mp('1', "ONE") ),
						mp('H', mp('3', "THREE") ),
						mp('F', mp('5', "FIVE") ),
						mp('S', mp('7', "SEVEN") ),
						mp('I', mp('9', "NINE") )
							};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin >> T;
	
	for(int TCASE = 1; TCASE <= T; TCASE++) {
		string s;
		cin >> s;
		
		vector<int> cnt(256, 0);
		
		for(auto c : s)
			cnt[(int)c]++;
		
		
		//Now extract the letters
		string ret;
		
		for(auto num : number) {
			int ccnt = cnt[(int)num.f];
			
			ret.append(ccnt, num.s.f);
			for(auto c : num.s.s)
				cnt[(int)c] -= ccnt;
		}
		
		sort(ret.begin(), ret.end() );
		
		cout << "Case #" << TCASE << ": " << ret << '\n';
		
	}
	
	return 0;
}





































