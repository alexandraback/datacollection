#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;

int repeatsAt(string s)
{
    int i;
    int rlen=s.size()/2;
    int ret=0;
    for(i=0; i<rlen; i++)
    {
        string lasti = s.substr((s.size()+1)/2 + i, rlen-i);
        string firsti = s.substr(0, rlen-i);

        if(lasti == firsti)
            ret = rlen-i;
    }

    return ret;
}

int main()
{
    LL N,i,j,it; cin>>N;
    int k,l,s;

    char keyMap[26];

    for(it=0; it<N; it++)
    {
        cout << "Case #" << it+1 << ": ";
        cin>>k>>l>>s;
        string keyboard; cin>>keyboard;
        string target; cin>>target;

        //cout << endl;
        //cout << target << " repeats at " << repeatsAt(target) << endl;

        memset(keyMap, 0, 26);
        for(i=0; i<k; i++)
        {
            char c = keyboard[i];
            keyMap[c-'A']++;
        }

        double ans=0.0;
        
        double cumProb=1.0;
        bool bCantSpell=false;
        for(i=0; i<l; i++)
        {

            char c = target[i];
            int cCount = keyMap[c-'A'];
            if(cCount==0)
                bCantSpell=true;
            cumProb *= ((double)cCount/(double)k);
        }
        //cout << "Probability of spelling " << target << " once: " << cumProb << endl;

        // Calculate maximum number of times the word can appear in s spaces.
        int ra = repeatsAt(target);
        if(ra==0)
            ra = l;
        int maxNum = s/ra;
        if(bCantSpell || cumProb == 1.0)
            maxNum=0;

        double origP = cumProb;
        cumProb=0.0;
        /**/
        for(i=0; i<maxNum; i++)
        {
            //double dI = (double)(s/(ra*(i+1)));
            double dI = (double)i+1.0;
            //cout << dI << "," << origP << endl;
            cumProb += dI*origP;
            origP *= origP;
        }
        /**/
        //cumProb = (double)maxNum*origP;

        cout << (double)maxNum-cumProb << endl;
    }
    return 0;
}

