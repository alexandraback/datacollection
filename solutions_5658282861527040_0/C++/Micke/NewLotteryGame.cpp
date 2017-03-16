#include <fstream>
#include <iomanip>
#include <list>
#include <set>
#include <sstream>
#include <string>
#include <vector>

namespace
{
	template<typename T>
	T getValue(std::istream& input)
	{
		T value;
		input >> value;
		return value;
	}

	template<typename T>
	std::string toString(const T& value)
	{
		std::stringstream stream;
		stream << value;
		return stream.str();
	}

	struct CaseData
	{
		unsigned a;
		unsigned b;
		unsigned k;
	};

	struct ResultData
	{
		unsigned long long count;
	};

	CaseData readCaseData(std::istream& input)
	{
		CaseData data;

		data.a = getValue<unsigned>(input);
		data.b = getValue<unsigned>(input);
		data.k = getValue<unsigned>(input);

		return data;
	}

	ResultData processData(const CaseData& data)
	{
		ResultData result;

		result.count = 0;

		for (unsigned a = 0; a < data.a; ++a)
		{
			for (unsigned b = 0; b < data.b; ++b)
			{
				if ((a & b) < data.k)
					++result.count;
			}
		}

		return result;
	}

	std::string writeResultData(const ResultData& result)
	{
		return toString(result.count);
	}
}

int main(int argc, char** argv)
{
	std::ifstream input("b.in");
	std::ofstream output("b.out");

	unsigned cases = getValue<unsigned>(input);

	for (unsigned caseIndex = 0; caseIndex < cases; ++caseIndex)
		output << "Case #" << caseIndex + 1 << ": " << writeResultData(processData(readCaseData(input))) << std::endl;

	input.close();
	output.close();

	return 0;
}

