#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

struct State {
    int X, Y;
    string answ;
    int nextStep;
};

bool visited[2001][2001];
int OFFSET = 1000;

bool validateState(State &s)
{
    return s.X >= -OFFSET && s.X <= OFFSET && s.Y >= -OFFSET && s.Y <= OFFSET && ! visited[s.X+OFFSET][s.Y+OFFSET];
    //return !visited[s.X+OFFSET][s.Y+OFFSET];
}

string solve(int X, int Y) {
    State initialState;
    initialState.X = 0; initialState.Y = 0;
    initialState.answ = "";
    initialState.nextStep = 1;
    visited[OFFSET][OFFSET] = true;
    
    queue<State> states;
    states.push(initialState);
    
    while (! states.empty()) {
        State nextState = states.front();
        states.pop();
    
        if (nextState.X == X && nextState.Y == Y) {
            return nextState.answ;
        }
        
        State newState;
        
        //expand the state to the North
        newState = nextState;
        newState.answ += "N";
        newState.Y += newState.nextStep;
        newState.nextStep++;
        if (validateState(newState)) {
            visited[newState.X+OFFSET][newState.Y+OFFSET] = true;
            states.push(newState);
        }
        
        //expand the state to the South
        newState = nextState;
        newState.answ += "S";
        newState.Y -= newState.nextStep;
        newState.nextStep++;
        if (validateState(newState)) {
            visited[newState.X+OFFSET][newState.Y+OFFSET] = true;
            states.push(newState);
        }
        
        //expand the state to East
        newState = nextState;
        newState.answ += "E";
        newState.X += newState.nextStep;
        newState.nextStep++;
        if (validateState(newState)) {
            visited[newState.X+OFFSET][newState.Y+OFFSET] = true;
            states.push(newState);
        }
        
        //expand the state to West
        newState = nextState;
        newState.answ += "W";
        newState.X -= newState.nextStep;
        newState.nextStep++;
        if (validateState(newState)) {
            visited[newState.X+OFFSET][newState.Y+OFFSET] = true;
            states.push(newState);
        }
        
    }
    
    return "NOT SOLVED";
}

int main()
{
    int T, case_ = 1, X, Y;
    
    cin >> T;
    while (T--) {
        memset(visited, 0, sizeof(visited));
        cin >> X >> Y;
        cout << "Case #" << case_++ << ": " << solve(X, Y) << endl;
    }

    
    return 0;
}
