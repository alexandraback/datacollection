#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits>


using namespace std;

int main() {

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int T;

	fin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int R, C, M;
        fin >> R >> C >> M;

        // Test info received
        // Output


        vector<vector<bool> > matrix;
        vector<bool> emptyVector;
        for (int i = 0; i < C; ++i)
        {
            emptyVector.push_back(false);
        }
        for (int i = 0; i < R; ++i)
        {
            matrix.push_back(emptyVector);
        }

        fout << "Case #" << t << ": ";

        if ((R * C - M == 2 || R * C - M == 3 || R * C - M == 5 || R * C - M == 7) && R != 1 && C != 1)
        {

            /*if (M == 1 && R * C - M != 5)
            {
                for (int i = 0; i < R; ++i)
                    for (int j = 0; j < C; ++j)
                        matrix[i][j] = true;
                matrix[R - 1][C - 1] = false;

                fout << endl;

                for (int i = 0; i < R; ++i)
                {
                    for (int j = 0; j < C; ++j)
                    {
                        if (i == 0 && j == 0)
                        {
                            fout << 'c';
                        }
                        else if (matrix[i][j] == true)
                        {
                            fout << '.';
                        }
                        else
                        {
                            fout << '*';
                        }
                    }
                    fout << endl;
                }
            }
            else*/
            {
                fout << "\nImpossible" << endl;
            }
        }
        else
        {
            if (M == 1 && (C == 2 || R == 2) && (C != 1 && R != 1))
            {
                fout << "\nImpossible" << endl;
                goto EXIT;
            }

            if (M % 2 == 1 && (C == 2 || R == 2))
            {
                fout << "\nImpossible" << endl;
                goto EXIT;
            }

            fout << endl;
            int dotsCounter = R * C - M;

            // filling matrix

            if (R == 1 || C == 1)
            {
                for (int i = 0; i < R; ++i)
                {
                    for (int j = 0; j < C; ++j)
                    {
                        matrix[i][j] = true;
                        dotsCounter--;
                        if (dotsCounter == 0)
                            goto PRINT_MATRIX;
                    }
                }
            }
            else
            {
                if (dotsCounter % 2 == 0)
                {
                    // base
                    matrix[0][0] = true;
                    matrix[0][1] = true;
                    matrix[1][0] = true;
                    matrix[1][1] = true;
                    dotsCounter -= 4;
                    if (dotsCounter == 0)
                        goto PRINT_MATRIX;

                    int level = 0;
                    int x = 1;
                    int y = 1;
                    while (true)
                    {
                        while (x + 1 < C)
                        {
                            matrix[level * 2][x + 1] = true;
                            matrix[level * 2 + 1][x + 1] = true;
                            x++;
                            dotsCounter -= 2;
                            if (dotsCounter == 0)
                                goto PRINT_MATRIX;
                        }
                        if ((level + 1) * 2 + 1 < R)
                        {
                            level++;
                            if (dotsCounter == 2)
                            {
                                matrix[level * 2][0] = true;
                                matrix[level * 2][1] = true;
                                goto PRINT_MATRIX;
                            }
                            else
                            {
                                matrix[level * 2][0] = true;
                                matrix[level * 2][1] = true;
                                matrix[level * 2 + 1][0] = true;
                                matrix[level * 2 + 1][1] = true;
                                x = 1;
                                y = 1;
                                dotsCounter -= 4;
                                if (dotsCounter == 0)
                                    goto PRINT_MATRIX;
                            }
                        }
                        else
                        {
                            for (int i = 0; i < dotsCounter; ++i)
                            {
                                matrix[R - 1][i] = true;
                            }
                            goto PRINT_MATRIX;
                        }
                    }
                }
                else
                {
                    if (dotsCounter == 1)
                    {
                        matrix[0][0] = true;
                        goto PRINT_MATRIX;
                    }
                    if (M == 1)
                    {
                        cout << "STRANGE" << endl;
                        for (int i = 0; i < R; ++i)
                            for (int j = 0; j < C; ++j)
                                matrix[i][j] = true;
                        matrix[R - 1][C - 1] = false;
                        goto PRINT_MATRIX;
                    }

                    // base
                    for (int i = 0; i < 3; ++i)
                        for (int j = 0; j < 3; ++j)
                            matrix[i][j] = true;

                    dotsCounter -= 9;
                    if (dotsCounter == 0)
                        goto PRINT_MATRIX;

                    // move to right
                    int x = 2;
                    while (x + 1 < C)
                    {
                        matrix[0][x + 1] = true;
                        matrix[1][x + 1] = true;
                        x++;
                        dotsCounter -= 2;
                        if (dotsCounter == 0)
                            goto PRINT_MATRIX;
                    }
                    // move to down
                    int y = 2;
                    while (y + 1 < R)
                    {
                        matrix[y + 1][0] = true;
                        matrix[y + 1][1] = true;
                        y++;
                        dotsCounter -= 2;
                        if (dotsCounter == 0)
                            goto PRINT_MATRIX;
                    }

                    // linear move
                    while (dotsCounter > 0)
                    {
                        for (int i = 2; i < R; ++i)
                        {
                            for (int j = 2; j < C; ++j)
                            {
                                if (i != 2 || j != 2)
                                {
                                    matrix[i][j] = true;
                                    dotsCounter--;
                                    if (dotsCounter == 0)
                                        goto PRINT_MATRIX;
                                }
                            }
                        }
                    }
                }
            }


            PRINT_MATRIX:
            // matrix output

            for (int i = 0; i < R; ++i)
            {
                for (int j = 0; j < C; ++j)
                {
                    if (i == 0 && j == 0)
                    {
                        fout << 'c';
                    }
                    else if (matrix[i][j] == true)
                    {
                        fout << '.';
                    }
                    else
                    {
                        fout << '*';
                    }
                }
                fout << endl;
            }
        }
        EXIT:
        int a = 2;
    }

	fin.close();
	fout.close();

	return 0;
}
