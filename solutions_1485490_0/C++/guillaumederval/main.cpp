//
//  main.cpp
//  google code jam
//
//  Created by Guillaume Derval on 14/04/12.
//  Copyright (c) 2012 ITSelf.be. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cassert>
#include <stack>

/*struct CompareCase : public std::binary_function<Case, Case, bool>
{
    bool operator()(const Case lhs, const Case rhs) const
    {
        return lhs.lastT > rhs.lastT;
    }
};*/

struct Entry
{
    unsigned long long nb;
    int type;
};

struct Node
{
    unsigned long long made;
    int posBoxes;
    int posToys;
    unsigned long long remainingBoxes;
    unsigned long long remainingToys;
};

int main (int argc, const char * argv[])
{
    std::ifstream fin ("/Users/guillaumederval/Desktop/in.in", std::ifstream::in);
    std::ofstream fout("/Users/guillaumederval/Desktop/out.out", std::ofstream::out | std::ofstream::trunc);
    
    int tests;
    fin >> tests;
    for(int c = 0; c < tests; c++)
    {
        int N, M;
        fin >> N >> M;
        std::vector< Entry > boxes(N);
        std::vector< Entry > toys(M);
        for(int i = 0; i < N; i++)
            fin >> boxes[i].nb >> boxes[i].type;
        for(int i = 0; i < M; i++)
            fin >> toys[i].nb >> toys[i].type;
        
        std::queue< Node > nodes;
        Node firstnode; 
        firstnode.made = 0; 
        firstnode.posToys = 0;
        firstnode.posBoxes = 0; 
        firstnode.remainingBoxes = boxes[0].nb;
        firstnode.remainingToys = toys[0].nb;
        nodes.push(firstnode);
        unsigned long long best = 0;
        while(!nodes.empty())
        {
            Node state = nodes.front();
            nodes.pop();
            if(boxes[state.posBoxes].type == toys[state.posToys].type)
            {
                unsigned long long min = std::min(state.remainingBoxes, state.remainingToys);
                state.remainingBoxes -= min;
                state.remainingToys -= min;
                bool done = false;
                if(state.remainingToys == 0)
                {
                    state.posToys++;
                    if(state.posToys >= M)
                        done = true;
                    else
                        state.remainingToys = toys[state.posToys].nb;
                }
                if(state.remainingBoxes == 0)
                {
                    state.posBoxes++;
                    if(state.posBoxes >= N)
                        done = true;
                    else
                        state.remainingBoxes = boxes[state.posBoxes].nb;
                }
                
                state.made += min;
                if(best < state.made)
                    best = state.made;
                if(!done)
                    nodes.push(state);
            }
            else
            {
                if(state.posBoxes + 1 < N)
                {
                    Node nstate = state;
                    nstate.posBoxes++;
                    nstate.remainingBoxes = boxes[nstate.posBoxes].nb;
                    nodes.push(nstate);
                }
                if(state.posToys + 1 < M)
                {
                    Node nstate = state;
                    nstate.posToys++;
                    nstate.remainingToys = toys[nstate.posToys].nb;
                    nodes.push(nstate);
                }
            }
        }
        fout << "Case #" << (c+1) << ": " << best << std::endl;
    }
}