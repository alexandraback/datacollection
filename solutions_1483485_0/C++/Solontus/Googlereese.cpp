// Speaking in Tongues


#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>

using namespace std;

char map[26][2] = { {'a', 'y'},
                    {'b', 'n'},
                    {'c', 'f'},
                    {'d', 'i'},
                    {'e', 'c'},
                    {'f', 'w'},
                    {'g', 'l'},
                    {'h', 'b'},
                    {'i', 'k'},
                    {'j', 'u'},
                    {'k', 'o'},
                    {'l', 'm'},
                    {'m', 'x'},
                    {'n', 's'},
                    {'o', 'e'},
                    {'p', 'v'},
                    {'q', 'z'},
                    {'r', 'p'},
                    {'s', 'd'},
                    {'t', 'r'},
                    {'u', 'j'},
                    {'v', 'g'},
                    {'w', 't'},
                    {'x', 'h'},
                    {'y', 'a'},
                    {'z', 'q'} };


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
                  }else{
                            cout << line[i];                           
                  }
          }
}

int main(){

    int numlines = 0;
    cin >> numlines;
    getchar(); // whitespace--newline
    for( int i = 0; i < numlines; i++ ){
        read(i);
        cout << endl;
    }
    return 0; 
} 
