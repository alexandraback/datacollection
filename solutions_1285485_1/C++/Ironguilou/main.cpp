#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <set>
#include <utility>

using namespace std;

inline int absInt(int a)
{
    return a > 0 ? a : -a ;
}

// base p paire
// dx, dy entiers / p
// le reste en unites habituelles
bool reflet(int p, int xPos, int yPos, int dx, int dy, int W, int H, int D, int** hall)
{
    xPos = xPos * p + p / 2 ;
    yPos = yPos * p + p / 2 ;

    int x = xPos ;
    int y = yPos ;
    int sx = dx > 0 ? 1 : -1 ;
    int sy = dy > 0 ? 1 : -1 ;
    for (int k = (int) (p * D / sqrt(dx * dx + dy * dy)) ; k > 0 ; k--)
    {
        x += dx ;
        y += dy ;

        if (x == xPos && y == yPos)
            return true ;

        if (x % p != 0 && y % p != 0)
            continue ;

        if (x % p != 0)
        {
            if (hall[x / p][(y + sy) / p] == 1)
            {
                dy = -dy ;
                sy = -sy ;
            }
        }
        else if (y % p != 0)
        {
            if (hall[(x + sx) / p][y / p] == 1)
            {
                dx = -dx ;
                sx = -sx ;
            }
        }
        // on a corner
        else
        {
            int nx = hall[(x + sx) / p][(y - sy) / p] ;
            int ny = hall[(x - sx) / p][(y + sy) / p] ;
            int nxy = hall[(x + sx) / p][(y + sy) / p] ;
            if (nx == 1 && nxy == 1 && ny == 0)
            {
                dx = -dx ;
                sx = -sx ;
            }
            else if (ny == 1 && nxy == 1 && nx == 0)
            {
                dy = -dy ;
                sy = -sy ;
            }
            else if (nx == 0 && ny == 0 && nxy == 1)
                return false ;
            else if (nx == 1 && ny == 1 && nxy == 1)
            {
                dx = -dx ;
                sx = -sx ;
                dy = -dy ;
                sy = -sy ;
            }
        }

    }
    return false ;
}

int main()
{
    int nCases ;
    cin >> nCases ;

    string s ;
    string line ;

    getline(cin, s) ;

    int H, W, D ;
    int** hall ;
    int xPos, yPos ;
    set<double> dxDone ;
    for (int iCase = 0 ; iCase < nCases ; iCase++)
    {
        cerr << iCase << endl ;
        cin >> H ;
        cin >> W ;
        cin >> D ;

        hall = new int*[W] ;

        char c ;
        for (int i = 0 ; i < W ; i++)
        {
            hall[i] = new int[H] ;
        }

        for (int j = 0 ; j < H ; j++)
        {

            for (int i = 0 ; i < W ; i++)
            {
                cin >> c ;
                if (c == '#')
                    hall[i][j] = 1 ;
                else
                    hall[i][j] = 0 ;
                if (c== 'X')
                {
                    xPos = i ;
                    yPos = j ;
                }
            }

        }

        int nReflets = 0 ;
//        int maxWH = 5 * max(H, W) ;
        int maxWH = 2 * D ;

        dxDone.clear() ;
        for (int p = 2 ; p < 2 * maxWH ; p += 2)
        {
            for (int dx = -p/2 + 1 ; dx < p/2 ; dx++)
            {
                if (dxDone.count((double) dx / (double) p) != 0)
                    continue ;
                int pVrai = max(p, p * (int) abs(dx)) ;
                if (reflet(pVrai, xPos, yPos, dx, p / 2, W, H, D, hall))
                {
                    nReflets++ ;
                }
                dxDone.insert((double) dx / (double) p) ;
            }
        }

        dxDone.clear() ;
        for (int p = 2 ; p < 2 * maxWH ; p += 2)
        {
            for (int dx = -p/2 + 1 ; dx < p/2 ; dx++)
            {
                if (dxDone.count((double) dx / (double) p) != 0)
                    continue ;

                int pVrai = max(p, p * (int) abs(dx)) ;
                if (reflet(pVrai, xPos, yPos, dx, -p / 2, W, H, D, hall))
                {
                    nReflets++ ;
                }
                dxDone.insert((double) dx / (double) p) ;
            }
        }

        dxDone.clear() ;
        for (int p = 2 ; p < 2 * maxWH ; p += 2)
        {
            for (int dy = -p/2 ; dy <= p/2 ; dy++)
            {
                if (dxDone.count((double) dy / (double) p) != 0)
                    continue ;

                int pVrai = max(p, p * (int) abs(dy)) ;
                if (reflet(pVrai, xPos, yPos, p / 2, dy, W, H, D, hall))
                {
                    nReflets++ ;
                }
                dxDone.insert((double) dy / (double) p) ;
            }
        }


        dxDone.clear() ;
        for (int p = 2 ; p < 2 * maxWH ; p += 2)
        {
            for (int dy = -p/2 ; dy <= p/2 ; dy++)
            {
                if (dxDone.count((double) dy / (double) p) != 0)
                    continue ;

                int pVrai = max(p, p * (int) abs(dy)) ;
                if (reflet(pVrai, xPos, yPos, -p / 2, dy, W, H, D, hall))
                {
                    nReflets++ ;
                }
                dxDone.insert((double) dy / (double) p) ;
            }
        }



        // writing output file
        cout << "Case #" << iCase + 1 << ": " ;
        cout << nReflets ;
        cout << endl ;

        for (int i = 0 ; i < W ; i++)
            delete[] hall[i] ;
        delete[] hall ;
    }


    return 0;
}
