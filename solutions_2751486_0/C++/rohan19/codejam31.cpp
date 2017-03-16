#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    string s[4],t1;
    ifstream fin;
    ofstream fout;
    fin.open("cji1.txt");
    fout.open("cjo1.txt");
    int t,i,j,flag=0,n,result=0,k,temp=0,temp2=0;
    fin>>t;
    getline(fin,s[0]);
    for(k=0;k<t;k++)
    {
        temp2=0;
        temp=0;
        result=0;
        getline(fin,t1,' ');
        fin>>n;
        getline(fin,s[0]);
        for(i=0;i<t1.length()-n+1;i++)
        {
            flag=0;
            if(t1[i]=='a' || t1[i]=='e' || t1[i]=='i' || t1[i]=='o' ||t1[i]=='u' )
                continue;
            else
            {
                temp=i;
                for(j=i+1;j<i+n;j++)
                {
                   if(t1[j]=='a' || t1[j]=='e' || t1[j]=='i' || t1[j]=='o' ||t1[j]=='u' )
                   {
                       flag=1;
                       i=j;
                       break;
                   }
                }
                if(flag==0)
                {

                   result+=((temp-temp2)+1)*(t1.length()-j+1);
                   temp2=temp+1;
                }
            }


        }
        fout<<"Case #"<<k+1<<": "<<result<<endl;
    }
    fout.close();

}
