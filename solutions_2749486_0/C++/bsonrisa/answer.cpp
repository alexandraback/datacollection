#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

string doit(int expectedX, int expectedY) {
       map<pair<int, int>, string> themap;
       themap[make_pair(1,0)] = "E";
       themap[make_pair(-1,0)] = "W";
       themap[make_pair(0,1)] = "N";
       themap[make_pair(0,-1)] = "S";
       
       int count=2;
       while (count <= 500) {
          cout << count << endl;             
                        map<pair<int, int>, string> newmap;
                            
          for (map<pair<int, int>, string>::iterator it=themap.begin(); it!=themap.end(); ++it) {
              
              int x = it->first.first;
              int y = it->first.second;
              string str = it->second;
              
              if (x == expectedX && y == expectedY) return str;
              newmap[make_pair(x+count,y)] = str+"E";
              newmap[make_pair(x-count,y)] = str+"W";
              newmap[make_pair(x,y+count)] = str+"N";
              newmap[make_pair(x,y-count)] = str+"S";
          }
          count++;
          themap = newmap;           
       }
       return "INVALID";
       
} 


int main() {
 
    ifstream infile("C:/a.in");
    ofstream outfile("C:/a.out");
    int numCases = 0;
    infile >> numCases;
    for (int i = 0; i < numCases; i++) {
        int x, y;
        infile >> x >> y;
        string result = doit(x,y);
        //system("PAUSE");
        outfile << "Case #" << (i+1) << ": " << result << endl;
    }    
    outfile.close();
    return 0;   
    
}
