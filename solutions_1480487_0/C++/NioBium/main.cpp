#include <iostream>

using namespace std;

#include <fstream>
int main()
{
    ifstream infile("q1.in");
    ofstream outfile("q2.out");
    unsigned long T;
    infile >> T;

    cout << "T=" << T << "\n";

    signed int N,M;
    double a[200],y[200];
    int ind[200];
    double sum=0,frac;
    outfile.setf(ios_base::fixed);
    outfile.precision(7);

    for (unsigned long i = 0; i<T; i++)
    {
        if (i>0) outfile << "\n";

        infile >>N;
        sum=0;

        M=N;
        for (int j=0;j<N;j++)
        {
            infile >> a[j];
            sum+=a[j];
            ind[j]=j;
        }
        for (int j=0;j<N;j++)
          for (int k=0;k<N-1;k++)
             {
                 if (a[ind[k]]<a[ind[k+1]])
                 {
                     ind[k]=ind[k]+ind[k+1];
                     ind[k+1]=ind[k]-ind[k+1];
                     ind[k]=ind[k]-ind[k+1];
                 }
             }

        outfile << "Case #" << i+1 << ": ";
        int j=0;
        frac=2;
        M=N;
        while ((j<N) && (a[ind[j]]/sum>((double)frac/M)))
        {
            y[ind[j]]=0;
            M--;
            frac -= a[ind[j]]/sum;
            j++;
        }
        while (j<N)
        {
            y[ind[j]]=frac/M-a[ind[j]]/sum;
            j++;
        }

        for (int j=0;j<N;j++)
        {
            outfile << (double)(100*y[j]) << " ";
        }

    }
    infile.close();
    outfile.close();

    return 0;
}
/*
void quicksort(*int array, int length)
{
    if (length<=1)
          return array;  // an array of zero or one elements is already sorted

/*      select and remove a pivot value 'pivot' from 'array'
      create empty lists 'less' and 'greater'
      for each 'x' in 'array'
          if 'x' <= 'pivot' then append 'x' to 'less'
          else append 'x' to 'greater'
      return concatenate(quicksort('less'), 'pivot', quicksort('greater')) // two recursive calls

      */


