#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<sstream>
using namespace std;

char vow[] = { 'a', 'e', 'i', 'o', 'u' };
int main()
{
    ifstream in("in.txt");
    ofstream out("out.txt");
    int T, n;
    in >> T;
    for(int t = 1; t <= T; t++)
    {
        string word;
        in >> word >> n;
        int val = 0;
        for(int i = 0; i <= word.size() - n; i++)
        {
            for(int end = i; end < word.size(); end++)
            { 
              int ma = 0;
              int cur = 0;
              for(int j = i; j <= end; j++)
              {
                  int good = 1;
                  for(int k = 0; k < 5; k++)
                  {
                    if(word[j] == vow[k]) good = 0;
                  }
                  if(good) cur++;
                  else
                  {
                    ma = max(ma,cur);
                    cur = 0;
                  } 
              }
              ma = max(ma,cur);
              if(ma >= n) val++;
            }
        }
        
       out<<"Case #"<<t<<": "<<val<<endl;   
    }
    return 0;
}
