#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<fstream>

typedef long long ll;
using namespace std;
int main()
{
    ifstream fin("B-small-attempt1.in");
    ofstream fout("output.out");
    int t,x,y,i;
    fin>>t;
    for(int cno=1;cno<=t;cno++)
    {
        fin>>x>>y;
        fout<<"Case #"<<cno<<": ";
        if(x>0&&y>0)
        {
            for(i=1;i<=x;i++)
            {
                fout<<"WE";
            }
            for(i=1;i<=y;i++)
            {
                fout<<"SN";
            }


        }
        else if(x==0 && y>0)
        {
            for(i=1;i<=y;i++)
            {
                fout<<"SN";
            }

        }

        else if(x<0&&y>0)
        {
            for(i=1;i<=(-x);i++)
            {
                fout<<"EW";
            }
            for(i=1;i<=y;i++)
            {
                fout<<"SN";
            }

        }
        else if(x<0 &&y==0)
        {
            for(i=1;i<=(-x);i++)
            {
                fout<<"EW";
            }

        }
        else if(x<0&&y<0)
        {
            for(i=1;i<=(-x);i++)
            {
                fout<<"EW";
            }
            for(i=1;i<=(-y);i++)
            {
                fout<<"NS";
            }

        }
        else if(x==0&&y<0)
        {

            for(i=1;i<=(-y);i++)
            {
                fout<<"NS";
            }

        }

        else if(x>0&&y<0)
        {
            for(i=1;i<=x;i++)
            {
                fout<<"WE";
            }
            for(i=1;i<=(-y);i++)
            {
                fout<<"NS";
            }


        }
        else if(y==0 && x>0)
        {
            for(i=1;i<=x;i++)
            {
                fout<<"WE";
            }

        }
        fout<<"\n";






    }
    return 0;
}
