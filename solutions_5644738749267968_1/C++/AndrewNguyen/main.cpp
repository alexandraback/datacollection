//
//  main.cpp
//  Deceitful War
//

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

void display(vector<double> arr)
{
    for (int i = 0; i < arr.size(); ++i)
        cout << arr[i] << " ";
    cout << endl;
}

int main(int argc, const char * argv[])
{

    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
//    freopen("test.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    
    int ncases;
    scanf("%d", &ncases);
    
    for (int i = 0; i < ncases; ++i)
    {
        int T;
        scanf("%d", &T);
        vector<double> naomi;
        vector<double> ken;
        double tmp;
        for (int j = 0; j < T; ++j)
        {
            scanf("%lf", &tmp);
            naomi.push_back(tmp);
        }
        for (int j = 0; j < T; ++j)
        {
            scanf("%lf", &tmp);
            ken.push_back(tmp);
        }
        
        sort(naomi.begin(), naomi.end());
        sort(ken.begin(), ken.end());
        
        deque<double> dn1, dk1;
        deque<double> dn2, dk2;
        
        for (int j = 0; j < T; ++j)
        {
            dn1.push_back(naomi[j]);
            dn2.push_back(naomi[j]);
            dk1.push_back(ken[j]);
            dk2.push_back(ken[j]);
        }
        
        printf("Case #%d: ", i+1);
        int np1 = 0, kp1 = 0;
        
        for (int j = 0; j < T; ++j)
        {
            if (dn1.front() < dk1.front())
            {
                dn1.pop_front();
                dk1.pop_back();
                kp1++;
            }
            else
            {
                dn1.pop_front();
                dk1.pop_front();
                np1++;
            }
        }
        
        int np2 = 0, kp2 = 0;
        for (int j = 0; j < T; ++j)
        {
            if (dn2.back() > dk2.back())
            {
                dn2.pop_back();
                dk2.pop_front();
                np2++;
            }
            else
            {
                dn2.pop_back();
                dk2.pop_back();
                kp2++;
            }
        }
        
        printf("%d %d\n", np1, np2);
    }
    
    fclose(stdout);
    fclose(stdin);
    return 0;
}

