#include <iostream>

using namespace std;

#include <fstream>
int main()
{
    ifstream infile("q2.in");
    ofstream outfile("q2.out");
    unsigned int T;
    infile >> T;

    cout << T << "\n";

    unsigned int N;//1000
    signed int* a = new int[1001];
    signed int* b = new int[1001];
    signed short* c = new short[1001];
    signed int stars = 0;
    signed int counter;
    signed int games = 0;
    signed int j = 0;
    signed int infty = 3000;
    a[1000]=-1;
    b[1000]=-1;
    int maxa, maxb1,maxb2;
    for (unsigned int i = 0; i<T; i++)
    {
        if (i>0) outfile << "\n";

        infile >> N;
        for (long j=0;j<N;j++)
        {
            infile>>a[j]>>b[j];
            c[j]=0;
        }
        stars = 0;
        //counter = N*2;
        games = 0;
        //j = 0;

        while (stars < 2*N)
        {
            maxa = 1000;
            maxb1 = 1000;
            maxb2 = 1000;
            for (int j=0;j<N;j++)
            {
                if ((a[j] <= stars) && (b[maxa] < b[j]) && (c[j] < 1)) maxa = j;
                if ((b[j] <= stars) && (b[maxb1] < b[j]) && (c[j] < 2)) maxb1 = j;
                if ((b[j] <= stars) && (b[maxb2] < b[j]) && (c[j] < 1)) maxb2 = j;
            }

            if (maxb2<1000)
            {
                games++;
                c[maxb2]=2;
                stars+=2;
                cout << maxb2 << "\t";
            }
            else if (maxb1<1000)
            {
                games++;
                c[maxb1]=2;
                stars++;
                cout << maxb1 << "\t";
            }
            else if (maxa<1000)
            {
                games++;
                c[maxa]=1;
                stars++;
                cout << maxa << "\t";
            }
            else
                break;
        }

        if (stars < 2*N)
            outfile << "Case #" << i+1 << ": Too Bad";
        else
        outfile << "Case #" << i+1 << ": " << games;
        /*
        while ((counter>0) && (stars<2*N))
        {
            cout << "j=" <<j<<"\n";

            counter--;
            if (counter>=N)
            {
                if (b[j]<=stars)
                {
                    games++;
                    counter = N*2;
                    b[j]=infty;
                    if(a[j]<infty)
                    {
                        stars+=2;
                        a[j]=infty;
                    }
                    else
                        stars++;
                }

            }
            else
            {
                if (a[j]<=stars)
                {
                    a[j]=infty;
                    stars++;
                    games++;
                    counter = N*2;
                }
            }

            j = (j+1) % N;
        }

        if (counter == 0 )
            outfile << "Case #" << i+1 << ": Too Bad";
        else
            outfile << "Case #" << i+1 << ": " << games;
        */

    }
    infile.close();
    outfile.close();
    cout << "done\n";
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


