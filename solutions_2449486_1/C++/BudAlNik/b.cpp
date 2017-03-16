#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
struct cell{
    int h, x, y;
};

bool comp(cell c1, cell c2){
    return c1.h > c2.h;
}


int t, n, m, l_h;
bool usedx[100], usedy[100], truly;
vector <cell> mas;
vector <int> l_x, l_y;
cell c;
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> n >> m;
        mas.clear();
        for(int j = 0; j < n; ++j){
            usedy[j] = false;
            for(int k = 0; k < m; ++k){
                usedx[k] = false;
                cin >> c.h;
                c.x = k;
                c.y = j;
                mas.push_back(c);
            }
        }
        sort(mas.begin(), mas.end(), comp);
        l_x.clear();
        l_y.clear();
        l_h = mas[0].h;
        truly = true;
        for(int j = 0; j < n * m; ++j){
            if(l_h == mas[j].h){
                if(usedx[mas[j].x] == true && usedy[mas[j].y] == true){
                    cout << "Case #" << i + 1 << ": NO" << endl;
                    truly = false;
                    break;
                }
                l_x.push_back(mas[j].x);
                l_y.push_back(mas[j].y);
            }
            else{
                for(int k = 0; k < l_x.size(); ++k){
                    usedx[l_x[k]] = true;
                }
                for(int k = 0; k < l_y.size(); ++k){
                    usedy[l_y[k]] = true;
                }
                l_x.clear();
                l_y.clear();
                l_h = mas[j].h;
                if(usedx[mas[j].x] == true && usedy[mas[j].y] == true){
                    cout << "Case #" << i + 1 << ": NO" << endl;
                    truly = false;
                    break;
                }
                l_x.push_back(mas[j].x);
                l_y.push_back(mas[j].y); 
            } 

        }
        if(truly){
            cout << "Case #" << i + 1 << ": YES" << endl;   
        }
    }

    return 0;
}