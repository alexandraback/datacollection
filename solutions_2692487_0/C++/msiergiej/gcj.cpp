#include <fstream>
#include <string>
#include <algorithm>

std::ifstream INPUT;
std::ofstream OUTPUT;

void RunCase();

int main(int argc, char *argv[])
{
    std::string inFileName("test.in");
    std::string outFileName("test.out");
    if (argc == 3)
    {
        inFileName = argv[1];
        outFileName = argv[2];
    }
    INPUT.open(inFileName.c_str());
    OUTPUT.open(outFileName.c_str());
    int noCases;
    INPUT >> noCases;
    for (int i = 0; i < noCases; i++)
    {
        OUTPUT << "Case #" << i + 1 << ": ";
        RunCase();
        OUTPUT << std::endl;
    }
    INPUT.close();
    OUTPUT.close();
    return 0;
}

#include <vector>
std::vector<unsigned int> list;
void ReadList(int size)
{
    list.resize(size);
    for (int i = 0; i < size; i++)
        INPUT >> list[i];
}

void RunCase()
{
    unsigned long long int A, N, y(0);
    INPUT >> A >> N;
    ReadList(N);

    std::sort(list.begin(), list.end());
    while (!list.empty() && list.front() < A) {
        A += list.front();
        list.erase(list.begin());
    }

    unsigned int lSize(list.size());
    if (lSize) {
        if (A > 1) {
            while (!list.empty()) {
                while (list.front() >= A) {
                    A += A - 1;
                    y++;
                }
                if (lSize <= y) {
                    y = lSize;
                    break;
                }
                A += list.front();
                list.erase(list.begin());
                if (lSize > list.size() + y) {
                    lSize = list.size() + y;
                }
            }
        } else {
            y = lSize;
        }
    }

    OUTPUT << y;
}
