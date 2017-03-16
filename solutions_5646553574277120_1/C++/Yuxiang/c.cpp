#include <bits/stdc++.h>
#include <fstream>
using namespace std;
bool va[50];

int main(){
	ifstream in("C-small-attempt3.in");
	ofstream out("output");
	int T;
	in >> T;
	for (int z = 1 ; z <= T ; z++)
	{
		long long C, D, V;
		in >> C >> D >> V;
		int indexD = 0;
		long long d[D];
		for (int i = 0 ; i < D ; i++)
			in >> d[i];
		long long indexV = 1;
		long long add = 0;
		while (indexV <= V)
		{
			if (indexV >= d[indexD])
			{
				indexD++;
				indexV = d[indexD]*C + indexV;
			}
			else
			{
				add++;
				indexV += 1 + indexV*C;
			}
		}
		out << "Case #"<<z<<": "<<add<<endl;
	}
	in.close();
	out.close();
	return 0;
}
