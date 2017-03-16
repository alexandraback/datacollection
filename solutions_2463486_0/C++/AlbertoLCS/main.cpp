#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream arc1;
    ofstream arc2;
    arc1.open("input.txt");
    arc2.open("output.txt");
    int casos, a, b, x, y;
    int pal[] = {1,4,9,121,484}, cant = 5;
    arc1 >> casos;
    for(int i = 1; i < casos+1; i++){
        arc1 >> a >> b;
        x = 0;
        while(pal[x++] < a && x <= cant);
        y = x-1;
        while(pal[y++] <= b && y <= cant);
        arc2 << "Case #" << i << ": " << y - x << endl;
    }
    arc1.close();
    arc2.close();
    return 0;
}
