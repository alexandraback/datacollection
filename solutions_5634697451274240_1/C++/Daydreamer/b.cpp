#include <iostream>
#include <algorithm>
using namespace std;
int mem[2][2][101][101] = {-1}, len = 0;
int dc(int a[], int b[], int start, int end, int tar, int m)
{   

    if (mem[m][tar][start][end] != -1) return mem[m][tar][start][end];

    if (start == end-1)
        return abs(tar-a[start]);
    if (start == end) return 0;

    int dem = a[start], flag = 0;
    for (int i = start+1; i < end; i++)
        if (a[i] != dem)
        { flag = 1; break; }
    if (flag==0 && dem == tar) return 0;
    else if (flag ==0) return 1;

    int init = dc(a, b, start, start+1, tar, m)+ dc(b, a, len-end, len-start-1, !tar, !m);
    if (dc(b, a, len-end, len-start-1, !tar, !m) > 0) init = init+2;

    int ano = dc(a, b, start, start+1, !tar, m)+ dc(b, a, len-end, len-start-1, tar, !m)+1;
    if (dc(b, a, len-end, len-start-1, tar, !m) > 0) ano = ano+2;

    init = min(init, ano);

    for (int i = 2; i < end-start; ++i)
    {   int temp = dc(a, b, start, start+i, tar, m)+ dc(b, a, len-end, len-start-i, !tar, !m);
        if (dc(b, a, len-end, len-start-i, !tar, !m) > 0) temp = temp+2;

            init = min(init, temp);

        temp = dc(a, b, start, start+i, !tar, m)+ dc(b, a, len-end, len-start-i, tar, !m)+1;
        if (dc(b, a, len-end, len-start-i, tar, !m) > 0) temp = temp+2;

            init = min(init, temp);

    }

// cout << "b = "<< m << "start = " << start << "end = " << end << "tar " << tar << " int " << init << endl;
    return mem[m][tar][start][end] = init;
}

int main()
{   
    int T;
    cin >> T;
    
    for (int kase = 1; kase <= T; kase++)
    {   string s;
    cin >> s;
    len = s.length();
    int a[101], b[101];
    for (int i = 0 ; i < s.length(); ++i)
        if (s[i] == '-')
            a[i] = 0, b[len-1-i] = 1;
        else a[i] = 1, b[len-1-i] = 0;

    for (int i = 0; i <= len; ++i)
        for (int j = i; j <= len; ++j)
            mem[0][0][i][j] = mem[1][0][i][j] = mem[0][1][i][j] = mem[1][1][i][j] = -1;

    cout << "Case #" << kase << ": " << dc(a, b, 0, s.length(), 1, 0) << endl; 
    }
        
}
