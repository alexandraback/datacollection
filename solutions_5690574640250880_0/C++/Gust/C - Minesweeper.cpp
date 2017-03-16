#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
using namespace std;
//Espaco extra para seguranca
class Mat
{
public:
  Mat(char matrix[55][55], int width, int height)
  {
    w = width;
    h = height;
    freed = 0;
    for(int y = 0; y < h;y++)
        for(int x = 0; x < w;x++){
          mat[x][y] = matrix[x][y];
          if(matrix[x][y] != '*') {
            freed++;
          }
        }
  }

  char mat[55][55];
  int w;
  int h;
  int freed;
  int id;

  Mat makeSubSet(int type = 0)
  {
    //type 0 left, type 1 up, type 3 alone
    Mat m(mat,w,h);
    if(type == 0)
    {
      for(int j = h-1; j >= 1;j--){
        for(int i = w-1; i >= 0;i--){
          if(mat[i][j] == '*' && isInsideValid(i,j-1) &&
            mat[i][j-1] == '*')
          {
            if(isInsideValid(i+1,j) && mat[i+1][j] != '*' &&
              isInsideValid(i+1,j-1) && mat[i+1][j-1] != '*'){
                m.mat[i][j] = '.'; m.freed++;
                m.mat[i][j-1] = '.'; m.freed++;
                return m;
              }
          }
        }
      }

    } else if(type == 1)
    {
      for(int i = w-1; i >= 1;i--){
        for(int j = h-1; j >= 0;j--){
          if(mat[i][j] == '*' && isInsideValid(i-1,j) &&
            mat[i-1][j] == '*')
          {
            if(isInsideValid(i,j+1) && mat[i][j+1] != '*' &&
              isInsideValid(i-1,j+1) && mat[i-1][j+1] != '*'){
                m.mat[i][j] = '.'; m.freed++;
                m.mat[i-1][j] = '.'; m.freed++;
                return m;
              }
          }
        }
      } 

    } else if(type == 2)
    {
      for(int i = w-1; i >= 0;i--){
        for(int j = h-1; j >= 0;j--){
          if (mat[i][j] == '*')
          {
            m.mat[i][j] = '.'; 
            if ( m.canOpen(i,j)) 
            {
              m.freed++;
              return m;
            } else
            {
              m.mat[i][j] = '*'; 
            }
          }
        }
      }
    }
    m.freed = -1;
    return m;
  }

  bool isNumber0(int px, int py)
  {
    if( mat[px][py] == '*') return false;
    //cout << "try: " << px<<"|"<<py<<endl;
    for(int y = -1; y <= 1; y++){
      for(int x = -1; x <= 1; x++)
      {
        if(x == 0 && y == 0) continue;
        if(isInsideValid(px+x,py+y)) {
          if(mat[px+x][py+y] == '*')
          {
            //cout << px+x <<"&"<<py+y<<endl;
            return false;
          }
        }
      }
    }
    //cout << "-------------TRUE-------: " << px << py << endl;
    return true;
  }

  bool canOpen(int px, int py)
  {
    //cout << "can Open: " << px<<"<|"<<py<<endl;
    for(int y = -1; y <= 1; y++){
      for(int x = -1; x <= 1; x++){
        if(x == 0 && y == 0) continue;

        if(isInsideValid(px+x,py+y)) {
          if(isNumber0(px+x, py+y) )
          {
            //cout << px+x<<"|"<<py+y<<endl;
            return true;
          }
        }
      }
    }
    return false; 
  }
  bool isInsideValid(int px, int py)
  {
    if(px >= w || py >= h) return false;
    if(px < 0 || py < 0) return false;

    return true;
  }

  void showMatrix()
  {
    for(int y = 0; y < h;y++){
      for(int x = 0; x < w;x++){
        cout << mat[x][y];
      }
      cout << endl;
    }
  }
};
char matrix[55][55];
int width;
int height;

bool isInsideValid(int px, int py)
{
  if(px >= width || py >= height) return false;
  if(px < 0 || py < 0) return false;

  return true;
}


