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
using namespace std;

vector<int> f;
vector<bool> p;
int ans;
void dfs(int start, int last, int current, int counter )
{
    int n = f.size();

    if ((f[last]==current) && (f[current]==start)) ans = max(ans, counter);
    if (f[current]==last) ans = max(ans, counter);
      // cout<<"("<<f[current]<<","<<start<<"="<<ans<<")"<<endl;
    for (int i=0;i<f.size();i++)
        if (!p[i])
        {
            if ((f[last]==current)&&(f[current] == i ))
            {
              //  cout<<"append"<<i<<",";
                p[i] = true;
                dfs(start, current , i,  counter+1);
                p[i] = false;
            }
            if ((f[current] == last)&&(f[i]==current))
            {
                // cout<<"append"<<i<<",";
                p[i] = true;
                 dfs(start, current , i, counter+1);
                p[i] = false;
            }
        }
      //  cout<<"back"<<endl;

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

    for (int step=0;step<case_count;step++)
    {
        int n;
        f.clear();
        fin>>n;
        cout<<step<<":"<<n<<endl;
        for (int i=0;i<n;i++)
        {
            int x;
            fin>>x;
            f.push_back(x-1);

        }
        ans = 0;
        for (int i=0;i<n;i++)

        {
            cout<<"start from"<<i<<endl;
            p.clear();
            for (int j=0;j<n;j++)
                p.push_back(false);
            p[i] = true;
            p[f[i]] = true;
            dfs(i, i , f[i] , 2);
        }

        fout<<"Case #"<<step+1<<": "<<ans<<endl;
    }

    fin.close();
    fout.close();
    return 0;
}

