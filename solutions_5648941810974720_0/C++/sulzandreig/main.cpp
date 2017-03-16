#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <fstream>
using namespace std;
ifstream in("data.in");
ofstream out("data.out");
vector<int> solutie;
string digits[] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"    };
unordered_map<char,int> sol;
void solve(string s, int caz)
{
    solutie.clear();
    for(char c = 'A' ; c <= 'Z' ; c ++)
        sol[c] = 0;
    for(int i = 0 ; i < s.size(); i++)
        sol[s[i]]++;
    char c;
    //sterg 0;
    int i=0;
    c = 'Z';
    while(sol[c]>0)
    {
         //delete 0
        for(int j = 0 ; j < digits[i].size() ; j++)
            sol[digits[i][j]]--;
        solutie.push_back(i);
    }
    //sterg 2 ca are W unic ramas
    i = 2;
    c = 'W';
    while(sol[c]>0)
    {
         //delete 8
        for(int j = 0 ; j < digits[i].size() ; j++)
            sol[digits[i][j]]--;
        solutie.push_back(i);
    }
    //sterg 4 ca are U unic
    i = 4;
    c = 'U';
    while(sol[c]>0)
    {
         //delete 8
        for(int j = 0 ; j < digits[i].size() ; j++)
            sol[digits[i][j]]--;
        solutie.push_back(i);
    }
 //sterg 8 ca are G unic
    i = 8;
    c = 'G';
    while(sol[c]>0)
    {
         //delete 8
        for(int j = 0 ; j < digits[i].size() ; j++)
            sol[digits[i][j]]--;
        solutie.push_back(i);
    }
    //sterg 3 are T unic ramas
    i = 3;
    c = 'T';
    while(sol[c]>0)
    {
         //delete 8
        for(int j = 0 ; j < digits[i].size() ; j++)
            sol[digits[i][j]]--;
        solutie.push_back(i);
    }
     //si sterg pe 1 ramas O
    i = 1;
    c = 'O';
    while(sol[c]>0 )
    {
         //delete 8
        for(int j = 0 ; j < digits[i].size() ; j++)
            sol[digits[i][j]]--;
        solutie.push_back(i);
    }
    //sterg 5 ca are F unic ramas
    i = 5;
    c = 'F';
    while(sol[c]>0)
    {
         //delete 8
        for(int j = 0 ; j < digits[i].size() ; j++)
            sol[digits[i][j]]--;
        solutie.push_back(i);
    }
    //sterg 6 ca are  S unic ramas
     i = 6;
    c = 'X';
    while(sol[c]>0)
    {
         //delete 8
        for(int j = 0 ; j < digits[i].size() ; j++)
            sol[digits[i][j]]--;
        solutie.push_back(i);
    }
    //sterg 7 ca are V unic
     i = 7;
    c = 'S';
    while(sol[c]>0)
    {
         //delete 8
        for(int j = 0 ; j < digits[i].size() ; j++)
            sol[digits[i][j]]--;
        solutie.push_back(i);
    }

//sterg 9 ca are N unic ramas
    i = 9;
    c = 'N';
    while(sol[c]>0 )
    {
         //delete 9
        for(int j = 0 ; j < digits[i].size() ; j++)
            sol[digits[i][j]]--;
        solutie.push_back(i);
    }


    sort(solutie.begin(),solutie.end(),[](int a,int b){return a<b;});
    out << "Case #"<<caz<<": ";
    for(int i : solutie)
        out<<i;
    out<<'\n';
}
int main()
{
    int t;
    string s;
    in>> t;
    for(int i = 0 ; i < t ; i ++)
    {

        in >> s;
        solve(s,i+1);
    }
    return 0;
}
