#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
double solveN2(double C, double F, double X)//solve using brutal force
{
    double acc_time_buy_farm = 0.0;

    double last_total_time = X/2.0;
    double rate = 2.0;
    int ansN = 0;//¤É¯Å0¦¸

    while(true)
    {

        acc_time_buy_farm = acc_time_buy_farm+(C/rate);

        /*
#ifndef ONLINE
        cout << "C = " << C << endl << "rate = " << rate << endl;
        cout << "addition update time = " << (C/rate) << endl;
        cout << "total update time = " << acc_time_buy_farm << endl;
#endif // ONLINE*/

        double total_time = acc_time_buy_farm + X/(rate+F);
/*
#ifndef ONLINE
        cout << total_time << endl;
#endif // ONLINE*/

        if(total_time<last_total_time)
        {
            last_total_time = total_time;
            //keep move
            rate = rate+F;
            ansN++;
        }
        else
        {
            break;
        }
    }
    return last_total_time;
}

int main()
{
    int T=0;

    cin >> T;

    for(int ca=0; ca<T; ca++)
    {
        double C,F,X;

        cin >> C >> F >> X;


        printf("Case #%d: %.7f\n",ca+1,solveN2(C,F,X));
    }

}
