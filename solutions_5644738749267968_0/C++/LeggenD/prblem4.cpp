#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

int main()
{

    int T,i,j,n,C[50][2];
    int i1,i2;      //index A
    int j1,j2;       //index B
    double A[1000],B[1000];
    ifstream File("D-small-attempt0 (1).in");
    File>>T;
    for(j=0; j<T; j++)
    {
        File>>n;
        for(i=0; i<n; i++)
            File>>A[i];

        for(i=0; i<n; i++)
            File>>B[i];

        int dw = 0, w = 0;
        sort(A,A+n);
        sort(B,B+n);
        i1 = j1 = 0;
        i2 = j2 = n-1;

         for(i=0;i<n;i++)
        {
            if (A[i1]>B[j1])
            {
                i1++;
                j1++;
                dw++;
            }
            else
                i1++;
        }
       // cout<<"deceit: "<<dw<<endl;
        for(i=0;i<n;i++)
        {
            if (A[i2]>B[j2])
            {
                i2--;
                w++;
            }
            else
            {
               i2--;
               j2--;
            }

        }
        //cout<<"war: "<<w<<endl;
        C[j][0] = dw;
        C[j][1] = w;
    }

    ofstream ofile;
    ofile.open("outc.txt");

    for(j=0;j<T;j++)
    {
        ofile<<"Case #"<<(j+1)<<": "<<C[j][0]<<" "<<C[j][1]<<endl;
    }

    return 0;
}
