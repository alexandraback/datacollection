#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<fstream>
using namespace std;

int main()
{
    int T;
    ifstream in("in.txt");
    ofstream out("out.txt");
    in >> T; 
    for (int t = 1; t <= T; t++)
    {
        int A, B, K;
        in >> A >> B >> K;
        int count = 0;
        for(int i = 0; i < A; i++)
            for(int j = 0; j < B; j++)
            {
                int res = i & j;
                if(res < K) count++;
                
            }  
        out << "Case #" << t << ": " <<count <<  endl;   
    }    
    return 0;
    
}
