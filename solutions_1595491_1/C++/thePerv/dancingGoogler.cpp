// Dancing With the Googlers

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <fstream>

using namespace std;

int main(){
   
    ifstream infile ("B-large.in");
    
    int numPeople;
    int numSurprise;
    int minScore;
    int temp;
    vector<int> peopleScores;
    
    int count = 0;
  
    if (infile.is_open()){
    
        int numTests;
        infile >> numTests;
    
        for(int test = 0; test < numTests; test++){
            int numGood = 0;
            infile >> numPeople;
            infile >> numSurprise;
            infile >> minScore;
            peopleScores.clear();
            count++;
            
            for(int i = 0; i < numPeople; i++){
                infile >> temp;
                peopleScores.push_back(temp);
            }
            
            //process data
            cout << "Case #" << count << ": ";
            
            for(int i = 0; i < numPeople; i++){
                
                if( (peopleScores[i] - minScore) >= 2 * (minScore - 1) ){
                    numGood++;
                }
                else if( (peopleScores[i] - minScore) >= 0 && 
                         (peopleScores[i] - minScore) >= 2 * (minScore - 2) && 
                         numSurprise > 0 ){
                    numGood++;
                    numSurprise--;
                }
            }
            
            cout << numGood << endl;  
            
        }
        infile.close();
    }
}
    
