#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>

#define D(x) 

using namespace std;

static set<pair<int,int>> DELTAS = { {0,1}, {0,-1}, {1,0}, {-1,0} };

struct polyomino {
    set<pair<int,int>> coords;

    template<typename T>
    polyomino(T coords_) {
        int min_x, min_y;
        bool first = true;

        for (const pair<int,int>& p : coords_) {
            if (first) {
                min_x = p.first;
                min_y = p.second;
                first = false;
            } else {
                min_x = min(min_x, p.first);
                min_y = min(min_y, p.second);
            }
        }

        for (const pair<int,int>& p : coords_) {
            coords.insert(make_pair(p.first - min_x, p.second - min_y));
        }
    }

    polyomino rotate90() const {
        set<pair<int,int>> coords2;
        for (const pair<int,int>& p : coords) {
            coords2.insert(make_pair(p.second, -p.first));
        }
        return polyomino(coords2);
    }

    polyomino reflect() const {
        set<pair<int,int>> coords2;
        for (const pair<int,int>& p : coords) {
            coords2.insert(make_pair(-p.first, p.second));
        }
        return polyomino(coords2);
    }


    bool operator<(const polyomino& other) const {
        return coords < other.coords;
    }

    bool operator==(const polyomino& other) const {
        return coords == other.coords;
    }

    void dump() const {
        int max_x = 0, max_y = 0;
        for (const pair<int,int>& p : coords) {
            max_x = max(max_x, p.first);
            max_y = max(max_y, p.second);
        }

        vector<vector<bool>> grid(max_x+1, vector<bool>(max_y+1));
        for (const pair<int,int>& p : coords) {
            grid[p.first][p.second] = true;
        }

        for (int j = 0; j <= max_y; j++) {
            for (int i = 0; i <= max_x; i++) {
                cerr << (grid[i][j] ? "#" : " ");
            }
            cerr << endl;
        }
    }
};

void build_omino_map(const polyomino& current, int remaining, vector<polyomino>& reps, map<polyomino,int>& lookup) {
    if (remaining > 0) {
        // add all possible neighbors
        for (const pair<int,int>& p : current.coords) {
            for (const pair<int,int>& delta : DELTAS) {
                pair<int,int> p2 = { p.first+delta.first, p.second+delta.second };
                if (current.coords.count(p2) == 0) {
                    set<pair<int,int>> next = current.coords;
                    next.insert(p2);
                    build_omino_map(polyomino(next), remaining-1, reps, lookup);
                }
            }
        }
    } else {
        if (lookup.count(current) > 0) return;

        polyomino rotated = current;
        set<polyomino> rotations;
        for (int i = 0; i < 4; i++) {
            rotations.insert(rotated);
            rotations.insert(rotated.reflect());
            rotated = rotated.rotate90();
        }
        
        const polyomino& rep = *rotations.begin();
        int index = reps.size();
        reps.push_back(rep);

        for (const polyomino& rotation : rotations) {
            lookup[rotation] = index;
        }
    }

}

void dump_board(int R, int C, const vector<vector<bool>>& right, const vector<vector<bool>>& down) {
    for (int j = 0; j < C; j++) {
        cerr << "+--";
    }
    cerr << "+" << endl;
    for (int i = 0; i < R; i++) {
        cerr << "|";
        for (int j = 0; j < C; j++) {
            bool r = (j < C-1) ? right[i][j] : false;
            cerr << (r ? "   " : "  |");
        }
        cerr << endl << "+";
        for (int j = 0; j < C; j++) {
            bool d = (i < R-1) ? down[i][j] : false;
            cerr << (d ? "  +" : "--+");
        }
        cerr << endl;
    }
}

void dfs(int i, int j, int R, int C, 
        const vector<vector<bool>>& right, const vector<vector<bool>>& down,
        vector<vector<bool>>& visited, vector<pair<int,int>>& points, int depth) {
    if (visited[i][j]) return;
    for (int i = 0; i < depth; i++) D(cerr << "\t");
    D(cerr << "visiting " << i << "," << j << endl);
    visited[i][j] = true;
    points.push_back(make_pair(i,j));

    // right
    if (j < C-1 && right[i][j]) dfs(i, j+1, R, C, right, down, visited, points, depth+1);
    // up
    if (i > 0 && down[i-1][j]) dfs(i-1, j, R, C, right, down, visited, points, depth+1);
    // left
    if (j > 0 && right[i][j-1]) dfs(i, j-1, R, C, right, down, visited, points, depth+1);
    // down
    if (i < R-1 && down[i][j]) dfs(i+1, j, R, C, right, down, visited, points, depth+1);
}

int main() {
    int numCases;
    cin >> numCases;

    for (int testCase = 1; testCase <= numCases; testCase++) {
        int X, R, C;
        cin >> X >> R >> C;

        bool result;

        if (X == 1) {
            result = true;
        } else if ((R*C) % X != 0) {
            result = false;
        } else {
            // enumerate all X-ominoes
            vector<polyomino> reps;
            map<polyomino, int> lookup;
            build_omino_map(polyomino(set<pair<int,int>>{{0,0}}), X-1, reps, lookup);

            for (int i = 0; i < reps.size(); i++) {
                D(cerr << "==========" << endl);
                for (const pair<polyomino,int>& p : lookup) {
                    if (p.second == i) {
                        D(p.first.dump());
                        D(cerr << endl);
                    }
                }
            }

            // enumerate all boards
            int num_bits = R*(C-1) + (R-1)*C;
            vector<vector<bool>> right(R, vector<bool>(C-1));
            vector<vector<bool>> down(R-1, vector<bool>(C));

            vector<bool> found_pieces(reps.size());

            for (int mask = 0; mask < (1<<num_bits); mask++) {
                // construct board
                for (int bit = 0; bit < R*(C-1); bit++) {
                    int i = bit/(C-1), j = bit%(C-1);
                    right[i][j] = (mask & (1<<bit)) != 0;
                }
                for (int bit = 0; bit < (R-1)*C; bit++) {
                    int i = bit/C, j = bit%C;
                    down[i][j] = (mask & (1<<(bit+R*(C-1)))) != 0;
                }
                D(cerr << mask << endl);
                D(dump_board(R, C, right, down));

                // find polyominoes
                vector<vector<bool>> visited(R, vector<bool>(C));
                vector<pair<int,int>> points;
                vector<bool> board_pieces(reps.size());

                bool board_valid = true;
                for (int i = 0; i < R && board_valid; i++) {
                    for (int j = 0; j < C && board_valid; j++) {
                        dfs(i, j, R, C, right, down, visited, points, 0);
                        if (!points.empty()) {
                            D(cerr << endl);
                            if (points.size() != X) {
                                D(cerr << "invalid board" << endl);
                                board_valid = false;
                                break;
                            }

                            polyomino piece(points);
                            int index = lookup[piece];
                            D(piece.dump());
                            D(cerr << "piece #" << index << endl);
                            board_pieces[index] = true;
                            points.clear();
                        }
                    }
                }

                if (board_valid) {
                    for (int i = 0; i < reps.size(); i++) {
                        if (board_pieces[i]) found_pieces[i] = true;
                    }
                }
            }

            // check if we've seen all pieces
            int num_pieces = 0;
            for (int i = 0; i < reps.size(); i++) {
                if (found_pieces[i]) num_pieces++;
            }
            result = (num_pieces == reps.size());
            D(cerr << "found " << num_pieces << " of " << reps.size() << endl);
        }

        cout << "Case #" << testCase << ": " << (result ? "GABRIEL" : "RICHARD") << endl;
    }
}
