#include <iostream>
using namespace std;


int main()
{
	int n, i, j, k, b[4][4], o, x;
	string s;
	
	cin >> n;
	getline(cin, s);
	for (i=0; i<n; i++) {
		for (j=0; j<4; j++) {
			getline(cin, s);
				for (k=0; k<4; k++) {
					b[j][k]=0;
					if (s[k]=='T') b[j][k]=5;
					if (s[k]=='X') b[j][k]=1;
					if (s[k]=='O') b[j][k]=2;
				}
		}
		o=0;
		for (j=0; j<4; j++) 
			for (k=0; k<4; k++) 
				if (b[j][k] == 0) o=1;		

		for (j=0; j<4; j++) {
			x=1;
			for (k=0; k<4; k++) 
				if (b[j][k] == 2 || b[j][k] == 0) x=0;		
			if (x) o=20;
		}

		for (j=0; j<4; j++) {
			x=1;
			for (k=0; k<4; k++) 
				if (b[k][j] == 2 || b[k][j] == 0) x=0;		
			if (x) o=20;
		}

		x=1;
		for (k=0; k<4; k++) 
			if (b[k][k] == 2 || b[k][k] == 0) x=0;		
		if (x) o=20;

		x=1;
		for (k=0; k<4; k++) 
			if (b[k][3-k] == 2 || b[k][3-k] == 0) x=0;		
		if (x) o=20;
		

		for (j=0; j<4; j++) {
			x=1;
			for (k=0; k<4; k++) 
				if (b[j][k] == 1 || b[j][k] == 0) x=0;		
			if (x) o=50;
		}

		for (j=0; j<4; j++) {
			x=1;
			for (k=0; k<4; k++) 
				if (b[k][j] == 1 || b[k][j] == 0) x=0;		
			if (x) o=50;
		}

		x=1;
		for (k=0; k<4; k++) 
			if (b[k][k] == 1 || b[k][k] == 0) x=0;		
		if (x) o=50;

		x=1;
		for (k=0; k<4; k++) 
			if (b[k][3-k] == 1 || b[k][3-k] == 0) x=0;		
		if (x) o=50;

		
		if (o==50) cout << "Case #" << i+1 << ": O won" <<  endl;
		if (o==20) cout << "Case #" << i+1 << ": X won" <<  endl;
		if (o==1) cout << "Case #" << i+1 << ": Game has not completed" <<  endl;
		if (o==0) cout << "Case #" << i+1 << ": Draw" << endl;
		getline(cin, s);
	}	
	return 0;
}
