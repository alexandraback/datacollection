#include<cstdio>
#include<cmath>
#include<cstring>
#include<vector>
#include<iostream>
#include<fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream in("B-small-attempt0.in");
    ofstream out("a.txt");
int T ; in >> T;
vector<char> result;
	for(int t = 1 ; t<=T; t++){
            result.clear();
       int a[2555], hold , n;
       in >> n;
       int res[n];
       for(int i = 0 ; i < 2555; i++) a[i]=0;
       for(int i = 0; i < (n*(2*n-1)) ; i++){in >> hold;  a[hold]++;}

       for(int j = 0 , i=0;i<n,j <2555;j++){
        if(a[j]%2==1)res[i++]=j;
       }

            out << "Case #" << t << ": ";
       for(int i = 0 ; i < n; i++)
       out << res[i] << " ";
       out << endl;
       }


	return 0;
	out.close();
}
