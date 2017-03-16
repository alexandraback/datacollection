#include <iostream>
#include <utility>
#include <vector>
#include <set>

using namespace std;

void dispSet(set<int> &a)
{
    for(set<int>::iterator it = a.begin(); it != a.end(); ++it)
    {
        cout << *it << " ";
    }
}

bool isDiamond(vector<set<int> > &graph, set<int>& achievedClasses, size_t start)
{
    for(set<int>::iterator it = graph[start - 1].begin(); it != graph[start - 1].end(); ++it)
    {
        pair<set<int>::iterator, bool> result = achievedClasses.insert(*it);
        if(!result.second)
        {
            return true;
        }
        bool deepResult = isDiamond(graph, achievedClasses, *it);
        if(deepResult)
        {
            return true;
        }
    }
    return false;
}

set<int> getBottoms(vector<set<int> > &graph)
{
    set<int> result;
    for(size_t i = 0; i < graph.size(); ++i)
    {
        bool ok = true;
        for(size_t j = 0; j < graph.size(); ++j)
        {
            if(graph[j].count(i+1) > 0)
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            result.insert(i+1);
        }
    }
    return result;
}

int main()
{
	int cnt = 0;
	cin >> cnt;

    for(int i = 0 ; i < cnt; ++i)
    {
        int classesNo = 0;
        cin >> classesNo;

        vector<set<int> > graph;

        // Biuld graph
        for(int a = 0; a < classesNo; ++a)
        {
            set<int> classData;
            int parents = 0;
            cin >> parents;
            for(int b = 0; b < parents; ++b)
            {
                int tmp = 0;
                cin >> tmp;
                classData.insert(tmp);
            }
            graph.push_back(classData);
        }

        set<int> bottoms = getBottoms(graph);
        set<int> starter;

        bool found = false;

        for(set<int>::iterator it = bottoms.begin(); it != bottoms.end(); ++it)
        {
            found = isDiamond(graph, starter,*it);
            if(found)
            {
                break;
            }
            starter.clear();
        }

        cout << "Case #" << (i+1) << ": ";
        if(found)
        {
            cout << "Yes" << endl;
        }else
        {
            cout << "No" << endl;
        }
    }

	return 0;
}
