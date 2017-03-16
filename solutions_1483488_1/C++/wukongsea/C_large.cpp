#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cmath>


using  namespace std;


typedef long long int LL;
LL A, B;
int solve_single(int case_num);
int d[2000010];
int index[2000010][8];

LL MAX = 2000000;

LL tran2(string s);
int tran(string &s, LL d,int n);
void pre();

int main(int argc, char**argv)
{
   
    
    if (argc != 2)
	{
             printf("usage:%s input file! \n", argv[0]);
             return 0;
	}
	string line;
	pre();
	ifstream fin(argv[1]);
	if (fin.fail())
	{
		printf("open file %s error!\n", argv[1]);
	}
	int total_case;
	fin >> total_case;

	for(int i = 0; i < total_case; i++)
	{
            fin >> A >> B;
		solve_single(i+1);
	}

	fin.close();
	return 0;

}

int solve_single(int case_num)
{
	
	memset(d,0,sizeof(int) * (MAX+10));
	LL cnt = 0;
	for(LL i = A; i <= B; i++)
	{
            for(LL j = 0; j < 8; j++)
            {
                    if(index[i][j] > i&& index[i][j] <= B)
                    {
                                   d[index[i][j]] = 0;
                    }
                    
            }
            
            
            for(int j = 0; j < 8; j++)
            {
                    if(index[i][j] > i && index[i][j] <=B && d[index[i][j]] == 0)
                    {
                                   cnt++;
                                   d[index[i][j]] = 1;
                    }
                    
            }
    }
    printf("Case #%d: %ld\n",case_num,cnt);
	return 0;
}

void pre()
{
     memset(index,0, sizeof(int) * (MAX + 10) * 8);
     LL i = 1;
     LL k = 1;
     LL e = 10;
     while(i <=MAX)
     {
             for(LL j = e/10; j < e && j <= MAX; j++)
             {
                     string s;
                     tran(s,j,k);
                     for(int kk = 1; kk <= k -1; kk++)
                     {
                              string temp = s.substr(kk,k-kk) + s.substr(0,kk);
                              LL r = tran2(temp);
                             index[i][kk-1] = r; 
                              
                     }
                     i++;
             }
             
             k++;
             e *= 10;
                    
     }
}
int tran(string &s, LL d,int n)
{
    s.clear();
    for(int i = 0; i < n; i++)
    {
            s.push_back((d % 10) + '0');
            d = d / 10;
    }
    //printf("test %s\n", s.c_str());
    reverse(s.begin(),s.end());
}
LL tran2(string s)
{
          LL r = 0;
          LL k = 1;
          for(int i = s.size()-1; i >= 0; i--)
          {
                  r += (s.at(i) - '0')*k;
                  k *= 10;
          }
          return r;
}
