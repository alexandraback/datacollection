#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

string ans[501][201][201];    
int main()
{
   ifstream fin("B-small-attempt0.in");
   ofstream fout("B-small-attempt0.out");
//    ifstream fin("B-large.in");
//    ofstream fout("B-large.out");

    int T; fin >> T; int X, Y;
    
    
    ans[1][101][100] = "E";
	ans[1][99][100] = "W";
  ans[1][100][101] = "N";
		ans[1][100][99] = "S";
		for (int d = 2; d <= 500 ; d++)
        {
            cout <<d << endl;
		    for (int i = -100 ; i <= 100 ; i++)
                for (int j = -100 ; j <= 100 ; j++)   
                    if (ans[d-1][i+100][j+100] != "")
                    {
                       if (i+100+d <= 200) ans[d][i+100+d][j+100] = ans[d-1][i+100][j+100] + "E";
                       if (i+100-d >= 0) ans[d][i+100-d][j+100] = ans[d-1][i+100][j+100] + "W";
                       if (j+100+d <= 200) ans[d][i+100][j+100+d] = ans[d-1][i+100][j+100] + "N";
                       if (j+100-d >= 0) ans[d][i+100][j+100-d] = ans[d-1][i+100][j+100] + "S";                                                                     
                    }
      cout <<d << endl;
        } 
        
    for (int t = 1 ; t <= T; t++)
    {  
		fout << "Case #" << t << ": ";
		
		fin >> X >> Y;
		for (int d = 1 ; d <= 500 ; d++)
		    if (ans[d][X+100][Y+100] != "")
		    {
              fout << ans[d][X+100][Y+100] << endl;
              break;
              }
    }
}
