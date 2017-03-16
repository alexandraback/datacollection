#include <stdio.h>
#include <stdlib.h> 
#include <fstream>
#include <string>
#include <sstream>
int main(int argc, const char* argv[]) {
	std::ifstream file(argv[1]);
	std::string line;
	
	std::getline(file, line);
	int counter = atoi(line.c_str()), i = 0;
	
	while (std::getline(file, line) && i++ < counter)
	{
		double cost, bonus, total, rate = 2;
		std::istringstream iss(line);
		iss >> cost >> bonus >> total;

		double max_so_far = total / rate;
		double factory_time = 0;
		double current = max_so_far;

		while (max_so_far >= current) {
			max_so_far = current;
			factory_time += cost / rate;
			rate += bonus;
			current = factory_time + total / rate;
		}

		printf("Case #%d: %.7f\n", i, max_so_far);
	}
}
