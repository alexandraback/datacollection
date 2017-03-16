#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	fstream output_file;
	output_file.open("output.txt");


	int T;
	cin >> T;
	for(int i=0; i<T;i++)
	{
		int N, y=0, z=0;
		cin >> N;
		float delta = 0.000001;

		vector<float> naomi;
		vector<float> ken;

		for(int j=0;j<N;j++)
		{
			float w;
			cin>>w;
			naomi.push_back(w);
		}
		sort(naomi.begin(), naomi.end());

		for(int j=0;j<N;j++)
		{
			float w;
			cin>>w;
			ken.push_back(w);
		}
		sort(ken.begin(), ken.end());

		//war
		vector<float>::iterator ken_it = ken.begin();
		for(int j = 0; j < naomi.size();j++)
		{
			while(ken_it < ken.end() && *ken_it < naomi[j])
			{
				ken_it++;
			}
			if(ken_it < ken.end())
			{
				ken_it++;
			}
			else
			{
				z++;
			}
			if(ken_it == ken.end())
			{
				z += naomi.size()-j-1;
				break;
			}
		}
		

		//deceitful war
		int ken_sub = 0;
		ken_it = ken.begin();
		for(int j = 0; j < naomi.size();j++)
		{
			if(naomi[j] > *ken_it)
			{
				ken_it++;
				y++;
			}
			else
			{
				ken_sub++;
			}

			if(ken_it == ken.end()-ken_sub)
			{
				y += naomi.size()-j-1;
				break;
			}
		}


		output_file << "Case #" << i+1 << ": " << y << " " << z << endl;

	}

	output_file.close();
	return 0;
}