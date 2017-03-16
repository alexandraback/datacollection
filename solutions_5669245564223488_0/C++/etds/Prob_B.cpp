
#define PROBLEM_NAME "B"
#define PROBLEM_SMALL_INPUT "-small-attempt0"
#define PROBLEM_LARGE_INPUT "-large"

void swap(int* vidx, int i, int j)
{
	int temp;
	temp = vidx[i];
	vidx[i] = vidx[j];
	vidx[j] = temp;
}

vector<string> vstr;
int total;


bool evaluate(int* vidx, int n)
{
	string strall;

	for (int i=0; i<n; ++i)
	{
		int idx = vidx[i];
		string str = vstr[idx];
		strall += str;
	}

	vector<int> visited(26);
	char curr = strall[0];
	visited[curr-'a'] = 1;

	for (int i=1; i<strall.length(); ++i)
	{
		if (strall[i] == curr)
		{
			continue;
		}
		else
		{
			char prev = curr;
			curr = strall[i];

			if (visited[curr-'a']) // already occurred
				return false;
			visited[curr-'a'] = 1;
			continue;
		}
	}
	return true;


	//	char first = str[0];
	//	char last = str.back();

	//	for (int j=i+1; j<n; ++j)
	//	{
	//		int curr_idx = vidx[j];
	//		string curr_str = vstr[curr_idx];

	//		char curr_first = curr_str[0];
	//		char curr_last = curr_str.back();

	//		if (
	//	}
	//}
}

//void permute(int *vidx, int i, int n)
//{
//	int j;
//	if (i == n)
//	{
//		evaluate(vidx, n);
//	}
//	else
//	{
//		for (j = i; j <= n; j++)
//		{
//			swap(vidx, i, j);
//			permute(vidx, i+1, n);
//			swap(vidx, i, j);
//			//backtrack
//		}
//	}
//}  
//
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
		int N;
		fin >> N;

		vstr.clear();
		total = 0;
		vstr.reserve(N);
		for (int i=0; i<N; ++i)
		{
			string str;
			fin >> str;
			vstr.push_back(str);
		}

		vector<int> vidx;
		vidx.reserve(N);
		for (int i=0; i<N; ++i)
		{
			vidx.push_back(i);
		}

		do
		{
			bool b = evaluate(&vidx[0], N);
			if (b)
				total++;
		}
		while(std::next_permutation(vidx.begin(), vidx.end()));

		fout << "Case #" << cases << ": " << total << endl;
	}

	return 0;
}
