#include <algorithm>
#include <fstream>
#include <vector>


int main()
{
    std::ifstream fin("input.txt");
    size_t T;
    fin >> T;
    std::vector<size_t> answers(T);
    size_t D;
    std::vector<size_t> eaters;
    size_t minutes;
    for (size_t i = 0; i < T; ++i)
    {
        fin >> D;
        eaters.resize(D);
        for (size_t j = 0; j < D; ++j)
        {
            fin >> eaters[j];
            if (eaters[j] > answers[i])
            {
                answers[i] = eaters[j];
            }
        }
        for (size_t j = 1; j < answers[i]; ++j)
        {
            minutes = 0;
            for (size_t eater : eaters)
            {
                if (eater > j)
                {
                    minutes += eater / j;
                    if (eater % j == 0)
                    {
                        --minutes;
                    }
                }
            }
            if (j + minutes < answers[i])
            {
                answers[i] = j + minutes;
            }
        }
    }
    fin.close();
    std::ofstream fout("output.txt");
    for (size_t i = 0; i < T; ++i)
    {
        fout << "Case #" << i + 1 << ": " << answers[i] << std::endl;
    }
    fout.close();
    return 0;
}
