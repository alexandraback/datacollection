#include<iostream>
using namespace std;

const int maxn = 1100;

int tt, n, J, M;
int a[maxn], b[maxn];

int main(){
	M = 1000;
	cin >> tt;
	for (int _t=0 ; _t<tt ; _t++){
		cin >> n;
		memset(a, 0, sizeof a);
		for (int i=0 ; i<n ; i++){
			int x;
			cin >> x;
			a[x]++;
		}
		J = M;
		for (int i=1 ; i<=M ; i++){
			for (int j=0 ; j<=M ; j++)
				b[j] = a[j];
			int J2 = i;
			for (int j=i+1 ; j<=M ; j++){
				int jj = j;
				while(jj>i){
					jj -= i;
					J2 += b[j];
				}
			}	
//			for (int j=M ; j>i ; j--){
//				J2 += b[j];
//				b[j/2] += b[j];
//				b[j-j/2] += b[j];
//			}
			J = min(J, J2);
		}
		cout << "Case #" << _t+1 << ": " << J << endl;
	}

}
