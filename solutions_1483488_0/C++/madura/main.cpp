#define PROBLEM "C"
//#define PROBLEM_ID "small-attempt0"
#define PROBLEM_ID "small-attempt0"
#include<iostream>
#include<map>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<sstream>
#include<list>
#include<set>
#include<algorithm>
#include<sstream>
#include<climits>

using namespace std;

typedef stringstream ss;
typedef unsigned char uchar;

int nCr ( int n, int r ) {
    if (n<r)
        return 0;
    if( n == r || r == 0 ) 
        return 1;
    return nCr( n-1, r-1 ) + nCr( n-1, r );
}

int main()
{

    freopen(PROBLEM"-"PROBLEM_ID".in","r",stdin);
    freopen(PROBLEM"-"PROBLEM_ID".out","w",stdout);

    int cases=0,c=0;
    long pten[9] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};
    long pten_1[9] = {0,9,99,999,9999,99999,999999,9999999,99999999};
    //char line[1000];
    cin>>cases;
    //cin.ignore(10,'\n');
    //cin.getline(line,1000);
   
    while (c++<cases){
        long a,b;
        char sa[10], sb[10];
        cin>>sa>>sb;
        
        int len=strlen(sa);
        long count=0;
        a=atol(sa);
        b=atol(sb);
        set<long> lx;
        for (long i=a;i<=b;i++) {
            long min = i;
            long subcount=1;
            int found=0;
            for (int j=1;j<len;j++) {
                long y = (i % pten[j])* pten[len-j];
                long x = i/pten[j] + y;

                if (x==i){
                    break;
                }
                if (x>=a && x<=b){

                    if (min>x)
                        min = x;
                    //if (x<i){
                    found=1;
                    subcount++;
                    //}
                }
            }
            if (found==1 && lx.find(min) == lx.end()){
                lx.insert(min);
                count+=nCr(subcount,2);
                
            }
        }
        cout<<"Case #"<<c<<": ";
        cout<<count<<endl;
        
    }
    return 0;
}