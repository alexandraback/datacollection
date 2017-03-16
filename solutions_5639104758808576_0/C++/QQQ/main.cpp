#include <iostream>
#include <string>


int main()
{
	int numCases = 0;
	std::cin >> numCases;

	for (int iCase = 1; iCase <= numCases; iCase++)
	{
		int shyMax = 0;
		std::cin >> shyMax;

		std::string audience;
		std::getline(std::cin, audience);

		int minFriends = 0;
		int sum = 0;

		for (int index = 0; index < shyMax + 1; index++)
		{
			char S = audience[index + 1] - '0';
			sum += S;
			if (sum < index + 1)
			{
				minFriends += index + 1 - sum;
				sum = index + 1;
			}
		}

		std::cout<<"Case #" << iCase << ": " << minFriends << std::endl;
	}

	return 0;
}