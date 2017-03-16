#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;



int K, L, S;
string klav, hledam;

int celkem;
int kolikrat(string &kde){
	int nums = 0;

	for(int i=0;i<=kde.length()-hledam.length();i++){
		int j;
		for(j=0;j<hledam.length();j++){
			if(kde[i+j] != hledam[j]){
				break;
			}
		}
		if(j == hledam.length()){
			nums++;
			//cout<< "yes";
		}
	}
	//cout << nums;
	return nums;
}
void gen(string akt, int len){
	if(len == S){
		celkem += kolikrat(akt);
		return;
	}
	for(int i=0;i<klav.length();i++){
		gen(akt+klav[i], len+1);
	}
}

int main(){
	int T; scanf("%d", &T);
	for(int t=1;t<=T;t++){
		 scanf("%d %d %d", &K, &L, &S);
		char key[20];
		char my[20];
		scanf(" %s ", key);
		scanf(" %s ", my);
		klav = key;
		hledam = my;

		celkem = 0;

		gen("", 0);

		int pocetVysledku = 1;
		for(int i=0;i<S;i++){
			pocetVysledku *= K;
		}
		int minBan = 0;
		//chec kAAAA
		//otherwise
		for(int i=0;i<L-1;i++){
			int ok = true;
			for(int j = L-1-i;j<L;j++){
				if(hledam[i]!=hledam[j]){
					ok = false;
					break;
				}
			}
			if(ok){
				minBan = i+1;
			}
		}
		int ok = true;
		for(int i=0;i<L-1;i++){
			if(hledam[i] != hledam[i+1]){
				ok = false;
				break;
			}
		}
		int banany;
		if(ok || L == 1){
			banany = S-L+1;
		}else{
			minBan = L-minBan;
			banany = (S/minBan);
			if(S%minBan < L-minBan){//ocas
				banany -= 1;
			}
		}

		for(int i=0;i<L;i++){
			//cout << klav.find(hledam[i]) << " " << (int) klav.end() << endl;
			if(klav.find(hledam[i]) == -1){
				banany = 0;
				break;
			}
		}

		//cout << banany << " " << pocetVysledku << " " << celkem << endl;
		double ans = banany*1.0 - (celkem*1.0)/(1.0*pocetVysledku);
		//cout << ans;
		printf("Case #%d: %.8lf\n", t, ans);
	}
}
