#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <set>
#include <queue>
#include <fstream>
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
    int T;
    long long m,b;
    fstream cin("BBB.in");
    ofstream cout("BBB.txt");
    cin>>T;
    for(int t=0;t<T;t++)
    {
    cin>>b>>m;
    if(b==2)
    {
        if(m>1) {cout<<"Case #"<<t+1<<": "<<"IMPOSSIBLE"<<endl;}
        else {
                cout<<"Case #"<<t+1<<": "<<"POSSIBLE"<<endl;
            cout<<"01"<<endl;
            cout<<"00"<<endl;
        }
        continue;
    }
    if(b==3)
    {
       if(m>2) {cout<<"Case #"<<t+1<<": "<<"IMPOSSIBLE"<<endl;}
       else
       {
            cout<<"Case #"<<t+1<<": "<<"POSSIBLE"<<endl;
            if(m==1){
            cout<<"001"<<endl;
            cout<<"000"<<endl;
            cout<<"000"<<endl;
            }
            else
            {
            cout<<"011"<<endl;
            cout<<"001"<<endl;
            cout<<"000"<<endl;
            }
       }
       continue;
    }
    if(b==4)
    {
        if(m>4) {cout<<"Case #"<<t+1<<": "<<"IMPOSSIBLE"<<endl;}
        else
       {
            cout<<"Case #"<<t+1<<": "<<"POSSIBLE"<<endl;
            if(m==1){
            cout<<"0001"<<endl;
            cout<<"0000"<<endl;
            cout<<"0000"<<endl;
            cout<<"0000"<<endl;
            }
            if(m==2)
            {
            cout<<"0101"<<endl;
            cout<<"0001"<<endl;
            cout<<"0000"<<endl;
            cout<<"0000"<<endl;
            }
            if(m==3)
            {
            cout<<"0111"<<endl;
            cout<<"0001"<<endl;
            cout<<"0001"<<endl;
            cout<<"0000"<<endl;
            }
            if(m==4)
            {
            cout<<"0111"<<endl;
            cout<<"0011"<<endl;
            cout<<"0001"<<endl;
            cout<<"0000"<<endl;
            }
       }
       continue;
    }
    if(b==5)
    {
        if(m>8) {cout<<"Case #"<<t+1<<": "<<"IMPOSSIBLE"<<endl;}
        else
            {
                cout<<"Case #"<<t+1<<": "<<"POSSIBLE"<<endl;
              if(m==1){
            cout<<"00001"<<endl;
            cout<<"00000"<<endl;
            cout<<"00000"<<endl;
            cout<<"00000"<<endl;
            cout<<"00000"<<endl;
            }
            if(m==2)
            {
            cout<<"01001"<<endl;
            cout<<"00001"<<endl;
            cout<<"00000"<<endl;
            cout<<"00000"<<endl;
            cout<<"00000"<<endl;
            }
            if(m==3)
            {
            cout<<"01101"<<endl;
            cout<<"00001"<<endl;
            cout<<"00001"<<endl;
            cout<<"00000"<<endl;
            cout<<"00000"<<endl;
            }
            if(m==4)
            {
            cout<<"01111"<<endl;
            cout<<"00001"<<endl;
            cout<<"00001"<<endl;
            cout<<"00001"<<endl;
            cout<<"00000"<<endl;
            }
            if(m==5)
            {
            cout<<"01111"<<endl;
            cout<<"00001"<<endl;
            cout<<"00011"<<endl;
            cout<<"00001"<<endl;
            cout<<"00000"<<endl;
            }
            if(m==6)
            {
            cout<<"01111"<<endl;
            cout<<"00011"<<endl;
            cout<<"00011"<<endl;
            cout<<"00001"<<endl;
            cout<<"00000"<<endl;
            }
            if(m==8)
                {
            cout<<"01111"<<endl;
            cout<<"00111"<<endl;
            cout<<"00011"<<endl;
            cout<<"00001"<<endl;
            cout<<"00000"<<endl;
            }
            if(m==7)
                {
            cout<<"01110"<<endl;
            cout<<"00111"<<endl;
            cout<<"00011"<<endl;
            cout<<"00001"<<endl;
            cout<<"00000"<<endl;
            }
            }
            continue;
    }
    if(b==6)
    {
        if(m>16) {cout<<"Case #"<<t+1<<": "<<"IMPOSSIBLE"<<endl;}
        else
        {
            cout<<"Case #"<<t+1<<": "<<"POSSIBLE"<<endl;
               if(m==1){
            cout<<"000001"<<endl;
            cout<<"000000"<<endl;
            cout<<"000000"<<endl;
            cout<<"000000"<<endl;
            cout<<"000000"<<endl;
            cout<<"000000"<<endl;
            }
            if(m==2)
            {
            cout<<"010001"<<endl;
            cout<<"000001"<<endl;
            cout<<"000000"<<endl;
            cout<<"000000"<<endl;
            cout<<"000000"<<endl;
            cout<<"000000"<<endl;
            }
            if(m==3)
            {
            cout<<"011001"<<endl;
            cout<<"000001"<<endl;
            cout<<"000001"<<endl;
            cout<<"000000"<<endl;
            cout<<"000000"<<endl;
            cout<<"000000"<<endl;
            }
            if(m==4)
            {
            cout<<"001111"<<endl;
            cout<<"000001"<<endl;
            cout<<"000001"<<endl;
            cout<<"000001"<<endl;
            cout<<"000000"<<endl;
            cout<<"000000"<<endl;
            }
            if(m==5)
            {
            cout<<"011111"<<endl;
            cout<<"000001"<<endl;
            cout<<"000001"<<endl;
            cout<<"000001"<<endl;
            cout<<"000001"<<endl;
            cout<<"000000"<<endl;
            }
            if(m==6)
            {
            cout<<"011111"<<endl;
            cout<<"000001"<<endl;
            cout<<"000001"<<endl;
            cout<<"000011"<<endl;
            cout<<"000001"<<endl;
            cout<<"000000"<<endl;
            }
             if(m==7)
            {
            cout<<"011111"<<endl;
            cout<<"000001"<<endl;
            cout<<"000011"<<endl;
            cout<<"000011"<<endl;
            cout<<"000001"<<endl;
            cout<<"000000"<<endl;
            }
            if(m==8)
            {

            cout<<"011111"<<endl;
            cout<<"000011"<<endl;
            cout<<"000011"<<endl;
            cout<<"000011"<<endl;
            cout<<"000001"<<endl;
            cout<<"000000"<<endl;
            }
            if(m==9)
            {

            cout<<"011111"<<endl;
            cout<<"000001"<<endl;
            cout<<"000111"<<endl;
            cout<<"000011"<<endl;
            cout<<"000001"<<endl;
            cout<<"000000"<<endl;
            }
            if(m==10)
            {
            cout<<"011111"<<endl;
            cout<<"000011"<<endl;
            cout<<"000111"<<endl;
            cout<<"000011"<<endl;
            cout<<"000001"<<endl;
            cout<<"000000"<<endl;
            }
            if(m==14)
            {
            cout<<"011111"<<endl;
            cout<<"001011"<<endl;
            cout<<"000111"<<endl;
            cout<<"000011"<<endl;
            cout<<"000001"<<endl;
            cout<<"000000"<<endl;
            }
            //??????
            if(m==11)
            {
            cout<<"011111"<<endl;
            cout<<"001011"<<endl;
            cout<<"000111"<<endl;
            cout<<"000010"<<endl;
            cout<<"000001"<<endl;
            cout<<"000000"<<endl;
            }
            if(m==12)
            {
            cout<<"011111"<<endl;
            cout<<"000111"<<endl;
            cout<<"000111"<<endl;
            cout<<"000011"<<endl;
            cout<<"000001"<<endl;
            cout<<"000000"<<endl;
            }
            if(m==13)
            {
            cout<<"011110"<<endl;
            cout<<"001011"<<endl;
            cout<<"000111"<<endl;
            cout<<"000011"<<endl;
            cout<<"000001"<<endl;
            cout<<"000000"<<endl;
            }
            if(m==12)
            {

            }
            if(m==15)
            {
            cout<<"011110"<<endl;
            cout<<"001111"<<endl;
            cout<<"000111"<<endl;
            cout<<"000011"<<endl;
            cout<<"000001"<<endl;
            cout<<"000000"<<endl;
            }
            if(m==16)
            {
            cout<<"011111"<<endl;
            cout<<"001111"<<endl;
            cout<<"000111"<<endl;
            cout<<"000011"<<endl;
            cout<<"000001"<<endl;
            cout<<"000000"<<endl;
            }
        }
        continue;
    }
           // cout<<"Case #"<<t+1<<": ";

    }
   return 0;
}
