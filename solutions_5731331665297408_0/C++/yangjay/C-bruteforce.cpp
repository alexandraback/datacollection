#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

int ncities;
int idMap[8];
pair<string,int> zips[8];
int cities[8];

bool graph[8][8];

bool checkCities(){
    int flights[8];//inbound flights
    for(int i=0;i<ncities;i++){
        if(i==0){
            flights[cities[i]] = -1;
        }
        else{
            int curr = cities[i-1];
            while(curr!=-1){
                if(graph[curr][cities[i]]){
                    flights[cities[i]] = curr;
                    break;
                }
                curr = flights[curr];
            }
            if(curr==-1){
                return false;
            }
        }
    }
    return true;
}

bool cmp_first(const pair<string,int>& a,const pair<string,int>& b){
    return a.first<b.first;
}

void output_cities(){
    for(int i=0;i<ncities;i++){
        cout << zips[cities[i]].first;
    }
    cout << endl;
}

int main(){
    int ncases;
    cin >> ncases;
    for(int c=1;c<=ncases;c++){
        int M;
        cin >> ncities >> M;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                graph[i][j] = false;
            }
        }
        for(int i=0;i<ncities;i++){
            cin >> zips[i].first;
            zips[i].second = i;
        }
        sort(zips,zips+ncities,cmp_first);
        for(int i=0;i<ncities;i++){
            idMap[zips[i].second] = i;
        }
        for(int i=0;i<M;i++){
            int a,b;
            cin >> a >> b;
            a--;b--; //zero indexing
            graph[idMap[a]][idMap[b]] = true;
            graph[idMap[b]][idMap[a]] = true;
        }
        for(int i=0;i<ncities;i++)
            cities[i] = i;
        cout << "Case #" << c << ": ";
        do{
            if(checkCities()){
                //output time
                output_cities();
                break;
            }
        }while(next_permutation(cities,cities+ncities));
    }
}
