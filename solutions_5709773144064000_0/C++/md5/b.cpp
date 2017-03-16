#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    int nbTests;
    scanf("%d", &nbTests);
    
    for (int iTest = 1; iTest <= nbTests; iTest++) {
        double coutFerme, prodFerme, coutVictoire;
        double tempsMin, tempsCourant, prodCourante;
        scanf("%lf%lf%lf", &coutFerme, &prodFerme, &coutVictoire);
        prodCourante = 2;
        tempsMin = coutVictoire / prodCourante;
        tempsCourant = 0;
        
        for (int iFerme = 0; iFerme < coutVictoire; iFerme++) {
            double tempsFerme = tempsCourant + coutFerme / prodCourante;
            prodCourante += prodFerme;
            tempsMin = min(tempsMin, tempsFerme + coutVictoire / prodCourante);
            tempsCourant = tempsFerme;
        }
        
        printf("Case #%d: %.7f\n", iTest, tempsMin);
    }
    
    return 0;
}
