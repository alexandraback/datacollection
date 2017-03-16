#include <iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	cout << "Case #1:" << endl;
	int r,n,m,k;
	cin >> r >> n >> m >> k;
	for(int i=0;i<r;i++){
		int a;
		bool five=false;
		bool five2=false;
		bool five3=false;
		bool three=false;
		bool three2=false;
		bool three3=false;
		bool two=false;
		bool two2=false;
		bool two3=false;
		bool two4=false;
		bool two5=false;
		bool two6=false;
		for(int j=0;j<7;j++){
			cin >> a;
			if(a%5==0) five=true;
			if(a%25==0) five2=true;
			if(a%125==0) five3=true;
			if(a%3==0) three=true;
			if(a%9==0) three2=true;
			if(a%27==0) three3=true;
			if(a%2==0) two=true;
			if(a%4==0) two2=true;
			if(a%8==0) two3=true;
			if(a%16==0) two4=true;
			if(a%32==0) two5=true;
			if(a%64==0) two6=true;
		}
		if(three3){
			cout << 333 << endl;
			continue;
		}
		if(five3){
			cout << 555 << endl;
			continue;
		}
		if(two6){
			cout << 444 << endl;
			continue;
		}
		if(three2){
			if(five){
				cout << 335 << endl;
				continue;
			}
			if(two2){
				cout << 334 << endl;
				continue;
			}
			if(two){
				cout << 332 << endl;
				continue;
			}
			cout << 333 << endl;
			continue;
		}
		if(five2){
			if(three){
				cout << 355 << endl;
				continue;
			}
			if(two2){
				cout << 455 << endl;
				continue;
			}
			if(two){
				cout << 255 << endl;
				continue;
			}
			cout << 555 << endl;
			continue;
		}
		if(three & five){
			if(two2){
				cout << 435 << endl;
				continue;
			}
			if(two){
				cout << 235 << endl;
				continue;
			}
			cout << 335 << endl;
			continue;
		}
		if(three){
			if(two4){
				cout << 344 << endl;
				continue;
			}
			if(two3){
				cout << 324 << endl;
				continue;
			}if(two2){
				cout << 322 << endl;
				continue;
			}if(two){
				cout << 322 << endl;
				continue;
			}
			cout << 322 << endl;
			continue;
		}
		if(five){
			if(two4){
				cout << 544 << endl;
				continue;
			}
			if(two3){
				cout << 524 << endl;
				continue;
			}if(two2){
				cout << 522 << endl;
				continue;
			}if(two){
				cout << 522 << endl;
				continue;
			}
			cout << 522 << endl;
			continue;
		}
		if(two5){
			cout << 244 << endl;
			continue;
		}
		if(two4){
			cout << 224 << endl;
			continue;
		}
		if(two3){
			cout << 222 << endl;
			continue;
		}
		if(two2){
			cout << 224 << endl;
			continue;
		}
		if(two){
			cout << 222 << endl;
			continue;
		}
		cout << 222 << endl;
		continue;
	}
	return 0;
}