#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
int dx,dy;
int way[1000];
int counti=0;
    ifstream in("pbB.txt");
    ofstream out("pbB_a.txt");
bool dfs(int step,int x,int y)
{
    //out<<step<<" ";
    if(step>27) return false;
    if(abs(x-dx)>(step+28)*(28-step)/2 || abs(y-dy)>(step+28)*(28-step)/2) return false;
    if(x==dx && y==dy)
    {
        counti=step-1;
        return true;
    }
    way[step-1]=1;
    if(dfs(step+1,x,y+step))
    {
        return true;
    }
    way[step-1]=2;
    if(dfs(step+1,x+step,y))
    {
        return true;
    }
    way[step-1]=3;
    if(dfs(step+1,x,y-step))
    {
        return true;
    }
    way[step-1]=4;
    if(dfs(step+1,x-step,y))
    {
        return true;
    }
    return false;
}
        
int main()
{

    int po=0;
    in>>po;
    for(int co=0;co<po;co++)
    {
        
        out<<"Case #"<<co+1<<": ";
        in>>dx>>dy;
        
        counti=0;
        
        if(dfs(1,0,0))
        {
            
            for(int h=0;h<counti;h++)
            {
                
                if(way[h]==1) out<<"N";
                else if(way[h]==2) out<<"E";
                else if(way[h]==3) out<<"S";
                else if(way[h]==4) out<<"W";
            }
            
        }
        out<<endl;
    }
    return 0;
}
