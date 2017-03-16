#include<iostream>
#include<fstream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include<cstring>
using namespace std;

ifstream fin("B2.in");
ofstream fout("B.out");




class LV
{
    public:
    int stars1;
    int stars2;
    int id;
};
bool myfunction1 (LV i,LV j) 
{
    if (i.stars1<j.stars1)return true;
    else if(i.stars1==j.stars1)return i.stars2>j.stars2;
    else return false;
}

bool myfunction2 (LV i,LV j) 
{
    return i.stars2<j.stars2;
}

bool myfunction3 (LV i, LV j)
{
    return i.stars2>j.stars2;
}

LV lv1[2000];
LV lv2[2000];
int s[2000];

int main()
{
    int T;
    fin >> T;
    for(int i=0;i<T;i++)
    {
        int N;
        fin >> N;
        for(int j=0;j<N;j++)
        {
            fin >> lv1[j].stars1 >> lv2[j].stars2;
            lv1[j].id = j;
            lv2[j].id = j;
            lv1[j].stars2 = lv2[j].stars2;
        }
        sort(lv1, lv1+N, myfunction1);
        sort(lv2, lv2+N, myfunction2);
        memset(s, 0, sizeof(s));
        
        int lv1p = 0;
        int lv2p = 0;
        int curr = 0;
        int steps = 0;
        while(lv2p<N)
        {
            if(lv2[lv2p].stars2<=curr)
            {
                if(s[lv2[lv2p].id]==0)
                {
                    curr+=2;
                    s[lv2[lv2p].id]=2;
                    steps++;
                }
                else
                {
                    curr++;
                    s[lv2[lv2p].id]=2;
                    steps++;
                }
                lv2p++;
                continue;
            }
            else if(lv1[lv1p].stars1<=curr)
            {
                //cout << curr << endl;
                int index = lv1p;
                while(lv1[index].stars1<=curr && index<N)index++;
                sort(lv1+lv1p,lv1+index,myfunction3);
                //for(int k = 0;k<N;k++)
                    //cout << lv1[k].stars1 << " " << lv1[k].stars2 << endl;
                //cout << endl;
                if(s[lv1[lv1p].id]==0)
                {
                    curr+=1;
                    s[lv1[lv1p].id]=1;
                    steps++;
                }
                lv1p++;
                continue;
            }
            else break;
        }
        fout << "Case #" << i+1 <<": ";
        if(lv2p==N) fout << steps << endl;
        else fout << "Too Bad" << endl;
    }
    system("pause");
}
