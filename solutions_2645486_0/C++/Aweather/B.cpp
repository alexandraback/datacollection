#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc!=3) 
    {
	cout << "Missing arguments." << endl;
	return -1;
    }
    
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    int T;

    fin >> T;

    int E, R, N;


    for (int i = 0; i < T; ++i)
    {

	fin >> E;
	fin >> R;
	fin >> N;

	vector<int> V;


	for (int j = 0; j < N; ++j)
	{
	     int temp;
	    fin >> temp;

	    V.push_back(temp);

	}

	for (int j = 0; j < 5; ++j)
	    V.push_back(0);


	
	int eng = E;
	int ret = 0;

	for ( int j = 0; j < V.size() ;++j)
	{
	    if (eng > E-R)
	    {
		ret += (eng - E + R) * V[j];
			    cout << "Spend energy " << eng - E + R << " at task " << j << endl;
		eng = E - R;
			    cout << "Total: " << ret << endl;
	    }

	    int cond = eng/R + 1;
		for (int k = 1; k <= cond +1 ; ++k)
		{

		    if (V[j+k] <= V[j])
		    {
			if (eng >= R)
			{
			    ret += R * V[j];
			    cout << "Spend energy " << R << " at task " << j << endl;
			    eng -= R;

			    cout << "Total: " << ret << endl;
			}
			else
			{
			    ret += eng * V[j];
			    cout << "Spend energy " << eng << " at task " << j << endl;
			    eng = 0;
			    cout << "Total: " << ret << endl;
			}
		    }
		    else break;
		}
	    
	    eng += R;
	}
	

	fout << "Case #" << i+1 << ": " << ret << endl;

    }




    return 0;
}
