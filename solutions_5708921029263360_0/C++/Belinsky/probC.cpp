#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Outfit{
	int S;
	int P;
	int J;
};

int main()
{
	ifstream input;
	ofstream output;
	input.open("C-small-attempt0.in");
	output.open("output.txt");
	
	int T, J, P, S, K;
	Outfit outfit;
	
	input >> T;
	
	for (int t = 1; t <= T; t++)
	{
		output <<"Case #" << t << ": ";
		input >> J >> P >> S >> K;
		vector<Outfit> outfits;
		vector<int> combJP, combJS, combPS;
		for(int j = 1; j <= J; j++)
		{
			for(int p = 1; p <= P; p++)
			{
				for(int s = 1; s <= S; s++)
				{
					outfit.J = j;
					outfit.P = p;
					outfit.S = s;
					outfits.push_back(outfit);
				}
			}
		}
		for(int i = 0; i < J*P; i++)
		{
			combJP.push_back(0);
		}
		for(int i = 0; i < J*S; i++)
		{
			combJS.push_back(0);
		}
		for(int i = 0; i < P*S; i++)
		{
			combPS.push_back(0);
		}
		for(int i = 0; i < outfits.size(); i++)
		{
			combJP[((outfits[i].J-1)*P)+(outfits[i].P-1)]++;
			combJS[((outfits[i].J-1)*S)+(outfits[i].S-1)]++;
			combPS[((outfits[i].P-1)*S)+(outfits[i].S-1)]++;
			if(combJP[((outfits[i].J-1)*P)+(outfits[i].P-1)] > K || combJS[((outfits[i].J-1)*S)+(outfits[i].S-1)] > K || combPS[((outfits[i].P-1)*S)+(outfits[i].S-1)] > K)
			{
				combJP[((outfits[i].J-1)*P)+(outfits[i].P-1)]--;
				combJS[((outfits[i].J-1)*S)+(outfits[i].S-1)]--;
				combPS[((outfits[i].P-1)*S)+(outfits[i].S-1)]--;
				outfits.erase(outfits.begin() + i);
				i--;
			}
		}
		output << outfits.size() << endl;
		for(int i = 0; i < outfits.size(); i++)
		{
			output << outfits[i].J << ' ' << outfits[i].P << ' ' << outfits[i].S << endl;
		}
	}
	
	output.close();
	input.close();
	
	return 0;
}