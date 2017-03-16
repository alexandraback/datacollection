#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

int t;
string a[2];

vector<int> moz_a[2];

int res_abs, res[2];

int lic1, lic2, new_abs;

void zamien(int z, int x, int y){
	res[0] = x;
	res[1] = y;
	res_abs = z;
}

int main(){
	cin >> t;
	
	for(int test = 1; test <= t; test++){
		res_abs = 9999;
	
		cin >> a[0] >> a[1];
		
		moz_a[0].clear();
		moz_a[1].clear();
		
		for(int k = 0; k < 2; k++){
		
			if(a[k].size() == 1){
				if(a[k][0] == '?'){
					for(int i = 0;i < 10; i++)moz_a[k].push_back(i);
				}
				else moz_a[k].push_back(int(a[k][0] - '0'));
			}
			else if(a[k].size() == 2){
				for(int i = 0; i < 10; i++){
					for(int j = 0; j < 10; j++){
						if((a[k][0] == char(i + '0') || a[k][0] == '?') && (a[k][1] == char(j + '0') || a[k][1] == '?')){
							moz_a[k].push_back(i*10 + j);
			//				cout << "w "<<k<<" wrzucam: "<<i*10 + j << endl;
			//				cout << "bo: "<<a[k][0]<<","<<i<<" "<<a[k][1]<<" "<<j<<endl;
						}
					}
				}
			}
			else{
				for(int i = 0; i < 10; i++){
					for(int j = 0; j < 10; j++){
						for(int q = 0; q < 10; q++){
							if((a[k][0] == char(i + '0') || a[k][0] == '?') && (a[k][1] == char(j + '0') || a[k][1] == '?') && (a[k][2] == char(q + '0') || a[k][2] == '?')){
								moz_a[k].push_back(i*100 + j*10 + q);
						//		cout << "dodaje: "<<i*100 + j*10 + k << endl;
							}
						}
					}
				}
			}
		}
		
		for(int i = 0; i < moz_a[0].size(); i++){
			for(int j = 0; j < moz_a[1].size(); j++){
				lic1 = moz_a[0][i];
				lic2 = moz_a[1][j];
				
	//			cout << "para: "<<lic1<<" "<<lic2<<endl;
				
				new_abs = abs(lic1 - lic2);
				if(new_abs < res_abs){
					zamien(new_abs,lic1,lic2);
				}
				else if(new_abs == res_abs){
					if(lic1 < res[0]){
						zamien(new_abs,lic1,lic2);
					}
					else if(lic1 == res[0]){
						if(lic2 < res[1]){
							zamien(new_abs,lic1,lic2);
						}
					}
				}
			}
		}
		
		cout << "Case #"<<test<<": "<<setfill('0')<<setw(a[0].size())<<res[0]<<" "<<setfill('0')<<setw(a[0].size())<<res[1]<<endl;
	}

return 0;
}
