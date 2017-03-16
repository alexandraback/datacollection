#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <iterator>

using namespace std;

int main(){
    int t;
    int decwar(set<double> &naomi, set<double> &ken);
    int realwar(set<double> naomi, set<double> ken);
    //ifstream infile("a.txt");
    ifstream infile("D-small-attempt1.in");
    ofstream out("war.in");
    if(!infile){
        cerr << "error";
        return -1;
    }

    infile >> t;
    set<double> naomi, ken;

    for(int i = 0; i < t; i++){
        int num;
        infile >> num;

        for(int j = 0; j < num; j++){
            double mass;
            infile >> mass;
            naomi.insert(mass);
        }

        for(int j = 0; j < num; j++){
            double mass;
            infile >> mass;
            ken.insert(mass);
        }

        int real = realwar(naomi, ken);
        int dec = decwar(naomi, ken);
        out << "Case #" << i+1 << ": " << dec << " " << real << "\n";

        naomi.erase(naomi.begin(), naomi.end());
        ken.erase(ken.begin(), ken.end());
    }
    infile.close();
    out.close();
    return 0;
}

int realwar(set<double> naomi, set<double> ken){
    int points = 0;

    for(set<double>::iterator it = naomi.begin(); it != naomi.end(); it++){
        bool check = true;
        for(set<double>::iterator it2 = ken.begin(); it2 != ken.end(); it2++){
            if(*it2 > *it){
                ken.erase(it2);
                check = false;
                break;
            }
        }
        if(check){
            points++;
            ken.erase(ken.begin());
        }
    }
    return points;
}

int decwar(set<double> &naomi, set<double> &ken){
    int points = 0;
    for(set<double>::iterator it = naomi.begin(); it != naomi.end(); it++){
        bool check = true;
        for(set<double>::iterator it2 = ken.end(); it2 != ken.begin(); ){
            it2--;
            if(*it > *it2)
                return points + naomi.size();
            else if(*it > *ken.begin()){
                points++;
                ken.erase(*ken.begin());
                naomi.erase(*it);
                break;
            }else{
                ken.erase(*it2);
                naomi.erase(*it);
                break;
            }
            
        }
    }
    return points;
}
