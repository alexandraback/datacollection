#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <utility>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <sstream>
#include <math.h>

using namespace std;

int m[1001][1001];

int main() {
        int T;
        cin>>T;
        int count=1;
        while(T--)
        {

            int N;
            cin>>N;
            
            for(int i=1;i<=N;i++)
            	for(int j=1;j<=N;j++)
            		m[i][j]=0;
            
            for(int i=1;i<=N;i++)
            {
            	int Mi;
            	cin>>Mi;
            	for(int j=1;j<=Mi;j++)
            	{
            		int p;
            		cin>>p;
            		m[p][i]=1;
            	}
            }
            
            bool iexist=false;
            for(int k=1;k<=N;k++)
            {
            	for(int i=1;i<=N;i++)
            	{
            		for(int j=1;j<=N;j++)
            		{
                        if(k==i||k==j||i==j)
                        	continue;
                        if(m[i][k]==1&&m[k][j]==1)
                        {
                        	if(m[i][j]==1)
                        	{
                        		iexist=true;
                        		break;
                        	}
                        	m[i][j]=1;
                        }
            		}
            		if(iexist==true)
            			break;
            	}      
            	if(iexist==true)
                   break;
            }
            if(iexist==true)
                cout<<"Case #"<<count++<<": Yes"<<endl;
            else
                cout<<"Case #"<<count++<<": No"<<endl;
         }



        return 0;
}
