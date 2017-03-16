/* 
 * File:   main.cpp
 * Author: warlock
 *
 * Created on April 12, 2014, 12:35 PM
 */

#include <cstdlib>
#include <list>
#include <vector>
#include <iostream>
#include <cstdio>

#define CELL_EMPTY 0
#define CELL_MINE 1
#define CELL_CHECKED 2

using namespace std;

typedef struct Point
{
    int row;
    int col;
} point_t;

/*
 * 
 */

void printMap(vector< vector<int> > &map, point_t center, point_t max)
{
    for(int row = 0; row < max.row; row++)
    {
        for(int col = 0; col < max.col; col++)
        {
            if(row == center.row && col == center.col)
            {
                cout << "c";
            }
            else
            {
                if(map.at(row).at(col) == CELL_MINE)
                {
                    cout << "*";
                }
                if(map.at(row).at(col) == CELL_EMPTY)
                {
                    cout << ".";
                }
            }
        }
        cout << endl;
    }
}

bool checkPoint(vector< vector<int> > &map, point_t center, point_t max, int total, int empty)
{
    point_t it;
    point_t maxIt;
    int count = 0;
    vector<point_t> pVector;
    
    // Bounds check
    it.row = center.row - 1;
    if(it.row < 0) it.row = 0;
    it.col = center.col - 1;
    if(it.col < 0) it.col = 0;
    
    maxIt.row = center.row + 1;
    if(maxIt.row >= max.row) maxIt.row = max.row - 1;
    maxIt.col = center.col + 1;
    if(maxIt.col >= max.col) maxIt.col = max.col - 1;
    
//    cout << "c " << center.row << " " << center.col << " m " << max.row << " " << max.col << " t " << total << " e " << empty << endl;
//    //cout << "itrow " << it.row << " itcol " << it.col << " maxitrow " << maxIt.row << " maxitcol " << maxIt.col << endl;
//    cout << "____________________-" << endl;
//    printMap(map, center, max);
//    cout << "____________________-" << endl;
    
    // Show all cells around center
    for(; it.row <= maxIt.row; it.row++)
    {
        it.col = center.col - 1;
        if(it.col < 0) it.col = 0;
        for(; it.col <= maxIt.col; it.col++)
        {
            if(map.at(it.row).at(it.col) == CELL_MINE)
            {
                pVector.push_back(it);
                map.at(it.row).at(it.col) = CELL_EMPTY;
                count++;
            }
        }
    }
    
//    cout << "try: ";
//    for(int i = 0; i < pVector.size(); i++)
//    {
//        cout << pVector.at(i).row << " " << pVector.at(i).col << " | ";
//    }
//    
//    cout << "count " << count << endl;
//    cout << "____________________-" << endl;
//    printMap(map, center, max);
//    cout << "____________________-" << endl;
    
    // Check if we're done
    if((empty + count) == total) return true;
    if((empty + count) > total)
    {
        for(int i = 0; i < pVector.size(); i++)
        {
            map.at(pVector.at(i).row).at(pVector.at(i).col) = CELL_MINE;
//            cout << "remove " << pVector.at(i).row << " " << pVector.at(i).col << endl;
        }
        return false;
    }
    
    // Call recursively
    for(int i = 0; i < pVector.size(); i++)
    {
        if(!(pVector.at(i).row == center.row && pVector.at(i).col == center.col))
        {
            if(checkPoint(map, pVector.at(i), max, total, empty + count) == true) return true;
        }
    }
    for(int i = 0; i < pVector.size(); i++)
    {
        map.at(pVector.at(i).row).at(pVector.at(i).col) = CELL_MINE;
//        cout << "done trying " << pVector.at(i).row << " " << pVector.at(i).col << endl;
    }
    return false;
}

