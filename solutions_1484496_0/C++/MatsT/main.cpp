#include <iostream>
#include <map>
#include <list>

using namespace std;

int numbers[20];
map<int, list<int> > sumMap;

bool count(int index, int sumSoFar, list<int> listOfInts){
    list<int>::iterator listit;
    map<int,list<int> >::iterator mapit;
    mapit=sumMap.find(sumSoFar);
    if(mapit!=sumMap.end()){
        list<int> myList = mapit->second;
        bool first=true;
        for(listit=myList.begin(); listit != myList.end(); listit++ ){
            if(!first){
                cout << " ";
            }
            first=false;
            cout << *listit;
        }
        cout << endl;
        first=true;
        for(listit=listOfInts.begin(); listit != listOfInts.end(); listit++ ){
            if(!first){
                cout << " ";
            }
            first=false;
            cout << *listit;
        }
        return true;
    }
    if(index==20){
        if(sumSoFar>0){
            sumMap.insert(pair<int, list<int> >(sumSoFar, listOfInts));
        }
        return false;
    }
    int newnumber=numbers[index];
    if(count(index+1, sumSoFar, listOfInts)){
        return true;
    }

    listOfInts.push_back(newnumber);
    sumSoFar+=newnumber;
    if(count(index+1, sumSoFar, listOfInts)){
        return true;
    }
    return false;
}

int main()
{
	int tests, amount;
    cin >> tests;
	for(int i = 1; i<=tests; i++){
	    sumMap.clear();
	    cin >> amount;
	    for(int j=0;j<amount;j++){
            cin >> numbers[j];
	    }
	    if(i!=1){
            cout<<endl;
	    }
	    cout << "Case #"<<i<<": "<<endl;

	    list<int> newlist;
	    if(!count(0,0,newlist)){
            cout << "Impossible";
	    }
	}
}
