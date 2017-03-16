#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <stack>
#include<map>

using namespace std;

struct move
{
    int x;
    int y;
    string path;
    int jump;


}temp;

int main()
{
    int t;
    cin>>t;
	
	int count = 1;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        
        map< pair<int,int>, bool> visited; 
        

        queue< move> bfs;
        temp.x = 0;
        temp.y = 0;
        temp.jump = 0;
 		temp.path = "";
 		       
        pair<int,int> coord;
        coord.first = 0;
        coord.second = 0;
        
        visited[coord] = true;
        bfs.push(temp);
        while(!bfs.empty())
        {
            move top = bfs.front();
            bfs.pop();
         	
         	//cout<<top.jump<<endl;    
            int jump = top.jump+1; 
            int X = top.x;
            int Y = top.y;
            
            if(X == x && Y==y)
            {
                cout<<"Case #"<<count<<": "<<top.path<<endl;
                count++;
 				while(!bfs.empty())
 					bfs.pop();               
                visited.clear();
                break;
            
            }
            
            coord.first = X+jump;
            coord.second = Y;
            
            if(!visited[coord])
            {
                temp.x = X+jump;
                temp.y = Y;
                temp.jump = jump;
                string p;
                p = top.path;
                p.push_back('E');
                
                temp.path = p;
                visited[coord]= true; 
                
                bfs.push(temp);
            }
            coord.first = X-jump;
            coord.second = Y;
            if(!visited[coord])
            {
                temp.x = X-jump;
                temp.y = Y;
                temp.jump = jump;
                string p;
                p = top.path;
                p.push_back('W');
                temp.path = p;
                visited[coord]= true; 
                
                bfs.push(temp);
            }
            coord.first = X;
            coord.second = Y+jump;;
            if(!visited[coord])
            {
                temp.x = X;
                temp.y = Y+jump;
                temp.jump = jump;
                string p;
              	p = top.path;
                p.push_back('N');
                temp.path = p;
                visited[coord]= true; 
                
                bfs.push(temp);
            }
            coord.first = X;
            coord.second = Y-jump;;
            if(!visited[coord])
            {
                temp.x = X;
                temp.y = Y-jump;
                temp.jump = jump;
                string p;
                p = top.path;
                p.push_back('S');
                temp.path = p;
                visited[coord]= true; 
                
                bfs.push(temp);
            }


        }

    }
}
