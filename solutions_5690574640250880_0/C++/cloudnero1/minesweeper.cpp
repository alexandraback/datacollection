#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <set>
using namespace std;

int r, c, m, min_sweep, cell;
int mines[50][50];
set<pair<int, int> > subject;

int main(){
    
    int partmine(int i, int j, int &cell);
    int t;
    ifstream infile("C-small-attempt7.in");
    //ifstream infile("a.txt");
    ofstream out("mine2.in");
    //ofstream out("ans.txt");
    if(!infile){
        cerr << "error" ;
        return -1;
    }
    infile >> t;
    for(int i = 0; i < t; i++){
        infile >> r >> c >> m;
        min_sweep = 0;
        if(c == 1)
            min_sweep = 2;
        else if(c == 2){
            if(r == 1)
                min_sweep = 2;
            else
                min_sweep = 4;
        }
        cell = r * c- m;
        out << "Case #" <<i+1 << ":\n";
        memset(mines, 0, sizeof(mines));


        if(cell == 1){
            bool firsttime = true;         
            for(int i = 0; i < r; i++){
                        for(int m = 0; m < c; m++){
                            if(firsttime){
                                firsttime = false;
                                out << 'c';
                            }
                            else if(mines[i][m] == 0)
                                out << "*";
                            else
                                out << ".";
                        }
                        out << "\n";
                    }
            continue;
        }



        if(min_sweep > cell){
            out << "Impossible\n";
        }else{
            int j,k;
            for(j = 0; j < r; j++){
                for(k = 0; k < c; k++){
                    int clone = cell;
                    partmine(j, k, cell);
                    if(cell == 0){
                        break;
                    }
                    else{
                        cell = clone;
                        mines[j][k] = 0;
                    }
                }
                if(cell == 0){
                    for(int i = 0; i < r; i++){
                        for(int m = 0; m < c; m++){
                            if(mines[i][m] == 0)
                                out << "*";
                            else if(i == j && m == k)
                                out << "c";
                            else
                                out << ".";
                        }
                        out << "\n";
                    }
                    break;
                }
            }
        
            if(cell != 0)
               out << "Impossible\n";
                
        }
    }
    out.close();
    infile.close();
}

int partmine(int i, int j, int &cell){
    set<pair<int, int> > sorrund(int j, int k);
   bool check = false; 
    if(mines[i][j] == 1)
        return 0;//has checked;
    int k = cell;
    if(mines[i][j] == 0){
        cell--;
        check = true;
    }
    mines[i][j] = 1;
    set<pair<int, int> > sub = sorrund(i, j);//change sorrounds
    if(sub.size() == 0)
        return 0;
     //   cout << sub.size() << "sub" << i << j << endl;
    cell -= sub.size();
    //cout << cell << "cell" << endl; 
    if(cell == 0){
       // cout << i << "    " << j << endl;
        return 1;
    }else if(cell < 0){
        for(set<pair<int, int> >::iterator it = sub.begin(); it != sub.end(); it++){
            cell++;
            mines[it->first][it->second] = 0;
     //       cout << it -> first << "  " << it -> second << endl;
        }
        if(check)
            cell++;
        return 0;
    }

    for(int i = 0; i < r; i++)
        for(int j = 0; j < c; j++){
            if(mines[i][j] == 2){
                partmine(i, j, cell);
                if(cell == 0)
                    return 0;
                mines[i][j] = 2;
            }
        }

        for(set<pair<int, int> >::iterator it = sub.begin(); it != sub.end(); it++){
            cell++;
        //cout << it->first << it -> second << "itcell" << check<< endl;
            mines[it->first][it->second] = 0;
        }
        if(check)
            cell++;

    return 0;
}

set<pair<int, int> > sorrund(int j, int k){
    set<pair<int, int> > sub;
    //cout << j << mines[0][2] << "sun" <<endl;
                if(j-1 >= 0 && mines[j-1][k] == 0){
                    mines[j-1][k] = 2;
                    sub.insert(make_pair(j-1, k));
      //              cout << 1111 << endl;
                }
                if(j+1 < r && mines[j+1][k] == 0){
                    mines[j+1][k] = 2;
                    sub.insert(make_pair(j+1, k));
        //            cout << j << " " <<222 << endl;
                }
                if(k-1>=0 && mines[j][k-1] == 0){
                    mines[j][k-1] = 2;
                    sub.insert(make_pair(j, k-1));
          //          cout << 333 << endl;
                }
                if(k+1 < c && mines[j][k+1] == 0){
                    mines[j][k+1] = 2;
                    sub.insert(make_pair(j, k+1));
            //        cout << 4 << endl;
                }
                if(j-1>=0 && k-1>=0 && mines[j-1][k-1] == 0){
                    mines[j-1][k-1] = 2;
                    sub.insert(make_pair(j-1, k-1));
              //      cout << 5 << endl;
                }
                if(j-1>=0 && k+1 < c && mines[j-1][k+1] == 0){
                    mines[j-1][k+1] = 2;
                    sub.insert(make_pair(j-1, k+1));
                //    cout << 6 << endl;
                }
                if(j+1<r && k-1>=0 && mines[j+1][k-1] == 0){
                    mines[j+1][k-1] = 2;
                    sub.insert(make_pair(j+1, k-1));
                  //  cout << 7 << endl;
                }
                if(j+1<r && k+1 < c && mines[j+1][k+1] == 0){
                    mines[j+1][k+1] = 2;
                    sub.insert(make_pair(j+1, k+1));
                    //cout << 8 << endl;
                }
    return sub;

}
