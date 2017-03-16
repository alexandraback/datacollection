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

    int N;
    int* graph = new int[1001000];
    int* stack = new int[1000000];
    int stacklength=1;
    int visited[1000];
    int di;
    int cur;
    for (unsigned long i = 0; i<T; i++)
    {
        if (i>0) outfile << "\n";
        di = 0;
        infile >> N;
  //      cout << "N=" << N << "\n";
        for (int j=0;j<N;j++)
        {
            infile>>graph[j*1001];
//            cout << "A="<<graph[j*1001] << "\n";
            for (int k=1;k<=graph[j*1001];k++)
            {
                infile >> graph[j*1001+k];
                graph[j*1001+k]--;
          //      cout << "k=" << k << "\tp=" << graph[j*1001+k] <<"\n";

            }

        }
        //cout << "started\n";
//        cout << i << "\n";
        for (int j=0;(j<N) && (!di);j++)
        {
            stack[0]=j;

            stacklength=1;
            for (int k=0;k<N;k++)
                visited[k]=0;
            visited[j]=1;
            while ((stacklength>0) && (!di))
            {
               cur = stack[--stacklength];
               //cout << "cur=" << cur <<"\n";
               if (graph[cur*1001]>0)
               for (int k=1;k<=graph[cur*1001] && !di;k++)
               {
                   //cout << "proj=" <<graph[cur*1001+k] <<"\n";

                   if (visited[graph[cur*1001+k]]) di = 1;
                   else
                   {
                       stack[stacklength++] = graph[cur*1001+k];
                       visited[graph[cur*1001+k]]=1;
                   }
               }
            }
        }

        //outfile.setf(ios_base::fixed);
        //outfile.precision(7);
        outfile << "Case #" << i+1 << ": " <<  (di?"Yes":"No");






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


