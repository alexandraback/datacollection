#include <iostream>
#include <fstream>
#include <cassert>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;



int main()
{
    fstream in,out;
    in.open("large.in",fstream::in);
    out.open("large.out",fstream::out|fstream::app);
    int num;
    in >> num;
    for(int i = 0;i != num; ++i)
    {
        int r = 0, x=0,c=0,rlt=0;
        in >> x >>r>>c;
        if(r>c) swap(r,c);
        if(x==1) rlt=0;
        else if(x==2)
        {
            if((r*c)%2!=0) rlt=1;
            if(c<x) rlt=1;
        }

        else if(x==3)
        {
            if(r<2) rlt=1;
            if((r*c)%x!=0) rlt=1;
            if(c<x) rlt=1;
        }
        else if(x==4||x==5)
        {
            if((r*c)%x!=0) rlt=1;
            if(r<=2) rlt=1;
            if(c<x) rlt=1;
        }
        else if(x>6)
        {
             rlt=1;
        }
        else{
            if((r*c)%x!=0) rlt=1;
            if(r<=4) rlt=1;
            if(c<x) rlt=1;
        }

        out << "Case #" << i+1 << ": ";
        if(rlt) out<< "RICHARD" <<endl;
        else out<<"GABRIEL"<<endl;

    }
    return 0;
}
