#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

int main(int argc, char *argv[])
{
    queue<int> q;
    string a[1][1];
    int canuse = 0;
    int num1;
    int s,s2;
    int bomb;
    int count = 0;
    int hasmi = 0;
    int cheap = 0;
 ifstream myfile ("C-small-attempt2.in");
 ofstream myfile2 ("output.txt");
   myfile >> num1;
   for(int aa=1;aa<=num1;aa++)
{ // for round

int ttt = q.size();
for(int i=0;i<ttt;i++)
q.pop();
count = 0;
cheap = 0;
           myfile >> s >> s2 >> bomb;
           string a[s][s2];
           string b[s][s2];
           for(int i=0;i<s;i++)// defult
           {
                   for(int j=0;j<s2;j++)
                   {
                           a[i][j] = '#';
                           b[i][j] = '#';
                   }
           }
           //
           a[s-1][s2-1] = 'c';
           b[s-1][s2-1] = 'c';
           if(s-1 >= 0 && s2-2 >= 0)
           {
           a[s-1][s2-2] = '-';
           b[s-1][s2-2] = '-';   
           }
           if(s-2 >= 0 && s2-1 >= 0)
           {
           a[s-2][s2-1] = '-';
           b[s-2][s2-1] = '-'; 
           }
           if(s-2 >=0 && s2-2 >= 0)
           { 
           a[s-2][s2-2] = '-'; 
           b[s-2][s2-2] = '-';   
           }
            
           // queue
           q.push(s-1);
           q.push(s2-2);
           q.push(s-2);
           q.push(s2-1);
           q.push(s-2);
           q.push(s2-2);
           //
           // test put bomb
           for(int i=0;i<s;i++)
           {
                              if(count == bomb)
           break;
                   for(int j=0;j<s2;j++)
                   { // for j
                 //  cout << "j : " << j << endl;
                   cheap = 0;
                     if(b[i][j] == "#" || b[i][j] == "+" || (count+1 == bomb && count > 0))
                     {
                                //
                                b[i][j] = '*';
                              /*  if(i-1 >= 0 && j-1 >= 0)
                                {
                                if(b[i-1][j-1] == "#" || b[i-1][j-1] == "-")
                                b[i-1][j-1] = '+';
                                }
                                if(i-1 >=0)
                                {
                                if(b[i-1][j] == "#" || b[i-1][j] == "-")
                                b[i-1][j] = '+';
                                }
                                if(i-1 >= 0 && j+1 < s2)
                                {
                                if(b[i-1][j+1] == "#" || b[i-1][j+1] == "-")
                                b[i-1][j+1] = '+';
                                }
                                if(j-1 >= 0)
                                {
                                if(b[i][j-1] == "#" || b[i][j-1] == "-")
                                b[i][j-1] = '+';
                                }
                                if(j+1 < s2)
                                {
                                if(b[i][j+1] == "#" || b[i][j+1] == "-")
                                b[i][j+1] = '+';
                                }
                                if(i+1 < s && j-1 >= 0)
                                {
                                if(b[i+1][j-1] == "#" || b[i+1][j-1] == "-")
                                b[i+1][j-1] = '+';
                                }
                                if(i+1 < s)
                                {
                                if(b[i+1][j] == "#" || b[i+1][j] == "-")
                                b[i+1][j] = '+';
                                }
                                if(i+1 <s && j+1 <s2)
                                {
                                if(b[i+1][j+1] == "#" || b[i+1][j+1] == "-")
                                b[i+1][j+1] = '+';
                                }*/
                                //
                                //

                                while(!q.empty())
                                                 {// while
                                                 int y,x;
                                                      while (1)
                                                      {
                                                      y = q.front();
                                                      q.pop();
                                                      x = q.front();
                                                      q.pop();
                                                      if((x >= 0 && x <s2) && (y >=0  && y < s))
                                                      break;
                                                      if(q.size() == 0)
                                                      break;
                                                      }
                                                      if(y < 0)
                                                      break;
                                                      if(x < 0)
                                                      break;
                                                    //  cout << y << " " << x << endl;
                                                      if(y-1 >= 0 && x-1 >=0)
                                                      {
                                                      if(b[y-1][x-1] == "*")
                                                      b[y][x] = '+';
                                                      }
                                                      if(y-1 >= 0)
                                                      {
                                                      if(b[y-1][x] == "*")
                                                      b[y][x] = '+';
                                                      }
                                                      if(y-1 >=0 && x+1 < s2)
                                                      {
                                                      if(b[y-1][x+1] == "*")
                                                      b[y][x] = '+';
                                                      }
                                                      if(x-1 >= 0)
                                                      {
                                                      if(b[y][x-1] == "*")
                                                      b[y][x] = '+';
                                                      }
                                                      if(x+1 < s2)
                                                      {
                                                      if(b[y][x+1] == "*")
                                                      b[y][x] = '+';
                                                      }
                                                      if(y+1 < s && x-1 >= 0)
                                                      {
                                                      if(b[y+1][x-1] == "*")
                                                      b[y][x] = '+';
                                                      }
                                                      if(y+1 < s)
                                                      {
                                                      if(b[y+1][x] == "*")
                                                      b[y][x] = '+';
                                                      }
                                                      if(y+1 < s && x+1 < s2)
                                                      {
                                                      if(b[y+1][x+1] == "*")
                                                      b[y][x] = '+';
                                                      }
                                                      if(b[y][x] == "-")
                                                      {
                                                                 if(y-1 >=0 && x-1 >= 0)
                                                                 {
                                                                 if(b[y-1][x-1] == "#")
                                                                 {
                                                                 b[y-1][x-1] = '-';
                                                                 q.push(y-1);
                                                                 q.push(x-1);
                                                                 }
                                                                 }
                                                                 
                                                                 if(y-1 >= 0)
                                                                 {
                                                                 if(b[y-1][x] == "#")
                                                                 {
                                                                 b[y-1][x] = '-';
                                                                 q.push(y-1);
                                                                 q.push(x);
                                                                 }
                                                                 }
                                                                 
                                                                 
                                                                 if(y-1 >=0 && x+1 < s2)
                                                                 {
                                                                 if(b[y-1][x+1] == "#")
                                                                 {
                                                                 b[y-1][x+1] = '-';
                                                                 q.push(y-1);
                                                                 q.push(x+1);
                                                                 }
                                                                 }
                                                                 
                                                                 if(x-1 >= 0)
                                                                 {
                                                                 if(b[y][x-1] == "#")
                                                                 {
                                                                 b[y][x-1] = '-';
                                                                 q.push(y);
                                                                 q.push(x-1);
                                                                 }
                                                                 }
                                                                 
                                                                 if(x+1 < s2)
                                                                 {
                                                                 if(b[y][x+1] == "#")
                                                                 {
                                                                 b[y][x+1] = '-';
                                                                 q.push(y);
                                                                 q.push(x+1);
                                                                 }
                                                                 }
                                                                 
                                                                 if(y+1 <s && x-1 >=0)
                                                                 {
                                                                 if(b[y+1][x-1] == "#")
                                                                 {
                                                                 b[y+1][x-1] = '-';
                                                                 q.push(y+1);
                                                                 q.push(x-1);
                                                                 }
                                                                 }
                                                                 
                                                                 if(y+1 < s)
                                                                 {
                                                                 if(b[y+1][x] == "#")
                                                                 {
                                                                 b[y+1][x] = '-';
                                                                 q.push(y+1);
                                                                 q.push(x);
                                                                 }
                                                                 }
                                                                 
                                                                 if(y+1 < s && x+1 < s2)
                                                                 {
                                                                 if(b[y+1][x+1] == "#")
                                                                 {
                                                                 b[y+1][x+1] = '-';
                                                                 q.push(y+1);
                                                                 q.push(x+1);
                                                                 }
                                                                 }
                                                      }
                                                 } // while
                                //
                                // check all reval
                                for(int kk=0;kk<s;kk++)
                                {
                                        for(int zz=0;zz<s2;zz++)
                                        {
                                        hasmi = 0;
                                        if(b[kk][zz] == "#")
                                        cheap = cheap+1;
                                        }
                                }
                               // cout << "cheap : "<<cheap << endl;
                                if(cheap == 1 && count+1 <= bomb)
                                {
                                canuse = 0;
                                }
                                if(cheap > 1)
                                canuse = -1;
                                if(canuse == 0)
                                {
           a[i][j] = '*';
           b[i][j] = '*';
           q.push(s-1);
           q.push(s2-2);
           q.push(s-2);
           q.push(s2-1);
           q.push(s-2);
           q.push(s2-2);
           //
                                           for(int sep =0;sep<s;sep++)
                                {
                                        for(int sep2=0;sep2<s2;sep2++)
                                        {
                                                b[sep][sep2] = a[sep][sep2];
                                        }
                                }
           //
           count = count+1;
           if(count == bomb)
           break;
                                }
                                else if(canuse == -1)
                                {
           q.push(s-1);
           q.push(s2-2);
           q.push(s-2);
           q.push(s2-1);
           q.push(s-2);
           q.push(s2-2);
           canuse = 0;
                      //
                                           for(int sep =0;sep<s;sep++)
                                {
                                        for(int sep2=0;sep2<s2;sep2++)
                                        {
                                                b[sep][sep2] = a[sep][sep2];
                                        }
                                }
           //
                                }
                                // check all reval
                     }      
                   } // for j
           }
                                                                         //
           if(count == bomb)
           {
                    myfile2 << "Case #" << aa << ":" << endl;
                                           for(int sep =0;sep<s;sep++)
                                {
                                        for(int sep2=0;sep2<s2;sep2++)
                                        {
                                                if(b[sep][sep2] == "#" || b[sep][sep2] == "-")
                                                myfile2 << ".";
                                                else
                                                myfile2 << b[sep][sep2];
                                        }
                                        myfile2 << endl;
                                }
           }
           else
           {
           myfile2 << "Case #" << aa << ":"<< endl << "Impossible" << endl;
           }
} //
    system("PAUSE");
    return EXIT_SUCCESS;
}
