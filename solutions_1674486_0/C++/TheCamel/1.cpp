#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void path_add(vector<bool>& path, int value, const vector< vector<int> >& inh)
{
	if(path[value])
		return;
	path[value] = true;
	for(int i=0; i<inh[value].size(); i++)
		path_add(path, inh[value][i]-1, inh);
	return;
}

int main()
{
	ofstream out("1.output");
	int T;
	cin >> T;
	for(int cases=1; cases<=T; cases++)
	{
		int N;
		cin >> N;
		vector< vector<int> > inh;
		inh.resize(N);
		bool valid = false;
		for(int i=0; i<N; i++)
		{
			int tmp;
			cin >> tmp;
			inh[i].resize(tmp);
			if(tmp >= 2)
				valid = true;
			for(int j=0; j<tmp; j++)
				cin >> inh[i][j];
		}
		if(!valid)
			out << "Case #" << cases << ": No" << endl;
		else
		{
			bool diamond = false;
			for(int i=0; i<N && !diamond; i++)
			{
				if(inh[i].size()>=2)
				{
					vector< vector<bool> > paths;
					paths.resize(inh[i].size());
					for(int j=0; j<paths.size(); j++)
					{
						vector<bool> tmp;
						tmp.resize(N);
						for(int k=0; k<N; k++)
							tmp[k] = false;
						tmp[i] = true;
						path_add(tmp, inh[i][j]-1, inh);
						for(int k=0; k<N; k++)
							cout << tmp[k] << " ";
						cout << endl;
						paths[j] = tmp;
					}
					for(int j=0; j<N && !diamond; j++)
					{
						if(j != i)
						{
							int count = 0;
							for(int k=0; k<paths.size() && count<2; k++)
							{
								if(paths[k][j] == true)
									count++;
							}
							//cout << count << " ";
							if(count == 2)
								diamond = true;
						}
					}
					//cout << endl;
				}
			}
			if(diamond)
				out << "Case #" << cases << ": Yes" << endl;
			else
				out << "Case #" << cases << ": No" << endl;
		}
	}
	return 0;
}
