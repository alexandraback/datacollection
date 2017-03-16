#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <queue>
#include <utility>
#include <set>
using namespace std;

typedef pair<long long, long long> XY;

struct entry {
    entry *parent;
    char move; // Move to get here
    long long x,y;
    long long nextmovewidth;
};

int main(int argc, char **argv) {
    if (argc < 2) {
        cout << "Please specify input file" << endl;
        return 1;
    }
    ifstream in(argv[1]);

    int testCases;
    in >> testCases;
    for (int testCase =0; testCase < testCases; testCase++) {
        // Read test case
        long long X,Y;
        in >> X >> Y;
        
        // Handle problem:
        entry *start = new entry();
        start->move = ' ';
        start->parent = 0;
        start->x = 0;
        start->y = 0;
        start->nextmovewidth = 1;
        
        queue<entry*> q;
        queue<entry*> handled;
        q.push(start);
        entry *final = 0;
        set<XY> visited;
        while (!q.empty()) {
            entry *curr = q.front();
            if (visited.count(XY(curr->x, curr->y)) != 0) {
                handled.push(curr);
                q.pop();
                continue;
            }
            else {
                visited.insert(XY(curr->x, curr->y));
            }
            //cout << "Evaluate pos: " << curr->x << " / " << curr->y << endl;
            q.pop();
            handled.push(curr);
            if (curr->x == X && curr->y == Y) {
                //cout << "FINAL" << endl;
                final = curr;
                break;
            }
            // Move east:
            entry *next = new entry();
            next->parent = curr;
            next->x = curr->x + curr->nextmovewidth;
            next->y = curr->y;
            next->nextmovewidth = curr->nextmovewidth + 1;
            next->move = 'E';
            if (visited.count(XY(next->x, next->y)) == 0) {
                q.push(next);
            }
            else {
                delete next;
            }

            // Move west:
            next = new entry();
            next->parent = curr;
            next->x = curr->x - curr->nextmovewidth;
            next->y = curr->y;
            next->nextmovewidth = curr->nextmovewidth + 1;
            next->move = 'W';
            if (visited.count(XY(next->x, next->y)) == 0) {
                q.push(next);
            }
            else {
                delete next;
            }

            // Move south: 
            next = new entry();
            next->parent = curr;
            next->x = curr->x;
            next->y = curr->y - curr->nextmovewidth;
            next->nextmovewidth = curr->nextmovewidth + 1;
            next->move = 'S';
            if (visited.count(XY(next->x, next->y)) == 0) {
                q.push(next);
            }
            else {
                delete next;
            }
            
            // Move north: 
            next = new entry();
            next->parent = curr;
            next->x = curr->x;
            next->y = curr->y + curr->nextmovewidth;
            next->nextmovewidth = curr->nextmovewidth + 1;
            next->move = 'N';
            if (visited.count(XY(next->x, next->y)) == 0) {
                q.push(next);
            }
            else {
                delete next;
            }
            
        }
        
        string result = "";
        while(final->parent != 0) {
            result = final->move + result;
            final = final->parent;
        }

        while(!q.empty()) {
            delete q.front();
            q.pop();
        }
        while(!handled.empty()) {
            delete handled.front();
            handled.pop();
        }


        cout << "Case #" << (testCase+1) << ": " << result << endl;
    } 
    
    return 0;
}
