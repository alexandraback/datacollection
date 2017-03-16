#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

double naomi[1010], ken[1010], aux1[1010], aux2[1010];
int n, t, ptn1, ptk1, ptn2;

void citire()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%lf", &naomi[i]);
    }
    naomi[n] = aux1[n] = -1;
    for(int j=0; j<n; j++){
        scanf("%lf", &ken[j]);
    }
    ken[n] = aux2[n] = -1;
}

void solve1()
{
    ptn1=ptk1=0;
//    while(i>=0){
//        if(naomi[i]>ken[j]){
//            ptn1++;
//        }
//        else{
//            ptk1++;
//            j--;
//        }
//        i--;
//    }
    int ind;
    for(int i=0; i<n; i++){
        ind = upper_bound(ken, ken+n, naomi[i]) - ken;
        if(naomi[i] > ken[ind])
            ptn1++;
        ken[ind] = -1;
    }
    for(int i=0; i<=n; i++)
        ken[i] = aux2[i];
}

//void solve2()
//{
//    ptn2=0;
//    int i=0, j=0, lst=n-1;
//    while(naomi[lst]>ken[n-1]){
//        lst--;
//        if(lst < i){
//            ptn2 = n;
//            return;
//        }
//    }
//    int ind=0;
//    int ult=n-1;
//    while(1){
//        ind = upper_bound(ken, ken+n, naomi[lst])-ken;
//        i++;
//        ken[ind] = -1;
//        while(ken[ult]==-1) ult--;
//        while(naomi[lst]>ken[ult]){
//            lst--;
//            if(lst < i){
//                ptn2 = n-i;
//                return;
//            }
//        }
//    }
//}
void solve2()
{
    ptn2 = 0;
    int i=0, j=0;
    while(i<n){
        if(naomi[i]>ken[j]){
            j++;
            ptn2++;
        }
        i++;
    }

}


int main()
{
    freopen("Input", "r", stdin);
    freopen("Output", "w", stdout);

    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        citire();
        sort(naomi, naomi+n);
        sort(ken, ken+n);
        for(int i=0; i<n; i++)
            {aux1[i]=naomi[i]; aux2[i]=ken[i];}
        solve1();
        for(int i=0; i<n; i++)
            {naomi[i] = aux1[i]; ken[i] = aux2[i];}
        solve2();
        printf("Case #%d: %d %d\n", i, ptn2, ptn1);
    }
    return 0;
}
