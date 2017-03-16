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
    
    freopen("B-small.txt","r",stdin);   
    freopen("Boutput.txt","w",stdout);
    
    int T, A,B,K, counter;

    cin>>T;
    for (int trial=1;trial<=T;++trial)
    {
        counter = 0;
        cin>>A>>B>>K;
        for (int a=0; a< A; ++a)
        {
         for (int b=0; b<B; ++b)
         {
             if ((a&b)<K)
                counter++;    
         }    
        }
        
        cout<<"Case #"<<trial<<": "<<counter<<"\n";
    }
    
    return 0;
}
