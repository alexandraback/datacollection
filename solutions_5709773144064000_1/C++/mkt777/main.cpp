#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    ifstream cin;
    cin.open("large.in");
    ofstream cout;
    cout.open("output.txt");
    int cases;
    double c, f, x, sec, act, n;
    cin >> cases;
    for(int i=1;i<=cases;i++){
        cin >> c >> f >> x;
        act=2;
        n=0;
        while(true){
            if(x/act<c/act+x/(act+f)){
                n+=x/act;
                break;
            }
            else{
                n+=c/act;
                act+=f;
            }
        }
        cout << "Case #" << i << ": " << fixed << setprecision(7) << n << endl;
    }
    cin.close();
    cout.close();
    return 0;
}
