#include <iostream>

using namespace std;

int main()
{
    int t;
    double c,f,x;
    double boundTime,total,currentV;
    cin>>t;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    for (int ii = 0; ii < t; ++ii)
    {
        cin>>c>>f>>x;
        total = 0;
        currentV = 2;
        boundTime = c / f;
        if (x < c){
            cout<<"Case #"<<(ii + 1)<<": ";
            cout.precision(7);
            cout<<total + x / currentV<<endl;
            continue;
        }

        while(true){
            if (x / (currentV+f) < boundTime){
                cout<<"Case #"<<ii + 1<<": ";
                cout.precision(7);
                cout<<(total + x/currentV)<<endl;
                break;
            }else{
                total += c / currentV;
                currentV += f;
            }
        }
    }
    return 0;
}
