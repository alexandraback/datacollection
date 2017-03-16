#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");

	string s1("ejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjvyeqz ");
	string s2("ourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveupaozq ");

	char mapping[256];
	memset(mapping,0,sizeof(mapping));
	
	for (int i=0; i<s1.size(); ++i)
		mapping[s1[i]] = s2[i];

	unsigned int numberOfCases;
	fin >> numberOfCases;

	string result;
	getline(fin, result);

	for (unsigned int zz=1; zz<=numberOfCases; ++zz)
	{
		getline(fin, result);
		for (int i=0; i<result.size(); ++i)
			result[i] = mapping[result[i]];

		fout << "Case #" << zz << ": " <<result << endl;
	}

	return 0;
}