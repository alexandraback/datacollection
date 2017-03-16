#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cmath>

int N, S, p;

int sum[150];

using  namespace std;


int solve_single(int case_num);

int main(int argc, char**argv)
{
    if (argc != 2)
	{
             printf("usage:%s input file! \n", argv[0]);
             return 0;
	}
	string line;
	ifstream fin(argv[1]);
	if (fin.fail())
	{
		printf("open file %s error!\n", argv[1]);
	}
	int total_case;
	fin >> total_case;
	
	for(int i = 0; i < total_case; i++)
	{
            fin >> N >> S >> p;
            for(int j = 0; j < N; j++)
            {
                    fin >> sum[j];
            }
		solve_single(i+1);
	}

	fin.close();
	return 0;

}

int solve_single(int case_num)
{
    bool is[150];
    int cnt1 = 0;
    int cnt2 = 0;
    int cnt3 = 0;
    for(int i = 0; i < N; i++)
    {
            if(sum[i] % 3 == 0)
            {
                      int d = sum[i] / 3;
                      if(d >= p)
                      {
                           cnt1++;
                      }
                      else
                      {
                          if(d+1 >= p && d > 0)
                          {
                                 cnt2++;
                          }
                      }
            }
            else if(sum[i] %3 == 1)
            {
                 int d = (sum[i]-1) / 3;
                 if(d+1 >= p)
                 {
                      cnt1++;
                 }
            }
            else
            {
                int d = (sum[i]-2) / 3;
                if(d+1 >= p)
                {
                       cnt1++;
                }
                else
                {
                    if(d+2 >= p)
                    {
                           cnt2++;
                    }
                }
                
            }
    }
    if(cnt2 >= S)
    {
            cnt1 += S;
    }
    else
    {
        cnt1 += cnt2;
    }
	printf("Case #%d: %d\n",case_num,cnt1);
	return 0;
}
