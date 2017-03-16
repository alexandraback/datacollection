#include <algorithm>
#include <fstream>
#include <vector>


int main()
{
    std::ifstream fin("input.txt");
    size_t T;
    fin >> T;
    std::vector<bool> answers(T);
    size_t X, R, C;
    for (size_t i = 0; i < T; ++i)
    {
        fin >> X >> R >> C;
        answers[i] = (R * C % X != 0) || (X == 3 && (R == 1 || C == 1)) || (X == 4 && (R <= 2 || C <= 2));
    }
    fin.close();
    std::ofstream fout("output.txt");
    for (size_t i = 0; i < T; ++i)
    {
        fout << "Case #" << i + 1 << ": " << (answers[i] ? "RICHARD" : "GABRIEL") << std::endl;
    }
    fout.close();
    return 0;
}
