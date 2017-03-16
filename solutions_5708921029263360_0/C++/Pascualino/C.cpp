#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int, PII> PIII;
typedef pair<PII, PII> PIIII;
typedef vector<int> VI;
typedef vector<vector<int> > VVI;

#define x first
#define y second

int sol;
vector<vector<int> > solMoves;

int J, P, S, K;

bool validMove(int j, int p, int s, VVI &JP, VVI &JS, VVI &PS){
    if(JP[j][p] == K || JS[j][s] == K || PS[p][s] == K){
        return false;
    }
    return true;
}

void rec(int j, int p, int s, VVI &JP, VVI &JS, VVI &PS, VVI &moves){
    s++;
    if(s == S){
        s = 0;
        p++;
    }
    if(p == P){
        p = 0;
        j++;
    }
    if(j == J){
        if(sol < (int)moves.size()){
            sol = (int)moves.size();
            solMoves = moves;
        }
        return;
    }
    rec(j, p, s, JP, JS, PS, moves);

    if(validMove(j, p, s, JP, JS, PS)){
      moves.push_back(vector<int>(3));
      moves[moves.size()-1][0] = j;
      moves[moves.size()-1][1] = p;
      moves[moves.size()-1][2] = s;
      JP[j][p]++;
      JS[j][s]++;
      PS[p][s]++;
      rec(j, p, s, JP, JS, PS, moves);
      PS[p][s]--;
      JS[j][s]--;
      JP[j][p]--;
      moves.resize(moves.size()-1);
    }
}

int main(){


    int T;
    cin >> T;
    for(int t=1;t<=T;t++){
        sol = 0;
        solMoves = VVI(0);

        cin >> J >> P >> S >> K;

        vector<vector<int> > JP(3, vector<int>(3, 0));
        vector<vector<int> > JS(3, vector<int>(3, 0));
        vector<vector<int> > PS(3, vector<int>(3, 0));
        vector<vector<int> > moves(0);

        rec(0, 0, -1, JP, JS, PS, moves);

        cout << "Case #" << t << ": " << sol << endl;
        for(int i=0;i<sol;i++){
            cout << solMoves[i][0]+1 << " " << solMoves[i][1]+1 << " " << solMoves[i][2]+1 << endl;
        }


    }
}
