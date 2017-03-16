#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

static bool recursive(set<int>& visit, vector< vector<int> >& edges, int i);

static void calculation()
{
    int classes;
    cin >> classes;
    
    vector< vector<int> > edges;
    
    for(int i=0; i<classes; i++)
    {
        int count;
        cin >> count;
        
        vector<int> edge;
        for(int j=0; j<count; j++)
        {
            int end;
            cin >> end;
            
            edge.push_back(end);
        }
        
        edges.push_back(edge);
    }
    
    
    bool result = false;
    for(int i=0; i<classes; i++)
    {
        set<int> visit;
        
        if(recursive(visit, edges, i))
        {
            result = true;
            break;
        }
    }
    
    if(!result)
    {
        cout << "No";
    }
    else
    {
        cout << "Yes";
    }
    
}

static bool recursive(set<int>& visit, vector< vector<int> >& edges, int i)
{
    int vertex = i+1;
    
    if(visit.find(vertex) != visit.end())
    {
        return true;
    }
    else
    {
        visit.insert(vertex);
    }
    
    vector<int> edge = edges.at(i);
    
    for(unsigned int j=0; j<edge.size(); j++)
    {
        if(recursive(visit, edges, edge.at(j)-1))
        {
            return true;
        }
    }
    
    
    return false;
}




int main()
{
    int cases;

    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        printf("Case #%d: ", i+1);
        
        calculation();
        
        cout << endl;
    }

    return 0;
}

