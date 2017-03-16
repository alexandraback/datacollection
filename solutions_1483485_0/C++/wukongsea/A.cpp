#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <sstream>

using  namespace std;

string s[3] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
 "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
 "de kr kd eoya kw aej tysr re ujdr lkgc jv"};

string t[3] ={"our language is impossible to understand",
"there are twenty six factorial possibilities",
 "so it is okay if you want to just give up"};

char tr[30];
string g;
int solve_single(int case_num);
int tran()
{
    for(int i = 0; i < 30; i++)
    {
            tr[i] = '-';
    }
    
    for(int i = 0; i < 3; i++)
    {
            for(int j = 0; j < s[i].size(); j++)
            {
                    if(s[i].at(j) != ' ')
                    {
                                  tr[s[i].at(j) - 'a'] = t[i].at(j); 
                    }
            }
    }
    //tr['o'-'a'] = 'e';
    tr['z'-'a'] = 'q';
    tr['q'-'a'] = 'z';
    for(int i = 0; i < 26; i++)
    {
           // printf("%c %c\n",i + 'a',tr[i]);
            }
    //        printf("\n");
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
	tran();
	getline(fin,line,'\n');
	stringstream ss(line);
	ss >> total_case;
	for(int i = 0; i < total_case; i++)
	{
            getline(fin, g, '\n'); 
       //     printf("%s ok \n",g.c_str());
		solve_single(i+1);
	}

	fin.close();
	return 0;

}

int solve_single(int case_num)
{
    string line;
    for(int i = 0; i < g.size(); i++)
    {
            if(g.at(i) == ' ')
            {
                       line.push_back(' ');
                       }
            else
            {
                line.push_back(tr[g.at(i)-'a']);
            }
    }
	printf("Case #%d: %s\n",case_num,line.c_str());
	return 0;
}
