#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    string const nomFichier("C:/test/scores.txt");
    string const aa("C:/test/data.txt");
    ifstream fin(aa.c_str());
    ofstream fout(nomFichier.c_str());

    int T;

    fin >> T;
    for (int t=0;t<T;t++)
    {  bool resultat=false;
        cout << endl << "T= " << t << endl;
                int c[50][50]={0};
                int cloture[50][50]={0};
                int v[50]={0};
        int N;
        fin >> N;
        for (int i=0;i<N;i++)
            {

                int M;
                fin >> M;
                v[i]=M;
                for (int j=0;j<M;j++)
                {

                    fin >>  c[i][j];

                }
            }

        for (int i=0;i<N;i++)
        {
            if (v[i]>1)
            {
                for (int k=0;k<v[i];k++)
                {
                    int kk=c[i][k];
                    { // fabriquer la cloture de kk (voisin de i
                        cloture[kk-1][kk-1]=1;
                        int r=1;
                        int bord[50]={0};
                        bord[kk-1]=1;
                        while (r==1)
                        {
                            for (int j=0;j<50;j++)
                            {
                                if (bord[j]!=0)
                                {
                                    bord[j]=0;
                                    for (int a=0;a<v[j];a++)
                                    {
                                        cloture[kk-1][c[j][a]-1]=1;
                                        bord[c[j][a]-1]=1;
                                    }
                                }
                            }
                            r=0;
                            for (int z=0;z<50;z++)
                            {
                                if (bord[z]==1) {r=1;}
                            }

                        }
                 //   cout << endl << "Cloture de kk= " << kk << " : ";
                 /*   for (int y=0;y<50;y++)
                    {
                        cout << cloture [kk-1][y] << " ";
                    }*/
                    }
                }

                { // verifie qu'on ai pas une inheritance.
                        int bigboard[50]={0};
                    //   cout << endl << "bigboard: " ;
                    for (int q=0;q<50;q++)
                    {

                        for (int w=0;w<v[i];w++)
                        {
                             bigboard[q]=bigboard[q]+cloture[c[i][w]-1][q];

                        }
                      //  cout <<  bigboard[q] << " ";
                    }
                    for (int q=0;q<50;q++)
                    {
                        if (bigboard[q]>=2) {resultat=true;}
                    }

                }

            }






        }
    if (resultat) {fout << "Case #" << t+1 <<": " << "Yes" << endl;}
    else {fout << "Case #" << t+1 <<": " << "No" << endl;}
    }




    return 0;
}
