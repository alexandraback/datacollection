#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int ex, ey, x, y, cas, CAS;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &CAS);
    for (cas = 1; cas <= CAS; cas++){
        printf("Case #%d: ", cas);
        scanf("%d%d", &ex, &ey);
        x = 0; y = 0;
        while (x != ex || y != ey){
            if (x < ex){
                printf("WE");
                x++;
            }else if (x > ex){
                printf("EW");
                x--;
            }else if (y < ey){
                printf("SN");
                y++;
            }else if (y > ey){
                printf("NS");
                y--;
            }
        }
        puts("");
    }
}
