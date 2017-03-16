#include <iostream>
#include <string.h>
#include <fstream>

int main(int argc, char** argv)
{
	char translator[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};
	std::ifstream in(argv[1]);
	std::ofstream out("result.txt");
	int num = 0;
	in >> num;
	std::string sentence;
	getline(in, sentence);
	for (int i = 0; i < num; i++)
	{
		getline(in, sentence);
		int len = sentence.length();
		for (int j = 0; j < len; j++)
		{
			if (sentence[j] >= 'a' && sentence[j] <= 'z')
			{
				sentence[j] = translator[sentence[j] - 'a'];
			}
		}
		out << "Case #" << i + 1 << ": " << sentence << std::endl;
	}
	in.close();
	out.close();
}
