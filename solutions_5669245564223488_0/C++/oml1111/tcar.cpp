#include<iostream>
#include<string>
#include<vector>
#include<string>
#define MOD 1000000007
using namespace std;

int t, n, midc[27], startc[27], endc[27], dech[27];
string car[200];

void DFS(int cur, int conn[27], bool explr[27]) {
	explr[cur] = true;
	if(conn[cur] != -1)
		DFS(conn[cur], conn, explr);
}

long long modfac(int a) {
	if(a == 1)
		return 1;
	return modfac(a-1) * a % MOD;
}

int main() {
	cin >> t;
	
	for(int TCASE = 0; TCASE < t; TCASE++) {
		bool explr[27];
		int nextch[27], numcomp = 0;
	
		for(int i=0;i<'z'-'a' + 1; i++)
			midc[i] = 0, startc[i] = 0, endc[i] = 0, dech[i] = 0, explr[i] = false, nextch[i] = -1;
		
		cin >> n;
		for(int i=0;i<n;i++)
			cin >> car[i];
		
		bool inv = false;
		
		cout << "Case #" << TCASE + 1 << ": ";
		
		for(int i=0;i<n;i++) {
			int cs = 0, cursz = car[i].size(), ce = cursz-1, last;
			
			while(cs < cursz && car[i][cs] == car[i][0])
				cs++;
			while(ce >= cs && car[i][ce] == car[i][cursz-1])
				ce--;
			
			if(cs > ce && car[i][0] == car[i][cursz - 1])
				dech[car[i][0] - 'a'] ++;
				
			else if(car[i][cursz-1] == car[i][0]) {
				inv = true;
				break;
			}
			
			else {
				while(cs <= ce) {
					last = cs;
					while(car[i][cs] == car[i][last])
						cs++;
					
					midc[car[i][last] - 'a'] ++;
					
					if(midc[car[i][last] - 'a'] > 1) {
						inv = true;
						break;
					}
				}
				
				startc[car[i][0] - 'a'] ++;
				endc[car[i][cursz - 1] - 'a'] ++;
				
				if(startc[car[i][0] - 'a'] > 1 || endc[car[i][cursz - 1] - 'a'] > 1) {
					inv = true;
					break;
				}
				
				nextch[car[i][0] - 'a'] = car[i][cursz - 1] - 'a';
			}
			
		}
		
		if(inv) {
			cout << "0\n";
			continue;
		}
		
		//finally we find the no of possibilities
		//First we divide into must-be-connected components
		for(int i=0;i<27;i++)
			if(startc[i] == 1 && endc[i] == 0)
				DFS(i, nextch, explr), numcomp++;
		
		long long result = 1;
		for(int i=0;i<27;i++) {
			if( (startc[i] == 1 && !explr[i]) || (midc[i] == 1 && (dech[i] > 0 || startc[i] > 0 || endc[i] > 0) ) ) {
				inv = true;
				break;
			}
			
			if(dech[i] > 0) {
				if(startc[i] == 0 && endc[i] == 0)
					numcomp++;
				result = (result * modfac(dech[i])) % MOD;
			}
		}
			
		if(inv) {
			cout << "0\n";
			continue;
		}
		
		result = (result * modfac(numcomp) ) % MOD;
		cout << result << '\n';
	}
}




























