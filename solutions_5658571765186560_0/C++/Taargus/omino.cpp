#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("D-small.in");
    ofstream fout("D-small.out");

    int cases;
    fin >> cases;

    for(int i = 0; i < cases; i++) {
        int size, rows, cols;
        string answer;

        fin >> size >> rows >> cols;

        // The one with the hole in it
        if(size > 6) {
            answer = "RICHARD";
        }

        // Nothing will fit perfectly
        else if((rows * cols) % size != 0) {
            answer = "RICHARD";
        }

        // Everything will fit perfectly
        else if(size <= 2) {
            answer = "GABRIEL";
        }

        else {
            int maxside = size / 2 + 1;
            int minside;

            
            if(size % 2 == 0) {
                minside = maxside - 1;
            }

            else {
                minside = maxside;
            }

            // short for "template". not sure why
            int mintemp = min(rows, cols);
            int maxtemp = max(rows, cols);

            // Maximal spanning L shape bigger than the grid
            if(minside > mintemp || maxside > maxtemp) {
                answer = "RICHARD";
            }

            // Staight line bigger than the grid
            else if(size > maxtemp) {
                answer = "RICHARD";
            }

            // Doesn't fit for math reasons (odd on both sides)
            else if(size == 4 && mintemp == 2) {
                answer = "RICHARD";
            }

            // "U" shape can't fit
            else if(size == 5 && mintemp == 2) {
                answer = "RICHARD";
            }

            // really getting into some corner cases - pentomino W
            else if(size == 5 && mintemp == 3 && maxtemp < 10) {
                answer = "RICHARD";
            }

            // Most shapes won't fit - math reasons
            else if(size == 6 && mintemp == 3) {
                answer = "RICHARD";
            } 

            else {
                answer = "GABRIEL";
            }
        }

        fout << "Case #" << i + 1 << ": " << answer << "\n";
    }
}
