#include <iostream>
#include <string>
#include <fstream>
using namespace std;

char mapping[26] = {
    'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r',
    'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'
};

ofstream fout("A.out");
int main()
{
    int testcases;
    char str[255];
    scanf("%d", &testcases);
    getchar();
    for (int tc=0; tc<testcases; ++tc) {
        gets(str);
        fout << "Case #" << (tc+1) << ": ";
        int size = strlen(str);
        for (int i=0; i<size; ++i) {
            if (str[i] >= 'a' && str[i] <= 'z') {
                fout << (char)(mapping[str[i] - 'a']);
            } else fout << str[i];
        }
        fout << endl;
    }
    
    return 0;
}