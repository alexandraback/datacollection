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



long long dp[33][2][2][2];

int mx(long long a)
{
    int ans = 31;
    
    while(ans>=0 && (a & (1<<ans))==0)
        ans--;
    return ans;
}

int f(int a, int add)
{
    if(add==0)
        return a;
    else if(add==1)
        return add;
    return 0;
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
        
		long long a,b,c;
        
        fin >> a >> b >> c;
        a--;
        b--;
        c--;
        
        memset(dp,0,sizeof(dp));
        dp[0][0][0][0]=1;
        
        
        
        int i,j,k;
        
        for(i=0; i<=31; i++)
        {
            
            int diga =0 ;
            
            if( (a & (1<<i))>0)
                diga=1;
            int digb =0 ;
            
            if( (b & (1<<i))>0)
                digb=1;
            int digc =0 ;
            
            if( (c & (1<<i))>0)
                digc=1;
            
            int fa,fb,fc;
            
            fa=fb=fc= 0;
            
            for(j=0; j<4; j++)
            {
                if(j==0)
                {
                    fa = 0;
                    fb = 0;
                    fc = 0;
                }
                else if(j==1)
                {
                    fa = 1;
                    fb = 0;
                    fc = 0;
                }
                else if(j==2)
                {
                    fa = 0;
                    fb = 1;
                    fc = 0;
                }
                else
                {
                    fa = 1;
                    fb = 1;
                    fc = 1;
                }
                fa-=diga;
                fb-=digb;
                fc-=digc;
                
                for(int x=0; x<2; x++)
                {
                    for(int y=0; y<2; y++)
                    {
                        for(int z=0; z<2; z++)
                        {
//                            if(j==0 && i<=10)
//                            {
//                                cout << dp[i][x][y][z] << "  ";
//                                
//                            }
                            dp[i+1][f(x,fa)][f(y,fb)][f(z,fc)]+=dp[i][x][y][z];
                        }
                    }
                }
//                if(j==0 && i<=10)
//                    cout << endl;
            }
            
            
            
        }
        

        long long ans = dp[32][0][0][0];
        
		cout << "Case #" << ct << ": ";
		fout << "Case #" << ct << ": ";
		
        
        cout << ans;
        fout << ans;
        
        
       
		
		
		
		fout << endl;
		cout << endl;
		
	}
	
	
	return 0;
}

