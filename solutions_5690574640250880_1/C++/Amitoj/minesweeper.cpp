#include <algorithm>  
#include <iostream>  
#include <iomanip>  
#include <fstream>  
#include <sstream>  
#include <string>  
#include <list>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
using namespace std;  

#define FOR(i,a,b) for(long i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define MAX(i,j) ((i>j)?i:j)
#define MIN(i,j) ((i<j)?i:j)
class board
{
    private:
        int a_rows;
        int a_cols;
        int a_mines;
        int rows;
        int cols;
        int mines;
        int** layout;
    public:
        board(int r, int c, int m) : rows(r),cols(c),mines(m){
            a_rows = rows;
            a_cols = cols;
            a_mines = mines;
            layout = new int*[rows];
            for(int i = 0; i < rows; ++i)
            {
                layout[i] = new int[cols];
                for(int j = 0; j < cols; ++j)
                {
                    layout[i][j] = -1;
                }
            }

        }
        void reduceBoard();
        void solve(ostream& out);
        void placeMinesAtCorners();
        void print(ostream& out);
        bool verify();
};


void board::reduceBoard()
{
    if(rows < cols)
    {
        if (mines >= rows)
        {
            mines -= rows;
            --cols;
            for(int i = 0; i < a_rows; ++i)
            {
                layout[i][cols] = -100;
            }
            reduceBoard();
        }
    }
    else
    {
        if(mines >= cols)
        {
            mines -= cols;
            --rows;
            for(int i = 0; i < a_cols; ++i)
            {
                layout[rows][i] = -100;
            }
            reduceBoard();
        }
    }
}

void board::solve(ostream& out)
{
    //cout << "rows = " << rows << " cols = " << cols << " mines = " << mines << endl;
    if(mines >= (rows*cols))
    {
        //cout << "impossible" << endl;
        out << "Impossible" << endl;
        return;
    }

    reduceBoard();
    //cout << "After reducing \n";
    //print(cout);
    //cout << "rows = " << rows << " cols = " << cols << " mines = " << mines << endl;

    placeMinesAtCorners();
    if((mines > 0) or !verify())
    {
        //cout << "After verification \n";
        //print(cout);
        out << "Impossible" << endl;
    }
    else
        print(out);
}

void board::placeMinesAtCorners()
{
    //bottom right
    if(mines <= 0) return;

    int placeX = rows-1;
    int placeY = cols-1;
    while(mines and (placeY > 1) )
    {
        layout[placeX][placeY] = -100;
        --mines;
        --placeY;
    }
    
    placeX = rows-2;
    placeY = cols-1;
    while(mines and (placeX > 1) )
    {
        layout[placeX][placeY] = -100;
        --mines;
        --placeY;
    }
}

bool board::verify()
{
    REP(i, a_rows)
    {
        REP(j, a_cols)
        {
            if(layout[i][j] == -100)
                continue;

            int rs = MAX(i-1,0);
            int re = MIN(i+2,a_rows);
            int cs = MAX(j-1,0);
            int ce = MIN(j+2,a_cols);

            int minecount = 0;
            FOR(x,rs,re)
            {
                FOR(y,cs,ce)
                {
                    if(x==i and y==j)
                        continue;
                    else if(layout[x][y] == -100)
                        minecount++;
                }
            }
            layout[i][j] = minecount;

        }
    }

    REP(i, a_rows)
    {
        REP(j, a_cols)
        {
            if(layout[i][j] == -100)
                continue;
            else if(!i and !j)
                continue;

            int rs = MAX(i-1,0);
            int re = MIN(i+1,a_rows);
            int cs = MAX(j-1,0);
            int ce = MIN(j+1,a_cols);

            bool ok = false;
            FOR(x,rs,re)
            {
                FOR(y,cs,ce)
                {
                    if(x==i and y==j)
                        continue;
                    else if(layout[x][y] == 0)
                    {
                        ok = true;
                        break;
                    }
                }
                if(ok) break;
            }
            //if(!ok) cout << "Not ok found for i = " << i <<" and j = " << j << endl;
            if(!ok) return false;
        }
    }
    return true;
}

void board::print(ostream& out)
{
    for(int i = 0; i < a_rows; ++i)
    {
        for(int j = 0; j < a_cols; ++j)
        {
            if(!i and !j)
                out << 'c';
            else if(layout[i][j] == -100)
            {
                out << '*';
            }
            else
            {
                //out << layout[i][j];
                out << '.';
            }

        }
        out << endl;
    }
}

int main(int argc, char** argv)
{
    ifstream in;
    in.open(argv[1],ios::in);
    ofstream out;
    out.open(argv[2],ios::out);
    int N = 0;
    in>>N;
    cout << " Total  " << N <<endl;
    REP(caseN,N)
    {
        cout<<"solving case "<<caseN+1<<endl;
        int r,c,m;
        in >> r >> c >> m;

        board b(r,c,m);
        out << "Case #"<<caseN+1<<":";
        out << endl;
        b.solve(out);
    }
        
    in.close();
    out.close();
    return 0;
}
