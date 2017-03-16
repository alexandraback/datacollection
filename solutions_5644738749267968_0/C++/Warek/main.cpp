#include <iostream>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <vector>

void quickSort(std::vector<double> &input, int left, int right)  
{  
	int i=left, j=right;
	double pivot = input[(i+j)/2];
	while (i <= j) {
		while (input[i] < pivot)
			i++;

		while (input[j] > pivot)
			j--;

		if (i <= j) {
			double tmp = input[i];
			input[i] = input[j];
			input[j] = tmp;

			i++;
			j--;
		}
	}
	if (left < j)
		quickSort(input, left, j);
	if (i < right)
		quickSort(input, i, right);
}

int main(int argc, char *argv[])
{
	std::ifstream read("D-small-attempt0.in");
	std::ofstream write("D-small-attempt0.out");
	int num=0;
	read >> num;
	int blocks;
	for (int i=0;i<num;i++)
	{
		read >> blocks;
		std::vector<double> naomi(blocks);
		std::vector<double> ken(blocks);
		for (int j=0;j<blocks;j++)
			read >> std::fixed >> std::setprecision(5) >> naomi[j];
		for (int j=0;j<blocks;j++)
			read >> std::fixed >> std::setprecision(5) >> ken[j];
		quickSort(naomi,0,naomi.size()-1);
		quickSort(ken,0,ken.size()-1);
		std::vector<double> naomiNormal(naomi);
		std::vector<double> kenNormal(ken);
		int decWar=0;
		int normalWar=0;
		while(naomi.size()>0)
		{
			if (naomi[naomi.size()-1] > ken[ken.size()-1])
			{
				decWar++;
				naomi.erase(naomi.begin()+(naomi.size()-1));
				ken.erase(ken.begin()+(ken.size()-1));
				continue;
			}
			else 
			{
				if (naomi[0]<ken[ken.size()-1])
				{
					naomi.erase(naomi.begin());
					ken.erase(ken.begin()+(ken.size()-1));
				}
			}
		}
		while(naomiNormal.size()>0)
		{
			if (naomiNormal[naomiNormal.size()-1] > kenNormal[kenNormal.size()-1])
			{
				normalWar++;
				naomiNormal.erase(naomiNormal.begin()+(naomiNormal.size()-1));
				kenNormal.erase(kenNormal.begin());
				continue;
			}
			else 
			{
				if (naomiNormal[naomiNormal.size()-1]<kenNormal[kenNormal.size()-1])
				{
					naomiNormal.erase(naomiNormal.begin()+(naomiNormal.size()-1));
					kenNormal.erase(kenNormal.begin()+(kenNormal.size()-1));
				}
			}
		}
		write << "Case #" << i+1 << ": " << decWar << " " << normalWar <<std::endl;
	}
	return 0;
}

