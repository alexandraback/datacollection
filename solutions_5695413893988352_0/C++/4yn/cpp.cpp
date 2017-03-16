#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;
typedef pair<int,int> pi;

int tc;

int main(){
	cin >> tc;
	for(int t=1;t<=tc;t++){
		cout << "Case #" << t << ": ";
		string a,b;
		cin >> a >> b;
		int higher = 4;
		// 1 if for team a win, 2 if for b win
		// 3 for haven't decided,
		// 4 for all ?? until now
		for(int i=0;i<a.size();i++){
			if(a[i]=='?'||b[i]=='?'){
				if(higher<3){
					if(higher==1){
						// minimise a, maximise b;
						if(a[i]=='?') a[i] = '0';
						if(b[i]=='?') b[i] = '9';
					} else {
						// maximise a, minimise b;
						if(a[i]=='?') a[i] = '9';
						if(b[i]=='?') b[i] = '0';
					}
				} else if(higher == 4){
					if(a[i]=='?' && b[i]=='?'){
						a[i] = '0';
						b[i] = '0';
					} else if(a[i]=='?'){
						a[i] = b[i];
					} else {
						b[i] = a[i];
					}
				}
			} else {
				if(higher>2){
					if(a[i]==b[i]){
						//still equal, don't decide
					} else {
						if(a[i]>b[i]){
							// a wins
							higher = 1;
						} else {
							higher = 2;
						}
					}
				}
			}
		}
		cout << a << ' ' << b << endl;
	}
}