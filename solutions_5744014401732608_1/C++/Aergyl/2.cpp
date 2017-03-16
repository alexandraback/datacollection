#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <math.h>


using namespace std;


const bool OUTPUT_TO_FILE = true;


//Constants:


//IO variables:
int t_in;
int b_in;
long m_in;
string s_in;
stringstream out;


//Other global variables:
int b_matrix[50][50];
bool possible;
long alt;
long alts[50];




void setup()
{
    
}

void reset_variables()
{
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            if (i < j)
            {
                b_matrix[i][j] = 1;
            }
            else
            {
                b_matrix[i][j] = 0;
            }
        }
    }
}

void do_the_real_deal()
{
    cin >> b_in >> m_in;

    alt = pow(2, b_in - 2);

    if (m_in > alt)
    {
        possible = false;
        out << "IMPOSSIBLE\n";
        return;
    }
    else
    {
        possible = true;
        out << "POSSIBLE\n";
    }


    alts[b_in - 1] = 1;
    for (int i = 2; i < b_in; i++)
    {
        alts[b_in - i] = pow(2, i - 2);
    }

    alt -= m_in;
    int idx = 1;

    while (alt > 0)
    {
        if (alt >= alts[idx])
        {
            alt -= alts[idx];
            b_matrix[0][idx] = 0;
        }

        idx++;
    }
}

void add_answer_to_output()
{
    for (int i = 0; i < b_in; i++)
    {
        for (int j = 0; j < b_in; j++)
        {
            out << b_matrix[i][j];
        }
        out << "\n";
    }
}





void print_output()
{
	if (OUTPUT_TO_FILE)
	{
		ofstream output_file;
		output_file.open("out.txt");
		output_file << out.rdbuf();
		output_file.close();
	}
	else
	{
		cout << out.rdbuf();
	}
}

int main()
{
    cout.sync_with_stdio(false);
    setup();
    cout << "Setup finished.\n";

	cin >> t_in;
	for (int run = 1; run <= t_in; run++)
	{
        reset_variables();

        out << "Case #" << run << ": ";
        do_the_real_deal();
        if (possible)
        {
            add_answer_to_output();
        }
	}

    print_output();
}
