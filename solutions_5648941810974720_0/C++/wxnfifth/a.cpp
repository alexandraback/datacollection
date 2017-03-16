#include <cstdio>
#include <string>
#include <vector>
using namespace::std;


int main() 
{
	FILE* file_in = fopen("A-small-attempt0.in","r");
	FILE* file_out = fopen("A-small-attempt0.out","w");
	int n_case;
	fscanf(file_in,"%d",&n_case);
	for (int i_case = 0; i_case < n_case; ++i_case) {
		string s;
		char buf[3000];
		fscanf(file_in, "%s", buf);
		s = buf;
		vector<int> nums(300, 0);
		for (int i = 0; i < s.length(); ++i) {
			nums[s[i]]++;
		}
		int cnt = s.length();
		vector<int> tmp(10);
		tmp[0] = nums['Z'];
		nums['Z'] -= tmp[0];
		nums['E'] -= tmp[0];
		nums['R'] -= tmp[0];
		nums['O'] -= tmp[0];

		tmp[2] = nums['W'];
		nums['T'] -= tmp[2];
		nums['W'] -= tmp[2];
		nums['O'] -= tmp[2];

		tmp[4] = nums['U'];
		nums['F'] -= tmp[4];
		nums['O'] -= tmp[4];
		nums['U'] -= tmp[4];
		nums['R'] -= tmp[4];

		tmp[6] = nums['X'];
		nums['S'] -= tmp[6];
		nums['I'] -= tmp[6];
		nums['X'] -= tmp[6];

		tmp[8] = nums['G'];
		nums['E'] -= tmp[8];
		nums['I'] -= tmp[8];
		nums['G'] -= tmp[8];
		nums['H'] -= tmp[8];
		nums['T'] -= tmp[8];

		tmp[1] = nums['O'];
		nums['O'] -= tmp[2];
		nums['N'] -= tmp[2];
		nums['E'] -= tmp[2];

		tmp[3] = nums['T'];
		nums['T'] -= tmp[3];
		nums['H'] -= tmp[3];
		nums['R'] -= tmp[3];
		nums['E'] -= tmp[3];
		nums['E'] -= tmp[3];

		tmp[5] = nums['F'];
		nums['F'] -= tmp[5];
		nums['I'] -= tmp[5];
		nums['V'] -= tmp[5];
		nums['E'] -= tmp[5];

		tmp[7] = nums['S'];
		nums['S'] -= tmp[7];
		nums['E'] -= tmp[7];
		nums['V'] -= tmp[7];
		nums['E'] -= tmp[7];
		nums['N'] -= tmp[7];

		//NINE
		tmp[9] = nums['I'];

		fprintf(file_out,"Case #%d: ", i_case + 1);
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < tmp[i]; ++j) {
				fprintf(file_out, "%d", i);
			}
		}
		fprintf(file_out, "\n");
	
	}


	
	fclose(file_out);
	fclose(file_in);

	system("pause");
	return 0;
}