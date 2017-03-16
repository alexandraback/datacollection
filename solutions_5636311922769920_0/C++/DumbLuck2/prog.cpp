#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
//#include <iomanip>
using namespace std;

template <class X>
void printArray(X a[], int len);


long long answer[100];
int visited[100];
int size;
int K, C, S;//Number of tiles in original, complexity, number of cleaners



void getAnswer(int complexity, long long toAdd)
{
    //cout << "complexity = " << complexity << endl;
    //cout << "toAdd = " << toAdd << endl;

    for(int i = 0; i < K; i++)
    {

        if(visited[i] == 0)
        {
            visited[i] = 1;
            if(complexity == 1)
                answer[size++] = (toAdd-1)*K + i+1;
            else
            {
                getAnswer(complexity-1, (toAdd-1)* K + i + 1);
            }
            //cout << "size = " << size << endl;
            return;
        }
    }


    //cout << "while active\n";
    //cout << "complexity = " << complexity << endl;
    while(complexity != 0)
    {
        toAdd = toAdd*K;//Go right
        complexity--;
        //cout << "ToAdd = " << toAdd << endl;
    }

    answer[size++] = toAdd;




}

int main()
{
    //fstream fin("ABtest.in", ios::in);

    fstream fin("D-small-attempt1.in", ios::in);
    //fstream fin("B-large.in", ios::in);

    fstream fout("Output.out", ios:: out);

    int T;
    fin >> T;
    for(int TC = 1; TC <= T; TC++)
    {
        fout << "Case #" << TC << ": ";


        fin >> K >> C >> S;


       size = 0;

       for(int i = 0; i < 100; i++)
            visited[i] = 0;

        for(int i = 0; i < K; i++)
        {
            if(visited[i] == 0)
            {
                getAnswer(C, 1);
            }
        }


        if(size > S)
            fout << "IMPOSSIBLE\n";
        else
        {
            fout << answer[0];
            for(int i = 1; i < size; i++)
                fout << " " << answer[i];
            fout << endl;
        }


        /*for(int i = K; i > 1; i--)
            fout << i << " ";
        fout << endl;*/
    }
    fout.close();
    fin.close();

    return 0;
}


template <class X>
void printArray(X a[], int len)
{
    for(int i = 0; i < len; i++)
        cout << a[i] << " ";
    cout <<  endl;
}
