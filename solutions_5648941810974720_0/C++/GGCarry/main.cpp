#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream coutt("output.txt");
    ifstream cinn("input.txt");
    int T;
    cinn>>T;
    for(int ii=0;ii<T;ii++)
    {
        string a;
        int ch[26]={0,};
        int num[10]={0,};
        cinn>>a;
        coutt<<"Case #"<<ii+1<<": ";
        for(int i=0;i<a.size();i++)
        {
          ch[a[i]-'A']++;
        }

            while(ch['Z'-'A']!=0){
                ch['Z'-'A']--;
                ch['E'-'A']--;
                ch['R'-'A']--;
                ch['O'-'A']--;
                num[0]++;
            }
            while(ch['W'-'A']!=0){
                    ch['T'-'A']--;
                ch['W'-'A']--;
                ch['O'-'A']--;
                num[2]++;
            }
            while(ch['U'-'A']!=0){
                ch['F'-'A']--;
                ch['O'-'A']--;
                ch['U'-'A']--;
                ch['R'-'A']--;
                num[4]++;
            }
            while(ch['X'-'A']!=0){
                ch['S'-'A']--;
                ch['I'-'A']--;
                ch['X'-'A']--;
                num[6]++;
            }
            while(ch['G'-'A']!=0){
                ch['E'-'A']--;
                ch['I'-'A']--;
                ch['G'-'A']--;
                ch['H'-'A']--;
                ch['T'-'A']--;
                num[8]++;
            }
            while(ch['F'-'A']!=0){
                    ch['F'-'A']--;
                ch['I'-'A']--;
                ch['V'-'A']--;
                ch['E'-'A']--;
                num[5]++;
            }
            while(ch['V'-'A']!=0){
                ch['S'-'A']--;
                ch['E'-'A']--;
                ch['V'-'A']--;
                ch['E'-'A']--;
                ch['N'-'A']--;
                num[7]++;
            }
            while(ch['O'-'A']!=0){
                ch['O'-'A']--;
                ch['N'-'A']--;
                ch['E'-'A']--;
                num[1]++;
            }
            while(ch['I'-'A']!=0){
                ch['N'-'A']--;
                ch['I'-'A']--;
                ch['N'-'A']--;
                ch['E'-'A']--;
                num[9]++;
            }
            while(ch['T'-'A']!=0){
                ch['T'-'A']--;
                num[3]++;
            }

        for(int i=0;i<10;i++)
        {
            for(int j=0;j<num[i];j++)coutt<<i;
        }
        coutt<<endl;
    }
}
