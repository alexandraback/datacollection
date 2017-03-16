#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int calculate(int A, int B);

int main(int argc, char *argv[])
{
    ifstream fin;
    ofstream fout;
    int number_of_test_cases, number_A, number_B, total_recycled;
    fin.open("Csmallattempt.in");
    fout.open("answerSmall.in");
    fin>>number_of_test_cases;
    for(int i=0; i <number_of_test_cases; i++)
    {
        fin>>number_A>>number_B;
        total_recycled = calculate(number_A, number_B);
        fout<<"Case #"<<(i+1)<<": "<<total_recycled<<endl;
        //cout<<"Case #"<<(i+1)<<": "<<total_recycled<<endl;
    }
    fin.close();
    fin.clear();
    fout.close();
    fout.clear();
    system("PAUSE");
    return EXIT_SUCCESS;
}

int calculate(int A, int B)
{
    int total = 0;
    int start, end;
    int stemp, etemp;
    int rolls = (int)log10(A);
    double temp = pow(10.,rolls);
    int rolls_power_ten = (int)temp;
    
    for(; A < B ; A++)
    {
        start = A;
        end = start + 1;
        for(; end <= B; end++)
        {
            start = A;
            for(int i=0; i<rolls; i++)
            {
                start = (start%rolls_power_ten*10) + (start/rolls_power_ten);
                if(start == end)
                {
                    total++;
                    break;
                }
            }
        }
    }
    return total;
}
