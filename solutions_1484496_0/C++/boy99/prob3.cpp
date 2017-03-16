#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

#define SIZE 20
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
        int flag = 0;
        map<unsigned long long, unsigned long long> mymap;
        set<unsigned long long> myset;


        unsigned long long numbers[SIZE];
        //prob = (float*) malloc (sizeof(float) * A);

        //int ret=0;
        //for(int i=0 ; i<A; i++)
        for(unsigned long long i=0 ; i<N; i++)
        {
            unsigned long long temp;
            cin >> temp;
            numbers[i] = temp;
            //cout << numbers[i] << " ";
        }

        //cout << endl;

        unsigned long long maxtemp = 1024 * 1024;
        unsigned long long res1;
        unsigned long long res2 ;
        for (unsigned long long i = 1; i < maxtemp; i++)
        {
           int tmpind = 1;
           unsigned long long tmp = 1;
           unsigned long long tempsum = 0;
           while (tmpind <= 20)
           {
               unsigned long long val = i & tmp;

               if (val == tmp)
               {
                   tempsum = tempsum + numbers[tmpind-1];
               }
               tmp = tmp << 1;
               //cout << tmpind << " : " << val << " : "  << tmp << " : " << tempsum << endl;
               tmpind++;
           }

           //cout << i  << " : "<< tempsum << endl;
           if (myset.find(tempsum) == myset.end())
           {
               mymap[tempsum] = i;
               myset.insert(tempsum);

           }
           else
           {
                res1 = mymap[tempsum];
                flag = 1;
                res2 = i;
                break;
           }
        }
        
        outfile <<"Case #"<<ind+1<<":"<<endl;
        if (flag == 1)
        {
           int tmpind = 1;
           unsigned long long tmp = 1;
           while (tmpind <= 20)
           {
               unsigned long long val = res1 & tmp;
               if (val == tmp)
               {
                   outfile << numbers[tmpind - 1] << " ";
               }
               tmp = tmp << 1;
               tmpind++;
           }
           outfile << endl;

           tmpind = 1;
           tmp = 1;
           while (tmpind <= 20)
           {
               unsigned long long val = res2 & tmp;
               if (val == tmp)
               {
                   outfile << numbers[tmpind - 1] << " ";
               }
               tmp = tmp << 1;
               tmpind++;
           }

           outfile << endl;
        }
        else
        {
            outfile << "Impossible" << endl;
        }
        
    }
}
