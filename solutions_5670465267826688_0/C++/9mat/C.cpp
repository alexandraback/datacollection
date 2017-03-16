#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define FOR(i,n) for(int i = 0, n_ = (n); i < n_; i++)
#define FORS(i,s,n) for(int i = (s), n_ = (n); i < n_; i++)
#define ITER(it,v) for(auto it = (v).begin(); it != (v).end(); ++it)

template <typename T> void updatemax (T& a, const T& b) {
	if(b>a) a=b;
}

template <typename T> void updatemin (T& a, const T& b) {
	if(b<a) a=b;
}

using namespace std;

int main(){
	int T, L, X;
	char ch;
	cin>>T;

	int prodtable_[4][4] = {{0,1,2,3}, {1,0,3,2}, {2,3,0,1}, {3,2,1,0}};
	int signtable[4][4] = {{0,0,0,0}, {0,1,0,1}, {0,1,1,0}, {0,0,1,1}};

	int prodtable[8][8];
	FOR(i,8) FOR(j,8){
		prodtable[i][j] = prodtable_[i%4][j%4];
		if((i>3)^(j>3)^signtable[i%4][j%4])
			prodtable[i][j] += 4;
	}

	int invtable[8][8], inv2table[8][8];

	FOR(i,8) FOR(j,8) invtable[i][prodtable[i][j]] = j;
	FOR(i,8) FOR(j,8) inv2table[j][prodtable[i][j]] = i;

	
	FOR(icase, T){
		cin>>L>>X;

		int prod = 0, first[8], last[8];
		FOR(i,8) first[i] = last[i] = -1;

		FOR(i,L){
			do cin>>ch; while(ch != 'i' & ch != 'j' & ch != 'k');
			prod = prodtable[prod][ch-'i'+1];

			if(first[prod] == -1) first[prod] = i;
			last[prod] = i;
		}


		int power = 0;
		FOR(i,X%4) power = prodtable[power][prod];

		if(power != 4) {
			cout<<"Case #"<<icase+1<<": NO"<<endl;
			continue;
		}

		int first_i = -1, last_k = -1;

		power = 0;
		FOR(i,4) {
			first_i = first[invtable[power][1]];
			if(first_i != -1) {
				first_i += i*L;
				break;
			}
			power = prodtable[power][prod];
		}

		power = 0;
		FOR(i,4) {
			last_k = last[inv2table[inv2table[power][3]][prod]];
			if(last_k != -1){
				last_k++;
				last_k += (X-i-1)*L;
				break;
			}
			power = prodtable[power][prod];
		}

		if(first_i >= 0 & last_k > 0 & (first_i/L < X) & first_i < last_k)
			cout<<"Case #"<<icase+1<<": YES"<<endl;
		else
			cout<<"Case #"<<icase+1<<": NO"<<endl;

	}

	return 0;
}

