#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include <utility>
#include<algorithm>
using namespace std;
typedef vector<int> IntContainer;
typedef IntContainer::iterator IntIterator;


bool rek(multimap<int,int> clas, vector<int> &list, int index)
{
    IntIterator i = find(list.begin(), list.end(), index);
        if (i != list.end()) {

                return true;
        }
    pair<multimap<int, int>::iterator, multimap<int, int>::iterator> ppp;
    ppp = clas.equal_range(index);
    list.push_back(index);
    bool yes = false;
    for (multimap<int, int>::iterator it2 = ppp.first;it2 != ppp.second;++it2)
    {
        yes = rek(clas,list,(*it2).second);
        if (yes)
            return true;
    }
    return false;
}
int main()
{
    ifstream in("in1.txt");
    ofstream out("out1.txt");
    int T;
    in>>T;
    for ( int u = 0; u < T;u++)
    {
        int N;
        in>>N;
        multimap <int,int> clas;
        for ( int i = 0; i< N; i++)
        {
            int M;
            in>>M;
            for ( int j = 0; j< M; j++)
            {
                int uu;
                in>>uu;
                clas.insert(pair<int,int>(i+1,uu));
            }
        }

        bool bagus = false;
        vector<int> done;
        for (multimap<int, int>::iterator it = clas.begin();it != clas.end();++it)
        {
            vector<int> list;
            vector<int>::iterator i = find(done.begin(), done.end(), (*it).first);
            if (i != done.end()) {
                continue;
            }
            bagus = rek(clas,list,(*it).first);
            done.push_back((*it).first);
            if (bagus)
                break;
        }
        out<<"Case #"<<u+1<<": ";
        if (bagus)
            out<<"Yes"<<endl;
        else
            out<<"No"<<endl;
    }
    out.close();
    return 0;

}
