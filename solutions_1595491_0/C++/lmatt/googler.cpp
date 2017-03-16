#include <iostream>

using namespace std;
int func(int parray[], int gn, int s, int p) 
{
    int res = 0;
    for(int i = 0; i < gn; i++) 
    {
        if(parray[i] % 3 == 2)
        {
            if((parray[i] + 1) / 3 >= p) 
            {
                res++;
            }
            else if((parray[i] + 4) / 3 >= p)
            {
                if(s == 0) continue;
                res++;
                s--;
            }
        }
        else if(parray[i] % 3 == 1) 
        {
            if((parray[i] + 2) / 3 >= p) 
            {
                res++;
            }
        }
        else 
        {
            
            if(parray[i] / 3 >= p) 
            {
                res++;
            }
            else if((parray[i] + 3) / 3 >= p) 
            {
                if(parray[i] == 0) continue;
                if(s == 0) continue;
                res++;
                s--;
            }
        }
    }
    return res;
}
int main() 
{
    int n;
    cin >> n;
    int gn, s, p;
    int parray[100];
    for(int i = 0; i < n; i++) 
    {
        cin >> gn >> s >> p;
        for(int j = 0; j < gn; j++) cin >> parray[j];
        cout << "Case #" << (i + 1) << ": ";
        cout << func(parray, gn, s, p);
        cout << endl;
    }
    return 0;
}
