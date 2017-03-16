#include <iostream>
#include <string.h>
#include <fstream>

int main(int argc, char** argv)
{
	std::ifstream in(argv[1]);
	std::ofstream out("result2.txt");
	int num = 0;
	in >> num;
	for (int i = 0; i < num; i++)
	{
		int n = 0;
		int s = 0;
		int p = 0;
		in >> n >> s >> p;
		int score = 0;
		int result = 0;
		int a = 3 * p - 2;
		int b = 3 * p - 4;
		if (p == 1) b = 1;
		for (int j = 0; j < n; j++)
		{
			in >> score;
			if (score >= a) {
				result++;
			} else if (score >= b) {
				if (s > 0) {
					result++;
					s--;
				}
			}
		} 

		out << "Case #" << i + 1 << ": " << result << std::endl;
	}
	in.close();
	out.close();
}
