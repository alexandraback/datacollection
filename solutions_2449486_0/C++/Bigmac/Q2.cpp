#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <string>
#include <algorithm>
using namespace std;
int main(int argc, char **argv)
{
	char *filename_in = "input.txt";
	if(argc > 1)
	{
		filename_in = argv[1];
	}
	string filename_out(filename_in);
	filename_out.append("_output.txt");
	FILE *fi = fopen(filename_in, "rt");
	if(fi == NULL)
	{
		return -1;
	}
	FILE *fo = fopen(filename_out.c_str(), "wt");
	int in_t;
	fscanf(fi, "%d", &in_t);
	for(int it_t = 1; it_t <= in_t; it_t++)
	{
		int in_n;
		fscanf(fi, "%d", &in_n);
		int in_m;
		fscanf(fi, "%d", &in_m);
		int glen[150][150];
		for(int it_n = 0; it_n < in_n; it_n++)
		{
			for(int it_m = 0; it_m < in_m; it_m++)
			{
				fscanf(fi, "%d", &glen[it_n][it_m]);
			}
		}
		bool isYes = true;
		for(int it_n = 0; it_n < in_n; it_n++)
		{
			for(int it_m = 0; it_m < in_m; it_m++)
			{
				//find vert
				bool isSol = true;
				for(int it_find = 0; it_find < in_n; it_find++)
				{
					if(glen[it_n][it_m] < glen[it_find][it_m])
					{
						isSol = false;
					}
				}
				if(isSol)
				{
					continue;
				}
				isSol = true;
				//find hori
				for(int it_find = 0; it_find < in_m; it_find++)
				{
					if(glen[it_n][it_m] < glen[it_n][it_find])
					{
						isSol = false;
					}
				}
				if(!isSol)
				{
					isYes = false;
					break;
				}
			}
		}
		if(isYes)
		{
			fprintf(fo, "Case #%d: YES", it_t);
		}
		else
		{
			fprintf(fo, "Case #%d: NO", it_t);
		}
		fprintf(fo, "\n");
	}
	fclose(fi);
	fclose(fo);
}