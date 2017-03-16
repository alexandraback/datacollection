#include <fstream>
#include <vector>

int main()
{
    std::ifstream fin("A-large.in.txt");
    size_t T;
    fin >> T;
    std::vector<size_t> answers(T);
    std::string input;
    size_t S_max, people;
    for (size_t i = 0; i < T; ++i)
    {
        fin >> S_max >> input;
        people = 0;
        for (size_t j = 0; j < input.length(); ++j)
        {
            if (people < j)
            {
                answers[i] += j - people;
                people = j;
            }
            people += input[j] - '0';
        }
    }
    fin.close();
    std::ofstream fout("output2.txt");
    for (size_t i = 0; i < T; ++i)
    {
        fout << "Case #" << i + 1 << ": " << answers[i] << std::endl;
    }
    fout.close();
    return 0;
}
