//
//  main.cpp
//  MagicTrick
//
//  Created by L on 14-4-12.
//  Copyright (c) 2014ๅนด L. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
int ans,team1,team2, lent;
void dfs(string str,int k)
{
    if (k==str.length())
    {
        string a = "";
        string b = "";
        bool words = false;
        for (int i=0;i<str.length();i++)
        {
            if (str[i]==' ') {
                words = true;
                continue;
            }
            if (!words) a+=str[i];
            else b+=str[i];
        }
        if (lent ==-1) lent = a.length();
        int num1 = atoi(a.c_str());
        int num2 = atoi(b.c_str());
           // cout<<num1<<":"<<num2<<endl;
        if (abs(num1-num2)<ans) {
            ans = abs(num1-num2);
            team1 = num1;
            team2 = num2;
            //cout<<team1<<":"<<team2<<endl;
        }
        else if (abs(num1-num2)==ans)
        {
            if ((num1<team1) or (num1==team1) and (num2<team2))
            {
                team1 = num1;
                team2 = num2;
            }
        }
        return;
    }
    if (str[k] == '?')
        {
            for (char x = '0';x<='9';x++)
            {
                str[k] = x;
                dfs(str, k+1);
            }
        str[k] = '?';
        }
    else dfs(str, k+1);

}
int main(int argc, const char * argv[])
{

    // insert code here...
    ifstream fin;
    ofstream fout;
    int case_count;
    fin.open("data.in",std::ofstream::in);
    fout.open("data.out",std::ofstream::out);
    fin>>case_count;
    string str;
    ans = 0;
    getline(fin,str);

    for (int step=0;step<case_count;step++)
    {
        getline(fin,str);
        ans = 1000;
        bool words = false;
         lent = -1;
        dfs(str,0);
        string t1,t2;

        stringstream ss1;
        stringstream ss2;
        ss1 << team1;
        ss2 << team2;

        t1 = ss1.str();
        t2 = ss2.str();

        cout<<t1<<","<<t2<<"="<<lent<<endl;
        while (t1.length()<lent)
            t1 = '0' + t1;
        while (t2.length()<lent)
            t2 = '0' + t2;

        fout<<"Case #"<<step+1<<": "<<t1<<" "<<t2<<endl;
        fout<<endl;
    }

    fin.close();
    fout.close();
    return 0;
}

