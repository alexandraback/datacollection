/*

*/

#include <fstream>
#include <string>
#include <iostream>
#include <queue>
#include <list>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <deque>


using namespace std;


int main ()
{
    int t,n,answer;
    
    freopen("C-small.in","r",stdin);   
    freopen("CSoutput.txt","w",stdout);
    
    scanf ("%d\n", &t);
    
    int d[1000];
        int num[1000];
        int w[1000];
        int e[1000];
        int s[1000];
        int dd[1000];
        int dp[1000];
        int ds[1000];
        int wall [100000][3];
    
    
    
    for (int trial=1;trial<=t;++trial)
    {
        answer = 0;
        
        
         int numWalls = 0;
        
        priority_queue<int, vector<int>, greater<int> > all;
        
        scanf ("%d\n", &n);
        priority_queue<int, vector<int>, greater<int> > tribe[n];
        
        
        
        for (int i=0;i<n;++i)
        {
                scanf ("%d %d %d %d %d %d %d %d", &d[i], &num[i], &w[i], &e[i], &s[i], &dd[i], &dp[i], &ds[i]);
                w[i] += 50000;
                e[i] += 50000;
        }
        
        //For each tribe calculate all attack days
        for (int i=0;i<n;++i)
        {
            int temp = d[i];
            for (int j=0;j<num[i];++j)
            {
                tribe[i].push(temp);
                all.push(temp);
                temp += dd[i];
            }    
        }
        
        int prev = -1;
        while (!all.empty())
        {
              int cur = all.top();all.pop();
              if (prev != cur)
              {
                 prev = cur;
                 //Get which tribes attack on day cur
                 for (int i=0;i<n;++i)
                 {
                     if (tribe[i].top() == cur)
                     {
                            //   cout<<"Tribe "<<i<<" attacking "<<w[i]<<" to "<<e[i]<<" on day "<<cur<<" with strength "<<s[i]<<"\n";
                                        
                               //Successful breach?
                              
                               int fragment[100][2];
                               int numfrags = 1;
                               int numDeleted = 0;
                               fragment[0][0] = w[i]; fragment[0][1] = e[i];
                               
                               for (int j=0;j<numWalls;++j)
                               {
                                //   cout<<"Trying wall "<<wall[j][0]<<" "<<wall[j][1]<<" "<<wall[j][2]<<"\n";
                                   if (wall[j][2] >= s[i])
                                   {
                                      for (int k=0;k<numfrags;++k)
                                      {
                                          if (fragment[k][0] != fragment[k][1])
                                          {
                                                            // cout<<"here\n";
                                             if (wall[j][0] <= fragment[k][0])
                                             {
                                                        //    cout<<" and here\n";
                                                if (wall[j][1] >= fragment[k][1])
                                                {
                                                             //  cout<<"deleted\n";
                                                       fragment[k][1] = fragment[k][0];
                                                       numDeleted++;
                                                } 
                                                else if (wall[j][1] > fragment[k][0])
                                                {
                                                    fragment[k][0] = wall[j][1];    
                                                }
                                             }                   
                                            
                                              else if (wall[j][0] < fragment[k][1])
                                              {
                                                   if (wall[j][1] >= fragment[k][1])
                                                      fragment[k][1] = wall[j][0];
                                                   else
                                                   {
                                                       fragment[numfrags][0] = wall[j][1];
                                                       fragment[numfrags][1] = fragment[k][1];
                                                       numfrags++;
                                                       fragment[k][1] = wall[j][0];
                                                   }   
                                              } 
                                          }
                                      }              
                                   }                                   
                               }    
                               
                               if (numDeleted != numfrags)
                               {
                                          answer++; 
                                //  cout<<"Increased ans to "<<answer<<"\n";
                                 
                               }
                                     
                     }    
                 }  
                 
                 //Raise the walls and update the tribes' stats
                 for (int i=0;i<n;++i)
                 {
                     if (tribe[i].top() == cur)
                     {
                        wall[numWalls][0] = w[i];             
                        wall[numWalls][1] = e[i];
                        wall[numWalls][2] = s[i];
                        numWalls++;
                        tribe[i].pop();
                        w[i] += dp[i]; e[i] += dp[i];
                        s[i] += ds[i];
                     }    
                 }       
              }  
        }
        
        cout<<"Case #"<<trial<<": "<<answer<<"\n";
    }
    return 0;
}
