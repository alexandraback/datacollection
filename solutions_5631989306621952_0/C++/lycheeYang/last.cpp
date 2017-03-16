#include <fstream>

using namespace std;

int main() {
	ifstream in("in.txt");
	ofstream out("out.txt");
	int T = 0;
	in >> T;
	for (int i = 0; i < T; ++i)
	{
		string S;
		in >> S;
		int l = S.length();
		string result = "";
		result += S[0];
		for (int j = 1; j < l; ++j)
		{
			if (S[j] >= result[0])	
			{
				result.insert(result.begin(), S[j]);
			}
			else result.insert(result.end(), S[j]);
		}
		out << "Case #"<<i+1<<": "<<result<<endl;
	}
}