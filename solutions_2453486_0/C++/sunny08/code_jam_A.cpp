#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
int main()
{
  fstream myf,f2;
  myf.open("input.txt",ios::in|ios::app);
  f2.open("output.txt",ios::out);
    string s[4];
    int t;
    if(myf.is_open())
    {
        myf>>t;
        //cin>>t;
        //getline(cin,line);
        int test=0;
        while(t--)
        {
            test++;
            for(int i=0;i<4;i++)
            myf>>s[i];
            //check rows first
            int flg1=0,flg2=0,cnt=0;
            for(int i=0;i<4;i++)
            {
                int ct1=0,ct2=0;
                for(int j=0;j<4;j++)
                {
                    if(s[i][j]=='X')
                    ct1++;
                    else if(s[i][j]=='O')
                    ct2++;
                    else if(s[i][j]=='T')
                    ct1++,ct2++;
                    else
                    cnt++;
                }
                if(ct1==4)
                {
                    flg1=1;break;
                }
                if(ct2==4)
                {
                    flg2=1;break;
                }
            }
            if(!(flg1==1||flg2==1))
            {
                for(int j=0;j<4;j++)
                {
                    int ct1=0,ct2=0;
                    for(int i=0;i<4;i++)
                    {
                        if(s[i][j]=='X')
                        ct1++;
                        else if(s[i][j]=='O')
                        ct2++;
                        else if(s[i][j]=='T')
                        ct1++,ct2++;
                        else
                        cnt++;
                    }
                    if(ct1==4)
                    {
                        flg1=1;break;
                    }
                    if(ct2==4)
                    {
                        flg2=1;break;
                    }
                }
            }
            if(!(flg1==1||flg2==1))
            {
                int ct1=0,ct2=0;
                for(int i=0;i<4;i++)
                {
                        if(s[i][i]=='X')
                        ct1++;
                        else if(s[i][i]=='O')
                        ct2++;
                        else if(s[i][i]=='T')
                        ct1++,ct2++;
                        else
                        cnt++;

                }
                    if(ct1==4)
                    {
                        flg1=1;
                    }
                    if(ct2==4)
                    {
                        flg2=1;
                    }
            }
            if(!(flg1==1||flg2==1))
            {
                int ct1=0,ct2=0;
                int j=3;
                for(int i=0;i<4;i++)
                {
                        if(s[i][j]=='X')
                        ct1++;
                        else if(s[i][j]=='O')
                        ct2++;
                        else if(s[i][j]=='T')
                        ct1++,ct2++;
                        else
                        cnt++;
                    j--;
                }
                    if(ct1==4)
                    {
                        flg1=1;
                    }
                    if(ct2==4)
                    {
                        flg2=1;
                    }
            }

            f2<<"Case #"<<test<<": ";
            if(flg1==1)
            f2<<"X won\n";
            else if(flg2==1)
            f2<<"O won\n";
            else if(cnt>0)
            f2<<"Game has not completed\n";
            else
            f2<<"Draw\n";
        }
    }
    myf.close();
    f2.close();
    return 0;
}

