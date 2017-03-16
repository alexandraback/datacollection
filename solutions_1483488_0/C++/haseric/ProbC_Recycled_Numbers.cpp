#include <stdio.h>
#include <iostream>
#include <fstream>
#include <deque>
#include <stdlib.h>
#include <string.h>
using namespace std;

int countRecycle(int low, int high){
    int ans = 0;
    bool checkedNum[2000000] = {0};
    for (int a = low; a <= high; a++){
        deque<int> cycle;
        int temp = a;
        int cycleCtr = 0;
        while (temp != 0){
            cycle.push_front(temp%10);
            temp /= 10;    
        }
        cycleCtr = cycle.size() - 1;
        //cout << a << " Cycle: " << cycleCtr << endl;
        int ctr = 1;
        while (cycleCtr >= 0 && checkedNum[a] == false){
            int sum = 0;
            int mul = 1;
            for (int b = cycle.size() - 1 ; b >= 0; b--){
                sum += cycle[b] * mul;
                mul *= 10;
            }
            if (sum != a && sum <= high && sum >= low && checkedNum[sum] == false){
                checkedNum[sum] = true;
                ans += ctr++;
                //cout << sum << " ctr: " << ctr << " ans: " << ans << endl;
                //system("PAUSE");
            }
            int temp2 = cycle.front();
            cycle.pop_front();
            cycle.push_back(temp2);
            cycleCtr--;
        }
        checkedNum[a] = true;
        cycle.clear();
    }
    return ans;
}

int main(){
    ofstream answer("prob_c_output.out");
    FILE *in = fopen("C-small-attempt0.in","r");
    int testcase = 0;
    fscanf(in,"%d\n",&testcase);
    for (int a = 0; a < testcase; a++){
        int low,high,ans;
        fscanf(in, "%d %d\n",&low,&high);
        ans = countRecycle(low,high);
        answer << "Case #" << a+1 << ": " << ans << endl;
    }
    fclose(in);
}
