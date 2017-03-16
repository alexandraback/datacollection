#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<fstream>
#include<sstream>
using namespace std;

long long fac(long long n)
{
    if(n == 0) return 1;
    if(n == 1) return 1;
    return n * fac(n-1);   
}
int main()
{
    int T;
    ifstream in("in.txt");
    ofstream out("out.txt");
    in >> T; 
    for (int t = 1; t <= T; t++)
    {
        int N;
        in >> N;
        vector<string> str(N);
        for(int i = 0; i < N; i++)
            in >> str[i];
        sort(str.begin(),str.end());
        int count[11];
        memset(count,0,sizeof(count));
        int k =0;
        count[0] = 1;
        for(int i = 0; i < str.size()-1; i++)
        {
            if(str[i] == str[i+1])
                count[k]++;
            else
            {
                k++;
                count[k] = 1;
            }
        }
        int i;
        int used[256];
        long long ret = 0;
        do
        {
            int isValid = 1;
            memset(used,0,sizeof(used));
            string S = "";
            for(i = 0; i < N; i++)
            {
                S += str[i];
            }

            char cur = S[0];
            for(i = 0; i < S.size(); i++)
            {
                if(cur != S[i])
                {
                    cur = S[i];
                    if(used[cur])
                    {
                        isValid = 0;
                        break;
                    }
                }
                used[S[i]] = 1;
            }
            if(isValid) ret++;
        }while(next_permutation(str.begin(),str.end()));
        for(int i = 0; i < 10; i++)
        {
            ret =  (ret *fac(count[i])) % 1000000007;   
        }
        out << "Case #" << t <<": " << ret << endl;
    }
    return 0;
    
}
