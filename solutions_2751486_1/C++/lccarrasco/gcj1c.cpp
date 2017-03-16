#include <string>
#include <iostream>
using namespace std;

bool isConsonant(char c){
	if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return false;
	return true;
}

long long getnvalue(const string& s, int n) {
	int consec = 0;
	long long total = 0;
	long long ultimoconsec = -1;
	size_t L = s.size();
	for (size_t i = 0 ; i < L ; ++i) {
			if (isConsonant(s[i])){
				consec++;
				if (consec >= n) {
					size_t d = i-n+1;
					size_t yo = 1;
					long long deberiamosContarDesde =0;
					if (ultimoconsec != -1) {
						deberiamosContarDesde = ultimoconsec-n+2;
					}
					if (deberiamosContarDesde < 0) deberiamosContarDesde = 0;
					long long desdeizq = d - deberiamosContarDesde;
					if (desdeizq <= 0) desdeizq = 0;
					long long desdeder = L-i-1;
					
					long long adic = (desdeizq > 0 && desdeder > 0)?
						desdeder*desdeizq:0;
					/*cout << "desde " << deberiamosContarDesde << '\n';
					cout << "totizq " <<desdeizq <<  '\n';
					cout << "totyo " <<yo <<  '\n';
					cout << "totder " <<desdeder <<  '\n';
					cout << "adic " << adic <<'\n';
					cout << "---------\n";*/
					total +=adic;
					total += desdeizq;
					total += yo;
					total += L-i-1;
					ultimoconsec = i;
				}
			}
			else {
				consec = 0;
			}
	}
	return total;
}

int main() {
	int T;
	cin >> T;
	ios_base::sync_with_stdio(false);
	for (int c= 1; c<=T ;++c ) {
		string s;int n;
		cin >> s >> n;
		cout << "Case #" << c << ": " <<getnvalue(s,n) << "\n";
	}
}