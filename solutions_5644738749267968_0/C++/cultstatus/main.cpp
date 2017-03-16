/* 
 * File:   main.cpp
 * Author: warlock
 *
 * Created on April 12, 2014, 6:28 PM
 */

#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int testCases;
    int blocks;
    int war;
    int dWar;
    double tMass;
    vector<double> ken;
    vector<double> naomi;
    vector<double> tKen;
    vector<double> tNaomi;
    bool hasBigger;
    
    
    scanf("%d", &testCases);
    
    for(int currCase = 1; currCase <= testCases; currCase++)
    {
        war = 0;
        dWar = 0;
        naomi.clear();
        ken.clear();
        scanf("%d", &blocks);
        // Get Naomi's blocks
        for(int iBlocks = 0; iBlocks < blocks; iBlocks++)
        {
            scanf("%lf", &tMass);
            naomi.push_back(tMass);
        }
        // Get Ken's blocks
        for(int iBlocks = 0; iBlocks < blocks; iBlocks++)
        {
            scanf("%lf", &tMass);
            ken.push_back(tMass);
        }
        
        // Begin war
        tKen = ken;
        tNaomi = naomi;
        sort(tKen.begin(), tKen.end());
        sort(tNaomi.begin(), tNaomi.end());
        
        while(tKen.size() > 0 && tNaomi.size() > 0)
        {
            
//            cout << "naomi:" <<endl;
//            for(int i = 0; i < tNaomi.size(); i++)
//            {
//                cout << tNaomi.at(i) << " ";
//            }
//            cout << endl;
//            cout << "ken:" <<endl;
//            for(int i = 0; i < tKen.size(); i++)
//            {
//                cout << tKen.at(i) << " ";
//            }
//            cout << endl;
            
            hasBigger = false;
            for(int i = 0; i < tKen.size(); i++)
            {
                if(tKen.at(i) > tNaomi.at(0))
                {
                    hasBigger = true;
                    tKen.erase(tKen.begin() + i);
                    break;
                }
            }
            if(!hasBigger)
            {
                tKen.erase(min_element(tKen.begin(), tKen.end()));
                war++;
            }
            tNaomi.erase(tNaomi.begin());
        }
//        cout << "------------------------------------------------------" <<endl;
        // Begin deceitful war
        tKen = ken;
        tNaomi = naomi;
        sort(tKen.begin(), tKen.end());
        sort(tNaomi.begin(), tNaomi.end());
        
        while(tKen.size() > 0 && tNaomi.size() > 0)
        {
//            cout << "naomi:" <<endl;
//            for(int i = 0; i < tNaomi.size(); i++)
//            {
//                cout << tNaomi.at(i) << " ";
//            }
//            cout << endl;
//            cout << "ken:" <<endl;
//            for(int i = 0; i < tKen.size(); i++)
//            {
//                cout << tKen.at(i) << " ";
//            }
//            cout << endl;
            
            
            hasBigger = false;
            for(int i = 0; i < tNaomi.size(); i++)
            {
                if(tNaomi.at(i) > tKen.at(tKen.size() - 1))
                {
                    hasBigger = true;
                    dWar++;
                    tNaomi.erase(tNaomi.begin() + i);
                    break;
                }
            }
            if(!hasBigger)
            {
                tNaomi.erase(min_element(tNaomi.begin(), tNaomi.end()));
            }
            tKen.pop_back();
        }
        cout << "Case #" << currCase << ": " << dWar << " " << war << endl;
    }
    
    return 0;
}

