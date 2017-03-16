#include <string>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <string>
#include <algorithm>
using namespace std;
char in_a_arr[200];
char in_b_arr[200];
char *in_a;
char *in_b;
bool check_loop(char * val)
{
	int val_len = strlen(val);
	for(int i = 0; i < val_len; i++)
	{
		if(val[i] != val[val_len - 1 - i])
		{
			return false;
		}
	}
	return true;
}
bool isInside(char * val)
{
	//printf("check %s\n", val);
	int val_len = strlen(val);
	int a_len = strlen(in_a);
	int b_len = strlen(in_b);
	if((val_len > a_len  || (a_len == val_len && strcmp(val, in_a) >= 0)) &&
		(b_len > val_len || (b_len == val_len && strcmp(val, in_b) <= 0)))
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main(int argc, char **argv)
{
	in_a = in_a_arr;
	in_b = in_b_arr;
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
		char temp[200];
		char temp2[200];
		fscanf(fi, "%s %s", in_a, in_b);
		while(*in_a == '0'){in_a++;}
		while(*in_b == '0'){in_b++;}
		int len_a = strlen(in_a);
		int len_b = strlen(in_b);
		int result = 0;
		for(int k = 3; k <= 101; k++)
		{
			//compose
			if(k % 2 == 1)
			{
			//check 10201 pattern
				int zero = k / 2 - 1;
				int p = 0;
				temp[p++] = '1';
				for(int c = 0; c < zero; c++)
				{
					temp[p++] = '0';
				}
				temp[p++] = '2';
				for(int c = 0; c < zero; c++)
				{
					temp[p++] = '0';
				}
				temp[p++] = '1';
				temp[p++] = 0;
				if(isInside(temp))
				{
					result++;
				}
			//check 40804 pattern
				p = 0;
				temp[p++] = '4';
				for(int c = 0; c < zero; c++)
				{
					temp[p++] = '0';
				}
				temp[p++] = '8';
				for(int c = 0; c < zero; c++)
				{
					temp[p++] = '0';
				}
				temp[p++] = '4';
				temp[p++] = 0;
				if(isInside(temp))
				{
					result++;
				}
			//check 12321 pattern
				p = 0;
				if(zero >=1 && zero + 2 <=9)
				{
					for(int c = 1; c <= zero + 2; c++)
					{
						temp[p++] = '1' + (c-1);
					}
					for(int c = zero+1; c >= 1; c--)
					{
						temp[p++] = '1' + (c-1);
					}
					temp[p++] = 0;
					if(isInside(temp))
					{
						result++;
					}
				}
			}
		}
		//check 44944, 14641, 9, 4, 1
		if(isInside("44944"))
		{
			result++;
		}
		if(isInside("14641"))
		{
			result++;
		}
		if(isInside("9"))
		{
			result++;
		}
		if(isInside("4"))
		{
			result++;
		}
		if(isInside("1"))
		{
			result++;
		}
		/*
		int in_a_val = atoi(in_a);
		int in_b_val = atoi(in_b);
		int result_verify = 0;
		for(int ir = in_a_val; ir <= in_b_val; ir++)
		{
			int sr = sqrt((double)ir);
			if(sr * sr == ir)
			{
				sprintf(temp, "%d", ir);
				sprintf(temp2, "%d", sr);
				if(check_loop(temp) && check_loop(temp2))
				{
					result_verify++;
				}
			}
		}
		assert(result_verify == result);
		*/
		fprintf(fo, "Case #%d: %d", it_t, result);
		fprintf(fo, "\n");
	}
	fclose(fi);
	fclose(fo);
}