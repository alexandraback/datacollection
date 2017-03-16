// Speaking in Tongues


#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include<fstream>

using namespace std;

char map[26][2];

char decode(char input){
    for(int i = 0; i < 26; i++)
        if(map[i][1] == input) return map[i][0];
}

void read(int i){
          string line;
          getline(cin, line);
          cout << "Case #" << i+1 << ": ";
          for( int i = 0; i < line.length(); i++ ){
                  if( line[i] >= 97 && line[i] <= 122 ){
                            cout << decode(line[i]);
                  }
                  else{
                            cout << line[i];                           
                  }
          }
}


int main(){
    map[0][0] = 'a';
    map[0][1] = 'y';
    map[14][0] = 'o';
    map[14][1] = 'e';
    map[25][0] = 'z';
    map[25][1] = 'q';
    map[16][0] = 'q';
    map[16][1] = 'z';
    
    ifstream sampleIn ("sample.in");
    ifstream sampleOut ("sample.out");
    
    vector<string> vecSampleIn;
    vector<string> vecSampleOut;
    
    string line;
    if (sampleIn.is_open()){
        while ( sampleIn.good() ){
            getline (sampleIn,line);
            vecSampleIn.push_back(line);
        }
        sampleIn.close();
    }

    if (sampleOut.is_open()){
        while ( sampleOut.good() ){
            getline (sampleOut,line);
            vecSampleOut.push_back(line);
        }
        sampleOut.close();
    }
    
    for(int i = 0; i < vecSampleIn.size(); i++){
        for(int j = 0; j < vecSampleIn.at(i).length(); j++){
            if(vecSampleIn[i][j] != ' '){
                map[vecSampleIn[i][j] - 97][1] = vecSampleIn[i][j];
                map[vecSampleIn[i][j] - 97][0] = vecSampleOut[i][j];
            }
        }  
    }

    int numlines = 0;
    cin >> numlines;
    getchar();
    for( int i = 0; i < numlines; i++ ){
        read(i);
        cout << endl;
    }
    return 0;
} 
