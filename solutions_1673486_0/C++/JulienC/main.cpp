#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_key_correct(int sequence, int keyIndex, int A)
{
    return sequence & (1 << (A - keyIndex - 1));
}

double compute_y(int A, int B, vector<double>& prob)
{
    double keep_typing_expectation = 0.0;
    double *backspace_expectation = new double[A];
    for (int i = 0; i < A; i++)
    {
        backspace_expectation[i] = 0.0;
    }
    for (int i = 0; i < (1<<A); i++)
    {
        //cout << "i: " << i << endl;
        // compute probability to have this sequence
        double sequence_prob = 1.0;
        for (int j = 0; j < A; j++)
        {
            if (is_key_correct(i, j, A))
            {
                sequence_prob *= prob[j];
            }
            else
            {
                sequence_prob *= (1.0 - prob[j]);
            }
        }
        //cout << "sequence_prob: " << sequence_prob << endl;
        if (sequence_prob < 0.000001)
        {
            //cout << "skipping!" << endl;
            continue;
        }

        // keystrokes if I keep typing
        {
            int keep_typing_keystrokes;
            bool correct = i == (1<<A)-1;
            if (correct)
            {
                keep_typing_keystrokes = B - A + 1;
            }
            else
            {
                keep_typing_keystrokes = B - A + 1 + B + 1;
            }
            //cout << "keep typing keystrokes: " << keep_typing_keystrokes << endl;
            keep_typing_expectation += keep_typing_keystrokes * sequence_prob;
        }

        // keystrokes if I press backspace K times
        for (int k = 1; k <= A; k++)
        {
            //cout << "press backspace " << k << " times" << endl;
            int mask = ((1<<A)-1) ^ ((1<<k)-1);
            bool correct = ((i & mask) == mask);
            int backspace_keystrokes;
            if (correct)
            {
                backspace_keystrokes = k + k + B - A + 1;
            }
            else
            {
                backspace_keystrokes = k + k + B - A + 1 + B + 1;
            }
            //cout << "backspace keystrokes: " << backspace_keystrokes << endl;
            backspace_expectation[k-1] += backspace_keystrokes * sequence_prob;
        }
    }
    const double enter_right_away_expectation = 1 + B + 1;
#if 0
    cout << "keep_typing_expectation: " << keep_typing_expectation << endl;
    for (int i = 0; i < A; i++)
    {
        cout << "backspace_expectation[" << (i+1) << "]: " << backspace_expectation[i] << endl;
    }
    cout << "enter_right_away_expectation: " << enter_right_away_expectation << endl;
    cout << endl;
#endif

    double min_expectation = 1e10;
    min_expectation = min(min_expectation, keep_typing_expectation);
    for (int i = 0; i < A; i++)
    {
        min_expectation = min(min_expectation, backspace_expectation[i]);
    }
    min_expectation = min(min_expectation, enter_right_away_expectation);
    delete[] backspace_expectation;
    return min_expectation;
}

void read_file(const string& filename)
{
    ifstream file(filename.c_str());
    if (file.fail())
    {
        cerr << "not a file" << endl;
        exit(1);
    }
    int T; file >> T;
    for (int t = 0; t < T; t++)
    {
        int A, B;
        file >> A >> B;
        vector<double> prob;
        for (int i = 0; i < A; i++)
        {
            double p;
            file >> p;
            prob.push_back(p);
        }
        double y = compute_y(A, B, prob);
        cout.precision(8);
        cout << "Case #" << (t+1) << ": " << fixed << y << endl;
    }
    file.close();
}

int main(int argc, char *argv[])
{
    string filename;
    if (argc == 1)
    {
        filename = "sample.txt";
    }
    else
    {
        filename = argv[1];
    }
    read_file(filename);
    return 0;
}

