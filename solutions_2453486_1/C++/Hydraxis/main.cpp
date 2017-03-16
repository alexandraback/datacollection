#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int main()
{
    string fileName = "A-large";
    string fileInName = fileName+".in";
    string fileOutName = fileName+".out";
    string line;
    int currentCase=0;

    char table[4][4];

    ifstream fileIn(fileInName.c_str());
    ofstream fileOut(fileOutName.c_str());;

    if ( ! fileIn.is_open() )
    {
        cout << "File " << fileInName << " not found";
        return 1;
    }

    // number of cases
    getline (fileIn,line);
    int T = atoi(line.c_str());
    cout << "T=" << T << endl;

    // for each case
    while ( fileIn.good() and currentCase < T)
    {

        ++currentCase;
        cout << "----- Case #"<<currentCase<<" -----"<<endl;



        for (int i=0;i<4;i++)
        {
            getline (fileIn,line);
            for (int j=0;j<4;j++)
            {
                table[i][j] = line[j];
            }
        }


        for (int i=0;i<4;i++)
        {
            for (int j=0;j<4;j++)
            {
                cout << table[i][j];
            }
            cout << endl;
        }

        bool Xwin = false;
        bool Owin = false;

        bool tmpXwin;
        bool tmpOwin;

        // horizontal
        for (int i=0;i<4;i++)
        {
            tmpXwin = true;
            tmpOwin = true;
            for (int j=0;j<4;j++)
            {
                if(table[i][j] == 'X' || table[i][j] == '.')
                    tmpOwin = false;
                if(table[i][j] == 'O' || table[i][j] == '.')
                    tmpXwin = false;
            }
            if(tmpOwin == true)
                Owin = true;
            if(tmpXwin == true)
                Xwin = true;
        }

        // vertical
        for (int j=0;j<4;j++)
        {
            tmpXwin = true;
            tmpOwin = true;
            for (int i=0;i<4;i++)
            {
                if(table[i][j] == 'X' || table[i][j] == '.')
                    tmpOwin = false;
                if(table[i][j] == 'O' || table[i][j] == '.')
                    tmpXwin = false;
            }
            if(tmpOwin == true)
                Owin = true;
            if(tmpXwin == true)
                Xwin = true;
        }

        // diagonal 1
        tmpXwin = true;
        tmpOwin = true;
        for (int i=0;i<4;i++)
        {
            if(table[i][i] == 'X' || table[i][i] == '.')
                tmpOwin = false;
            if(table[i][i] == 'O' || table[i][i] == '.')
                tmpXwin = false;
        }
        if(tmpOwin == true)
            Owin = true;
        if(tmpXwin == true)
            Xwin = true;

        // diagonal 2
        tmpXwin = true;
        tmpOwin = true;
        for (int i=0;i<4;i++)
        {
            if(table[i][3-i] == 'X' || table[i][3-i] == '.')
                tmpOwin = false;
            if(table[i][3-i] == 'O' || table[i][3-i] == '.')
                tmpXwin = false;
        }
        if(tmpOwin == true)
            Owin = true;
        if(tmpXwin == true)
            Xwin = true;

        bool gameOver = true;
        for (int j=0;j<4;j++)
        {
            for (int i=0;i<4;i++)
            {
                if(table[i][j] == '.')
                {
                    gameOver = false;
                    goto end_loop;
                }
            }
        }
        end_loop:


        cout << "Case #"<<currentCase<<": X="<<Xwin<<" O="<<Owin<<endl;

        if(Xwin == true)
            fileOut << "Case #"<<currentCase<<": X won"<<endl;
        else if(Owin == true)
            fileOut << "Case #"<<currentCase<<": O won"<<endl;
        else if(gameOver == true)
            fileOut << "Case #"<<currentCase<<": Draw"<<endl;
        else
            fileOut << "Case #"<<currentCase<<": Game has not completed"<<endl;

        getline (fileIn,line); // empty line
    }

    fileOut.close();
    fileIn.close();

    return 0;
}
