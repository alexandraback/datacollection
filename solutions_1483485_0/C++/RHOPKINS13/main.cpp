#include <iostream>
#include <string>
using namespace std;

string ConvertToGooglerese(string input);

int main()
{
    int t = 1;
    cin >> t;
    cin.ignore();
    for(int i = 0; i < t; i++)
    {
        string input;
        getline(cin, input);
        cout << "Case #" << i + 1 << ": " << ConvertToGooglerese(input) << endl;
    }

    return 0;
}

string ConvertToGooglerese(string input)
{
    string alpha = "abcdefghijklmnopqrstuvwxyz ";
    string google = "ynficwlbkuomxsevzpdrjgthaq ";
    string output = "";
    for(int i = 0; i < input.length(); i++)
    {
        output = output + alpha[google.find_first_of(input[i])];
    }
    return output;
}
