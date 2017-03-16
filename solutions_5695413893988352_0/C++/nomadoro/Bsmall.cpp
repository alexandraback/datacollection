#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#define L 3
#define AL 1000

#define ABS(x) ((x)>=0?(x):(-(x)))

std::string rev(int a, int l)
{
    char s[L];
    for(int i=0; i<l; i++)
    {
        s[l-1-i] = a%10 + '0';
        a = a/10;
    }
    return std::string(s, l);
}

void genV(std::vector<int> & v, const std::string & s)
{
    std::vector<int> vp;
    for(int n=0; n<s.size(); n++)
    {
        vp.assign(v.begin(), v.end());
        v.clear();
        if(s[n] == '?')
        {
            if(vp.size())
            {
                for(int ip=0; ip<vp.size(); ip++)
                    for(int i=0; i<10; i++)
                        v.push_back(vp[ip]*10 + i);
            }
            else
            {
                for(int i=0; i<10; i++)
                    v.push_back(i);
            }
        }
        else
        {
            if(vp.size())
            {
                for(int ip=0; ip<vp.size(); ip++)
                    v.push_back(vp[ip]*10 + (s[n]-'0'));
            }
            else
            {
                v.push_back(s[n]-'0');
            }
        }
    }
}

int main()
{
    int T;
    std::cin >> T;
    for(int t=1; t<=T; t++)
    {
        std::string C, J;
        std::cin >> C >> J;
        std::vector<int> vc, vj;
        genV(vc, C);
        genV(vj, J);
        int m = AL;
        std::vector<int> voc, voj;
        for(int ic=0; ic<vc.size(); ic++)
        {
            for(int ij=0; ij<vj.size(); ij++)
            {
                int a = ABS(vc[ic] - vj[ij]);
                if(a < m)
                {
                    voc.clear(); voj.clear();
                    m = a;
                }
                if(a == m)
                {
                    voc.push_back(vc[ic]);
                    voj.push_back(vj[ij]);
                }
            }
        }
        m = AL;
        std::vector<int> cvoc, cvoj;
        for(int i=0; i<voc.size(); i++)
        {
            if(voc[i] < m)
            {
                m = voc[i];
                cvoc.clear(); cvoj.clear();
            }
            if(voc[i] == m)
            {
                cvoc.push_back(voc[i]);
                cvoj.push_back(voj[i]);
            }
        }

        m = AL;
        std::vector<int> jvoc, jvoj;
        for(int i=0; i<voc.size(); i++)
        {
            if(voj[i] < m)
            {
                m = voj[i];
                jvoc.clear(); jvoj.clear();
            }
            if(voj[i] == m)
            {
                jvoc.push_back(cvoc[i]);
                jvoj.push_back(cvoj[i]);
            }
        }

        std::cout << "Case #" << t << ": " << rev(jvoc[0], C.size()) << " " << rev(jvoj[0], J.size()) << std::endl;
    }
    return 0;
}
