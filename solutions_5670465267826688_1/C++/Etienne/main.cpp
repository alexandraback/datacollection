#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <Eigen/Core>

using namespace std;
using namespace Eigen;

void doTest()
{
    long long l, x;
    cin >> l >> x;
    string s;
    cin >> s;

    Matrix4i mi, mj, mk, m1;
    mi << 0, 1, 0, 0,
            -1, 0, 0, 0,
            0, 0, 0, 1,
            0, 0, -1, 0;

    mj << 0, 0, 0, -1,
            0, 0, -1, 0,
            0, 1, 0, 0,
            1, 0, 0, 0;

    mk << 0, 0, -1, 0,
            0, 0, 0, 1,
            1, 0, 0, 0,
            0, -1, 0, 0;

    m1 << 1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1;

    Matrix4i oneperiod = m1;
    for(int i=0; i<s.length(); i++)
    {
        switch(s[i])
        {
        case 'i':
            oneperiod = oneperiod * mi;
            break;
        case 'j':
            oneperiod = oneperiod * mj;
            break;
        case 'k':
            oneperiod = oneperiod * mk;
            break;
        }
    }
    Matrix4i total = m1;
    for(int i=0; i<x%4; i++)
        total *= oneperiod;
    if(total == -m1)
    {
        Matrix4i prefix = m1;
        int prefixdigits = 0;
        bool done = false;
        for(int i=0; i<4 && !done; i++)
            for(int j=0; j<s.length() && !done; j++)
            {
                switch(s[j])
                {
                case 'i':
                    prefix = prefix * mi;
                    break;
                case 'j':
                    prefix = prefix * mj;
                    break;
                case 'k':
                    prefix = prefix * mk;
                    break;
                }
                prefixdigits++;
                if(prefix == mi)
                    done = true;
            }
        if(!done)
        {
            cout << "NO" << endl;
            return;
        }
        Matrix4i postfix = m1;
        int postfixdigits = 0;
        done = false;
        for(int i=0; i<4 && !done; i++)
            for(int j=1; j<=s.length() && !done; j++)
            {
                switch(s[s.length()-j])
                {
                case 'i':
                    postfix = mi * postfix;
                    break;
                case 'j':
                    postfix = mj * postfix;
                    break;
                case 'k':
                    postfix = mk * postfix;
                    break;
                }
                postfixdigits++;
                if(postfix == mk)
                    done = true;
            }

        if(done && prefixdigits + postfixdigits < x*s.length())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        return;
    }
    else
    {
        cout << "NO" << endl;
    }
}


int main()
{
    int ncases;
    cin >> ncases;
    for(int i=0; i<ncases; i++)
    {
        std::cout << "Case #" << i+1 << ": ";
        doTest();
    }
}
