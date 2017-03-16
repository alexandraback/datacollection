#include <iostream>
#include <cstdio>
#include <cmath>
#include <deque>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <memory.h>
#include <list>
#include <complex>
#include <sstream>

using namespace std;

struct tribe{
    int day;
    int quantityOfAttacks;
    int w;
    int e;
    int s;
    int delta_d;
    int delta_p;
    int delta_s;
}temp;

int wall[2000];

vector<tribe> tribes;
int middle = 1000;

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C.out","w",stdout);
    int TestNumbers;
    scanf("%d",&TestNumbers);
    for(int test = 0; test < TestNumbers; test++)
    {
        printf("Case #%d: ", test + 1);

        tribes.clear();
        memset(wall,0,sizeof(wall));
        int N;
        scanf("%d",&N);
        for(int i = 0; i < N; i++){
            scanf("%d%d%d%d%d%d%d%d",&temp.day, &temp.quantityOfAttacks, &temp.w, &temp.e, &temp.s, &temp.delta_d, &temp.delta_p, &temp.delta_s);
            temp.w *= 2;
            temp.e *= 2;
            temp.delta_p *= 2;
            tribes.push_back(temp);
        }

        int quantity = 0;
        while(true){
            vector<int> tribesToAttack;
            int day = 1000000000;
            for(int i = 0; i < N; i++){
                if(tribes[i].quantityOfAttacks && day > tribes[i].day){
                    day = tribes[i].day;
                }
            }
            if(day == 1000000000)
                break;
            for(int i = 0; i < N; i++)
                if(tribes[i].quantityOfAttacks && day == tribes[i].day){
                    tribesToAttack.push_back(i);
                }

            for(int i = 0; i < tribesToAttack.size(); i++)
            {
                int currentTribe = tribesToAttack[i];
                bool ok = true;
                for(int j = tribes[currentTribe].w; j <= tribes[currentTribe].e; j++)
                {
                    if(wall[j + middle] < tribes[currentTribe].s)
                    {
                        ok = false;
                        break;
                    }
                }
                if(!ok)
                    quantity++;
            }

            for(int i = 0; i < tribesToAttack.size(); i++)
            {
                int currentTribe = tribesToAttack[i];
                for(int j = tribes[currentTribe].w; j <= tribes[currentTribe].e; j++)
                {
                    if(wall[j + middle] < tribes[currentTribe].s)
                    {
                        wall[j + middle] = tribes[currentTribe].s;
                    }
                }
            }
            for(int i = 0; i < tribesToAttack.size(); i++)
            {
                int currentTribe = tribesToAttack[i];
                tribes[currentTribe].e += tribes[currentTribe].delta_p;
                tribes[currentTribe].w += tribes[currentTribe].delta_p;
                tribes[currentTribe].s += tribes[currentTribe].delta_s;
                tribes[currentTribe].day += tribes[currentTribe].delta_d;
                tribes[currentTribe].quantityOfAttacks--;
            }
        }
        printf("%d",quantity);
        printf("\n");
    }
    return 0;
}

