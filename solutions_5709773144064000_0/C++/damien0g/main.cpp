//FRENCH
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    scanf("%d", &T);

    for(int t = 1; t <= T; t++)
    {
        double C, F, X;
        scanf("%lf %lf %lf", &C, &F, &X);

        double taux = 2;    //taux de production en cookies/seconde

        double tps_min = X/taux;   //temps sans ferme
        //servira de valeur max, inutile de tester les cas qui depasssent ce temps

        double avant_ferme[50001];  //pour chaque ferme (50 000 est un maximum du nombre de fermes achetables)
        //retient le temps mis pour avoir cette n-eme ferme

        avant_ferme[0] = 0; //pour avoir 0 ferme, on ne met aucun temps

        double tps = 0;
        for(int f = 1; tps <= tps_min; f++) //on essaie tous les nombres de fermes possibles, tant qu'il vaut mieux en rajouter une
        {
            avant_ferme[f] = avant_ferme[f-1] + C/taux;

            taux += F;  //on ajoute une ferme -> on produit plus

            tps = avant_ferme[f] + X/taux;

            tps_min = min(tps, tps_min);
        }

        printf("Case #%d: ", t);
        printf("%.7lf\n", tps_min);
    }

    return 0;
}
