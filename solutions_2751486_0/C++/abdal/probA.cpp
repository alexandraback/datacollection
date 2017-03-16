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

bool cons(char c)
{
    if(c=='a')
        return false;
    if(c=='e')
        return false;
    if(c=='i')
        return false;
    if(c=='o')
        return false;
    if(c=='u')
        return false;
    return true;
}

main()
{
    ifstream fin;
    ofstream fout;
    
    fin.open("data.in.txt");
    fout.open("data.out");
    
    int N, i,start,end, n;
    string esm;
    
    fin >> N;

    for(i=0;i<N;i++)    //iteration for each case
    {
        fin>>esm;
        fin>>n;
        
        int subcount=0,count,x;
        
        for(end=esm.length()-1;end>=n-1;end--)
            for(start=0;start<=end-n+1;start++)
            {
                count=0;
                for(x=start;x<=end;x++)
                {
                    if(cons(esm[x]))
                    {
                        count++;
                        if(count==n)
                        {
                            subcount++;
                            break;
                        }
                    }
                    else count=0;
                }
            }
        
        fout<<"Case #"<<i+1<<": "<<subcount<<endl;
        
    }
    fin.close();
    fout.close();
}