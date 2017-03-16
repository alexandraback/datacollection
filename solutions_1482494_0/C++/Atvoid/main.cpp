#include <iostream>
#include <fstream>
#include <iomanip>


using namespace std;

ifstream fin;
ofstream fout;

int a[2000][2];
bool used[2000][2];

bool big(int i, int k, int p)
{
    if (a[i][1]>p)
        return true;
    else if (a[i][1]<p)
        return false;
    else if (a[i][0]>k)
        return true;
    else if (a[i][0]<k)
        return false;
    else
        return false;
}

void kp(int s, int t)
{
    int i,j,k,p;
    i = s;
    j = t;
    k = a[i][0];
    p = a[i][1];
    while (i<j)
    {
        while (i<j && big(j,k,p)) --j;
        if (i<j)
        {
            a[i][0] = a[j][0];
            a[i][1] = a[j][1];
            ++i;
        }
        while (i<j && !big(i,k,p)) ++i;
        if (i<j)
        {
            a[j][0] = a[i][0];
            a[j][1] = a[i][1];
            --j;
        }
    }
    a[i][0] = k;
    a[i][1] = p;

    if (s<i-1) kp(s,i-1);
    if (j+1<t) kp(j+1,t);
}

void solve(int num)
{
    int n;
    int total = 0,count = 0;
    fin>>n;


    for (int i=0;i<n;++i)
    {
        fin>>a[i][0]>>a[i][1];
        used[i][0] = false;
        used[i][1] = false;
    }
    kp(0,n-1);

//    for (int i=0;i<n;++i)
//    {
//        fout<<a[i][0]<<"\t"<<a[i][1]<<endl;
//    }
    while (total<n*2)
    {
        int i;
        for (i=n-1;i>=0;--i)
        {
            if (!used[i][0] && total>=a[i][0])
            {
                if (!used[i][1] && total>=a[i][1])
                {
                    ++total;
                    used[i][1] = true;
                }
                used[i][0] = true;
                ++total;
                ++count;
                break;
            }
        }
        if (i<0)
        {
            fout<<"Case #"<<num<<": "<<"Too Bad"<<endl;
            return;
        }
        for (i=0;i<n;++i)
        {
            if (!used[i][0] && !used[i][1] && total>=a[i][1])
            {
                used[i][0] = used[i][1] = true;
                ++total;
                ++total;
                ++count;
            }
            if (!used[i][1] && total>=a[i][1])
            {
                ++total;
                ++count;
                used[i][1] =true;
            }
        }
    }


    for (int i=0;i<n;++i)
        if (!used[i][0] || !used[i][1])
        {
            fout<<"Case #"<<num<<": "<<"Too Bad"<<endl;
            return;
        }
    fout<<"Case #"<<num<<": "<<count<<endl;
}

int main()
{
    int total;
    fin.open("input.txt");
    fout.open("output.txt");

    fin>>total;
    for (int i=1;i<=total;++i)
    {
        solve(i);
    }

    fin.close();
    fout.close();
    return 0;
}
