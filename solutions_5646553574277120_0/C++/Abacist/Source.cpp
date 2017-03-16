#include<iostream>
#include<vector>
#include<fstream>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<algorithm>
#include<map>

using namespace std;

struct Info{
	int value;
	int rest;
};

bool cmp(Info i1, Info i2)
{
	return i1.value < i2.value;
}


int main()
{
	int T, C, D, V;
	ifstream in ("input.txt");
	ofstream out("output.txt");
	in >> T;
	for (int c = 1; c <= T; c++){
		in >> C >> D >> V;
		int result = 0;
		vector<int> type;
		for (int j = 0; j < D; j++){
			int temp;
			in >> temp;
			type.push_back(temp);
		}
		sort(type.begin(), type.end());

		//bool *flag = new bool[V + 1]{false};
		vector<bool> flag(V + 1, false);

		for (int i = 0; i < type.size(); i++){
			for (int j = 1; j <= V; j++){
				if (flag[j] == true)
				{
					if (j + type[i] <= V)
						flag[j + type[i]] = true;
				}
			}
			flag[type[i]] = true;
		}
		

		int cur = 1;
		while (cur <= V)
		{
			if (flag[cur] == false)
			{
				result++;
				for (int i = cur + 1; i<=V; i++)
				{
					if (flag[i] == false && flag[i - cur] == true)
					{
						flag[i] = true;
					}
				}
				flag[cur] = true;
			}
			cur++;
			
		}

		cout << "Case #" << c << ": " << result << endl;
		out << "Case #" << c << ": " << result << endl;
	}



	in.close();
	out.close();
}