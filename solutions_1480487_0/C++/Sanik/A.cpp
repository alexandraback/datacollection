#include<iostream>
#include<fstream>
#include <iomanip>
using namespace std;

ifstream fin("A.in");
ofstream fout("A.out");

int J[200];

int main()
{
    int T;
    fin >> T;
    for(int i=0;i<T;i++)
    {
        int N;
        fin >> N;
        int SUM = 0;
        for(int j=0;j<N;j++)
        {
            fin >> J[j];
            SUM+=J[j];
        }
        double AVG = 2.0*(double)SUM/(double)N;
        //cout << AVG << endl;
        int count = 0;
        int newSUM = 0;
        for(int j=0;j<N;j++)
            if(AVG>(double)J[j])
            {
                count++;
                newSUM += J[j];
            }
        double newAVG = ((double)newSUM+(double)SUM)/(double)count;
        fout << "Case #" << i+1 << ": ";
        for(int j=0;j<N;j++)
        {
            if(AVG>(double)J[j])
            {
                if(j==N-1)
                    fout << setprecision(6) << fixed << (newAVG-(double)J[j])/(double)SUM*100.0;
                else
                    fout << setprecision(6) << fixed << (newAVG-(double)J[j])/(double)SUM*100.0 << " ";
            }
            else 
            {
                if(j==N-1)
                    fout << setprecision(6) << fixed << 0;
                else
                    fout << setprecision(6) << fixed << 0 << " ";
            }
        }
        fout << endl;
    }
    system("pause");
}
