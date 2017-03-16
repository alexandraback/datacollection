#include "FileIo.h"

std::vector<std::string> GetLines(std::string fileName)
{
	std::string line;
	std::vector<std::string> file;
	file.clear();
	std::ifstream infile(fileName.c_str(), std::ios_base::in);
	while(std::getline(infile, line, '\n'))
	{
		file.push_back(line);
	}
	return file;
}