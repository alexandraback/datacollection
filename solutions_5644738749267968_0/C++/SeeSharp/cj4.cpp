#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ifstream _if("in.txt");
    ofstream _of("out.txt");
    _of.precision(7);
    _of.setf( ios::fixed, ios::floatfield );
    int n;
    _if >> n;
    for(int i=0;i < n; i++){
        int m;
        _if >> m;
        double a[m],b[m];
        for(int j=0;j<m;j++)
            _if >> a[j];
        for(int j=0;j<m;j++)
            _if >> b[j];
        vector<double> av (a, a+m);
        vector<double> bv (b, b+m);
        sort(av.begin(), av.end());
        sort(bv.begin(), bv.end());


        int finished = 0;
        int j=0;
        while(finished < m){
            while(av[finished] < bv[j])
                finished++;

            if (finished >= m) break;
            j++;
            finished++;
        }
        int deceitful_war = j;

        int x=m-1,z=m-1;
        int war = 0;
        for(;x>=0;x--){
            if(av[x] < bv[z])
                z--;
            else
                war++;
        }

        _of << "Case #" << i+1 << ": " << deceitful_war << " " << war << endl;

        /*for(int j=0;j<m;j++)
            cout << av[j] << " ";
        cout << endl;
        for(int j=0;j<m;j++)
            cout << bv[j] << " ";
        cout << endl;*/
    }
}
