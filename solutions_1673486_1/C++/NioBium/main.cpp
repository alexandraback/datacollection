#include <iostream>

using namespace std;

#include <fstream>
int main()
{
    ifstream infile("q1.in");
    ofstream outfile("q2.out");
    unsigned  T;
    infile >> T;

    cout << T << "\n";

    signed long A,B;
    double p;
    double c_keep, c_enter, c_bk;
    double q;
    signed long bk; // number of backspaces, 0 keep, -1 enter
    double ebk, pebk;
    for (unsigned  i = 0; i<T; i++)
    {
        if (i>0) outfile << "\n";

        infile >> A >> B;
        cout << i << "\t" << A  << "\t" << B << "\n";
        q=1;
        bk = A;
        c_bk = B+10;
        for (long j=0;j<A;j++)
        {
             infile >> p;

             q *= p;
             pebk = q*(B-A+1+2*(A-1-j))+(1-q)*(2*B-A+2*(A-1-j)+2);
        //     cout << "j = " << j << "\tp=" << p << "\tq=" << q << "\tpebk=" << pebk<<"\n" ;

             if (c_bk > pebk)
             {
                 c_bk = pebk;
                 bk = A-1-j;
             }
        }
        outfile.setf(ios_base::fixed);
        outfile.precision(7);
        outfile << "Case #" << i+1 << ": " <<  (double)((c_bk < (B+2)) ? c_bk : (double)(B+2));

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


