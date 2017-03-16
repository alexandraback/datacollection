#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
using namespace::std;

int min_diff = INT_MAX;
string r1, r2;

void dfs(int p, int n, string& s1, string& s2)
{
	if (p >= n) {
		//cout << s1 << "  " << s2 << "\n";
		int n1 = atoi(s1.c_str());
		int n2 = atoi(s2.c_str());
		if (abs(n1 - n2) < min_diff) {
			min_diff = abs(n1 - n2);
			r1 = s1;
			r2 = s2;
		}
		return;
	}
	if (s1[p] == '?') {
		string s1s = s1.substr(0, p+1);
		string s2s = s2.substr(0, p + 1);
		int n1 = atoi(s1s.c_str());
		int n2 = atoi(s2s.c_str());
		if (n1 < n2) {
			s1[p] = '9';
			s2[p] = '0';
			dfs(p + 1, n, s1, s2);
		}
		else if (n1 > n2) {
			s1[p] = '0';
			s2[p] = '9';
			dfs(p + 1, n, s1, s2);
		}
		else {
			for (char i = '0'; i <= '9'; ++i) {
				s1[p] = i;
				s2[p] = i;
				dfs(p + 1, n, s1, s2);
			}
		}
		s1[p] = '?';
		s2[p] = '?';
	
	}
	//if (p < n / 2) {
	//	if (s1[p] == '?') {
	//		for (char i = '0'; i <= '9'; ++i) {
	//			s1[p] = i;
	//			dfs(p + 1, n, s1, s2);
	//			s1[p] = '?';
	//		}
	//	}
	//	else {
	//		dfs(p + 1, n, s1, s2);
	//	}
	//}
	//else {
	//	if (s2[p - n / 2] == '?') {
	//		for (char i = '0'; i <= '9'; ++i) {
	//			s2[p - n / 2] = i;
	//			dfs(p + 1, n, s1, s2);
	//			s2[p - n / 2] = '?';
	//		}
	//	}
	//	else {
	//		dfs(p + 1, n, s1, s2);
	//	}
	//}


}

int main() 
{
	FILE* file_in = fopen("B.in","r");
	FILE* file_out = fopen("B.out","w");
	int n_case;
	fscanf(file_in,"%d",&n_case);
	for (int i_case = 0; i_case < n_case; ++i_case) {
		printf("i_case %d %d\n", i_case, n_case);
		char buf1[20];
		char buf2[20];
		string s1, s2;
		fscanf(file_in,"%s%s", buf1, buf2);
		s1 = buf1;
		s2 = buf2;
		min_diff = INT_MAX;
		int n = s1.length();
		for (int i = 0; i < n; ++i) {
			if (s1[i] == '?' && s2[i] != '?') {
				s1[i] = s2[i];
			} else if (s1[i] != '?' && s2[i] == '?') {
				s2[i] = s1[i];
			}
		}

		for (int i = 0; i < n; ++i) {
			if (s1[i] == '?' && s2[i] == '?') {
				s1[i] = s2[i] = '0';
			} else{
				break;
			}
		}

		dfs(0, s1.length(), s1, s2);

		
		fprintf(file_out,"Case #%d: %s %s\n", i_case + 1, r1.c_str(), r2.c_str());

	
	}


	
	fclose(file_out);
	fclose(file_in);

	system("pause");
	return 0;
}