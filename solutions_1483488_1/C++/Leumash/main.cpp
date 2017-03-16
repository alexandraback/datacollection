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
    fin.open("Clarge.in");
    fout.open("answerBig.in");
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
    int rolls = (int)log10(A);
    double temp = pow(10.,rolls);
    int rolls_power_ten = (int)temp;
    int rolled;
    int holding, holding2;
    bool first_is_used;
    
    if((rolls+1)%2)
    {
        for(int finding_recycled_for = A; finding_recycled_for<B; finding_recycled_for++)
        {
            rolled = finding_recycled_for;
            for(int j=0; j<rolls; j++)
            {
                rolled = (rolled%rolls_power_ten*10) + (rolled/rolls_power_ten);
                if((rolled <= B) && (rolled > finding_recycled_for))
                    total++;
            }
        }
    }
    else
    {
        for(int finding_recycled_for = A; finding_recycled_for<B; finding_recycled_for++)
        {
            rolled = finding_recycled_for;
            holding = holding2 = 0;
            first_is_used = false;
            for(int j=0; j<rolls; j++)
            {
                rolled = (rolled%rolls_power_ten*10) + (rolled/rolls_power_ten);
                if((rolled <= B) && (rolled > finding_recycled_for))
                {
                    if((rolled == holding) || (rolled == holding2))
                        ;
                    else
                    {
                        if(!first_is_used)
                        {
                            holding = rolled;
                            first_is_used = true;
                        }
                        holding2 = rolled;
                        total++;
                    }
                }
            }
        }
    }
    return total;
}
