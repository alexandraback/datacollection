#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <iomanip>
#include <utility>
#include <math.h>
#include <bitset>

using namespace std;    

int main()
{
    ifstream fin("in.txt");
    ofstream fout("out.txt");
    int t;
    fin >> t;
    int c,d,v,s,size;
    vector<int> n;
    bool is;
    for (int i=1; i<=t; i++){
        fin >> c >> d >> v; 
        s=0;
        n.assign(d,0);
        for (int j=0; j<d; j++)
            fin >> n[j];
            
        if (d>1 && n[0]+n[1]<=v)
           n.push_back(n[0]+n[1]);
        if (d>2 && n[0]+n[2]<=v)
           n.push_back(n[0]+n[2]);
        if (d>3 && n[0]+n[3]<=v)
           n.push_back(n[0]+n[3]);
        if (d>4 && n[0]+n[4]<=v)
           n.push_back(n[0]+n[4]);
        if (d>2 && n[1]+n[2]<=v)
           n.push_back(n[1]+n[2]);
        if (d>3 && n[1]+n[3]<=v)
           n.push_back(n[1]+n[3]);
        if (d>4 && n[1]+n[4]<=v)
           n.push_back(n[1]+n[4]);
        if (d>3 && n[2]+n[3]<=v)
           n.push_back(n[2]+n[3]);
        if (d>4 && n[2]+n[4]<=v)
           n.push_back(n[2]+n[4]);
        if (d>4 && n[3]+n[4]<=v)
           n.push_back(n[3]+n[4]);
           
        if (d>2 && n[0]+n[1]+n[2]<=v)
           n.push_back(n[0]+n[1]+n[2]);
        if (d>3 && n[0]+n[1]+n[3]<=v)
           n.push_back(n[0]+n[1]+n[3]);
        if (d>4 && n[0]+n[1]+n[4]<=v)
           n.push_back(n[0]+n[1]+n[4]);
        if (d>3 && n[0]+n[2]+n[3]<=v)
           n.push_back(n[0]+n[2]+n[3]);
        if (d>4 && n[0]+n[2]+n[4]<=v)
           n.push_back(n[0]+n[2]+n[4]);
        if (d>4 && n[0]+n[3]+n[4]<=v)
           n.push_back(n[0]+n[3]+n[4]);
           
        if (d>3 && n[0]+n[1]+n[2]+n[3]<=v)
           n.push_back(n[0]+n[1]+n[2]+n[3]);
        if (d>4 && n[0]+n[1]+n[2]+n[4]<=v)
           n.push_back(n[0]+n[1]+n[2]+n[4]);
        if (d>4 && n[0]+n[2]+n[3]+n[4]<=v)
           n.push_back(n[0]+n[2]+n[3]+n[4]);
        if (d>4 && n[1]+n[2]+n[3]+n[4]<=v)
           n.push_back(n[1]+n[2]+n[3]+n[4]);
           
        if (d>4 && n[0]+n[1]+n[2]+n[3]+n[4]<=v)
           n.push_back(n[0]+n[1]+n[2]+n[3]+n[4]);
        
        for (int k=1; k<=v; k++){
            is=0;
            for (int j=0; j<n.size(); j++) 
                if (n[j]==k)
                   is=1;
            if (!is){
               s++;
               size=n.size();
               n.push_back(k); 
               for (int j=0; j<size; j++) 
                   if (n[j]+k<=v)
                      n.push_back(n[j]+k);      
            }   
        }
        n.clear();
        fout << "Case #" << i << ": " << s << endl;    
    }
    fin.close();
    fout.close();
    return 0;
}
