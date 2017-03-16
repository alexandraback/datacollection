#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main()
{
    int T;
    cin >> T;
    for (int run = 1; run <= T; ++run)
    {
        int R, C, W;
        cin >> R >> C >> W;

        // 0-based indices!
        // For a single row:
        // how many turns do I need for hitting it once
        // if W > C/2
        //    check the middle, it will always hit
        //    so l turn
        // else
        //    battleship can be at [0,W[
        //    so try hitting W-1
        //    then he has to move it to at least
        //    [W,2W[
        //    then try at 2W-1 etc
        //int turnsPerRow = C / W;

        // In every row, we have to do turnsPerRow
        // turns first, and then enemy will move it to another row
        //int missTurns = R * turnsPerRow;

        // newC = W + C%W
        // possiblePositions = C % W;
        // after missTurns we have hit the ship exactly once
        // we know it is in a [0,newC[ interval
        // and can be in possiblePositions possible positions
        //
        // from the hit that we already have,
        // simply hit consecutive squares to the left
        // untill there is a miss, and then the ship is completely fixed
        // if possiblePositions == 0 then there will not
        // be a miss

        int answer = R * (C/W) + W - 1 + (C%W == 0 ? 0 : 1);

        cout << "Case #" << run << ": " << answer << endl;
    }
}
