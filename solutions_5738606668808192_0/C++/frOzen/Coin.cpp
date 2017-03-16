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

        fout<<"Case #"<<step+1<<": "<<endl;
        int n,m;
        fin>>n;
        fin>>m;
        vector<int> a;
        for (int i=0;i<n;i++)
            a.push_back(0);
        a[0]=1;a[n-1]=1;
        int num = 0;
        while (m>0)
        {
            //cout<<m<<endl;
            int x = num;

            num++;
            bool iffind;
            for (int j = n-2; j>0;j--)
            {
                a[j] = x%2;
                x = x/2;
                if (x==0) break;
            }
            vector<int> ans;

            for (int i=2;i<=10;i++)
            {
                long long value = 1,carry = i;
                for (int j = n-2;j>=0;j--)
                {

                    value+=carry*a[j];
                    carry*=i;
                }

                iffind = false;
                for (long long j=2;j*j<value;j++)
                {
                    if (value%j==0){
                        ans.push_back(j);
                        iffind = true;
                        break;
                    }
                }
                if (not iffind) break;
            }



            if (not iffind) continue;
            else {

                for (int i=0;i<n;i++)
                    fout<<a[i];
                fout<<" ";
                for (int i=0;i<9;i++)
                    fout<<" "<<ans[i];
                fout<<endl;
                m--;
            }
        }




    }

    fin.close();
    fout.close();
    return 0;
}

