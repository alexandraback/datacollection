#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cmath>
#include <map>
using namespace std;

int numTribes;
int attacksLeft[10];
int nextAttack[10];
int nextStart[10];
int nextEnd[10];
int nextStrength[10];

int deltaDays[10];
int deltaX[10];
int deltaStrength[10];

int wall[4000];

int doit() {

    int count = 0;
    // Set the wall to 0
    for (int i = 0; i < 4000; i++) wall[i] = 0;            
    int day = 100000000;
    
    for(int i = 0; i < numTribes; i++) day = min(day, nextAttack[i]);
    
    while (true) {
          //cout << "Day " << day << endl;
          // do attacks
          for (int i = 0; i < numTribes; i++) {
              if (nextAttack[i] == day ) {
                 bool success = false;
                 for (int j = nextStart[i]; j < nextEnd[i]; j++) {
                     if (wall[j] < nextStrength[i]) { success = true; break;}
                 }
                 if (success) count++;
                 cout << i << " " << success << endl;
              }              
          }
          
          // change wall and advance attacks
          for (int i = 0; i < numTribes; i++) {
              if (nextAttack[i] == day) {

                 //cout << "Change " << i << endl;

                 for (int j = nextStart[i]; j < nextEnd[i]; j++) {
                     wall[j] = max(wall[j], nextStrength[i]);
                 } 
                 
                 attacksLeft[i] --;
                 
                 if (attacksLeft[i] > 0) {
                 nextAttack[i] = day + deltaDays[i];
                 nextStart[i] += deltaX[i];
                 nextEnd[i] += deltaX[i];
                 nextStrength[i] += deltaStrength[i];
                 }
              }
          }
                    
          int nextDay = 100000000;
          for (int i = 0; i < numTribes; i++) {
              if (attacksLeft[i] > 0) nextDay = min(nextDay, nextAttack[i]);    
          }
          day = nextDay;
          if (nextDay == 100000000) return count;
          
    }    
    

    
}

int main() {
 
    ifstream infile("C:/a.in");
    ofstream outfile("C:/a.out");
    int numCases = 0;
    infile >> numCases;
    for (int i = 0; i < numCases; i++) {
        infile >> numTribes;
        for (int j = 0; j < numTribes; j++) {
            infile >> nextAttack[j] >> attacksLeft[j];
            int west, east;
            infile >> west >> east;
            nextStart[j] = west + 2000;
            nextEnd[j] = east + 2000;
            infile >> nextStrength[j] >> deltaDays[j] >> deltaX[j] >> deltaStrength[j];
        }
        int result = doit();
        //system("PAUSE");
        outfile << "Case #" << (i+1) << ": " << result << endl;
    }    
    outfile.close();
    return 0;   
    
}
