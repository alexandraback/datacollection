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

int main()
{
//    FILE* fid_in = stdin;
//    FILE* fid_out = stdout;
    FILE* fid_in = fopen("/Users/bochen/Downloads/textfile.in", "r+");
    FILE* fid_out = fopen("/Users/bochen/Downloads/textfile.out", "w+");

    int t;
    fscanf(fid_in, "%d", &t);
    for(int cid = 1; cid <= t; cid++){
        int n;
        char s[2000];
        fscanf(fid_in, "%d %s", &n, &s);
        
        int cnt_add = 0;
        int cnt_before = s[0]-'0';
        for(int i = 1; i <= n; i++){
            int d = s[i] - '0';
            if(cnt_before < i){
                cnt_add += i-cnt_before;
                cnt_before = i;
            }
            cnt_before += d;
        }
        fprintf(fid_out, "Case #%d: %d\n", cid, cnt_add);
    }
    fclose(fid_in);
    fclose(fid_out);
    return 0;
}
