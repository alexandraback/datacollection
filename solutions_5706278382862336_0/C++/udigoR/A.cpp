#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void main()
{
	int T = 0;

	ifstream in("A-small-attempt2.in");
	ofstream out("A-small-attempt2.out");

	in >> T;

	for(int i=0; i<T; ++i)
	{
		__int64 P, Q, p, q;
        char c;

		in >> P >> c >> Q;
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