void checar(vector< vector<int> > &map, point_t center, point_t max)
{
//    cout << "centro " << center.row << " " << center.col << endl;
    
    point_t pMin;
    point_t pMax;
    bool mina;
    vector<point_t> puntos;
    
    pMin.row = center.row-1;
    if(pMin.row < 0) pMin.row = 0;
    
    pMax.row = center.row+1;
    if(pMax.row >= max.row) pMax.row = max.row-1;
    pMax.col = center.col+1;
    if(pMax.col >= max.col) pMax.col = max.col-1;
    
    map.at(center.row).at(center.col) = CELL_CHECKED;
    // Recorrer 9 celdas
    mina = false;
    while(pMin.row <= pMax.row && mina == false)
    {
        pMin.col = center.col-1;
        if(pMin.col < 0) pMin.col = 0;
        while(pMin.col <= pMax.col && mina == false)
        {
            if(map.at(pMin.row).at(pMin.col) == CELL_MINE)
            {
                mina = true;
            }
            else
            {
                if(map.at(pMin.row).at(pMin.col) == CELL_EMPTY)
                {
//                    cout << "punto " << pMin.row << " " << pMin.col<< endl;
                    puntos.push_back(pMin);
                    
                }
            }
            pMin.col++;
        }
        pMin.row++;
    }
    
    
    if(mina == false)
    {
        for(int i = 0; i < puntos.size(); i++)
        {
            map.at(puntos.at(i).row).at(puntos.at(i).col) = CELL_CHECKED;
        }
//        cout << "puntos pasan"<<endl;
        for(int i = 0; i < puntos.size(); i++)
        {
            checar(map, puntos.at(i), max);
        }
    }
    
}

int main(int argc, char** argv) {
    int totalCases;
    int mines;
    vector< vector<int> > map;
    vector<int> mapRow;
    point_t center;
    point_t max;
    bool solution;
    bool specialCase;
    
    scanf("%d", &totalCases);
        
    for(int currCase = 1; currCase <= totalCases; currCase++)
    {
        scanf("%d %d %d", &max.row, &max.col, &mines);
//        max.row = 5;
//        max.col = 5; 
//        mines = 8;
        
        // Generate map
        map.clear();
        for(int row = 0; row < max.row; row++)
        {
            mapRow.clear();
            for(int col = 0; col < max.col; col++)
            {
                mapRow.push_back(CELL_MINE);
            }
            map.push_back(mapRow);
        }
        
        // Output
        cout << "Case #" << currCase << ": " << endl;
        solution = false;
        specialCase = false;
        center.row = -1;
        center.col = -1;
        for(int row = 0; row < max.row && !solution; row++)
        {
            for(int col = 0; col < max.col && !solution; col++)
            {
                // There is only 1 cell to click
                if(((max.row * max.col) - mines) == 1)
                {
                    specialCase = true;
                    solution = true;
                    for(int i = 0; i < max.row; i++)
                    {
                        for(int j = 0; j < max.col; j++)
                        {
                            if(i == 0 && j == 0)
                                cout << "c";
                            else
                                cout << "*";
                        }
                        cout << endl;
                    }
                    break;
                }
                // There are no mines
                if(mines == 0)
                {
                    specialCase = true;
                    solution = true;
                    for(int i = 0; i < max.row; i++)
                    {
                        for(int j = 0; j < max.col; j++)
                        {
                            if(i == 0 && j == 0)
                                cout << "c";
                            else
                                cout << ".";
                        }
                        cout << endl;
                    }
                    break;
                }
                // Regular approach
                center.row = row;
                center.col = col;
                solution = checkPoint(map, center, max, (max.row * max.col) - mines, 0);
            }
        }
        //printMap(map, center, max);
        if(!specialCase)
        {
            if(solution)
            {
                printMap(map, center, max);
//                vector< vector<int> > mapo;
//                vector<int> mapRowo;
//                for(int row = 0; row < max.row; row++)
//                {
//                    mapRowo.clear();
//                    for(int col = 0; col < max.col; col++)
//                    {
//                        if(map.at(row).at(col) == CELL_MINE)
//                        {
//                            mapRowo.push_back(CELL_MINE);
//                        }
//                        else
//                            mapRowo.push_back(CELL_EMPTY);
//                    }
//                    mapo.push_back(mapRowo);
//
//                }
//                checar(mapo, center, max);
//    //            cout << "mapo" << endl;
//    //            
//    //            for(int i = 0; i < mapo.size(); i++)
//    //            {
//    //                for(int j = 0; j < mapo.at(i).size(); j++)
//    //                {
//    //                    cout << mapo.at(i).at(j);
//    //                }
//    //                cout << endl;
//    //            }
//
//
//
//                for(int i = 0; i < mapo.size(); i++)
//                {
//                    for(int j = 0; j < mapo.at(i).size(); j++)
//                    {
//                        if(mapo.at(i).at(j) == CELL_EMPTY)
//                        {
//                            cout << "ERROR" << endl;
//                        }
//                    }
//                }

            }
            else
            {
                cout << "Impossible" << endl;
            }
        }
    }
    
    return 0;
}