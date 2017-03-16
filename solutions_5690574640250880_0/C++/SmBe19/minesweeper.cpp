/* Code Jam 2014
 * Task: Minesweeper Master
 * User: SmBe19 (Benjamin Schmid)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void printField(vector<vector<char> >& field)
{
    for(int y = 0; y < field.size(); y++)
    {
        for(int x = 0; x < field[y].size(); x++)
        {
            cout << field[y][x];
        }
        cout << endl;
    }
}

bool checkField(vector<vector<char> >& field)
{
    pair<int, int> c = make_pair(-1, -1);
    for(int y = 0; y < field.size(); y++)
        for(int x = 0; x < field[y].size(); x++)
            if(field[y][x] == 'c')
            {
                c = make_pair(y, x);
                y = field.size();
                break;
            }

    if(c == make_pair(-1, -1))
        return false;

    vector<vector<bool> > bad(field.size(), vector<bool>(field[0].size(), false));

    for(int y = 0; y < field.size(); y++)
    {
        for(int x = 0; x < field[y].size(); x++)
        {
            if(field[y][x] == '*')
            {
                int dirX[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
                int dirY[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
                for(int i = 0; i < 9; i++)
                {
                    if(y+dirY[i] >= 0 && y+dirY[i] < field.size() && x+dirX[i] >= 0 && x+dirX[i] < field[0].size())
                        bad[y+dirY[i]][x+dirX[i]] = true;
                }
            }
        }
    }

    int comps = 0;
    queue<pair<int, int> > q;
    vector<vector<bool> > visited(field.size(), vector<bool>(field[0].size(), false));
    for(int y = 0; y < field.size(); y++)
    {
        for(int x = 0; x < field[y].size(); x++)
        {
            if(!bad[y][x] && !visited[y][x])
            {
                visited[y][x] = true;
                q.push(make_pair(y, x));
                comps++;

                while(!q.empty())
                {
                    pair<int, int> ael = q.front();
                    q.pop();

                    int dirX[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
                    int dirY[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
                    for(int i = 0; i < 9; i++)
                    {
                        if(ael.first+dirY[i] >= 0 && ael.first+dirY[i] < field.size() && ael.second+dirX[i] >= 0 && ael.second+dirX[i] < field[0].size())
                        {
                            if(!visited[ael.first+dirY[i]][ael.second+dirX[i]])
                            {
                                visited[ael.first+dirY[i]][ael.second+dirX[i]] = true;
                                if(!bad[ael.first+dirY[i]][ael.second+dirX[i]])
                                    q.push(make_pair(ael.first+dirY[i],ael.second+dirX[i]));
                            }
                        }
                    }
                }
            }
        }
    }

    // all but c are covered
    if(comps == 0)
    {
        for(int y = 0; y < field.size(); y++)
        {
            for(int x = 0; x < field[y].size(); x++)
            {
                if(field[y][x] == '.')
                    return false;
            }
        }
        return true;
    }

    if(comps > 1)
        return false;

    for(int y = 0; y < field.size(); y++)
    {
        for(int x = 0; x < field[y].size(); x++)
        {
            if(field[y][x] == '.' && !visited[y][x])
                return false;
        }
    }
    if(!visited[c.first][c.second])
        return false;

    return true;
}

bool solveField(vector<vector<char> >& field, int m, int starty)
{
    if(m == 0)
        if(!checkField(field))
            return false;
        else
            return true;

    for(int y = starty; y < field.size(); y++)
    {
        for(int x = 0; x < field[y].size(); x++)
        {
            if(field[y][x] == '.')
            {
                field[y][x] = '*';
                if(solveField(field, m-1, y))
                    return true;
                field[y][x] = '.';
            }
        }
    }

    return false;
}

int main()
{
    int tcn;
    cin >> tcn;
    for(int tc = 1; tc <= tcn; tc++)
    {
        int r, c, m;
        bool possible = true;
        cin >> r >> c >> m;

        vector<vector<char> > field(r, vector<char>(c, '.'));

        field[r-1][c-1] = 'c';

        for(int y = 0; y < max(m/c-1, 0); y++)
        {
            for(int x = 0; x < c; x++)
            {
                field[y][x] = '*';
            }
        }

        int ay = max(m/c-1, 0);
        int ar = r-ay;
        int am = m - (max(m/c-1, 0))*c;
        for(int x = 0; x < max(am/ar-1, 0); x++)
        {
            for(int y = ay; y < r; y++)
                field[y][x] = '*';
        }

        int ax = max(am/ar-1, 0);
        int ac = c - ax;
        am = am - (max(am/ar-1, 0))*ar;

        vector<vector<char> > smallField(min(r, ar + 1), vector<char> (min(c, ac+1)));

        for(int y = max(ay-1, 0), sy = 0; y < r; y++, sy++)
        {
            for(int x = max(ax - 1, 0), sx = 0; x < c; x++, sx++)
            {
                smallField[sy][sx] = field[y][x];
            }
        }

        possible = solveField(smallField, am, 0);

        if(!possible)
        {
            smallField[smallField.size() - 1][smallField[0].size() - 1] = '.';
            if(smallField.size() > 2)
            {
                smallField[smallField.size() - 2][smallField[0].size() - 1] = 'c';
                possible = solveField(smallField, am, 0);
                if(!possible)
                    smallField[smallField.size() - 2][smallField[0].size() - 1] = '.';
            }
        }

        if(!possible && smallField[0].size() > 2)
        {
            smallField[smallField.size() - 1][smallField[0].size() - 2] = 'c';
            possible = solveField(smallField, am, 0);
            if(!possible)
                smallField[smallField.size() - 1][smallField[0].size() - 2] = '.';
        }

        if(!possible && smallField.size() > 2 && smallField[0].size() > 2)
        {
            smallField[smallField.size() - 2][smallField[0].size() - 2] = 'c';
            possible = solveField(smallField, am, 0);
        }

        if(possible)
        {
            for(int y = max(ay-1, 0), sy = 0; y < r; y++, sy++)
            {
                for(int x = max(ax - 1, 0), sx = 0; x < c; x++, sx++)
                {
                    field[y][x] = smallField[sy][sx];
                }
            }
        }

        cout << "Case #" << tc << ":" << endl;
        if(possible)
            printField(field);
        else
            cout << "Impossible" << endl;
    }
    return 0;
}
