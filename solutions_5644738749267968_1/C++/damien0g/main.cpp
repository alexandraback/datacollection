//FRENCH
#include <cstdio>
#include <deque>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++)
    {
        printf("Case #%d: ", t);

        ///Input, init des donnees

        int N;
        scanf("%d", &N);

        deque<double> naomi[2];    //on retient tout 2 fois car on va basarder les 2 queues pendant l'operation
        deque<double> ken[2];      //idem

        for(int i = 0; i < N; i++)
        {
            double masse;
            scanf("%lf", &masse);
            naomi[0].push_back(masse);
        }

        for (int i = 0; i < N; i++)
        {
            double masse;
            scanf("%lf", &masse);
            ken[0].push_back(masse);
        }
        ///Fin input

        ///Tris et copies
        sort(naomi[0].begin(), naomi[0].end());
        sort(ken[0].begin(), ken[0].end());

        for(int i = 0; i < N; i++)
        {
            naomi[1].push_back(naomi[0][i]);
            ken[1].push_back(ken[0][i]);
        }
        ///Fin tris

        ///Deceitful War
        //(dans les cases 0 des tableaux)

        int pts_deceit = 0;
        while(naomi[0].size() > 0)  //tant qu'ils ont encore des morceaux de bois
        {
            if (naomi[0].back() > ken[0].back())  //si naomi peut marquer des points
            {
                pts_deceit++;
                naomi[0].erase(upper_bound(naomi[0].begin(), naomi[0].end(), ken[0].front()));
                //on supprime le + petit element > que celui que ken va enlever
                ken[0].pop_front();
            }
            else
            {
                naomi[0].pop_front();
                ken[0].pop_back();
            }
        }

        ///Fin Deceitful War

        ///War
        //dans les cases 1 des tableaux

        int pts_war = 0;
        while(naomi[1].size() > 0)  //tant qu'ils ont encore des morceaux de bois
        {
            if (naomi[1].back() > ken[1].back())
            {
                pts_war++;
                naomi[1].pop_back();
                ken[1].pop_front();
            }
            else
            {
                naomi[1].pop_back();
                ken[1].pop_back();
            }
        }

        ///Fin war
        printf("%d %d\n", pts_deceit, pts_war);
    }
    return 0;
}
