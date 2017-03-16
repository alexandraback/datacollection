#include <cstdio>
#include <cmath>
#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

bool decide(int x, int r, int c){
    bool gabriel_win = false;
    switch (x){
        case 1:
            gabriel_win = true;
            break;
        case 2:
            if(r % 2 == 0 || c % 2 == 0)
                gabriel_win = true;
            break;
        case 3:
            if((r == 3 && c >= 2) || (c == 3 && r >= 2))
                gabriel_win = true;
            break;
        case 4:
            if((r == 4 && c >= 3) || (c == 4 && r >= 3))
                gabriel_win = true;
            break;
    }
    return gabriel_win;
}

int main()
{
//    FILE* fid_in = stdin;
//    FILE* fid_out = stdout;
    FILE* fid_in = fopen("/Users/bochen/Downloads/textfile.in", "r+");
    FILE* fid_out = fopen("/Users/bochen/Downloads/textfile.out", "w+");

//    for(int x = 1; x <= 4; x++)
//        for(int r = 1; r <= 4; r++)
//            for(int c = 1; c <= 4; c++)
//                printf("%d %d %d %s\n", x, r, c, decide(x, r, c)?"GABRIEL":"RICHARD");
    int t;
    fscanf(fid_in, "%d", &t);
    for(int cid = 1; cid <= t; cid++){
        int x, r, c;
        fscanf(fid_in, "%d %d %d", &x, &r, &c);
        bool gabriel_win = decide(x, r, c);
        fprintf(fid_out, "Case #%d: %s\n", cid, gabriel_win?"GABRIEL":"RICHARD");
    }
    fclose(fid_in);
    fclose(fid_out);
    return 0;
}
