/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2012/4/14 12:28:53
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define SZ(v) ((int)(v).size())

int t;
string str;
char ch[] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'};

int main()
{
        cin >> t;
        getchar();
        fstream fout("A.out");
        for (int k = 1; k <= t; ++ k)
        {
                getline(cin, str);
                for (int i = 0; i < SZ(str); ++ i)
                {
                        if (str[i] == ' ')
                                continue;
                        str[i] = ch[str[i] - 'a'];
                }
                fout << "Case #"<< k << ": ";
                fout << str;
                if (k < t)
                        fout << endl;
        }
        return 0;
}
