#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream arc1;
    ofstream arc2;
    arc1.open("input.txt");
    arc2.open("output.txt");
    long long int casos, a, b, x, y;
    long long int pal[] = {1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004};
    long long int cant = 39;
    arc1 >> casos;
    for(long long int i = 1; i < casos+1; i++){
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
