#include <iostream>
#include <iomanip>
#include <map>
#include <cfloat>

const double InitialRate = 2.0;

double CalculateTimeToGoal(std::map<int, double> & TimeToFarmMap,
                           int Farms, double C, double F, double X)
{
    double Rate;
    double TimeToFarms = 0;

    if (Farms > 0)
    {
        Rate = (InitialRate + (Farms - 1)*F);
        TimeToFarms = TimeToFarmMap[Farms - 1] +  C/Rate;
    }

    Rate = (InitialRate + Farms*F);
    TimeToFarmMap[Farms] = TimeToFarms;


    return TimeToFarms + X/Rate;
}

int main()
{
    int T;

    std::cin >> T;


    for (int idx = 1; idx <= T; idx ++)
    {
        std::map<int, double> TimeToFarmMap;

        TimeToFarmMap[0] = 0;
        
        double C, F, X;

        std::cin >> C; // Cost of a farm
        std::cin >> F; // Production gain of 1 farm
        std::cin >> X; // Goal cookies

        int NumFarms = 0;
        double PreviousTime = DBL_MAX;
        double CurrentTime;

        while(true)
        {
            CurrentTime = CalculateTimeToGoal(TimeToFarmMap, NumFarms++, C, F, X);

            if (CurrentTime > PreviousTime)
            {
                break;
            }

            PreviousTime = CurrentTime;
        }

        std::cout << "Case #" << idx << ": " 
                  << std::fixed << std::setprecision(7) 
                  << PreviousTime << std::endl;
    }

    return 0;
}