#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>

#define FORLOOP(i,n) for (int i=0; i<(int)(n); i++)

int main(int argc, char *argv[])
{
    int ncases;
    std::cin >> ncases;

    for(int c = 0; c < ncases; c++)
    {
        int N;
        std::cin >> N;

        std::vector<std::vector<int> > parents(N);
        std::vector<std::vector<int> > children(N);
        FORLOOP(i, N)
        {
            int M;
            std::cin >> M;
            parents[i] = std::vector<int>(M, 0);
            FORLOOP(j, M)
            {
                int p;
                std::cin >> p;
                p = p-1;
                parents[i][j] = p;          // i has parent p
                children[p].push_back(i);   // p has children i 
            }
        }

        std::vector<std::set<int> > ancestors(N);
        bool done = false;
        bool found = false;
        while(!done)
        {
            done = true;
            FORLOOP(i, N)
            {
                if(parents[i].size()==0 && children[i].size()>0)    // i has no more parents
                {
                    /*
                    std::cout << "before  " << i+1 << std::endl;
                    FORLOOP(ii, N)
                    {
                        std::cout << ii+1 << " " << ancestors[ii].size() << "   ";
                        for(std::set<int>::iterator it = ancestors[ii].begin(); it != ancestors[ii].end(); it++)                           
                            std::cout << *it+1 << " ";
                        std::cout << std::endl;
                    }
                    std::cout << std::endl;*/

                    
                    FORLOOP(j, children[i].size())  // add itself to its children
                    {
                        int child = children[i][j];
                        std::set<int> tempAncestors = ancestors[i];
                        tempAncestors.insert(i);

                        for(std::set<int>::iterator it = tempAncestors.begin(); it != tempAncestors.end(); it++)
                        {
                            // find diamond
                            int temp = *it;
                            if(ancestors[child].find(temp)!=ancestors[child].end())
                            {
                                found = true;
                                break;
                            }
                            else
                            {
                                done = false;
                                ancestors[child].insert(temp); // add to list of ancestors
                            }
                        }

                        parents[child].erase(std::find(parents[child].begin(), parents[child].end(), i));   // erase from parent
                    }
                    children[i].clear();

/*
                    std::cout << "after" << std::endl;
                    FORLOOP(ii, N)
                    {
                        std::cout << ii+1 << " " << ancestors[ii].size() << "   ";
                        for(std::set<int>::iterator it = ancestors[ii].begin(); it != ancestors[ii].end(); it++)                           
                            std::cout << *it+1 << " ";
                        std::cout << std::endl;
                    }
                    std::cout << std::endl;*/
                }

                if(found) break;
            }
        }

        if(found)
            std::cout << "Case #" << c+1 << ": Yes" << std::endl;
        else
            std::cout << "Case #" << c+1 << ": No" << std::endl;
    }
}
