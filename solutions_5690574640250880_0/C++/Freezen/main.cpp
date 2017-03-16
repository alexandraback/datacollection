//
//  main.cpp
//  minesweeper_master
//
//  Created by Yue Wang on 4/12/14.
//  Copyright (c) 2014 Yue Wang. All rights reserved.
//

#include <iostream>
#include <random>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

//vector<vector<int> > generateConfig(int rows, int cols, int mine)
//{
//    int total = rows * cols;
//    unordered_map<int, int> isSet;
//    for(int i = 0;i < total;i++)
//        isSet[i] = 0;
//    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//    default_random_engine generator(seed);
//    uniform_int_distribution<int> distribution(0,total-1);
//    auto mine_generator = bind(distribution, generator);
//    vector<vector<int> > field(rows, vector<int>(cols,0));
//    int numMine = mine;
//    while(numMine)
//    {
//        int pos = mine_generator();
//        if(isSet[pos] == 0)
//        {
//            isSet[pos] = 1;
//            int r = pos / cols;
//            int c = pos % cols;
//            field[r][c] = -1;
//            if(r-1 >= 0 && r-1 < rows && c-1 >= 0 && c-1 < cols && field[r-1][c-1] != -1)
//                field[r-1][c-1] += 1;
//            if(r-1 >= 0 && r-1 < rows && field[r-1][c] != -1)
//                field[r-1][c] += 1;
//            if(r-1 >= 0 && r-1 < rows && c+1 >= 0 && c+1 < cols && field[r-1][c+1] != -1)
//                field[r-1][c+1] += 1;
//            if(c-1 >= 0 && c-1 < cols && field[r][c-1] != -1)
//                field[r][c-1] += 1;
//            if(c+1 >= 0 && c+1 < cols && field[r][c+1] != -1)
//                field[r][c+1] += 1;
//            if(r+1 >= 0 && r+1 < rows && c-1 >= 0 && c-1 < cols && field[r+1][c-1] != -1)
//                field[r+1][c-1] += 1;
//            if(r+1 >= 0 && r+1 < rows && field[r+1][c] != -1)
//                field[r+1][c] += 1;
//            if(r+1 >= 0 && r+1 < rows && c+1 >= 0 && c+1 < cols && field[r+1][c+1] != -1)
//                field[r+1][c+1] += 1;
//            numMine -= 1;
//        }
//    }
//    return field;
//}

void isOk_helper(vector<vector<int> > &field, unordered_set<int> &isUsed, int start_pos, int rows, int cols, int &remains)
{
    isUsed.insert(start_pos);
    remains -= 1;
    int r = start_pos / cols;
    int c = start_pos % cols;
//    cout << r << ' ' << c << endl;
    if(field[r][c] > 0)
        return;
    if(r-1 >= 0 && r-1 < rows && c-1 >= 0 && c-1 < cols && field[r-1][c-1] != -1 && isUsed.find((r-1)*cols+c-1) == isUsed.end())
    {
        isOk_helper(field, isUsed, (r-1)*cols+c-1, rows, cols, remains);
    }
    if(r-1 >= 0 && r-1 < rows && field[r-1][c] != -1 && isUsed.find((r-1)*cols+c) == isUsed.end())
    {
        isOk_helper(field, isUsed, (r-1)*cols+c, rows, cols, remains);
    }
    if(r-1 >= 0 && r-1 < rows && c+1 >= 0 && c+1 < cols && field[r-1][c+1] != -1 && isUsed.find((r-1)*cols+c+1) == isUsed.end())
    {
        isOk_helper(field, isUsed, (r-1)*cols+c+1, rows, cols, remains);
    }
    if(c-1 >= 0 && c-1 < cols && field[r][c-1] != -1 && isUsed.find(r*cols+c-1) == isUsed.end())
    {
        isOk_helper(field, isUsed, r*cols+c-1, rows, cols, remains);
    }
    if(c+1 >= 0 && c+1 < cols && field[r][c+1] != -1 && isUsed.find(r*cols+c+1) == isUsed.end())
    {
        isOk_helper(field, isUsed, r*cols+c+1, rows, cols, remains);
    }
    if(r+1 >= 0 && r+1 < rows && c-1 >= 0 && c-1 < cols && field[r+1][c-1] != -1 && isUsed.find((r+1)*cols+c-1) == isUsed.end())
    {
        isOk_helper(field, isUsed, (r+1)*cols+c-1, rows, cols, remains);
    }
    if(r+1 >= 0 && r+1 < rows && field[r+1][c] != -1 && isUsed.find((r+1)*cols+c) == isUsed.end())
    {
        isOk_helper(field, isUsed, (r+1)*cols+c, rows, cols, remains);
    }
    if(r+1 >= 0 && r+1 < rows && c+1 >= 0 && c+1 < cols && field[r+1][c+1] != -1 && isUsed.find((r+1)*cols+c+1) == isUsed.end())
    {
        isOk_helper(field, isUsed, (r+1)*cols+c+1, rows, cols, remains);
    }

}

bool isOk(vector<vector<int> > &field, int start_pos, int rows, int cols, int mine)
{
    //pick an cell with 0
    int remains = rows * cols - mine;
    unordered_set<int> isUsed;
    isOk_helper(field, isUsed, start_pos, rows, cols, remains);
    if(remains)
        return false;
    else
        return true;
}

