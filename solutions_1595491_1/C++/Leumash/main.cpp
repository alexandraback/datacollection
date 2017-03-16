#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int calculate(int number_of_googlers, int surprises, int p_goal, int some_googler []);

int main(int argc, char *argv[])
{
    ifstream fin;
    ofstream fout;
    int number_of_test_cases, number_of_googlers, surprises, p_goal, line_goals_met;
    int some_googler[100];
    fin.open("Blarge.in");
    fout.open("answer.in");
    fin>>number_of_test_cases;
    for(int i=0; i <number_of_test_cases; i++)
    {
        fin>>number_of_googlers>>surprises>>p_goal;
        for(int j=0; j<number_of_googlers; j++)
            fin>>some_googler[j];
        line_goals_met = calculate(number_of_googlers, surprises, p_goal, some_googler);
        fout<<"Case #"<<(i+1)<<": "<<line_goals_met<<endl;
        //cout<<"Case #"<<(i+1)<<": "<<line_goals_met<<endl;
    }
    fin.close();
    fin.clear();
    fout.close();
    fout.clear();
    system("PAUSE");
    return EXIT_SUCCESS;
}

int calculate(int number_of_googlers, int surprises, int p_goal, int some_googler [])
{
    int total = 0, automatic_pass = p_goal*3 - 2;
    for(int i=0; i<number_of_googlers; i++)
    {
        if(some_googler[i] >= automatic_pass)
        {
            total++;
        }
        else if((some_googler[i] >= (automatic_pass - 2)) && p_goal > 1 && surprises > 0)
        {
            total++;
            surprises--;
        }
        //else fail =(
    }
    return total;
}
