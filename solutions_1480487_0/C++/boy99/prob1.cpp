#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    ofstream outfile;
    outfile.open("output.txt");

    int T;
    cin>>T;

    for(int ind=0;ind<T;ind++)
    {
        unsigned long long N;
        //int A,B;
        cin>>N;

        double score[200];
        double res[200];
        int check[200];
        //vector<int> score;
        //prob = (float*) malloc (sizeof(float) * A);
        int min = 101;
        int nextmin = 101;
        //int ret=0;
        //for(int i=0 ; i<A; i++)
        unsigned long long sum = 0;
        for(unsigned long long i=0 ; i<N; i++)
        {
            int temp;
            cin >> temp;            
            //score.push_back(temp);
            score[i] = temp;
            sum = sum + temp;
            check[i] = 0;
  /*          if (temp <= min)
            {
                nextmin = min;
                min = temp;
            }
            else if (temp <= nextmin)
            {
                nextmin = temp;
            }*/
        }

        double tmpsum = sum;
        unsigned long long tmpN = N;
        double avg = 2.0 * (double)sum /N;
        

        for (unsigned long long i = 0; i < N; i++)
        {
            if (score[i] > avg)
            {
                res[i] = 0;
                check[i] = 1;
                tmpsum = tmpsum - score[i];
                tmpN--;
            }           
        }

        avg = (tmpsum + sum)/tmpN;
       // double min = 2*B + 2;

       // double val;
        //for (int i = 0; i <= A; i++)
        //cout << N << " : " << score.size() << endl;
        //vector<double> res;
        for (unsigned long long i = 0; i < N; i++)
        {
           
            if (check[i] == 1)
            {
                continue;
            }
            double p;

            int val1 = score[i];
            
            p = (avg - val1)/sum;
            
           
            res[i] = p* 100;
//            cout << p << " : " << val1 << " : " << val2 << " : " << sum << endl;
        }

        outfile <<"Case #"<<ind+1<<":";

        for (int i = 0; i < N; i++)
        {
            outfile << " " << fixed << setprecision(6) << res[i];
        }
        outfile << endl;
    }
}
