#include <iostream>
#include <fstream>
#include <vector>
#include <set>
using namespace std;

vector<set<int> > ancestors(11);
vector<vector<int> > parents;

void loadan(int id, set<int>& s)
{
    s.insert(id);
    for(int j=0; j<parents[id].size(); j++)
    {
        loadan(parents[id][j], s);
    }
}

void megold(istream& in, ostream &out)
{
    int n;
    in>>n;
    parents.clear();
    parents.resize(n);
    for(int i=0; i<n; i++)
    {
        int m;
        in>>m;
        for(int j=0; j<m; j++)
        {
            int x;
            in>>x;
            parents[i].push_back(x-1);
        }
    }

    /*for(int i=0; i<parents.size(); i++)
    {
        for(int j=0; j<parents[i].size(); j++)
        {
             cout<<parents[i][j]<<' ';
        }cout<<endl;
    }*/

    for(int i=0;i<n;i++)
    {
        vector<int> nodes(n);
        for(int j=0; j<parents[i].size(); j++)
        {
            ancestors[j].clear();
            loadan(parents[i][j], ancestors[j]);
            for(set<int>::iterator it=ancestors[j].begin(); it!=ancestors[j].end(); it++)
            {
                //out<<(*it)<<' ';
                nodes[*it]++;
                if(nodes[*it]>=2) {
                    out<<"Yes";
                    return;
                }
            }
            //out<<endl;
        }
        //out<<endl<<endl;

    }
    out<<"No";
}

int main()
{
    ifstream in("A-small-attempt0.in");
    ofstream out("diamond.out");
    int n;
    in>>n;
    //out<<setprecision(9);
    for(int i=1; i<=n; i++)
    {
        out<<"Case #"<<i<<": ";
        megold(in, out);
        out<<endl;
    }
    in.close();
    out.close();
    return 0;
}
