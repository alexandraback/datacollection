#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

void print_board(vector<vector<bool> > table)
{
    for(int i=0; i<table.size();i++)
    {
        for(int j=0; j<table[i].size();j++)
        {
            if(i==0&&j==0)
            {
                cout << "c";
            }
            else if(table[i][j])
            {
                cout << ".";
            }
            else
            {
                cout << "*";
            }
        }
        cout << "\n";
    }
}

void mines()
{
    int nb_case;
    cin >> nb_case;

    vector<vector<bool> > table;

    vector<bool> tmp;

    int N, carre;

    int Ccarre, Rcarre;
    bool possible;
    int rempli;

    int  C, R, M;
    for(int i=0; i<nb_case; i++)
    {
        cin >> R;
        cin >> C;
        cin >> M;

        N = C*R-M;
        rempli = 0;

        table.clear();
        tmp.clear();

        possible = false;


        table.resize( R , vector<bool>( C , false ) );
        if(C!=1&&R!=1)
        {
            carre = (int)sqrt((float)N);
            if(carre<C&&carre<R&&carre>=2)
            {
                Ccarre = carre;
                Rcarre = carre;
                if((Rcarre+1)*Ccarre<=N&&Rcarre<R)
                {
                    Rcarre++;
                }
                if((Ccarre+1)*Rcarre<=N&&Ccarre<C)
                {
                    Ccarre++;
                }
            }
            else if(carre >=C)
            {
                Ccarre = C;
                Rcarre = carre;
                while(Rcarre*Ccarre<=N)
                {
                    Rcarre++;
                }
                Rcarre--;
            }
            else if(carre >=R)
            {
                Ccarre = carre;
                Rcarre = R;
                while(Rcarre*Ccarre<=N)
                {
                    Ccarre++;
                }
                Ccarre--;
            }
            else if(carre<2)
            {
                Ccarre=0;
                Rcarre=0;
            }

            rempli = Rcarre*Ccarre;

            for(int j=0; j<Rcarre; j++)
            {
                for(int k=0; k<Ccarre; k++)
                {
                    table[j][k] = true;
                }
            }
            //cout << "rempli : " << rempli << "N = " << N << "\n";
            if(rempli+1==N&&Ccarre>2&&Rcarre>2)
            {
                rempli--;
                table[Rcarre-1][Ccarre-1] = false;
            }

            if(Ccarre<C&&carre>=2)
            {
                for(int j=1; j<Rcarre; j++)
                {
                    if(rempli<N)
                    {
                        if(j==1)
                        {
                            table[0][Ccarre] = true;
                            rempli++;
                        }
                        table[j][Ccarre] = true;
                        rempli++;
                    }
                }
            }
            if(Rcarre<R&&carre>=2)
            {
                for(int j=1; j<Ccarre; j++)
                {
                    if(rempli<N)
                    {
                        if(j==1)
                        {
                            table[Rcarre][0] = true;
                            rempli++;
                        }
                        table[Rcarre][j] = true;
                        rempli++;
                    }
                }
            }
            if(rempli==N||N==1)
            {
                possible = true;
            }
        }
        else if(C==1)
        {
            if(M<R)
            {
                for(int j=0;j<N;j++)
                {
                    table[j][0] = true;
                }
                possible = true;
            }
        }
        else if(R==1)
        {
            if(M<C)
            {
                for(int j=0;j<N;j++)
                {
                    table[0][j] = true;
                }
                possible = true;
            }
        }
        cout << "Case #" << i+1 << ":\n";
        if(possible)
        {
            print_board(table);
        }
        else
        {
            cout << "Impossible\n";
        }

    }
}

int main()
{
    mines();
    return 0;
}


