//C++ Template

#include <bits/stdc++.h>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
typedef map<int,int>::iterator ITmii;

#define EPS 1e-9
#define FOR1(x,y,z) for( int x = y; x < z ; ++x)
#define FOR(x,y) FOR1(x,0,y)
#define FOR2(x,y) for(int x = y; x >= 0; --x)
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
#define SORT(X) sort(ALL(X))
#define SIZE(X) ((int)(X).size())

//------------------------------------------------------------------

int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.txt","w",stdout);
	int T; cin >> T;
	FOR(I,T){
		cout << "Case #" <<I+1 <<": ";
		int J,P,S,K;
		cin >> J >> P >> S >> K;
		if (S == 1){
			cout << 1 << '\n';
			cout << "1 1 1\n";
		}
		else if (S == 2){
			if (P == 1){
				if (K == 1){
					cout << 1 << '\n';
					cout << "1 1 1\n";
				}
				else{
					cout << 2 << '\n';
					cout << "1 1 1\n1 1 2\n";
				}
			}
			else{
				if (J == 1){
					if (K == 1){
						cout << 2 << '\n';
						cout << "1 1 1\n1 1 2\n";
					}
					else {
						cout << 4 << '\n';
						cout << "1 1 1\n1 1 2\n1 2 1\n1 2 2\n";
					}
				}
				else{
					if (K == 1){
						cout << 4 << '\n';
						cout << "1 1 1\n1 2 2\n2 1 2\n2 2 1\n";
					}
					else {
						cout << 8 << '\n';
						cout << "1 1 1\n1 1 2\n1 2 1\n1 2 2\n2 1 1\n2 1 2\n2 2 1\n2 2 2\n";
					}
				}
			}
		}
		else if (S == 3){
			if (P == 1){
				if (K == 1){
					cout << 1 << '\n';
					cout << "1 1 1\n";
				}
				else if (K == 2){
					cout << 2 << '\n';
					cout << "1 1 1\n1 1 2\n";
				}
				else{
					cout << 3 << '\n';
					cout << "1 1 1\n1 1 2\n1 1 3\n";
				}
			}
			else if (P == 2){
				if (J == 1){
					if (K == 1){
						cout << 2 << '\n';
						cout << "1 1 1\n1 2 2\n";
					}
					else if (K == 2){
						cout << 4 << '\n';
						cout << "1 1 1\n1 1 2\n1 2 1\n1 2 2\n";
					}
					else{
						cout << 6 << '\n';
						cout << "1 1 1\n1 1 2\n1 2 1\n1 2 2\n1 1 3\n1 2 3\n";
					}
				}
				else{
					if (K == 1){
						cout << 4 << '\n';
						cout << "1 1 1\n1 2 2\n2 1 2\n2 2 3\n";
					}
					else if (K == 2){
						cout << 8 << '\n';
						cout << "1 1 1\n1 2 2\n2 1 2\n2 2 3\n";
						cout << "1 1 2\n1 2 3\n2 1 1\n2 2 2\n";
					}
					else{
						cout << 12 << '\n';
						FOR(i,2){
							FOR(j,2){
								FOR(k,3){
									cout << i+1 <<' ' << j+1<< ' ' << k+1 << '\n';
								}
							}
						}
					}
				}
			}
			else if (P == 3){
				if (J == 1){
					if (K == 1){
						cout << 3 << '\n';
						cout << "1 1 1\n1 2 2\n1 3 3\n";
					}
					else if (K == 2){
						cout << 6 << '\n';
						cout << "1 2 1\n1 1 2\n1 1 3\n";
						cout << "1 3 1\n1 3 2\n1 2 3\n";

					}
					else{
						cout << 9 << '\n';
						cout << "1 1 1\n1 1 2\n1 1 3\n";
						cout << "1 2 1\n1 2 2\n1 2 3\n";
						cout << "1 3 1\n1 3 2\n1 3 3\n";
					}
				}
				else if(J == 2){
					if (K == 1){
						cout << 6 << '\n';
						cout << "1 1 1\n1 2 3\n1 3 2\n";
						cout << "2 1 2\n2 2 1\n2 3 3\n";
					}
					else if (K == 2){
						cout << 9 << '\n';
						cout << "1 1 1\n1 1 2\n";
						cout << "1 2 3\n1 2 2\n";
						cout << "1 3 3\n1 3 1\n";
						cout << "2 1 1\n2 1 2\n";
						cout << "2 2 3\n2 2 2\n";
						cout << "2 3 3\n2 3 1\n";

					}
					else{
						cout << 18 << '\n';
						cout << "1 1 1\n1 1 2\n1 1 3\n";
						cout << "1 2 1\n1 2 2\n1 2 3\n";
						cout << "1 3 1\n1 3 2\n1 3 3\n";
						cout << "2 1 1\n2 1 2\n2 1 3\n";
						cout << "2 2 1\n2 2 2\n2 2 3\n";
						cout << "2 3 1\n2 3 2\n2 3 3\n";
					}
				}

				else{
					if (K == 1){
						cout << 9 << '\n';
						cout << "1 1 1\n1 2 3\n1 3 2\n";
						cout << "2 1 2\n2 2 1\n2 3 3\n";
						cout << "3 1 3\n3 2 2\n3 3 1\n";
					}
					else if (K == 2){
						cout << 18 << '\n';
						cout << "1 1 1\n1 1 2\n";
						cout << "1 2 3\n1 2 2\n";
						cout << "1 3 3\n1 3 1\n";
						cout << "2 1 2\n2 1 3\n";
						cout << "2 2 1\n2 2 3\n";
						cout << "2 3 1\n2 3 2\n";
						cout << "3 1 3\n3 1 1\n";
						cout << "3 2 2\n3 2 1\n";
						cout << "3 3 2\n3 3 3\n";
						}
					else{
						cout << 27 << '\n';
						FOR(i,3){
							FOR(j,3){
								FOR(k,3){
									cout << i+1 <<' ' << j+1<< ' ' << k+1 << '\n';
								}
							}
						}
					}
				}
			}
		}
	}
}
