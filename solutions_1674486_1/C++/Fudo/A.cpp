#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

struct GCase
{
    int N;
    vector<vector<int>> M;
    bool Dia(int s)
    {
        vector<int> T;
        T.resize(N,0);
        T[s] = 1;
        stack<int> mq;
        mq.push(s);
        while(!mq.empty())
        {
            int a = mq.top();
            mq.pop();
            for (int i = 0; i < M[a].size(); ++i)
            {
                if (M[a][i] != a)
                {
                    mq.push(M[a][i]);
                    T[M[a][i]] += T[a];
                    if (T[M[a][i]] > 1)
                        return true;
                }
            }
        }
        for (int i = 0; i < N; ++i)
            if (T[i] > 1)
                return true;
        return false;
    }
    bool Dia()
    {
        for (int i = 0; i < N; ++i)
            if (Dia(i))
                return true;
        return false;
    }
};

int g_nCases;
vector<GCase*> g_cases;

void read_input(char* filename)
{
    ifstream fin (filename);
    if (!fin)
    {
        cerr << "Can't open the file " << filename << endl;
        exit(-1);
    }

    fin >> g_nCases;
    for (int i = 0; i < g_nCases; ++i)
    {
        //cout << "Case #" << i+1 << ": " ;
        GCase* gc = new GCase;
        // do sth
        fin >> gc->N;
        gc->M.resize(gc->N);
        for (int j = 0; j < gc->N; ++j)
        {
            int nI;
            fin >> nI;
            for (int k = 0; k < nI; ++k)
            {
                int t;
                fin >> t;
                gc->M[j].push_back(t-1);
            }
        }
        /*T.resize(gc->N+1,0);
        T[1] = 1;
        for (int j = 1; j <= gc->N; ++j)
        {
            int nI;
            fin >> nI;
            for (int k = 0; k < nI; ++k)
            {
                int t;
                fin >> t;
                T[t] += T[j];
            }
        }
        if (T[gc->N] > 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;*/
        g_cases.push_back(gc);
    }
    fin.close();
}

int main(int argc, char**argv)
{
    read_input("A-large.in");
    //read_input("A-small-attempt2.in");
    //read_input("B-large.in");

    ofstream fout("B.out");
    for (int i = 0; i < g_nCases; ++i)
    {
        //g_cases[i]->debugOutput();
        cout << "Case #" << i+1 << ": " ;
        if (g_cases[i]->Dia())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        //cout << g_cases[i]->output << endl;
        //for (int j = 0; j < g_cases[i]->d_size; ++j)
        //{
        //    fout << g_cases[i]->RPI(j) << endl;
        //    /*cout << g_cases[i]->WP(j) << endl;*/
        //    //cout << g_cases[i]->OWP(j) << endl;
        //    //cout << g_cases[i]->OOWP(j) << endl;
        //}
        //int minSteps = calMinSteps(g_BScases[i]);
        //<< minSteps << endl;
    }
    fout.close();
    return 0;
}
