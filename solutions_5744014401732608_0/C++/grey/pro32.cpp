#include <iostream>
#include <fstream>
#include <set>
#include <math.h>

using namespace std;

ifstream fin("input");
ofstream fout("output");


bool isok;
int inputnumber,ii,n,N,J,countcopy,maxppl,group,secondgroup;
//    int n;
string ss;
int total=0;
int m;
int bitcopy;

/*
void solve(int arr[], int n, int level)
{
    if (level==n+1)
        return;
    for (int ii=0; ii<n; ii++)
    {
        
    }
}
*/

void getcol(int number, int &a , int & b)
{
    switch (number)
    {
        case 0: a=0; b=1; return;
        case 1: a=0; b=2;return;
        case 2: a=1; b=2;return;
        case 3: a=0; b=3;return;
        case 4: a=1; b=3;return;
        case 5: a=2; b=3;return;
        case 6: a=0; b=4;return;
        case 7: a=1; b=4;return;
        case 8: a=2; b=4;return;
        case 9: a=3; b=4;return;
        case 10: a=0; b=5;return;
        case 11: a=1; b=5;return;
        case 12: a=2; b=5;return;
        case 13: a=3; b=5;return;
        case 14: a=4; b=5;return;
        default: return;
    }
}

int getnumber(int number)
{
    switch (number)
    {
        case 2: return 1;
        case 3: return 3;
        case 4: return 6;
        case 5: return 10;
        case 6: return 15;
        default: return 0;
    }
    
}

int main()
{

    fin>>inputnumber;
    
    for (int ii=1;ii<=inputnumber;ii++)
    {
        isok=false;
        fin>>n>>m;
        fout<<"Case #"<<ii<<": ";
        int arr[n][n];
        
        for (int i=0;i<n;i++)
                    for (int j=0;j<n;j++)
                        arr[i][j]=0;
        int level,a,b;
        for (int bit=0; bit < (1<<getnumber(n)) ; bit ++)
        {
            bitcopy=bit;
            level=0;
            while (bitcopy>0)
            {
                getcol(level,a,b);
                arr[a][b]= bitcopy % 2;
                bitcopy/=2;
                level++;
            }

            
            /*
            for (int i=0;i<n;i++)
            {
                for (int j=0;j<n;j++)
                    cout<<arr[i][j];
                cout<<endl;
            }
            */

        int dp[n];
        for (int jj=0;jj<n;jj++)
            dp[jj]=0;
        for (int jj=1;jj<n;jj++)
        {
            int total;
            if (arr[0][jj])
                total=1;
            else
                total=0;
            for (int kk=1;kk<jj;kk++)
                if (arr[kk][jj])
                {
                    total+=dp[kk];
                }
            dp[jj]=total;
        }
            if (dp[n-1]==m)
            {
                /*
                for (int bb=0;bb<n;bb++)
                    cout<<dp[bb]<<"  ";
                    cout<<endl;
                 */
                fout<<"POSSIBLE"<<endl;
                isok=true;
                for (int i=0;i<n;i++)
                    {
                        for (int j=0;j<n;j++)
                            fout<<arr[i][j];
                        fout<<endl;
                    }
                break;
            }
        }
        if (!isok)
            fout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}