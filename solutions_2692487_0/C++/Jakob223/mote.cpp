#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <deque>
#include <algorithm>
//#include <cassert>
using namespace std;
long A,N,x,T;
deque<long> motes;
int main() {
    std::ifstream fin ("A-small.in");
    std::ofstream fout("mote.out");
    fin>>T;
    for(long i=0;i<T;i++)
    {
        fout<<"Case #"<<(i+1)<<": ";
        fin>>A>>N;
        for(int n=0;n<N;n++){
            fin>>x;
            motes.push_back(x);
        }
        sort(motes.begin(),motes.end());
        unsigned int motesAdded=0;
        unsigned int minDone=1000000,min1;
        if(A==1){
            motes.clear();
            motesAdded=N;
        }
        while(!motes.empty())
        {
            if(A<=motes[0])
            {
                if(motesAdded+motes.size()<minDone)
                {
                    minDone=motesAdded+motes.size();
                    min1=motesAdded;
                }
                while(A<=motes[0]){A+=A-1;motesAdded++;}
            }
            A+=motes[0];
            motes.pop_front();
        }
        if(motesAdded<minDone)
        {
            minDone=motesAdded;
            min1=minDone+1000;
        }
        fout<<minDone<<"\n";//t"<<min1<<"\n";
    }
    
    return 0;
}
