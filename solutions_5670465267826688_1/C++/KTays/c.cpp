#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;


char table(char a, char b);

int main()
{
	long long int test_num, l, x, is_rev = 0;
	char str[10020];

	freopen("D:\\C-large.in", "r", stdin);
	freopen("D:\\out.txt", "w", stdout);

	cin >> test_num;
	for (int t = 1; t <= test_num; t++){
		cin >> l >> x >> str;
		is_rev = 0;

		char c = str[0];
		for (int i = 1; i < l; i++){
			c = table(c, str[i]);

			if (isupper(c)){
				is_rev ^= 1;
				c = tolower(c);
			}
			else if (c == '-'){
				is_rev ^= 1;
				c = '1';
			}
		}

		long long int c_temp = c, rev_temp = is_rev;
		for (int i = 1; i < x % 4 + 4; i++){
			c = table(c, c_temp);
			is_rev ^= rev_temp;

			if (isupper(c)){
				is_rev ^= 1;
				c = tolower(c);
			}
			else if (c == '-'){
				is_rev ^= 1;
				c = '1';
			}
		}


		cout << "Case #" << t << ": ";
		if (c != '1' || is_rev == 0){
			//cout << c << " " << is_rev << endl;
			cout << "NO" << endl;
			continue;
		}

		long long int minn = x > 4 ? 4 : x;
		long long int i_pos = -1;

		c = str[0];
		is_rev = 0;
		for (int i = 0; i < minn && i_pos == -1; i++){
			for (int j = 0; j < l; j++){
				if (i == 0 && j == 0)continue;

				if (is_rev == 0 && c == 'i'){
					i_pos = i*l + j - 1;
					break;
				}

				c = table(c, str[j]);

				if (isupper(c)){
					is_rev ^= 1;
					c = tolower(c);
				}
				else if (c == '-'){
					is_rev ^= 1;
					c = '1';
				}
			}
		}
		if (i_pos == -1){
			cout << "NO" << endl;
			continue;
		}

		long long int k_pos = -1;
		c = str[l - 1];
		is_rev = 0;
		for (int i = minn - 1; i >= 0 && k_pos == -1; i--){
			for (int j = l - 1; j >= 0; j--){
				if (j == l - 1 && i == minn - 1)continue;
				
				if (is_rev == 0 && c == 'k'){
					k_pos = i*l + j + 1;
					break;
				}

				c = table(str[j], c);

				if (isupper(c)){
					is_rev ^= 1;
					c = tolower(c);
				}
				else if (c == '-'){
					is_rev ^= 1;
					c = '1';
				}
			}
		}

		if (k_pos == -1 || i_pos + (l*minn - k_pos) > l*x){
			//cout << "TEST::" << i_pos << " " << k_pos << endl;
			//if (k_pos == -1)cout << "NO for k_pos" << endl;
			//else {
			//	cout << "NO for k_pos < i_pos " << k_pos << " " << i_pos << endl;
			//}
			cout << "NO" << endl;
			continue;
		}

		//cout << "TEST::" << i_pos << " " << k_pos << endl;
		cout << "YES" << endl;

	}
	return 0;
}


char table(char a, char b)
{
	if (a == '1'){
		if (b == '1')return '1';
		if (b == 'i')return 'i';
		if (b == 'j')return 'j';
		if (b == 'k')return 'k';
	}
	if (a == 'i'){
		if (b == '1')return 'i';
		if (b == 'i')return '-';
		if (b == 'j')return 'k';
		if (b == 'k')return 'J';
	}
	if (a == 'j'){
		if (b == '1')return 'j';
		if (b == 'i')return 'K';
		if (b == 'j')return '-';
		if (b == 'k')return 'i';
	}
	if (a == 'k'){
		if (b == '1')return 'k';
		if (b == 'i')return 'j';
		if (b == 'j')return 'I';
		if (b == 'k')return '-';
	}
}