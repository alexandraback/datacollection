#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

ofstream fout("../../../output.txt");
ifstream fin("../../../input.txt");


bool adj[2222][2222];
bool done[2222];
int origins[2222];
int nn;

bool bpm(int x)
{
    if(done[x])
        return false;
    done[x]=true;
    for(int i=0; i<nn; i++)
    {
        if(adj[x][i])
        {
            if(origins[i]==-1)
            {
                origins[i]=x;
                return true;
            }
            else if(bpm(origins[i]))
            {
                origins[i]=x;
                return true;
                
            }
        }
    }
    return false;
}

int runBPM(int _n)
{
    nn=_n;
    int ans = 0;
    memset(origins,-1,sizeof(origins));
    for(int i=0; i<nn; i++)
    {
        memset(done,0,sizeof(done));
        if(bpm(i))
            ans++;
    }
    return ans;
}


int main(void)
{
    int ttt;
    fin >> ttt;
    int ct = 0;
    string s;
    
    cout.precision(9);
    fout.precision(9);
    
    cout << "HELLO" <<  " " << ttt << endl;
    
    
    
    while(ttt>0)
    {
        ct++;
        ttt--;
        
        int n;
        fin >> n;
        
        memset(adj,0,sizeof(adj));
        
        vector<string> lis1;
        vector<string> lis2;
        
        string a,b;
        
        int i,j,k;
        
        for(i=0; i<n; i++)
        {
            fin >> a >> b;
            for(j=0; j<lis1.size(); j++)
            {
                if(lis1[j]==a)
                    break;
            }
            for(k=0; k<lis2.size(); k++)
            {
                if(lis2[k]==b)
                    break;
            }
            if(j==lis1.size())
                lis1.push_back(a);
            if(k==lis2.size())
                lis2.push_back(b);
            adj[j][k]=true;
            
        }
        int x = runBPM(n);
        
        int ret = lis1.size()+lis2.size()-x;
        
        ret = n-ret;
        
        
        cout << "Case #" << ct << ": ";
        fout << "Case #" << ct << ": ";
        cout << ret;
        fout << ret;
        
        
        
        
        fout << endl;
        cout << endl;
        
    }
    
    
    return 0;
}

