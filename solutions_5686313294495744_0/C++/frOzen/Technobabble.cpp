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
int ans,team1,team2, lent , n;
string p[20][2];
bool f[20];
void dfs(vector<string> left, vector<string> right, int k)
{
    if (k == n )
    {
        int c = 0;
        for (int i=0;i<n;i++)
            if (!f[i])
            {
                  if ( (find(left.begin(), left.end(), p[i][0])!=left.end()) and (find(right.begin(), right.end(), p[i][1])!=right.end()) )
                    c++;
                  else return;
            }
        if (c>ans)  ans = c;
        return ;
    }
    /*
    for (int i=0;i<left.size();i++)
        cout<<left[i]<<" ";
    cout<<endl;

    for (int i=0;i<right.size();i++)
        cout<<right[i]<<" ";

    cout<<endl<<"----------------"<<endl;
*/
    if ( (find(left.begin(), left.end(), p[k][0])!=left.end()) and (find(right.begin(), right.end(), p[k][1])!=right.end()) )
    {
        dfs(left,right,k+1);
    }
    else
    {
        f[k] = true;
        left.push_back(p[k][0]);
        right.push_back(p[k][1]);
        dfs(left,right,k+1);
        f[k] = false;
        left.pop_back();
        right.pop_back();
        dfs(left,right,k+1);
    }
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


    for (int step=0;step<case_count;step++)
    {
        fin>>n;
        getline(fin,str);
        for (int i=0;i<n;i++)
        {
             getline(fin,str);

            string a = "";
            string b = "";

            bool words = false;
            for (int j=0;j<str.length();j++)
            {
                if (str[j]==' ') {
                    words = true;
                    continue;
                }
                if (!words) a+=str[j];
                else b+=str[j];
            }

                p[i][0] = a;
                p[i][1] = b;
                cout<<a<<" "<<b<<endl;
            f[i] = false;
        }
        vector<string> left,right;
        ans = 0;
        dfs(left,right,0 );
        fout<<"Case #"<<step+1<<": "<<ans<<endl;

    }

    fin.close();
    fout.close();
    return 0;
}

