#include <iostream>
#include <map>
#include <string>
//#include <algorithm>
#include <stdlib.h>

using namespace std;

#define ita(i_,f_,t_) for(int i_=f_;i_<t_;++i_)
#define itd(i_,f_,t_) for(int i_=f_;i_>t_;--i_)

const char g0[] = "ejp mysljylc kd kxveddknmc re jsicpdrysi \
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd \
de kr kd eoya kw aej tysr re ujdr lkgc jv";


const char h0[] ="our language is impossible to understand \
there are twenty six factorial possibilities \
so it is okay if you want to just give up";


int main()
{
    map<char,char> mgh;

    ita(i,0,sizeof(g0))
    {
        mgh[g0[i]]=h0[i];
    }

    mgh['y']='a';
    mgh['e']='o';
    mgh['q']='z';
    mgh['z']='q';

    int T;
    cin>>T;
    string g;
    getline(cin,g); // remove LF
    for(int t=0; t<T; ++t)
    {
        getline(cin,g);
        ita(k,0,g.length())
        {
            g[k]=mgh[g[k]];
        }

        cout<<"Case #"<<(t+1)<<": "<<g<<endl;
    }
    return 0;
}
