/* 
 * File:   main.cpp
 * Author: Alex Ambrose
 *
 * Created on April 27, 2012, 6:10 PM
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>


using namespace std;




int main()
{
    ifstream input("A-large.txt");
    ofstream output("Password_Problem_Output_Large.txt");
    int T;
    input >> T;
    for (int i = 1; i <= T; i++)
    {
        int A, B;
        input >> A;
        input >> B;
        
        double P[A];
        double p_all_right = 1;
        for (int j = 0; j < A; j++)
        {
            input >> P[j];
            p_all_right *= P[j];
        }
        double expected_all_right = (p_all_right * (B - A + 1)) + ((1 - p_all_right) * (B - A + B + 2));
        double expected_enter = B + 2;
        
        double expected_backspace = 3 * B;
        
        for (int j = 1; j <= A; j++)
        {
            double p_right = 1;
            for (int k = 0; k < A-j; k++)
                p_right *= P[k];
            double temp1 = (p_right * (j + B - (A - j) + 1));
            double temp2 = temp1 + ((1 - p_right) * (B + (temp1/p_right) + 1));
            if (temp2 < expected_backspace)
                expected_backspace = temp2;
        }
        output << "Case #" << setiosflags(ios::fixed) << setprecision(6) << i <<": " << min(min(expected_all_right, expected_enter), expected_backspace) << endl;
    }
    input.close();
    output.close();
    return 0;
}

