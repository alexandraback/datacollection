/*!
 * \file     q2.cpp
 * \author   Cong Wang
 * \date     2012
 * \brief 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

int main (int argc, char const* argv[]){

	if(argc < 2){
		cout << "using: ./prog inputfile" << endl;
		exit(0);
	}

	string line;
	ifstream myfile (argv[1]);

	int numTests;
	myfile >> numTests;

    vector<vector<int> > levels;

	for (unsigned int z = 0; z < numTests; z += 1){
		//hand each test case here
        
        int numLevels;
        myfile >> numLevels;
        
        for (unsigned int j = 0; j < numLevels; j += 1){
            vector<int> temp;
            int tempVal;
            myfile >> tempVal;
            temp.push_back(tempVal);
            myfile >> tempVal;
            temp.push_back(tempVal);
            levels.push_back(temp);
        }
        
        int numStars = 0;
        int numComplete = 0;
        bool foundTwo = false;
        int mark = -1;
        bool fail = false;
        
        //10000 is sentinel
        
        while(levels.size() != 0){
            foundTwo = false;
            mark = -1;
            
            //find all ones that can be done, if 2 stars, do.
            for (unsigned int i = 0; i < levels.size(); i += 1){
                if(levels[i][1] <= numStars){
                
                    //cout << "foundTwo!!!!" << endl;
                
                    if(levels[i][0] != 10000){
                        numStars = numStars + 2;
                    }
                    else{
                        numStars = numStars + 1;
                    }
                    foundTwo = true;
                    levels.erase(levels.begin() + i);
                    i--;
                    numComplete++;
                    break;
                }
                
                if(levels[i][0] <= numStars){
                    if(mark != -1){
                        if(levels[i][1] > levels[mark][1]){
                            mark = i;
                        }
                    }
                    else{
                        mark = i;
                    }
                }
            }
            
            //cout << "outside loop" << endl;
            
            if(mark == -1 && !foundTwo){
                fail = true;
                break;
            }
            
            //use the mark
            if(!foundTwo){
                levels[mark][0] = 10000;
                numStars = numStars + 1;
                numComplete++;
            }
        }
        
       
        
        //print result
        cout << "Case #" << z+1 << ": ";
        if(fail){
            cout << "Too Bad" << endl;
        }
        else{
            cout << numComplete << endl;
        }
       
                
        
        /*
        //checking input
        for (unsigned int a = 0; a < levels.size(); a += 1){
            for (unsigned int b = 0; b < levels.at(a).size(); b += 1){
                cout << levels[a][b] << " ";
            }
            cout << endl;
        }
        */
        
        levels.clear();
	}

	myfile.close();

	return 0;
}
