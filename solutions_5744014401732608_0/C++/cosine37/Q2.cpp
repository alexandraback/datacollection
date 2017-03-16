#include<iostream>
#include<fstream>
using namespace std;
int a[100];
ifstream in("small.txt");
ofstream out("Q2.out");
bool impossible(long long n,long long ways){
     long long ans=1;
     long long i;
     for (i=2;i<n;i++) ans=ans*2;
     //out<<"ans="<<ans<<endl;
     //out<<"ways="<<ways<<endl;
     if (ans>=ways) return false;
     return true;
}
int main(){
    int t,i,j,k,index,high;
    long long n,ways,temp;
    in>>t;
    for (i=1;i<=t;i++){
        out<<"Case #"<<i<<": ";
        in>>n;
        in>>ways;
        if (impossible(n,ways)){
           out<<"IMPOSSIBLE"<<endl;
           continue;
        }
        out<<"POSSIBLE"<<endl;
        temp=ways-1;
        index=1;
        //out<<"temp="<<temp<<endl;
        while (temp>0){
              index++;
              a[index]=temp%2;
              temp=temp/2;
        }
        high=index;
        //out<<"high="<<high<<endl;
        out<<"0 ";
        for (j=2;j<=high;j++) out<<"1 ";
        for (j=high+1;j<n;j++) out<<"0 ";
        out<<"1"<<endl;
        for (j=2;j<n;j++){
            if (high<j){
               for (k=1;k<n;k++) out<<"0 ";
               out<<"0"<<endl;
               continue;
            }
            for (k=1;k<=j;k++) out<<"0 ";
            for (k=j+1;k<=high;k++) out<<"1 ";
            for (k=high+1;k<n;k++) out<<"0 ";
            if (a[n-j+1]==1) out<<"1"<<endl; else out<<"0"<<endl;
        }
        for (j=1;j<n;j++) out<<"0 ";
        out<<"0"<<endl;
    }
}
