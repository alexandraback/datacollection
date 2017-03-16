#include <iostream>
#include <limits>
#include <vector>
#include <set>

bool traverse( std::vector< std::vector<int> >& graph
             , std::set<int> &visited
             , int node )
{
    if( visited.find(node) != visited.end() )
    {
        return false;
    }

    visited.insert( node );
    for( unsigned int i=0 ; i<graph[node].size() ; ++i )
    {
        if( !traverse( graph , visited , graph[node][i]) )
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int N;
    std::cin >> N;
    ++N;//test cases are indexed from 1

    //now ingore the rest of the line inc newline, eases some tests that
	//try to read a line at a time (and stick on this \n if not removed)
    std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n' );

    for( int test_case=1 ; test_case<N ; ++test_case )
    {
    //Prep
        int nodes;
        std::cin >> nodes;

        std::vector< std::vector<int> > graph( nodes );

        for( int node=0 ; node<nodes ; ++node )
        {
            int links;
            std::cin >> links;
            graph[node].resize( links );

            for( int link=0 ; link<links ; ++link)
            {
                std::cin >> graph[node][link];
                graph[node][link]--; //comp for 1-index node values fed in
            }
        }

    //Work
        bool has_diamond = false;
        for( int i=0 ; i<nodes ; ++i)
        {
            std::set<int> visited;
            if( !traverse( graph, visited, i) )
            {
                has_diamond = true;
                break;
            }
        }

        std::cout << "Case #" << test_case << ": " << (has_diamond ? "Yes" : "No") << std::endl;

    //Clean Up
    }
}
