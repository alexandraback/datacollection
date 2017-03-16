#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

int f(int X, int R, int C)
{
    if(X>max(R,C)) return 0;
    if((R*C)%X!=0) return 0;
    if(X==1) return 1;
    if(X==2 && (R*C)%2==0) return 1;
    if(R==1 && X>2) return 0;

    if(X==3 && R==2 && C==3) return 1;
    else if(X==4 && R==2 && C==4) return 0;
    else if(X==3 && R==3 && C==3) return 1;
    else if(X==3 && R==3 && C==4) return 1;
    else if(X==4 && R==3 && C==4) return 1;
    else if(X==4 && R==4 && C==4) return 1;
    return -1;
    cout<<X<<" "<<R<<" "<<C<<endl;
}

int main()
{
    fstream in;
    in.open("D-small-attempt0 (1).in");
    fstream out;
    out.open("output.txt");
    int T,R,C,X;
    in>>T;
    for(int i=0; i<T; i++)
    {
        in>>X; in>>R; in>>C;
        int temp1=R; int temp2=C;
        R=min(temp1,temp2);
        C=max(temp1,temp2);
        if(f(X,R,C)==0) out<<"Case #"<<i+1<<": RICHARD"<<endl;
        else out<<"Case #"<<i+1<<": GABRIEL"<<endl;
    }
}
