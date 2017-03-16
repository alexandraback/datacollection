#include <cstdio>
#include <iostream>
#include <cstdio>
#include <fstream>

using namespace std;

ifstream in("pbC.txt");
ofstream out("pbC_a.txt");
int wall[20000];
int main()
{
    int po=0;
    in>>po;
    for(int co=0;co<po;co++)
    {
        for(int hh=0;hh<20000;hh++) wall[hh]=0;
        out<<"Case #"<<co+1<<": ";
        int num=0;
        in>>num;
        int tribe[num][8];
        int ans=0;
        int totalatt=0;
        for(int h=0;h<num;h++)
        {
            for(int u=0;u<8;u++)
            {
                in>>tribe[h][u];
            }
            totalatt+=tribe[h][1];
            
        }
        for(int day=0;day<676100 && totalatt>0;day++)
        {
            int wallnum[10000];
            int wallheight[10000];
            int tt=0;
            for(int d=0;d<num && totalatt>0;d++)
            {
                if(day==tribe[d][0] && tribe[d][1]>0)
                {
                    int total=0;
                    for(int v=((tribe[d][2]*2)+10000);v<=(tribe[d][3]*2)+10000;v++)
                    {
                        if(tribe[d][4]>wall[v])
                        {
                            total++;
                            wallnum[tt+total-1]=v;
                            wallheight[tt+total-1]=tribe[d][4];
                            //wall[v]=tribe[d][4];
                        }
                    }
                    if(total>0) ans++;
                    tribe[d][0]+=tribe[d][5];
                    tribe[d][4]+=tribe[d][7];
                    tribe[d][1]--;
                    totalatt--;
                    tt+=total;
                    tribe[d][2]+=tribe[d][6];
                    tribe[d][3]+=tribe[d][6];
                }
                
            }
            for(int ww=0;ww<tt;ww++)
            {
                if(wall[wallnum[ww]]<wallheight[ww]) wall[wallnum[ww]]=wallheight[ww];
            }
        }
        out<<ans<<endl;
    }
    return 0;
}
                    
        
    
