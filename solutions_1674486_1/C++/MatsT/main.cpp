#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <set>

using namespace std;

int main()
{
    int tests, classesCount, inhCount, tmp;
    cin >> tests;
    for(int i=1;i<=tests;i++){
        cin >> classesCount;
        map<int, list<int> > inhMap;
        map<int, list<int> > resMap;
        for(int j=1;j<=classesCount;j++){
            list<int> myList;
            cin >> inhCount;
            for(int k=0;k<inhCount;k++){
                cin >> tmp;
                myList.push_back(tmp);
            }
            inhMap.insert(pair<int, list<int> >(j, myList));
        }
        for(int j=1;j<=classesCount;j++){
            queue<int> theQueue;
            set<int> inheritsFrom;
            map<int,list<int> >::iterator mapit;
            list<int>::iterator listit;
            theQueue.push(j);
            while(!theQueue.empty()){
                int curr = theQueue.front();
                mapit=inhMap.find(curr);
                if(mapit!=inhMap.end()){
                    list<int> myList = mapit->second;
                    for (listit=myList.begin(); listit != myList.end(); listit++ ){
                        int inh=*listit;
                        if(inheritsFrom.find(inh)!=inheritsFrom.end()){
                            goto finish;
                        }
                        inheritsFrom.insert(inh);
                        theQueue.push(inh);
                    }
                }
                theQueue.pop();
            }
        }
        cout << "Case #"<<i<<": No"<<endl;
        continue;
        finish:
        cout << "Case #"<<i<<": Yes"<<endl;

    }
    return 0;
}
