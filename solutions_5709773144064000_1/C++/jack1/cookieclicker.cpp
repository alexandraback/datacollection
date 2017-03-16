#include <iostream>

static const double INITIAL_SPEED = 2.0;

double get_time(double c, double f, double x)
{
    double result = 0.0;
    double speed = INITIAL_SPEED;
    while (true)
    {
        const double time_to_finish = x / speed;
        const double time_to_buy = c / speed;
        const double time_to_finish_with_buy = time_to_buy + x / (speed + f);
        if (time_to_finish <= time_to_finish_with_buy)
        {
            result += time_to_finish;
            break;
        }
        else
        {
            result += time_to_buy;
            speed += f;
        }
    }
    return result;
}

int main()
{


    std::cout.precision(10);
    std::cout.setf( std::ios::fixed, std:: ios::floatfield ); // floatfield set to fixed

    int no_test_cases;
    std::cin >> no_test_cases;
    
    //debug
    //std::cout << no_test_cases << std::endl;
    
    for (int i = 1; i <= no_test_cases; i++)
    {
        double c, f, x;
        std::cin >> c >> f >> x;
        //debug
        //std::cout << c << " " << f << " " << x << std::endl;
        const double time = get_time(c, f, x);
        std::cout << "Case #" << i << ": " << time << std::endl;
    }
    
    return 0;
    
}
