#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits>
#include<algorithm>


using namespace std;

int main() {

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int T;

	fin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int N;
        fin >> N;

        vector<double> arrNaomi;
        vector<double> arrKen;

        for (int i = 0; i < N; ++i)
        {
            double number;
            fin >> number;
            arrNaomi.push_back(number);
        }

        for (int i = 0; i < N; ++i)
        {
            double number;
            fin >> number;
            arrKen.push_back(number);
        }

        std::sort(arrNaomi.begin(), arrNaomi.end());
        std::sort(arrKen.begin(), arrKen.end());

        int warScore = 0;
        int decWarScore = 0;

        vector<double> arrNaomi2 = arrNaomi;
        vector<double> arrKen2 = arrKen;

        // calculate war
        for (int i = 0; i < N; ++i)
        {
            double a = arrNaomi[0];
            for (int j = 0; j < N - i; ++j)
            {
                if (arrKen[j] > a)
                {
                    arrNaomi.erase(arrNaomi.begin(), arrNaomi.begin() + 1);
                    arrKen.erase(arrKen.begin() + j, arrKen.begin() + j + 1);
                    break;
                }
                if (j == N - i - 1)
                {
                    arrNaomi.erase(arrNaomi.begin(), arrNaomi.begin() + 1);
                    arrKen.erase(arrKen.begin(), arrKen.begin() + 1);
                    warScore++;
                }
            }
        }

        // calculate decWar

        while (arrNaomi2.size() > 0)
        {
            // сначала поиск слабейших у Наоми которыми она никого не может забрать и их количества
            double b = arrKen2[0];
            int i;
            bool found = false;
            for (i = 0; i < N; ++i)
            {
                if (arrNaomi2[i] > b)
                {
                    found = true;
                    break;
                }
            }
            // затем размен своих слабейших на сильнейших Кена
            if (found)
            {
                arrNaomi2.erase(arrNaomi2.begin(), arrNaomi2.begin() + i);
                arrKen2.erase(arrKen2.end() - i, arrKen2.end());

                // затем использование своего слабейшего которым можно хоть кого-то забрать
                arrNaomi2.erase(arrNaomi2.begin(), arrNaomi2.begin() + 1);
                arrKen2.erase(arrKen2.begin(), arrKen2.begin() + 1);
                decWarScore++;
            }
            else
            {
                break;
            }
        }

        fout << "Case #" << t << ": " << decWarScore << " " << warScore << endl;

    }

	fin.close();
	fout.close();

	return 0;
}
