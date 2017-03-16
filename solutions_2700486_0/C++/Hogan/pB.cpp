#include<cstdio>
#include<map>
#include<utility>

std::map<int, std::map<std::pair<int, int>, double> >   myMap;

int main(){
    int T, n, x, y;

    myMap[1][std::pair<int, int>(0, 0)] = 1;

    myMap[2][std::pair<int, int>(0, 0)] = 1;
    myMap[2][std::pair<int, int>(2, 0)] = 0.5;
    myMap[2][std::pair<int, int>(-2, 0)] = 0.5;

    myMap[3][std::pair<int, int>(0, 0)] = 1;
    myMap[3][std::pair<int, int>(2, 0)] = 0.75;
    myMap[3][std::pair<int, int>(-2, 0)] = 0.75;
    myMap[3][std::pair<int, int>(1, 1)] = 0.25;
    myMap[3][std::pair<int, int>(-1, 1)] = 0.25;

    myMap[4][std::pair<int, int>(0, 0)] = 1;
    myMap[4][std::pair<int, int>(2, 0)] = 1;
    myMap[4][std::pair<int, int>(-2, 0)] = 1;
    myMap[4][std::pair<int, int>(1, 1)] = 0.5;
    myMap[4][std::pair<int, int>(-1, 1)] = 0.5;

    myMap[5][std::pair<int, int>(0, 0)] = 1;
    myMap[5][std::pair<int, int>(2, 0)] = 1;
    myMap[5][std::pair<int, int>(-2, 0)] = 1;
    myMap[5][std::pair<int, int>(1, 1)] = 1;
    myMap[5][std::pair<int, int>(-1, 1)] = 1;

    myMap[6][std::pair<int, int>(0, 0)] = 1;
    myMap[6][std::pair<int, int>(2, 0)] = 1;
    myMap[6][std::pair<int, int>(-2, 0)] = 1;
    myMap[6][std::pair<int, int>(1, 1)] = 1;
    myMap[6][std::pair<int, int>(-1, 1)] = 1;
    myMap[6][std::pair<int, int>(0, 2)] = 1;

    myMap[7][std::pair<int, int>(0, 0)] = 1;
    myMap[7][std::pair<int, int>(2, 0)] = 1;
    myMap[7][std::pair<int, int>(-2, 0)] = 1;
    myMap[7][std::pair<int, int>(1, 1)] = 1;
    myMap[7][std::pair<int, int>(-1, 1)] = 1;
    myMap[7][std::pair<int, int>(0, 2)] = 1;
    myMap[7][std::pair<int, int>(4, 0)] = 0.5;
    myMap[7][std::pair<int, int>(-4, 0)] = 0.5;

    myMap[8][std::pair<int, int>(0, 0)] = 1;
    myMap[8][std::pair<int, int>(2, 0)] = 1;
    myMap[8][std::pair<int, int>(-2, 0)] = 1;
    myMap[8][std::pair<int, int>(1, 1)] = 1;
    myMap[8][std::pair<int, int>(-1, 1)] = 1;
    myMap[8][std::pair<int, int>(0, 2)] = 1;
    myMap[8][std::pair<int, int>(4, 0)] = 0.75;
    myMap[8][std::pair<int, int>(-4, 0)] = 0.75;
    myMap[8][std::pair<int, int>(3, 1)] = 0.25;
    myMap[8][std::pair<int, int>(-3, 1)] = 0.25;

    myMap[9][std::pair<int, int>(0, 0)] = 1;
    myMap[9][std::pair<int, int>(2, 0)] = 1;
    myMap[9][std::pair<int, int>(-2, 0)] = 1;
    myMap[9][std::pair<int, int>(1, 1)] = 1;
    myMap[9][std::pair<int, int>(-1, 1)] = 1;
    myMap[9][std::pair<int, int>(0, 2)] = 1;
    myMap[9][std::pair<int, int>(4, 0)] = 0.875;
    myMap[9][std::pair<int, int>(-4, 0)] = 0.875;
    myMap[9][std::pair<int, int>(3, 1)] = 0.5;
    myMap[9][std::pair<int, int>(-3, 1)] = 0.5;
    myMap[9][std::pair<int, int>(2, 2)] = 0.125;
    myMap[9][std::pair<int, int>(-2, 2)] = 0.125;

    myMap[10][std::pair<int, int>(0, 0)] = 1;
    myMap[10][std::pair<int, int>(2, 0)] = 1;
    myMap[10][std::pair<int, int>(-2, 0)] = 1;
    myMap[10][std::pair<int, int>(1, 1)] = 1;
    myMap[10][std::pair<int, int>(-1, 1)] = 1;
    myMap[10][std::pair<int, int>(0, 2)] = 1;
    myMap[10][std::pair<int, int>(4, 0)] = 0.9375;
    myMap[10][std::pair<int, int>(-4, 0)] = 0.9375;
    myMap[10][std::pair<int, int>(3, 1)] = 0.6875;
    myMap[10][std::pair<int, int>(-3, 1)] = 0.6875;
    myMap[10][std::pair<int, int>(2, 2)] = 0.3125;
    myMap[10][std::pair<int, int>(-2, 2)] = 0.3125;
    myMap[10][std::pair<int, int>(1, 3)] = 0.0625;
    myMap[10][std::pair<int, int>(-1, 3)] = 0.0625;

    myMap[11][std::pair<int, int>(0, 0)] = 1;
    myMap[11][std::pair<int, int>(2, 0)] = 1;
    myMap[11][std::pair<int, int>(-2, 0)] = 1;
    myMap[11][std::pair<int, int>(1, 1)] = 1;
    myMap[11][std::pair<int, int>(-1, 1)] = 1;
    myMap[11][std::pair<int, int>(0, 2)] = 1;
    myMap[11][std::pair<int, int>(4, 0)] = 1;
    myMap[11][std::pair<int, int>(-4, 0)] = 1;
    myMap[11][std::pair<int, int>(3, 1)] = 0.875;
    myMap[11][std::pair<int, int>(-3, 1)] = 0.875;
    myMap[11][std::pair<int, int>(2, 2)] = 0.5;
    myMap[11][std::pair<int, int>(-2, 2)] = 0.5;
    myMap[11][std::pair<int, int>(1, 3)] = 0.125;
    myMap[11][std::pair<int, int>(-1, 3)] = 0.125;

    myMap[12][std::pair<int, int>(0, 0)] = 1;
    myMap[12][std::pair<int, int>(2, 0)] = 1;
    myMap[12][std::pair<int, int>(-2, 0)] = 1;
    myMap[12][std::pair<int, int>(1, 1)] = 1;
    myMap[12][std::pair<int, int>(-1, 1)] = 1;
    myMap[12][std::pair<int, int>(0, 2)] = 1;
    myMap[12][std::pair<int, int>(4, 0)] = 1;
    myMap[12][std::pair<int, int>(-4, 0)] = 1;
    myMap[12][std::pair<int, int>(3, 1)] = 1;
    myMap[12][std::pair<int, int>(-3, 1)] = 1;
    myMap[12][std::pair<int, int>(2, 2)] = 0.75;
    myMap[12][std::pair<int, int>(-2, 2)] = 0.75;
    myMap[12][std::pair<int, int>(1, 3)] = 0.25;
    myMap[12][std::pair<int, int>(-1, 3)] = 0.25;

    myMap[13][std::pair<int, int>(0, 0)] = 1;
    myMap[13][std::pair<int, int>(2, 0)] = 1;
    myMap[13][std::pair<int, int>(-2, 0)] = 1;
    myMap[13][std::pair<int, int>(1, 1)] = 1;
    myMap[13][std::pair<int, int>(-1, 1)] = 1;
    myMap[13][std::pair<int, int>(0, 2)] = 1;
    myMap[13][std::pair<int, int>(4, 0)] = 1;
    myMap[13][std::pair<int, int>(-4, 0)] = 1;
    myMap[13][std::pair<int, int>(3, 1)] = 1;
    myMap[13][std::pair<int, int>(-3, 1)] = 1;
    myMap[13][std::pair<int, int>(2, 2)] = 1;
    myMap[13][std::pair<int, int>(-2, 2)] = 1;
    myMap[13][std::pair<int, int>(1, 3)] = 0.5;
    myMap[13][std::pair<int, int>(-1, 3)] = 0.5;

    myMap[14][std::pair<int, int>(0, 0)] = 1;
    myMap[14][std::pair<int, int>(2, 0)] = 1;
    myMap[14][std::pair<int, int>(-2, 0)] = 1;
    myMap[14][std::pair<int, int>(1, 1)] = 1;
    myMap[14][std::pair<int, int>(-1, 1)] = 1;
    myMap[14][std::pair<int, int>(0, 2)] = 1;
    myMap[14][std::pair<int, int>(4, 0)] = 1;
    myMap[14][std::pair<int, int>(-4, 0)] = 1;
    myMap[14][std::pair<int, int>(3, 1)] = 1;
    myMap[14][std::pair<int, int>(-3, 1)] = 1;
    myMap[14][std::pair<int, int>(2, 2)] = 1;
    myMap[14][std::pair<int, int>(-2, 2)] = 1;
    myMap[14][std::pair<int, int>(1, 3)] = 1;
    myMap[14][std::pair<int, int>(-1, 3)] = 1;

    myMap[15][std::pair<int, int>(0, 0)] = 1;
    myMap[15][std::pair<int, int>(2, 0)] = 1;
    myMap[15][std::pair<int, int>(-2, 0)] = 1;
    myMap[15][std::pair<int, int>(1, 1)] = 1;
    myMap[15][std::pair<int, int>(-1, 1)] = 1;
    myMap[15][std::pair<int, int>(0, 2)] = 1;
    myMap[15][std::pair<int, int>(4, 0)] = 1;
    myMap[15][std::pair<int, int>(-4, 0)] = 1;
    myMap[15][std::pair<int, int>(3, 1)] = 1;
    myMap[15][std::pair<int, int>(-3, 1)] = 1;
    myMap[15][std::pair<int, int>(2, 2)] = 1;
    myMap[15][std::pair<int, int>(-2, 2)] = 1;
    myMap[15][std::pair<int, int>(1, 3)] = 1;
    myMap[15][std::pair<int, int>(-1, 3)] = 1;
    myMap[15][std::pair<int, int>(0, 4)] = 1;

    myMap[16][std::pair<int, int>(0, 0)] = 1;
    myMap[16][std::pair<int, int>(2, 0)] = 1;
    myMap[16][std::pair<int, int>(-2, 0)] = 1;
    myMap[16][std::pair<int, int>(1, 1)] = 1;
    myMap[16][std::pair<int, int>(-1, 1)] = 1;
    myMap[16][std::pair<int, int>(0, 2)] = 1;
    myMap[16][std::pair<int, int>(4, 0)] = 1;
    myMap[16][std::pair<int, int>(-4, 0)] = 1;
    myMap[16][std::pair<int, int>(3, 1)] = 1;
    myMap[16][std::pair<int, int>(-3, 1)] = 1;
    myMap[16][std::pair<int, int>(2, 2)] = 1;
    myMap[16][std::pair<int, int>(-2, 2)] = 1;
    myMap[16][std::pair<int, int>(1, 3)] = 1;
    myMap[16][std::pair<int, int>(-1, 3)] = 1;
    myMap[16][std::pair<int, int>(0, 4)] = 1;
    myMap[16][std::pair<int, int>(6, 0)] = 0.5;
    myMap[16][std::pair<int, int>(-6, 0)] = 0.5;

    myMap[17][std::pair<int, int>(0, 0)] = 1;
    myMap[17][std::pair<int, int>(2, 0)] = 1;
    myMap[17][std::pair<int, int>(-2, 0)] = 1;
    myMap[17][std::pair<int, int>(1, 1)] = 1;
    myMap[17][std::pair<int, int>(-1, 1)] = 1;
    myMap[17][std::pair<int, int>(0, 2)] = 1;
    myMap[17][std::pair<int, int>(4, 0)] = 1;
    myMap[17][std::pair<int, int>(-4, 0)] = 1;
    myMap[17][std::pair<int, int>(3, 1)] = 1;
    myMap[17][std::pair<int, int>(-3, 1)] = 1;
    myMap[17][std::pair<int, int>(2, 2)] = 1;
    myMap[17][std::pair<int, int>(-2, 2)] = 1;
    myMap[17][std::pair<int, int>(1, 3)] = 1;
    myMap[17][std::pair<int, int>(-1, 3)] = 1;
    myMap[17][std::pair<int, int>(0, 4)] = 1;
    myMap[17][std::pair<int, int>(6, 0)] = 0.75;
    myMap[17][std::pair<int, int>(-6, 0)] = 0.75;
    myMap[17][std::pair<int, int>(5, 1)] = 0.25;
    myMap[17][std::pair<int, int>(-5, 1)] = 0.25;

    myMap[18][std::pair<int, int>(0, 0)] = 1;
    myMap[18][std::pair<int, int>(2, 0)] = 1;
    myMap[18][std::pair<int, int>(-2, 0)] = 1;
    myMap[18][std::pair<int, int>(1, 1)] = 1;
    myMap[18][std::pair<int, int>(-1, 1)] = 1;
    myMap[18][std::pair<int, int>(0, 2)] = 1;
    myMap[18][std::pair<int, int>(4, 0)] = 1;
    myMap[18][std::pair<int, int>(-4, 0)] = 1;
    myMap[18][std::pair<int, int>(3, 1)] = 1;
    myMap[18][std::pair<int, int>(-3, 1)] = 1;
    myMap[18][std::pair<int, int>(2, 2)] = 1;
    myMap[18][std::pair<int, int>(-2, 2)] = 1;
    myMap[18][std::pair<int, int>(1, 3)] = 1;
    myMap[18][std::pair<int, int>(-1, 3)] = 1;
    myMap[18][std::pair<int, int>(0, 4)] = 1;
    myMap[18][std::pair<int, int>(6, 0)] = 0.875;
    myMap[18][std::pair<int, int>(-6, 0)] = 0.875;
    myMap[18][std::pair<int, int>(5, 1)] = 0.5;
    myMap[18][std::pair<int, int>(-5, 1)] = 0.5;
    myMap[18][std::pair<int, int>(4, 2)] = 0.125;
    myMap[18][std::pair<int, int>(-4, 2)] = 0.125;

    myMap[19][std::pair<int, int>(0, 0)] = 1;
    myMap[19][std::pair<int, int>(2, 0)] = 1;
    myMap[19][std::pair<int, int>(-2, 0)] = 1;
    myMap[19][std::pair<int, int>(1, 1)] = 1;
    myMap[19][std::pair<int, int>(-1, 1)] = 1;
    myMap[19][std::pair<int, int>(0, 2)] = 1;
    myMap[19][std::pair<int, int>(4, 0)] = 1;
    myMap[19][std::pair<int, int>(-4, 0)] = 1;
    myMap[19][std::pair<int, int>(3, 1)] = 1;
    myMap[19][std::pair<int, int>(-3, 1)] = 1;
    myMap[19][std::pair<int, int>(2, 2)] = 1;
    myMap[19][std::pair<int, int>(-2, 2)] = 1;
    myMap[19][std::pair<int, int>(1, 3)] = 1;
    myMap[19][std::pair<int, int>(-1, 3)] = 1;
    myMap[19][std::pair<int, int>(0, 4)] = 1;
    myMap[19][std::pair<int, int>(6, 0)] = 0.9375;
    myMap[19][std::pair<int, int>(-6, 0)] = 0.9375;
    myMap[19][std::pair<int, int>(5, 1)] = 0.6875;
    myMap[19][std::pair<int, int>(-5, 1)] = 0.6875;
    myMap[19][std::pair<int, int>(4, 2)] = 0.3125;
    myMap[19][std::pair<int, int>(-4, 2)] = 0.3125;
    myMap[19][std::pair<int, int>(3, 3)] = 0.0625;
    myMap[19][std::pair<int, int>(-3, 3)] = 0.0625;

    myMap[20][std::pair<int, int>(0, 0)] = 1;
    myMap[20][std::pair<int, int>(2, 0)] = 1;
    myMap[20][std::pair<int, int>(-2, 0)] = 1;
    myMap[20][std::pair<int, int>(1, 1)] = 1;
    myMap[20][std::pair<int, int>(-1, 1)] = 1;
    myMap[20][std::pair<int, int>(0, 2)] = 1;
    myMap[20][std::pair<int, int>(4, 0)] = 1;
    myMap[20][std::pair<int, int>(-4, 0)] = 1;
    myMap[20][std::pair<int, int>(3, 1)] = 1;
    myMap[20][std::pair<int, int>(-3, 1)] = 1;
    myMap[20][std::pair<int, int>(2, 2)] = 1;
    myMap[20][std::pair<int, int>(-2, 2)] = 1;
    myMap[20][std::pair<int, int>(1, 3)] = 1;
    myMap[20][std::pair<int, int>(-1, 3)] = 1;
    myMap[20][std::pair<int, int>(0, 4)] = 1;
    myMap[20][std::pair<int, int>(6, 0)] = 0.96875;
    myMap[20][std::pair<int, int>(-6, 0)] = 0.96875;
    myMap[20][std::pair<int, int>(5, 1)] = 0.8125;
    myMap[20][std::pair<int, int>(-5, 1)] = 0.8125;
    myMap[20][std::pair<int, int>(4, 2)] = 0.5;
    myMap[20][std::pair<int, int>(-4, 2)] = 0.5;
    myMap[20][std::pair<int, int>(3, 3)] = 0.1875;
    myMap[20][std::pair<int, int>(-3, 3)] = 0.1875;
    myMap[20][std::pair<int, int>(2, 4)] = 0.03125;
    myMap[20][std::pair<int, int>(-2, 4)] = 0.03125;

    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);

    scanf("%d", &T);

    for (int F=0; F<T; F++){
        scanf("%d%d%d", &n, &x, &y);
        printf("Case #%d: ", F + 1);
        if (myMap.count(n) && myMap[n].count(std::pair<int, int>(x, y)))    printf("%lf\n", myMap[n][std::pair<int, int>(x, y)]);
        else    puts("0.000000");
    }
}
