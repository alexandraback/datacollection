//
//  main.cpp
//  CodeJam
//
//  Created by Sercan Tutar on 4/13/13.
//  Copyright (c) 2013 Sercan Tutar. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include <fstream>
#include <unordered_map>

#define KEY_ID_TYPE int
#define KEY_COUNT_TYPE int
#define KEY_MAP_TYPE std::unordered_map<KEY_ID_TYPE, KEY_COUNT_TYPE>
#define CHEST_ID_TYPE int
#define CHEST_VEC_TYPE std::vector<Chest>
#define STATE_STACK_TYPE std::vector<State>
#define LOG_ERROR std::cout << "ERROR IN LINE: " << __LINE__ << std::endl

struct Chest
{
    CHEST_ID_TYPE id;
    KEY_ID_TYPE key; // key to open
    std::vector<KEY_ID_TYPE> keys;
};

struct State
{
    // key id to count map
    KEY_MAP_TYPE keyMap;
    CHEST_VEC_TYPE chestVec;
    int currentChest;
};

STATE_STACK_TYPE states;
KEY_ID_TYPE maxKey;

void addKeyToMap(KEY_ID_TYPE k, KEY_MAP_TYPE& m)
{
    KEY_MAP_TYPE::iterator it = m.find(k);
    if (it != m.end())
        it->second++;
    else
        m[k] = 1;
}

void removeKeyFromMap(KEY_ID_TYPE k, KEY_MAP_TYPE& m)
{
    KEY_MAP_TYPE::iterator it = m.find(k);
    if (it != m.end())
    {
        it->second--;
        if (it->second <= 0)
            m.erase(it);
    } else
        LOG_ERROR;
}

// return index of first chest which can be opened
int canOpen()
{
    CHEST_VEC_TYPE& c = states.back().chestVec;
    KEY_MAP_TYPE& k = states.back().keyMap;
    for (int i = states.back().currentChest; i < c.size(); i++)
        if (k.find(c[i].key) != k.end())
            return i;
    return -1;
}

void open()
{
    CHEST_VEC_TYPE& c = states.back().chestVec;
    int i = states.back().currentChest;
    State newState = states.back();
    removeKeyFromMap(c[i].key, newState.keyMap);
    for (int j=0; j<c[i].keys.size(); j++)
        addKeyToMap(c[i].keys[j], newState.keyMap);
    newState.chestVec.erase(newState.chestVec.begin()+i);
    newState.currentChest = 0;
    states.push_back(newState);
}

int check(bool checkRequired=false)
{
    KEY_MAP_TYPE requiredKeyMap;
    KEY_MAP_TYPE blockedKeyMap;
    KEY_MAP_TYPE existingKeyMap = states.back().keyMap;
    if (checkRequired)
        for (int i=0; i<states.back().chestVec.size(); i++)
            addKeyToMap(states.back().chestVec[i].key, requiredKeyMap);
    for (int i=0; i<states.back().chestVec.size(); i++) {
        for (int j=0; j<states.back().chestVec[i].keys.size(); j++) {
            addKeyToMap(states.back().chestVec[i].keys[j], existingKeyMap);
            if (states.back().chestVec[i].keys[j] == states.back().chestVec[i].key)
                addKeyToMap(states.back().chestVec[i].keys[j], blockedKeyMap);
        }
    }
    for (int i=1; i<=maxKey; i++) {
        KEY_MAP_TYPE::iterator it3 = blockedKeyMap.find(i);
        int c3 = it3 == blockedKeyMap.end() ? 0 : it3->second;
        if (c3 > 0) {
            KEY_MAP_TYPE::iterator it2 = existingKeyMap.find(i);
            int c2 = it2 == existingKeyMap.end() ? 0 : it2->second;
            if (c3 == c2)
                return true;
        }
        if (checkRequired) {
            KEY_MAP_TYPE::iterator it1 = requiredKeyMap.find(i);
            int c1 = it1 == requiredKeyMap.end() ? 0 : it1->second;
            KEY_MAP_TYPE::iterator it2 = existingKeyMap.find(i);
            int c2 = it2 == existingKeyMap.end() ? 0 : it2->second;
            if (c1 > c2)
                return true;
        }
    }
    return false;
}

void solve()
{
    if (check(true)) {
        std::cout << "IMPOSSIBLE" << std::endl;
        return;
    }
    
    while (!states.empty() && !states.back().chestVec.empty()) {
        int i = canOpen();
        if (i<0) {
            states.pop_back();
            states.back().currentChest++;
        } else {
            states.back().currentChest = i;
            open();

            if (check()) {
                states.pop_back();
                states.back().currentChest++;
            }
        }
    }

    if (states.empty())
        std::cout << "IMPOSSIBLE" << std::endl;
    else {
        for (int i=0; i<states.size()-1; i++)
            std::cout << states[i].chestVec[states[i].currentChest].id << " ";
        std::cout << std::endl;
    }
}

int main(int argc, const char * argv[])
{
    int noOfCases;
    std::cin >> noOfCases;
    for (int i = 0; i < noOfCases; i++) {
        states.clear();
        maxKey = 0;

        State s;
        int K, N;
        std::cin >> K >> N;
        for (int j = 0; j < K; j++) {
            int k;
            std::cin >> k;
            maxKey = k>maxKey ? k : maxKey;
            addKeyToMap(k, s.keyMap);
        }
        for (int j = 0; j < N; j++) {
            Chest c;
            c.id = j+1;
            std::cin >> c.key;
            maxKey = c.key>maxKey ? c.key : maxKey;
            int kcount;
            std::cin >> kcount;
            for (int k = 0; k < kcount; k++) {
                KEY_ID_TYPE key;
                std::cin >> key;
                maxKey = key>maxKey ? key : maxKey;
                c.keys.push_back(key);
            }
            s.chestVec.push_back(c);
        }
        states.push_back(s);

        std::cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
