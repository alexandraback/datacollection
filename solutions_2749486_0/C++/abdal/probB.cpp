//
//  prob1.cpp
//  
//
//  Created by Abdallah on 5/12/13.
//
//

#include <fstream>
#include <iostream>

using namespace std;

main()
{
    ifstream fin;
    ofstream fout;
    
    fin.open("data.in.txt");
    fout.open("data.out");
    
    int N,X,Y,i,j,curX=0,curY=0,step=1;
    fin >> N;
    for(i=0;i<N;i++)    //iteration for each case
    {
        fin>>X>>Y;
        fout<<"Case #"<<i+1<<": ";
        curX=0;curY=0;step=1;
        
        if(X>curX)
        {
            while(X>curX)
            {
                fout<<"E";
                curX=curX+step;
                step++;
            }
            for(j=0;j<curX-X;j++)
            {
                fout<<"EW";
                step+=2;
            }
        }
        else
        {
            while(X<curX)
            {
                fout<<"W";
                curX=curX-step;
                step++;
            }
            for(j=0;j<X-curX;j++)
            {
                fout<<"WE";
                step+=2;
            }
            
        }
        
        if(Y>curY)
        {
            for(j=0;j<Y;j++)
                fout<<"SN";
        }
        else
        {
            for(j=0;j<curY-Y;j++)
                fout<<"NS";
            
        }
        fout<<endl;
    }
    fin.close();
    fout.close();
}