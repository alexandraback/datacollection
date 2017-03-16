#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

bool pr(__int64 &P, __int64 &Q)
{
    __int64 i,j,k, p=P, q=Q;

    while(q %2 == 0)
        q/=2;

    if(p%q == 0)
        p/=q;
    else
        return false;

    q=Q/q;

    while(p % 2 == 0)
    {
        p/=2;
        q/=2;
    }

    P=p;
    Q=q;

    return true;
}

void main()
{
	int T = 0;

	ifstream in("A-large.in");
	ofstream out("A-large.out");

	in >> T;

	for(int i=0; i<T; ++i)
	{
		__int64 P, Q, p, q;
        char c;

		in >> P >> c >> Q;

        if(!pr(P,Q))
        {
            out << "Case #" << i+1 << ": impossible"; 
            out << endl;
            continue;
        }

        p=P; q=Q;

        __int64 s, j, k, t;

        for(j=1,s=0; j<Q; j*=2, s++);

        if(j==Q)
        {
            j/=2;
            q=j;

            for(k=0; j!=0;k++,j/=2)
                if(P>j)
                    break;
            p=j;

            if(p!=0)
            {
                while(p % 2 == 0)
                {
                    p/=2;
                    q/=2;
                }

                for(t=1,s=1; t<q; t*=2, s++);
            }
   

            if(Q==1)
                s=1;

            out << "Case #" << i+1 << ": " << s;
        }
        else
            out << "Case #" << i+1 << ": impossible";       

		out << endl;
	}
}