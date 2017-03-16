#include <stdio.h>
#include <malloc.h>
#include <vector>
#include <algorithm>

#define WHITE 0
#define GRAY 1
#define BLACK 2

using namespace std;
typedef struct vertexstruct{
   int color;
   vector<int> edgelist;
}vertex;

int ordinarydfs(int v,vertex *vertices,int numvertices){
    if(v == numvertices){
        return 1;       
    }

    if(vertices[v].color == WHITE){
         vertices[v].color = GRAY;
         for(int i=0;i<vertices[v].edgelist.size();i++){
             int x = ordinarydfs(vertices[v].edgelist[i],vertices,numvertices);
             if(x ==1) return 1;
         }
         vertices[v].color = BLACK; 
     }
     return 0;
}

int checkcycle(int v,vector<int>path,vertex *vertices,int numvertices){
    vector<int>::iterator it;
    vector<int>::iterator x;
    it = find (path.begin(), path.end(), v);
    for(x =it;x<path.end();x++)
        vertices[*x].color = WHITE;
    for(x =it;x<path.end();x++){
        if(ordinarydfs(*x,vertices,numvertices))
            return 1;   
    }
    for(x =it;x<path.end();x++)
        vertices[*x].color = GRAY;

    return 0;

}

long dfs(int v,vertex *vertices,int numvertices,vector<int> path){
    long paths = 0;
    if(v == numvertices){
            return 1;       
    }
    if(vertices[v].color == GRAY) {
         if(checkcycle(v,path,vertices,numvertices)) return -1;
    }   
    if(vertices[v].color == WHITE){
        vertices[v].color = GRAY;
        path.push_back(v);
        for(int i=0;i<vertices[v].edgelist.size();i++){     
            long x = dfs(vertices[v].edgelist[i],vertices,numvertices,path);
            vertices[vertices[v].edgelist[i]].color = WHITE;
            if(x == -1) return -1;
            paths += x;
        }
        vertices[v].color = BLACK;  
    }
    return paths % 1000000000;
}

void numpaths(int numvertices,int numedges,vertex *vertices){
    vector<int> path;
    long numpaths = 0;
    numpaths = dfs(1,vertices,numvertices,path);
    if(numpaths == -1)
        printf("INFINITE PATHS\n");
    else
        printf("%ld\n",numpaths);
}



int main(){
    int edgecount=0;
    int  numverts,numedges;
    fscanf(stdin,"%d %d",&numverts,&numedges);
   vertex verts[numverts+1];
   for(int i =1;i<=numverts;i++)
       verts[i].color = WHITE;
   edgecount = 0; 
   int a,b;
   while(edgecount < numedges){
       scanf("%d %d",&a,&b);
       verts[a].edgelist.push_back(b);
       edgecount++;
       }
   numpaths(numverts,numedges,verts);
}
