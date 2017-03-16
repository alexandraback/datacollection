#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream in("q2.in");
	ofstream out("q2.out");

	int t,caseNum = 1;
	in >> t;
	while (caseNum <=t) {
		int lawn[100][100];
		int n,m;
		in >> n >> m;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++)
				in >> lawn[i][j];
		bool flag = true;
		for (int i=0;i<n;i++)
			for (int j=0;j<m;j++) {
				bool h_flag = true;
				for (int k=0;k<m;k++)
					if (lawn[i][k]>lawn[i][j]) {
						h_flag = false;
						break;
					}
				bool v_flag = true;
				for (int k=0;k<n;k++) 
					if (lawn[k][j]>lawn[i][j]) {
						v_flag = false;
						break;
					}
				if (!h_flag && !v_flag) {
					flag = false;
					break;
				}
			}
		string ans = "NO";
		if (flag)
			ans = "YES";
		out << "Case #" << caseNum << ": " << ans << endl;
		caseNum++;
	}

	out.close();
}