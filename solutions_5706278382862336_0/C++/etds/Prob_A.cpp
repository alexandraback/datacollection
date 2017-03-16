
#define PROBLEM_NAME "A"
#define PROBLEM_SMALL_INPUT "-small-attempt1"
#define PROBLEM_LARGE_INPUT "-large"

int main(int argc, char* argv[])
{
//	set_fio(PROBLEM_NAME ".txt");
//	set_fio(PROBLEM_NAME PROBLEM_SMALL_INPUT ".in");
	set_fio(PROBLEM_NAME PROBLEM_SMALL_INPUT ".in", PROBLEM_NAME PROBLEM_SMALL_INPUT ".out.txt");
//	set_fio(PROBLEM_NAME PROBLEM_LARGE_INPUT ".in");
//	set_fio(PROBLEM_NAME PROBLEM_LARGE_INPUT ".in", PROBLEM_NAME PROBLEM_LARGE_INPUT ".out.txt");

	int T;
	fin >> T;
	for (int cases=1; cases<=T; ++cases)
	{
		string str;
		fin >> str;
		int P = atoi(&str[0]);
		string str2 = str.substr(str.find_first_of('/')+1);
		int Q = atoi(&str2[0]);

		int i = 0;
		int minAncestor = -1;
		for (; i<40; ++i)
		{
			if (P >= Q)
			{
				if (minAncestor < 0)
					minAncestor = i;
				P -= Q;
			}
			P *= 2;
			if (P == 0)
				break;
		}

		if (i < 40 && P == 0)
			fout << "Case #" << cases << ": " << minAncestor << endl;
		else
			fout << "Case #" << cases << ": impossible" << endl;
	}

	return 0;
}
