// c.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <string>
#include <cstdlib>

using namespace std;

#define fori(i_,f_,t_) for(int i_=f_;i_<t_;++i_)
#define fore(i_,c_) for(auto i_=c_.begin();i_!=c_.end();++i_)
#define pb	push_back

struct qn
{
    int s;
    char n;
};

qn mult(qn p1, qn p2)
{
    qn r;
    r.s = p1.s;

    if (p1.n=='1')
        r.n = p2.n;
    else if (p2.n=='1')
        r.n = p1.n;
    else if (p2.n==p1.n)
    {
        r.n = '1';
        r.s= 1-r.s;
    } else if (p1.n=='i')
    {
        if (p2.n=='j')
            r.n='k';
        else
        {
            r.n='j';
            r.s= 1-r.s;
        }
    } else if (p1.n=='j')
    {
        if (p2.n=='k')
            r.n='i';
        else
        {
            r.n='k';
            r.s= 1-r.s;
        }
    } else if (p1.n=='k')
    {
        if (p2.n=='i')
            r.n='j';
        else
        {
            r.n='i';
            r.s= 1-r.s;
        }
    }

    return r;
}


int main(int argc, char* argv[])
{
	int T;
	cin>>T;
	fori(t,0,T)
	{
        int L,X;
        __int64 X64;
        cin>>L>>X64;

        if (X64<4)
            X=(int)X64;
        else
            X = (X64 % 4) + 4;
        string ls;
        cin>>ls;

        int n = L*X;
        int i=0;
        qn p;
        p.s=0;
        p.n='1';
        while(i<n)
        {
            qn p2;
            p2.s=0;
            p2.n= ls[i % L]; ++i;
            p=mult(p,p2);
            if (p.s==0 && p.n=='i')
                break;
        }
        p.s=0;
        p.n='1';
        while(i<n)
        {
            qn p2;
            p2.s=0;
            p2.n= ls[i % L]; ++i;
            p=mult(p,p2);
            if (p.s==0 && p.n=='j')
                break;
        }
        p.s=0;
        p.n='1';
        while(i<n)
        {
            qn p2;
            p2.s=0;
            p2.n= ls[i % L];  ++i;
            p=mult(p,p2);
        }

		cout<<"Case #"<<t+1<<": ";

        if (p.s==0 && p.n == 'k')
            cout<<"YES"<<std::endl;
        else 
            cout<<"NO"<<std::endl;
	}

	return 0;
}

