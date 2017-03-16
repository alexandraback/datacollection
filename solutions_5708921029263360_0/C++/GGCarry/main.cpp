#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream cinn("input.txt");
    ofstream coutt("output.txt");
    int T;
    cinn>>T;
    for(int iii=0;iii<T;iii++)
    {
        coutt<<"Case #"<<iii+1<<": ";
        int a,b,c,n,sum=0,sum2=0;
        vector<int> arr1,arr2,arr3;
        vector<int> arr12,arr22,arr32;
        cinn>>a>>b>>c>>n;
        int pol[4][4][4]={0,};
        int pol2[4][4][4]={0,};
        for(int i=0;i<a;i++)
        {
            pol[3][i][i]++;
            pol[i][3][i]++;
            pol[i][i][3]++;
            sum++;
            arr1.push_back(i+1);
                    arr2.push_back(i+1);
                    arr3.push_back(i+1);
        }
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                for(int k=0;k<c;k++)
                {
                    if(i==j&&j==k)continue;
                    if(pol[3][j][k]==n)continue;
                    if(pol[i][3][k]==n)continue;
                    if(pol[i][j][3]==n)continue;
                    pol[3][j][k]++;
                    pol[i][3][k]++;
                    pol[i][j][3]++;
                    sum++;
                    arr1.push_back(i+1);
                    arr2.push_back(j+1);
                    arr3.push_back(k+1);
                }
            }
        }
        /*for(int i=0;i<a;i++)
        {
            pol[3][i][i]++;
            pol[i][3][i]++;
            pol[i][i][3]++;
            sum++;
            arr1.push_back(i+1);
                    arr2.push_back(i+1);
                    arr3.push_back(i+1);
        }*/
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                for(int k=0;k<c;k++)
                {
                   // if(i==j&&j==k)continue;
                    if(pol2[3][j][k]==n)continue;
                    if(pol2[i][3][k]==n)continue;
                    if(pol2[i][j][3]==n)continue;
                    pol2[3][j][k]++;
                    pol2[i][3][k]++;
                    pol2[i][j][3]++;
                    sum2++;
                    arr12.push_back(i+1);
                    arr22.push_back(j+1);
                    arr32.push_back(k+1);
                }
            }
        }
        if(sum>sum2){
        coutt<<sum<<endl;
        for(int i=0;i<arr1.size();i++)
        {
            coutt<<arr1[i]<<' '<<arr2[i]<<' '<<arr3[i]<<' '<<endl;
        }
        }
        else{
        coutt<<sum2<<endl;
        for(int i=0;i<arr12.size();i++)
        {
            coutt<<arr12[i]<<' '<<arr22[i]<<' '<<arr32[i]<<' '<<endl;
        }
        }
    }
    return 0;
}
