#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t,r,c,w,score,i,j,d,p;

    ifstream input("A-large.in");
    ofstream output("output.in");
    input>>t;

    for(i=1;i<=t;i++)
    {
        score=0;
        input>>r>>c>>w;
        d=c/w;
        score+=(d*r);
        score+=w-1;
        p=c%w;
        if(p!=0)
            score+=1;
        output<<"Case #"<<i<<": "<<score<<endl;
    }

 return 0;

}
