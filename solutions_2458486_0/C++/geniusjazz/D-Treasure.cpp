#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> keyInDoor[201];
int keyOnHand[201];
int chest[201];
bool doorOpened[201];
bool memory[2097152];

vector<int> doorOrder;
int N,M;

    ifstream fin("D-small-attempt1.in");
    ofstream fout("D-small-attempt1.out");

bool DFS()
{
     int t = 0;
     for (int i = 0 ; i < N ; i++)
         if (doorOpened[i]) t += 1<<i ; 
     if (memory[t]) return false;
     // Go through all doors
     bool gameOver = true;
     for (int i = 0 ; i < N ; i++)
         if (doorOpened[i] == false)
         {
            gameOver = false;
            if (keyOnHand[chest[i]] > 0) 
            {
                 keyOnHand[chest[i]]--;
                 for (int k = 0 ; k < keyInDoor[i].size() ; k++)    
                     keyOnHand[keyInDoor[i][k]]++;                         
                 doorOpened[i] = true;                   
                 bool tempAns = DFS();
                 if (tempAns)
                 {
                      doorOrder.push_back(i);
                      return true;            
                 }              
                 else
                 {
                     keyOnHand[chest[i]]++;
                     doorOpened[i] = false; 
                     for (int k = 0 ; k < keyInDoor[i].size() ; k++)    
                         keyOnHand[keyInDoor[i][k]]--;  
                     
                 }                   
            }
         }     
     memory[t] = true; 
     return gameOver;
     
}

int main()
{

 //   ifstream fin("B-large.in");
 //   ofstream fout("B-large.out");    
    int T, K;
    fin >> T;
    int keyNum, keyType;
    for (int t = 1 ; t <= T; t++)
    {  
		fin >> K >> N;
		memset(keyOnHand, 0, sizeof(keyOnHand));
		    
		for (int i = 0 ; i < K ; i++)
        {
            fin >> keyType;
            keyOnHand[keyType]++;
        }
		
		M = 0;
		memset(memory, 0, sizeof(memory));
		for (int i = 0 ; i < N ; i++)
		{
		    fin >> chest[i] >> keyNum;
		    if (M < chest[i]) M = chest[i];
		    
		    doorOpened[i] = false;
		    keyInDoor[i].clear();
		    
		    for (int k = 0 ; k < keyNum ; k++)
		    {
                fin >> keyType;
                keyInDoor[i].push_back(keyType);
            }
        }    
        
        doorOrder.clear();        
        bool answer = DFS();
  
		fout << "Case #" << t << ": ";
		if (answer == false) fout << "IMPOSSIBLE" << endl;
		else 
        {
             for (int i = doorOrder.size()-1 ; i > 0 ; i--)
                 fout << doorOrder[i]+1 << " ";
             fout << doorOrder[0]+1 << endl;
        }
        
    }
}




