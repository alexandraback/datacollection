#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

int checkResult(int n, int sur, int br, int ggr[100]){
    int ans = 0;
    for (int a = 0; a < n; a++){
        int avg = ggr[a] / 3;
        int left = ggr[a] - (3 * avg);
        if (avg < br){
            if (left == 1 && avg + 1 == br) avg += left;
            else if (left == 2 && avg + 1 == br) avg++;  
            else if (sur > 0){
                if (left == 0 && avg + 1 == br && avg > 0){avg++; sur--;}    // case 6: 12 -> 4 4 4 l0 -> 5 3 4 (surprise)	+1 -1
                else if (left == 1 && avg + 1 == br){avg += left; sur--;}    // case 3: 10 -> 3 3 3 l1 -> 4 2 4 (surprise)	+1 -1 +1
                else if (left == 2 && avg + 2 == br){avg += left; sur--;}    // case 1: 11 -> 3 3 3 l2 -> 5 3 3 (surprise) +2
            }
        }
        if (avg >= br) ans++;
        //cout << "now: " << ggr[a] << " avg: " << avg << " left: " << left << " sur: " << sur << " br: " << br << endl;
    }
    //system("PAUSE");
    return ans;
}

int main(){
    //ofstream answer ("prob_b_output.out");
    //FILE *in = fopen("B-small-attempt0.in","r");
    ofstream answer ("prob_b_output_large.out");
    FILE *in = fopen("B-large.in","r");
    int testcase;
    fscanf(in, "%d\n",&testcase);
    for (int a = 0; a < testcase; a++){
        int n,sur,br,ans = 0;
        int ggr[100] = {0};
        fscanf(in, "%d %d %d",&n,&sur,&br);
        for (int b = 0; b < n; b++) fscanf(in, "%d",&ggr[b]);
        ans = checkResult(n,sur,br,ggr);
        answer << "Case #" << a+1 << ": " << ans << endl;
    }
    fclose(in);
    return 0;
}
