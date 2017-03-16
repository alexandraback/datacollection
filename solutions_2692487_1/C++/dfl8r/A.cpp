#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <vector>

// Boost 1.53
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/range/adaptor/reversed.hpp>
#include <boost/range/algorithm.hpp>

//#define VERBOSE

//const std::string FILE_NAME = "test";
//const std::string FILE_NAME = "A-small-attempt0";
const std::string FILE_NAME = "A-large";
const std::string FILE_NAME_IN = FILE_NAME + ".in";
const std::string FILE_NAME_OUT = FILE_NAME + ".out";


struct TestCase
{
	unsigned int armin;
	std::multiset<unsigned int> motes;

	std::string execute() const;
};

void executeTests(const std::vector<TestCase>& testCases);
std::vector<TestCase> readTestCases();

int main()
{
	auto tests = readTestCases();
	executeTests(tests);

	return 0;
}

void executeTest(const TestCase& test, std::ofstream& fout, size_t total)
{
	static int number = 1;
	static double lastPer = 0;

#ifdef VERBOSE
	std::cout << "Executing test case " << number << ": ";
#endif

	auto result = test.execute();

#ifdef VERBOSE
	std::cout << result << std::endl;
#endif

	fout << "Case #" << number << ": " << result << std::endl;

	double per = number * 100.0 / total;

	if (per >= lastPer + 1)
	{
		std::cout << static_cast<int>(per) << "% complete\n";
		lastPer = per;
	}

	number++;
}

void executeTests(const std::vector<TestCase>& tests)
{
	std::ofstream fout(FILE_NAME_OUT);
	auto count = tests.size();
	boost::for_each(tests, [&](const TestCase& test) { executeTest(test, fout, count); });
	fout.flush();
	fout.close();
}

TestCase readTestCase(std::ifstream& fin)
{
	TestCase test;
	int count = 0;
	unsigned int mote = 0;

	fin >> test.armin >> count;

	for (int i = 0; i < count; i++)
	{
		fin >> mote;
		test.motes.insert(mote);
	}

	return test;
}

std::vector<TestCase> readTestCases()
{
	std::vector<TestCase> cases;
	std::ifstream fin(FILE_NAME_IN);

	int caseCount = 0;
	fin >> caseCount;
	std::cout << "Reading in " << caseCount << " test cases.\n";

	std::generate_n(std::back_inserter(cases), caseCount, [&] { return readTestCase(fin); });
	
	fin.close();

	return cases;
}


std::string TestCase::execute() const
{
	unsigned int result = motes.size(), add = 0, remove = motes.size(), size = armin;

	auto findNext =
		[&](unsigned int mote) -> bool
		{
			if (mote < size)
			{
				size += mote;
				remove--;
				return true;
			}
			return false;
		};

	auto it = motes.begin();
	auto oldIt = motes.end();

	while (it != motes.end() && it != oldIt)
	{
		while (size <= *it)
		{
			auto oldSize = size;
			size = 2 * size - 1;
			if (oldSize == size)
				break;
			add++;
		}
		
		oldIt = it;
		it = std::find_if_not(it, motes.end(), findNext);
		
		if (add + remove < result)
			result = add + remove;
	}

	return boost::lexical_cast<std::string>(result);
}
