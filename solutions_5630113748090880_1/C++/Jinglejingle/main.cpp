#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

#define MAX 2500

using namespace std;

static int testCase, N, cnt[MAX + 1], temp;
static vector<int> ans_list;

int main(void)
{
    string fileName;
    
    cin >> fileName;
    
    ifstream fin(fileName);
    ofstream fout("output.txt");
    
    fin >> testCase;
    
    for (int caseN = 0; caseN < testCase; caseN++)
    {
        memset(cnt, 0, sizeof(cnt));
        
        fin >> N;
        
        for (int i = 0; i < (N * 2) - 1; i++)
        {
            for (int j = 0; j < N; j++)
            {
                fin >> temp;
                cnt[temp]++;
            }
        }
        
        for (int i = 1; i <= MAX; i++)
            if (cnt[i] % 2 != 0) ans_list.push_back(i);
        
        sort(ans_list.begin(), ans_list.end());
        
        fout << "Case #" << caseN + 1 << ": ";
        
        for (int i = 0; i < ans_list.size(); i++) fout << ans_list[i] << " ";
        fout << endl;
        
        ans_list.clear();
    }
    
    return 0;
}
