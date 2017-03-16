#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


using namespace std;


const bool OUTPUT_TO_FILE = true;


//Constants:


//IO variables:
int t_in;
int n1;
int n2;
int n3;
int k_in;
string s_in;
stringstream out;
stringstream out2;


//Other global variables:
int used_pairs[32][32];
bool used_triple[32][32][32];
int ans;




void setup()
{
    
}

void reset_variables()
{
    for (int i = 0; i < 32; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            used_pairs[i][j] = 0;

            for (int k = 0; k < 32; k++)
            {
                used_triple[i][j][k] = false;
            }
        }
    }
    ans = 0;
}

void do_the_real_deal()
{
    cin >> n1 >> n2 >> n3 >> k_in;

    for (int k = 21; k <= n3 + 20; k++)
    {
        for (int j = 11; j <= n2 + 10; j++)
        {
            for (int i = 1; i <= n1; i++)
            {
                if (used_pairs[i][j] < k_in && used_pairs[i][k] < k_in && used_pairs[j][k] < k_in)
                {
                    used_triple[i][j][k] = true;
                    used_pairs[i][j]++;
                    used_pairs[i][k]++;
                    used_pairs[j][k]++;
                    ans++;
                    out2 << i << " " << j - 10 << " " << k - 20 << "\n";
                }
            }
        }
    }
}

void add_answer_to_output()
{
    out << out2.rdbuf();
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
        do_the_real_deal();

        out << "Case #" << run << ": " << ans << "\n";
        add_answer_to_output();
	}

    print_output();
}
