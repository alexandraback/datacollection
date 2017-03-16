#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

/*
int main (int argc, char * const argv[]) 
{
	freopen("input2012_2B_1.txt", "rt", stdin);
	freopen("output2012_2B_1.txt", "wt", stdout);
    
    int T; 
	cin >> T;
	
    for(int i = 0; i < T; i++) 
    {
        int N;
        cin >> N;
        int S[200], X = 0;
        for (int j = 0; j < N; j++)
        {
            cin >> S[j];
            X += S[j];
        }
        
        int noneed = 0;
        int noneedx = 0;
        
        cout << "Case #" << i+1 << ": ";
        for (int j = 0; j < N; j++)
        {
            if ((double)S[j] >= (double)X * 2 / (double)N)
            {
                noneed ++;
                noneedx += S[j];
            }
        }
            
        //int realn = (N > 2 ? N - noneed : N);
        for (int j = 0; j < N; j++)
        {
            double r = 0.0;
            if ((double)S[j] < (double)X * 2 / (double)N)
                r = ((double)(2 * X-noneedx) / (double)(N - noneed) - (double)S[j]) / (double)X;
            printf("%.6f", r * 100.0);
            if (j != N-1)
                cout << " ";
        }
        
        cout << endl;
    }
    
	return 0;
}
*/

bool incr(int flag[], int N)
{
    int i = 0;
    while(1)
    {
        flag[i]++;
        if (flag[i] > 1)
        {
            flag[i] = 0;
            i++;
            if (i > N)
                return false;
            continue;
        }
        else 
            return true;
    }
}

int su(int S[], int flag[], int N)
{
    int s = 0;
    for (int i = 0; i < N; i++)
    {
        if (flag[i] > 0)
            s += S[i];
    }
    return s;
}

int main (int argc, char * const argv[]) 
{
	freopen("input2012_2B_3.txt", "rt", stdin);
	freopen("output2012_2B_3.txt", "wt", stdout);
    
    int T; 
	cin >> T;
	
    for(int i = 0; i < T; i++) 
    {
        int N;
        cin >> N;
        int S[500];
        for (int j = 0; j < N; j++)
            cin >> S[j];
        
        int flag1[500], flag2[500];
        for (int j = 0; j < N; j++)
        {
            flag1[j] = 0;
            flag2[j] = 0;
        }
        flag1[0] = 1;
        flag2[1] = 1;
        
        bool w1 = true;
        bool found = false;
        while (w1)
        {
            int s1 = su(S, flag1, N);
            bool w2 = true;
            while (w2)
            {
                int s2 = su(S, flag2, N);
                if (s1 == s2)
                {
                    for (int j = 0; j < N; j++)
                    {
                        if (flag1[j] != flag2[j])
                        {
                            found = true;
                            break;
                        }
                    }
                }
                if (found)
                    break;
                w2 = incr(flag2, N);
            }
            if (found)
                break;
            w1 = incr(flag1, N);
        }
        
        cout << "Case #" << i+1 << ":" << endl;
        
        if (found)
        {
            for (int j = 0; j < N; j++)
            {
                if (flag1[j] > 0)
                    cout << S[j] << " ";
            }
            cout << endl;
            for (int j = 0; j < N; j++)
            {
                if (flag2[j] > 0)
                    cout << S[j] << " ";
            }
            
        }
        else {
            cout << "Impossible";
        }
        
        cout << endl;
    }
    
	return 0;
}