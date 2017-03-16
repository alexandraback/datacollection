#include <iostream>
#include <string>
//#include <algorithm>
#include <map>
#include <stdlib.h>
#include <math.h>

using namespace std;

#define ita(i_,f_,t_) for(int i_=f_;i_<t_;++i_)
#define itd(i_,f_,t_) for(int i_=f_;i_>t_;--i_)

int gcd(int a, int b)
{
    while( 1 )
    {
        a = a % b;
		if( a == 0 )
			return b;
		b = b % a;

        if( b == 0 )
			return a;
    }
}



int main()
{
    int T;
    cin>>T;
    for(int t=0; t<T; ++t)
    {
        int H,W,D;

        cin>>H>>W>>D;

        size_t p = string::npos;
        int x=-1;
        int y=-1;
        ita(h,0,H)
        {
            string s;
            cin>>s;
            if (y<0)
            {
                 p = s.find('X');
                 if (p != string::npos)
                 {
                    y=(int)h * 2 - 1;
                    x=(int)p * 2 - 1; 
                 }
            }
        }

        int m = 0;

        H-=2;
        W-=2;

        int hr = D / H + 1;
        int wr = D / W + 1;

        double md = (double)D + 0.00000001;

        map<unsigned,int> mc;

        for(int i = -hr; i< (hr+1); ++i)
        {
           int dy = ((i % 2)==0)? H * abs(i) : (abs(i) - 1) * H + ((i<0)?y:(2*H-y));
           for(int j = -wr; j< (wr+1); ++j)
           {
                
                if (i==0 && j==0)
                    continue;

                int dx = ((j % 2)==0)? W * abs(j) : (abs(j) - 1) * W +((j<0)?x:(2*W-x));
                
                double d = sqrt((double)dx*dx + dy*dy);
                if (d<md)
                {
                    int z;
                    if (dy==0 || dx==0)
                        z = dy>dx?dy:dx;
                    else
                        z = gcd(dy,dx);

                    unsigned w = ((unsigned)(dy / z) << 16) | ((unsigned)(dx / z) << 2);
                    if (i<0)
                        w |= j<0?0:1;
                    else
                        w |= j<0?2:3;
                    if (mc[w]!=1)
                    {
                         ++m;
                         mc[w]=1;
                    }
                }
           }
        }

        cout<<"Case #"<<(t+1)<<": "<<m<<endl;
    }
    return 0;
}
