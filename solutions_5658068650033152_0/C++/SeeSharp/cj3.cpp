#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream _if("in.txt");
    ofstream _of("out.txt");
    int t;
    _if >> t;
    for(int i=0;i < t; i++){
        int n,m,k;
        _if >> n >> m >> k;

        if(n>m){
            int temp = n;
            n=m;
            m=temp;
        }

        if(n<3){
            _of << "Case #" << i+1 << ": " << k << endl;
            continue;
        }

        cout << n << " - " << m << " - " << k << endl;
/*
        if(k>16){
            _of << "Case #" << i+1 << ": " << k - 6 << endl;
            continue;
        }
*/
        if(n==3){
            int x = (k-2)/3+2;
            if(m>=x){
                _of << "Case #" << i+1 << ": " << (x-1)*2 + (k-((x-2)*3+2)) << endl;
                cout << "Case #" << i+1 << ": " << (x-1)*2 + (k-((x-2)*3+2)) << endl;
                continue;
            }
            else{
                _of << "Case #" << i+1 << ": " << (m-1)*2+(k-((m-2)*3+2)) << endl;
                cout << "Case #" << i+1 << ": " << (m-1)*2+(k-((m-2)*3+2)) << endl;
                continue;
            }
        }
        if(n==4){
            if(m==4){
                if(k>=12){
                    _of << "Case #" << i+1 << ": " << k-4 << endl;
                    cout << "Case #" << i+1 << ": " << k-4 << endl;
                    continue;
                }
                else if(k==10){
                    _of << "Case #" << i+1 << ": " << 7 << endl;
                    cout << "Case #" << i+1 << ": " << 7 << endl;
                    continue;
                }
                else{
                    int x = (k-2)/3+2;
                    if(m>=x){
                        _of << "Case #" << i+1 << ": " << (x-1)*2 + (k-((x-2)*3+2)) << endl;
                        cout << "Case #" << i+1 << ": " << (x-1)*2 + (k-((x-2)*3+2)) << endl;
                        continue;
                    }
                    else{
                        _of << "Case #" << i+1 << ": " << (m-1)*2+(k-((m-2)*3+2)) << endl;
                        cout << "Case #" << i+1 << ": " << (m-1)*2+(k-((m-2)*3+2)) << endl;
                        continue;
                    }
                }
            }
            if(m==5){
                if(k>=16){
                    _of << "Case #" << i+1 << ": " << k-6 << endl;
                    cout << "Case #" << i+1 << ": " << k-6 << endl;
                    continue;
                }
                else if(k==15){
                    _of << "Case #" << i+1 << ": " << 10 << endl;
                    cout << "Case #" << i+1 << ": " << 10 << endl;
                    continue;
                }
                else if(k==14){
                    _of << "Case #" << i+1 << ": " << 9 << endl;
                    cout << "Case #" << i+1 << ": " << 9 << endl;
                    continue;
                }
                else if(k>=12){
                    _of << "Case #" << i+1 << ": " << k-4 << endl;
                    cout << "Case #" << i+1 << ": " << k-4 << endl;
                    continue;
                }
                else if(k==10){
                    _of << "Case #" << i+1 << ": " << 7 << endl;
                    cout << "Case #" << i+1 << ": " << 7 << endl;
                    continue;
                }
                else{
                    int x = (k-2)/3+2;
                    if(m>=x){
                        _of << "Case #" << i+1 << ": " << (x-1)*2 + (k-((x-2)*3+2)) << endl;
                        cout << "Case #" << i+1 << ": " << (x-1)*2 + (k-((x-2)*3+2)) << endl;
                        continue;
                    }
                    else{
                        _of << "Case #" << i+1 << ": " << (m-1)*2+(k-((m-2)*3+2)) << endl;
                        cout << "Case #" << i+1 << ": " << (m-1)*2+(k-((m-2)*3+2)) << endl;
                        continue;
                    }
                }
            }
        }

        cout << "ERROR: " << i+1 << endl;
    }
}
