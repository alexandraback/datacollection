#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

#define MAX_NUM 2000000

int main(int argc, char** argv) {
	std::ifstream in(argv[1]);
	std::ofstream out("result3.txt");
	int num = 0;
	in >> num;
	bool check[MAX_NUM];
	char tt[64];
	for (int i = 0; i < num; i++) {
		memset(check, false, MAX_NUM * sizeof(bool));
		int a = 0;
		int b = 0;
		in >> a >> b;
		int result = 0;
		sprintf(tt, "%d", a); 
		std::string number = tt;
		int len = number.length();
		for (int j = a; j <= b; j++) {
			if (!check[j]) {
				check[j] = true;
				sprintf(tt, "%d", j); 
				number = tt;
				int k = 1;
				for (int t = 1; t < len; t++) {
					if (number[t] != '0') {
						std::string buf = number.substr(t) + number.substr(0, t);
						int num2 =  atoi(buf.c_str());
						if (num2 >= a && num2 <= b) {
							if (!check[num2]) {
								check[num2] = true;
								k++;
							}
						}
					}
				}
				result += k * (k - 1) / 2;
			}
		}

		out << "Case #" << i + 1 << ": " << result << std::endl;
	}
	in.close();
	out.close();
}
