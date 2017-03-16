#include <iostream>

using namespace std;

#include <fstream>
int main()
{
    ifstream infile("q1.in");
    ofstream outfile("q2.out");
    unsigned long T;
    infile >> T;

    cout << T << "\n";
    long long s[500];
    short incl[500];
    int N;
    long long sum;
    short num1, num2;
    short found, impossible;
    int j;
    for (unsigned long i = 0; i<T; i++)
    {
        if (i>0) outfile << "\n";

        infile >> N;

        for (int j=0;j<N;j++)
        {
            infile>>s[j];
            incl[j]=-1;
        }

        do
        {
            j=0;
            while ((j<N) && (incl[j]==1))
            {
                incl[j]=-1;j++;
            }
            sum=0;
            impossible = (j==N);
            if (!impossible)
            {
                incl[j]++;
                num1 = 0;
                num2 = 0;
                for(j=0;j<N;j++)
                {
                    sum+=incl[j]*s[j];
                    if (incl[j]==1) num1=1;
                    if (incl[j]==-1) num2=1;
                }
                found = (sum==0) && num1 && num2;
            }
        } while(!impossible && !found);
        outfile << "Case #" << i+1 << ":\n";
        if (impossible)
            outfile << "Impossible";
        else
        {
            for (j=0;j<N;j++)
                if (incl[j]==1) outfile << s[j] << " ";
            outfile << "\n";
            for (j=0;j<N;j++)
                if (incl[j]==-1) outfile << s[j] << " ";
        }
        //outfile << "Case #" << i+1 << ": " <<  (double)((c_bk < (B+2)) ? c_bk : (double)(B+2));

        //outfile.printf("Case #%d %f.6\n",i+1,((c_bk < (B+2)) ? c_bk : (B+2)));
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


