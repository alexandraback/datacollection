#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("C-small-attempt1.in");
ofstream fout("data.out",std::ofstream::trunc);
void fashion(int j,int p,int s,int k);
int main()
{
    int tests, counts=1, j,p,s,k;
    fin >> tests;
    while(!fin.eof()&&tests){
        fin >> j >> p >> s >> k;
        tests--;
        if(counts>1){
            fout << endl;
            cout << endl;
        }
        fout << "Case #" << counts << ": ";
        cout << "Case #" << counts << ": ";
        fashion(j,p,s,k);
        counts++;
    }
    fin.close();
    fout.close();
    return 0;
}
void fashion(int j,int p,int s,int k){
    int arr[3][s];
    for(int i=0;i<3;i++){
        for(int j=0;j<s;j++){
            arr[i][j]=k;
        }
    }
    int counts=0;
    for(int q=1; q<=j; q++){
        for(int w=1; w<=p; w++){
            for(int e=1; e<=s; e++){
                if(arr[0][q-1]&&arr[1][w-1]&&arr[2][e-1]){
                    counts++;
                    //arr[0][q-1]--;
                    arr[1][w-1]--;
                    arr[2][e-1]--;
                }
            }
        }
    }
    fout << counts;
    cout << counts;
    for(int i=0;i<3;i++){
        for(int j=0;j<s;j++){
            arr[i][j]=k;
        }
    }
    for(int q=1; q<=j; q++){
        for(int w=1; w<=p; w++){
            for(int e=1; e<=s; e++){
                if(arr[0][q-1]&&arr[1][w-1]&&arr[2][e-1]){
                    fout << endl << q << " " << w << " " << e;
                    cout << endl << q << " " << w << " " << e;
                    //arr[0][q-1]--;
                    arr[1][w-1]--;
                    arr[2][e-1]--;
                }
            }
        }
    }
    /*
    fout << "1 1 1" << endl;
    cout << "1 1 1" << endl;*/
}
/*
void fashion(int j,int p,int s,int k){
    int counts=0;
    int t=k,t1=k,key=k;
    int temp[] = {1,1};
    for(int q=1; q<=j; q++){
        for(int w=1; w<=p; w++){
            for(int e=1; e<=s; e++){
                if((temp[0]!=q)||(temp[1]!=w)) key=k;
                if(key){
                    key--;
                    temp[0]=q;
                    temp[1]=w;
                    counts++;
                }
            }
        }

    }
    fout << counts;
    cout << counts;
    key=k;
    for(int q=1; q<=j; q++){
        for(int w=1; w<=p; w++){
            for(int e=1; e<=s; e++){
                if((temp[0]!=q)||(temp[1]!=w)) key=k;
                if(key){
                    key--;
                    temp[0]=q;
                    temp[1]=w;
                    fout << endl << q << " " << w << " " << e;
                    cout << endl << q << " " << w << " " << e;
                }
            }
        }
    }
    fout << "1 1 1" << endl;
    cout << "1 1 1" << endl;
}
*/