vector<vector<int> > generateConfig(int rows, int cols, int mine)
{
    if(mine == 0)
    {
        vector<vector<int> > field(rows, vector<int>(cols,0));
        field[0][0] = 9;
        return field;
    }
    unsigned int max = (1<<(rows * cols)) - 1;
    //0 ~ 2^total - 1(when total is within 25, I think is doable for small case)
    unsigned int v; // current permutation of bits
    unsigned int w; // next permutation of bits
    v = (1<<mine) - 1; // set the lower mine bits to 1 for initialization
    do{
        vector<vector<int> > field(rows, vector<int>(cols,0));
        unordered_set<int> isZero;
        for(int i = 0;i < rows * cols;i++)
            isZero.insert(i);
        unsigned int t = (v | (v - 1)) + 1;
        w = t | ((((t & -t) / (v & -v)) >> 1) - 1);
        int mc = 0;
        int pos = 0;
        while(mc < mine)
        {
            if(v & 1)
            {
                isZero.erase(pos);
                int r = pos / cols;
                int c = pos % cols;
                field[r][c] = -1;
                if(r-1 >= 0 && r-1 < rows && c-1 >= 0 && c-1 < cols && field[r-1][c-1] != -1)
                {
                    field[r-1][c-1] += 1;
                    if(isZero.find((r-1)*cols+c-1) != isZero.end())
                        isZero.erase((r-1)*cols+c-1);
                }
                if(r-1 >= 0 && r-1 < rows && field[r-1][c] != -1)
                {
                    field[r-1][c] += 1;
                    if(isZero.find((r-1)*cols+c) != isZero.end())
                        isZero.erase((r-1)*cols+c);
                }
                if(r-1 >= 0 && r-1 < rows && c+1 >= 0 && c+1 < cols && field[r-1][c+1] != -1)
                {
                    field[r-1][c+1] += 1;
                    if(isZero.find((r-1)*cols+c+1) != isZero.end())
                        isZero.erase((r-1)*cols+c+1);
                }
                if(c-1 >= 0 && c-1 < cols && field[r][c-1] != -1)
                {
                    field[r][c-1] += 1;
                    if(isZero.find(r*cols+c-1) != isZero.end())
                        isZero.erase(r*cols+c-1);
                }
                if(c+1 >= 0 && c+1 < cols && field[r][c+1] != -1)
                {
                    field[r][c+1] += 1;
                    if(isZero.find(r*cols+c+1) != isZero.end())
                        isZero.erase(r*cols+c+1);
                }
                if(r+1 >= 0 && r+1 < rows && c-1 >= 0 && c-1 < cols && field[r+1][c-1] != -1)
                {
                    field[r+1][c-1] += 1;
                    if(isZero.find((r+1)*cols+c-1) != isZero.end())
                        isZero.erase((r+1)*cols+c-1);
                }
                if(r+1 >= 0 && r+1 < rows && field[r+1][c] != -1)
                {
                    field[r+1][c] += 1;
                    if(isZero.find((r+1)*cols+c) != isZero.end())
                        isZero.erase((r+1)*cols+c);
                }
                if(r+1 >= 0 && r+1 < rows && c+1 >= 0 && c+1 < cols && field[r+1][c+1] != -1)
                {
                    field[r+1][c+1] += 1;
                    if(isZero.find((r+1)*cols+c+1) != isZero.end())
                        isZero.erase((r+1)*cols+c+1);
                }
                mc += 1;
            }
            pos += 1;
            v >>= 1;
        }
        v = w;
        //after generation, verify
        if(isZero.size() == 0)
        {
            if(rows*cols - mine == 1)
            {
                for(int i = 0;i < rows;i++)
                {
                    for(int j = 0;j < cols;j++)
                    {
                        if(field[i][j] != -1)
                        {
                            field[i][j] = 9;
                            return field;
                        }
                    }
                }
            }
            continue;
        }
        int start_pos = *isZero.begin();
        if(isOk(field, start_pos, rows, cols, mine))
        {
            field[start_pos / cols][start_pos % cols] = 9;
            return field;
        }
    }while(w <= max);
    return vector<vector<int> >();
}

int main(int argc, const char * argv[])
{
//    freopen("./C-small-attempt0.in","r",stdin);
//    freopen("test.txt","r",stdin);
    // insert code here...
    int R,C,M;
    int T;
    scanf("%d",&T);
    int cn = 1;
    while(T--)
    {
        scanf("%d %d %d",&R,&C,&M);
        //testing generate function
        auto field = generateConfig(R, C, M);
        printf("Case #%d:\n",cn);
        if(field.size() == 0)
            printf("Impossible\n");
        else
        {
            for(int i = 0;i < field.size();i++)
            {
                for(int j = 0;j < field[i].size();j++)
                {
                    if(field[i][j] == -1)
                        printf("*");
                    else if(field[i][j] != 9)
                        printf(".");
                    else
                        printf("c");
                }
                printf("\n");
            }
        }
        //testing isOk
//        vector<vector<int> > field = {
//            {0,0,0,0,0,2,-1},
//            {0,0,0,0,0,2,-1},
//            {0,1,1,1,0,1,1},
//            {0,1,-1,1,0,0,0}
//        };
//    cout << isOk(field, 1*7+2, 4, 7, 3) << endl;
        cn += 1;
    }
    return 0;
}