int main(int, char**)
{
  int test_cases = 0;
  cin >> test_cases;

  for(int id = 1; id <= test_cases;id++)
  {

    int mines;
    cin >> height >> width >> mines;

    bool isImpossible = false;
    bool isSizeOne = false;
    //Conta espacos disponiveis
    long int allSpaces = height*width; 
    //Conta necessarios
    long int allowed_spaces = 4;
    //Se somente uma coluna ou linha, 2 espacos sao suficiente
    if(width == 1 || height == 1) {
      allowed_spaces = 2;
      isSizeOne = true;
    }

    vector<Mat> tracking;
    bool isFound = false;
    
    if(mines > 0 && allSpaces < mines+allowed_spaces && allSpaces-mines != 1){
      isImpossible = true;
    } else
    {
      //Fill
      for(int y = 0; y < height;y++)
        for(int x = 0; x < width;x++)
        {
          matrix[x][y] = '*';
        }

      int extra = 0;
      //Somente limpa volta se mais de 1 espaco
      if(allSpaces-mines != 1){
        for(int y = height-2; y < height; y++)
          for(int x = width-2; x < width;x++)
            if(isInsideValid(x,y)){
              matrix[x][y] = '.';
              extra++;
            }
      }

      bool isBreak = false;
      if (allSpaces-mines == 0) {
        isSizeOne = true;//impede backtracking;
      }
      //Somente limpa em volta se nao for soh um
      if(allSpaces-mines != 1 && isSizeOne){
        //Limpa arredores
        if (extra < allSpaces - mines )
        {
          for(int y = height-1; y >= 0;y--){
            if(isBreak) break;
            for(int x = width-1; x >= 0;x--)
            {

              if(matrix[x][y] == '*')
              {
                extra++;
                matrix[x][y] = '.';
                //Verifica parada
                if (extra >= allSpaces - mines )
                {
                  isBreak = true;
                  break;
                }//if
              }//if
            }//for
          }//endfor
        }
      }

      matrix[width-1][height-1] = 'c';
      //Backtracking

       // Mat origin(matrix, width, height);
       // cout << "origin: " << endl;
       // origin.showMatrix();

       // cout << origin.canOpen(0,3) << endl;

       // cout << origin.isNumber0(1,2) << endl;
       // cout << origin.isNumber0(1,3) << endl;
       // cout << origin.isNumber0(1,4) << endl;
      
       //  cout << "subset: " << endl;
       //  Mat subset = origin.makeSubSet(2);
       //  subset.showMatrix();
       //  cout << subset.freed << endl;


      // Mat origin(matrix, width, height);
      // cout << "origin: " << endl;
      // origin.showMatrix();
      // cout << "subset: " << endl;
      // Mat subset = origin.makeSubSet(2);
      // subset.showMatrix();
      // cout << "subset2: " << endl;
      // Mat subset2 = subset.makeSubSet(1);
      // subset2.showMatrix();
      // //cout << "subset3: " << endl;
      // Mat subset3 = subset2.makeSubSet(1);
      // subset3.showMatrix();
      // cout << "subset4: " << endl;
      // Mat subset4 = subset3.makeSubSet();
      // subset4.showMatrix();
      // cout << "FindLONE: " << endl;
      // Mat subset5 = subset4.makeSubSet(2);
      // subset5.showMatrix();
      // cout << "FindLONE2: " << endl;
      // Mat subset6 = subset5.makeSubSet(2);
      // subset6.showMatrix();
      // cout << "Type1: " << endl;
      // Mat subset7 = subset6.makeSubSet(1);
      // subset7.showMatrix();
      // cout << "Type0: " << endl;
      // Mat subset8 = subset7.makeSubSet();
      // subset8.showMatrix();
      // cout << "FindLONE3: " << endl;
      // Mat subset9 = subset8.makeSubSet(2);
      // subset9.showMatrix();

      Mat origin(matrix, width, height);
      tracking.push_back(origin);
      long int livres = allSpaces - mines;
      int id = 0;
      if (origin.freed == livres)
      {
        isSizeOne = true;
      }
      while(isSizeOne == false && isFound == false && isImpossible == false)
      {
        int size = (int)tracking.size();
        if(tracking.size() == 0){
          isImpossible = true;
          //cout << "IMPOSSIBLE "<<endl;
        } else 
        {
          //cout << tracking.size() << endl;
        }

        for(int i = 0; i < size; i++)
        {
          if(isFound || isImpossible) break;

          for(int type = 0; type < 3; type++){
            Mat subset = tracking[i].makeSubSet(type);
            //cout << "f: " << subset.freed << endl;
            if(subset.freed != -1 && subset.freed <= livres)
            {
              //cout << "push: "<<subset.freed<<endl;
              subset.id = id; id++;

              tracking.push_back(subset);  
    /***************************************
              cout << "ID: " << id << endl;
              cout << "Size: " << tracking.size() << endl;
              subset.showMatrix();cout << endl;
              if(id == 887)
              {
                cout << "END OF TIMES:" << endl;
                Mat subset2 = subset.makeSubSet(2);
                cout << "f: " << subset2.freed<< endl;
                subset2.showMatrix();
                cout << subset2.isNumber0(0,1)<<endl;
                cout << subset2.isNumber0(1,1)<<endl;
                cout << subset2.isNumber0(2,1)<<endl;
                return 0;
              }
    *************************************/
              if(subset.freed == livres)
              {
                isFound = true;
                break;
              }
            }
          }//endtype
          if(isFound == false && isImpossible == false){
            //cout << "erase"<<endl;
            tracking.erase(tracking.begin()+i);
          }
        }//endfor

      }//endwhile

      //end backtracking

    } 

    cout << "Case #" << id << ":" << endl;
    if(isImpossible == true){
      cout << "Impossible" << endl;
    }else if(isFound)
    {
      //cout << "FOUND!!!"<<endl;
      tracking[tracking.size()-1].showMatrix();
    } else {
      for(int y = 0; y < height;y++){
        for(int x = 0; x < width;x++){
          cout << matrix[x][y];
        }
        cout << endl;
      }
    }

  }
  return 0;
}