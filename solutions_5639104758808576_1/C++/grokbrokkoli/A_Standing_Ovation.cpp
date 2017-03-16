#include <iostream>
#include <fstream>
#include <string>

int main()
{
	int testCases;
	std::cin >> testCases;
	for (int testCase = 1; testCase <= testCases; ++testCase) {
		int maxShyness;
		std::string shyStr;
		std::cin >> maxShyness >> shyStr;
		int standing = 0, friendsToInvite = 0;
		for (std::size_t i = 0; i < shyStr.size(); ++i) {
			if (standing < i) {
				friendsToInvite += i - standing;
				standing += i - standing;
			}
			standing += shyStr[i] - '0';
		}
		std::cout << "Case #" << testCase << ": " << friendsToInvite << std::endl;
	}
}
