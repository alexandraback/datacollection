#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <list>

using namespace std;

int main()
{
   ifstream fin("C-small-attempt4.in");
   ofstream fout("C-small-attempt4.out");
//    ifstream fin("B-large.in");
//    ofstream fout("B-large.out");

    int T; fin >> T;
    int N;
    int d[1001];
    int a[1001];
    int w[1001], e[1001];
    int s[1001];
    int deltaD[1001];
    int deltaP[1001];
    int deltaS[1001];
    int wall[501];
    int wallmid[501];
        
    for (int t = 1 ; t <= T; t++)
    {  
		fout << "Case #" << t << ": ";
		
		fin >> N;
		for (int i = 0 ; i < N ; i++)
		    fin >> d[i] >> a[i] >> w[i] >> e[i] >> s[i] >> deltaD[i] >> deltaP[i] >> deltaS[i];
        
        for (int i = 0 ; i <= 500 ; i++) {wall[i] = 0; wallmid[i] = 0;}
        int ans = 0;
        while (true)
        {
            int minD = 676061;
            for (int i = 0; i < N ; i++)
                if (a[i] > 0 && d[i] <= minD) minD = d[i];
            if (minD == 676061) break;
            
            
            for (int i = 0; i < N ; i++)
                if (a[i] > 0 && d[i] == minD) 
                {
                         bool attack = false;
                         for (int j = w[i]+250; j <= e[i]+250 ; j++)
                             if (wall[j] < s[i]) {attack = true; }
                         for (int j = w[i]+250; j < e[i]+250 ; j++)
                             if (wallmid[j] < s[i]) {attack = true; }    
                         if (attack) ans++;
                }
                
            for (int i = 0; i < N ; i++)
                if (a[i] > 0 && d[i] == minD) 
                {
                         //fout << i << " " << d[i] << " " << w[i] << " " << e[i] << " " << s[i] << " " << endl;
                         bool attack = false;
                         for (int j = w[i]+250; j <= e[i]+250 ; j++)
                             if (wall[j] < s[i]) {wall[j] = s[i]; }
                         for (int j = w[i]+250; j < e[i]+250 ; j++)
                             if (wallmid[j] < s[i]) {wallmid[j] = s[i]; }
                         if (attack) ans++;
                         //fout << attack << endl;
                         d[i] += deltaD[i]; 
                         a[i]--;
                         w[i] += deltaP[i];
                         e[i] += deltaP[i];
                         s[i] += deltaS[i];
                }                
        
        }		    
        fout << ans << endl;
    }
}
