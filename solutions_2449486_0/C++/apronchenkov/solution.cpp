#include <iostream>
#include <vector>

typedef std::vector< std::vector<int> > LawnPattern;

size_t ReadSize(std::istream* istream)
{
    size_t result;
    if ((*istream) >> result) {
        return result;
    }
    throw std::runtime_error("ReadSize");
}

int ReadInt(std::istream* istream)
{
    int result;
    if ((*istream) >> result) {
        return result;
    }
    throw std::runtime_error("ReadInt");
}


LawnPattern ReadLawnPattern(std::istream* istream)
{
    const size_t height = ReadSize(istream);
    const size_t width = ReadSize(istream);

    LawnPattern result(height, {});
    for (auto& row : result) {
        row.resize(width);
        for (int& item : row) {
            item = ReadInt(istream);
        }
    }
    return result;
}

size_t GetHeight(const LawnPattern& lawn_pattern)
{
    return lawn_pattern.size();
}

size_t GetWidth(const LawnPattern& lawn_pattern)
{
    if (lawn_pattern.empty()) {
        return 0;
    }
    return lawn_pattern.front().size();
}


bool VerifyLawnPattern(const LawnPattern& lawn_pattern)
{
    std::vector<int> row_max(GetHeight(lawn_pattern), 0);
    std::vector<int> column_max(GetWidth(lawn_pattern), 0);

    for (size_t i = 0; i < row_max.size(); ++i) {
        for (size_t j = 0; j < column_max.size(); ++j) {
            row_max[i] = std::max(row_max[i], lawn_pattern.at(i).at(j));
            column_max[j] = std::max(column_max[j], lawn_pattern.at(i).at(j));
        }
    }

    for (size_t i = 0; i < row_max.size(); ++i) {
        for (size_t j = 0; j < column_max.size(); ++j) {
            if (lawn_pattern.at(i).at(j) < row_max[i] && lawn_pattern.at(i).at(j) < column_max[j]) {
                return false;
            }
        }
    }
    return true;
}


int main()
{
    const int number_of_cases = ReadInt(&std::cin);
    for (int case_no = 1; case_no <= number_of_cases; ++case_no) {
        std::cout << "Case #" << case_no << ": "
                  << (VerifyLawnPattern(ReadLawnPattern(&std::cin)) ? "YES" : "NO") << '\n';
    }
    return 0;
}
