#include <iostream>
#include <string>
#include <algorithm>
#include <map>

std::map<char, int> m;
std::string r;

void count(char digit, char letter, std::string letters)
{
    int num = m[letter];
    for (size_t i = 0 ; i < letters.size() ; ++i)
        m[letters[i]] -= num;
    for (int i = 0 ; i < num ; ++i)
        r.push_back(digit);
}

int main()
{
	int T;
	std::cin >> T;
    std::string s;
    std::getline(std::cin, s);
	for (int t = 1 ; t <= T ; ++t)
	{
        std::getline(std::cin, s);
        m.clear();
        r.clear();
        for (size_t i = 0 ; i < s.size() ; ++i)
            ++m[s[i]];
        count('0', 'Z', "ZERO");
        count('2', 'W', "TWO");
        count('4', 'U', "FOUR");
        count('6', 'X', "SIX");
        count('3', 'R', "THREE");
        count('1', 'O', "ONE");
        count('5', 'F', "FIVE");
        count('7', 'V', "SEVEN");
        count('8', 'G', "EIGHT");
        count('9', 'E', "NINE");
        std::sort(r.begin(), r.end());
		std::cout << "Case #" << t << ": " << r << "\n";
	}
	return 0;
}

