#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream arc;
    ofstream sal;
    arc.open("input.txt");
    sal.open("output.txt");
    int casos;
    unsigned long long int r, t, area, m;
    arc >> casos;
    for(int i = 1; i <= casos; i++){
        arc >> r >> t;
        area = 0;
        m = 0;
        while(area <= t){
            area += (2*r+4*m+1);
            m++;
        }
        sal << "Case #" << i << ": " << m-1 << endl;
    }
    arc.close();
    sal.close();
    return 0;
}
