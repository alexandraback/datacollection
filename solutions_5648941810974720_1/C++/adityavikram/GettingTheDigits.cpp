#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;



int main()
{
    std::ios::sync_with_stdio(false);
    int t,T;
    cin >> T;
    for (t=0; t<T; t++)
    {
        string inp;
        cin>>inp;
        map<char,int> mci;
        for (char c:inp)
        {
            if (mci.count(c)==0) {
                mci[c] = 0;
            }
            mci[c] = mci[c] + 1;
        }
        vector<int> vi(10,0);
        while (mci['Z']>0)
        {
            vi[0]++;
            mci['Z'] -= 1;
            mci['E'] -= 1;
            mci['R'] -= 1;
            mci['O'] -= 1;
            
        }
        while (mci['W']>0)
        {
            vi[2]++;
            mci['T'] -= 1;
            mci['W'] -= 1;
            mci['O'] -= 1;
            
        }
        while (mci['U']>0)
        {
            vi[4]++;
            mci['F'] -= 1;
            mci['O'] -= 1;
            mci['U'] -= 1;
            mci['R'] -= 1;
            
        }
        while (mci['X']>0)
        {
            vi[6]++;
            mci['S'] -= 1;
            mci['I'] -= 1;
            mci['X'] -= 1;            
        }
        while (mci['F']>0)
        {
            vi[5]++;
            mci['F'] -= 1;
            mci['I'] -= 1;
            mci['V'] -= 1;
            mci['E'] -= 1;
        }
        while (mci['O']>0)
        {
            vi[1]++;
            mci['O'] -= 1;
            mci['N'] -= 1;
            mci['E'] -= 1;
        }
        while (mci['V']>0)
        {
            vi[7]++;
            mci['S'] -= 1;
            mci['E'] -= 1;
            mci['V'] -= 1;
            mci['E'] -= 1;
            mci['N'] -= 1;
        }
        while (mci['G']>0)
        {
            vi[8]++;
            mci['E'] -= 1;
            mci['I'] -= 1;
            mci['G'] -= 1;
            mci['H'] -= 1;
            mci['T'] -= 1;
        }
        while (mci['I']>0)
        {
            vi[9]++;
            mci['N'] -= 1;
            mci['I'] -= 1;
            mci['N'] -= 1;
            mci['E'] -= 1;
            
        }
        while (mci['R']>0)
        {
            vi[3]++;
            mci['T'] -= 1;
            mci['H'] -= 1;
            mci['R'] -= 1;
            mci['E'] -= 1;
            mci['E'] -= 1;
            
        }
        string out = "";
        for (int i=0; i<10; i++)
        {
            out += string(vi[i],'0'+i);
        }
        cout <<"Case #"<<t+1<<": "<< out <<endl;
    }
    return 0;
}

