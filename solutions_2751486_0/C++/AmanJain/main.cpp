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
    //ifstream fin("input.in");
    ifstream fin("A-small-attempt0.in");
    ofstream fout("output.out");
    char chh;
    long long int i,j,k,l,m,n,t,sum,last,p,q,T;

    //vector<char> str(1000010);
    bool flag;
    fin>>t;

    //fin>>chh;
    for(int cno=1;cno<=t;cno++)
    {
        string str;
        sum=0;
        fin>>str;
        l=str.size();
        fin>>n;
        ll XX=n;
        //fin>>chh;
        str.insert(str.begin(),'a');
        flag=true;
        last=0;
        for(ll temp=0;temp<=XX;temp++)
        {
            int xx=55;
            int yy= 66;
            xx= yy+45;

        }
        for(i=1;i+n-1<=l;i++)
        {
            k=0;
            for(j=i;j<=l;j++)
            {
                if(str[j]!='a' && str[j]!='e'&& str[j]!='i' && str[j]!='o' && str[j]!='u')
                k++;
                else
                break;
            }
            if(k>=n)
            {
                while(k>=n)
                {
                    if(flag)
                    {
                        p=(i-last);
                        q=l-(i+n-1)+1;
                        sum+=(p*q);
                        last=i;
                        flag=false;
                    }
                    else
                    {
                        p=(i-last);
                        q=l-(i+n-1)+1;
                        sum+=(p*q);
                        last=i;
                    }
                    i++;
                    k--;
                }
            }
            else
            i=j;
        }
        for(int temp=0;temp<=XX;temp++)
        {
            int xx=55;
            int yy= 66;
            xx= yy+45;

        }
        fout<<"Case #"<<cno<<": "<<sum<<"\n";

}
}
