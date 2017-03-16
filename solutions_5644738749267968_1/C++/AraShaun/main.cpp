#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    FILE* input = fopen("D-small.txt", "r");
    FILE* output = fopen("out.txt", "w");
    fscanf(input, "%d", &t);
    for(int q = 0; q < t; q++)
    {
        int n;
        fscanf(input, "%d", &n);
        vector<double> ken(n);
        vector<double> naomi(n);
        for(int i = 0; i < n; i++)
        {
            fscanf(input, "%lf", &naomi[i]);
        }
        for(int i = 0; i < n; i++)
        {
            fscanf(input, "%lf", &ken[i]);
        }
        int ks = 0, ns = 0;
        vector<double> ken2 = ken, naomi2 = naomi;
        sort(ken2.begin(), ken2.end());
        sort(naomi2.begin(), naomi2.end());
        for(int i = 0; i < n; i++)
        {
            if(naomi2[naomi2.size()-1] > ken2[ken2.size()-1])
            {
                ken2.erase(ken2.begin());
                naomi2.erase(naomi2.begin()+naomi2.size()-1);
                ks++;
            }
            else
            {
                naomi2.erase(naomi2.begin()+naomi2.size()-1);
                ken2.erase(ken2.begin()+ken2.size()-1);
            }
        }
        sort(ken.begin(), ken.end());
        sort(naomi.begin(), naomi.end());
        for(int i = 0; i < n; i++)
        {
            if(naomi[0] < ken[0])
            {
                naomi.erase(naomi.begin());
                ken.erase(ken.begin()+ken.size()-1);
            }
            else if(naomi[naomi.size()-1] < ken[ken.size()-1])
            {
                naomi.erase(naomi.begin());
                ken.erase(ken.begin()+ken.size()-1);
            }
            else
            {
                naomi.erase(naomi.begin()+naomi.size()-1);
                ken.erase(ken.begin()+ken.size()-1);
                ns++;
            }
        }
        fprintf(output, "Case #%d: %d %d\n", q+1, ns, ks);
    }
    return 0;
}
