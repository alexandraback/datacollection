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
            fin >> A >> B;
		solve_single(i+1);
	}

	fin.close();
	return 0;

}

int solve_single(int case_num)
{
	
	int n = 1;
    if(B > 0)
    {
         n = log10(B) + 1;
    }
    //printf("n:%d \n",n);
    string As,Bs;
    tran(As,A,n);
    tran(Bs,B,n);
    LL cnt = 0;
	for(LL i = A; i<=B; i++)
	{
           string s;
           tran(s, i, n);
           vector<string> stack;
           stack.push_back(s);
           for(int j = 1;j <= n-1; j++)
           {
                   string temp = s.substr(j,n-j) + s.substr(0,j);
                    if(temp <= s || temp > Bs)
                    {
                            continue;
                    }
                    if(find(stack.begin(),stack.end(),temp) != stack.end())
                    {
                      continue;
                    }
                    stack.push_back(temp);
                    cnt++;
           }
 
    }
    printf("Case #%d: %ld\n",case_num,cnt);
	return 0;
}
