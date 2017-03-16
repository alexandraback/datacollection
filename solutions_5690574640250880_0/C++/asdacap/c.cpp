#include<iostream>

using namespace std;

class Grid{
    public:
        int maxx;
        int maxy;
        int** grid;

        //only check right, bottom ,rightbottom
        bool hasZeroNextToIt(int x,int y){
            if(isValid(x+1,y) && grid[y][x+1]==0)return true;
            if(isValid(x,y+1) && grid[y+1][x]==0)return true;
            if(isValid(x+1,y+1) && grid[y+1][x+1]==0)return true;
            return false;
        }

        bool isValid(int x,int y){
            return x>=0 && y>=0 && x<maxx && y<maxy && grid[y][x]!=-1;
        }

        void addIfValid(int x, int y){
            if(isValid(x,y)){
                grid[y][x]++;
            }
        }

        void minusIfValid(int x, int y){
            if(isValid(x,y)){
                grid[y][x]--;
            }
        }

        //only mark on right and bottom and combination
        void markAdjecent(int x, int y){
            addIfValid(x+1,y);
            addIfValid(x,y+1);
            addIfValid(x+1,y+1);
            addIfValid(x-1,y+1);
            addIfValid(x+1,y-1);
        }

        void unmarkAdjecent(int x, int y){
            minusIfValid(x+1,y);
            minusIfValid(x,y+1);
            minusIfValid(x+1,y+1);
            minusIfValid(x-1,y+1);
            minusIfValid(x+1,y-1);
        }

        bool isHereGood(int x, int y,int left){
            bool result=false;
            int prevvalue=grid[y][x];
            grid[y][x]=-1;
            markAdjecent(x,y);

            /*
            cout<<"test is here good"<<endl;
            printIt();
            */
            
            if(left>1 && ( maxx-x==2 )){

                if(
                (!isValid(x,y+1) || hasZeroNextToIt(x,y+1))&&
                (!isValid(x+1,y+1) || hasZeroNextToIt(x+1,y+1))){
                    result=true;
                }

            }else if(left>1 && (maxy-y==2)){

                if(
                (!isValid(x+1,y) || hasZeroNextToIt(x+1,y))&&
                (!isValid(x+1,y+1) || hasZeroNextToIt(x+1,y+1))){
                    result=true;
                }

            }else{

                if(
                (!isValid(x+1,y) || hasZeroNextToIt(x+1,y))&&
                (!isValid(x,y+1) || hasZeroNextToIt(x,y+1))&&
                (!isValid(x+1,y+1) || hasZeroNextToIt(x+1,y+1))){
                    result=true;
                }

            }

            /*
            cout<<" Right "<<hasZeroNextToIt(x+1,y);
            cout<<" Bottom "<<hasZeroNextToIt(x,y+1);
            cout<<" BottomRight "<<hasZeroNextToIt(x+1,y+1);
            */

            unmarkAdjecent(x,y);
            grid[y][x]=prevvalue;
            return result;
        }

        int markToHorizontal(int x,int y,int left){
            //cout<<"Mark horizontal "<<x<<" "<<y<<endl;
            for(int i=x;i<maxx && left>0;i++){
                grid[y][i]=-1;
                markAdjecent(i,y);
                left--;
            }
            return left;
        }

        int markToVertical(int x,int y,int left){
            //cout<<"Mark vertical "<<x<<" "<<y<<endl;
            for(int i=y;i<maxy && left>0;i++){
                grid[i][x]=-1;
                markAdjecent(x,i);
                left--;
            }
            return left;
        }

        int markSame(int x,int y,int left){
            //cout<<"Mark both "<<x<<" "<<y<<" left "<<left<<endl;
            
            int howmanyx=((left-1)/2);
            howmanyx++;
            //x will do the common
            int howmanyy=((left-1)/2);
            if(left%2==0){
                //y will do the extra
                howmanyy++;
            }

            if(maxx-(howmanyx+x)==1){
                return -1;
            }

            if(maxy-(howmanyy+y+1)==1){
                return -1;
            }
            
            //cout<<"Mx "<<howmanyx<<" my "<<howmanyy<<endl;
            for(int i=x;i<x+howmanyx && left>0;i++){
                //cout<<"MK "<<y<<" "<<i<<endl;
                grid[y][i]=-1;
                markAdjecent(i,y);
                left--;
            }
            for(int i=y+1;i<y+howmanyy+1 && left>0;i++){
                //cout<<"MKy "<<y<<" "<<i<<endl;
                grid[i][x]=-1;
                markAdjecent(x,i);
                left--;
            }
            return left;
            return 0;
        }

        void printIt(){
            for(int y=0;y<maxy;y++){
                for(int x=0;x<maxx;x++){

                    if(x+1==maxx && y+1==maxy){
                        cout<<"c";
                    }else{
                        if(grid[y][x]==-1){
                            cout<<"*";
                        }else{
                            //cout<<grid[y][x];
                            cout<<".";
                        }
                    }

                }
                cout<<endl;
            }
        }

        int mNum(){
            int counter=0;
            for(int iy=0;iy<maxy;iy++){
                for(int ix=0;ix<maxx;ix++){
                    if(grid[iy][ix]==-1){
                        counter++;
                    }
                }
            }
            return counter;
        }

};

int main(int argv,char** argc){

    int ntest;
    cin>>ntest;
    int nums1[4];
    int nums2[4];

    for(int testi=0;testi<ntest;testi++){
        
        int r,c,m;
        cin>>r>>c>>m;
    
        int** grid=new int*[r]; 
        for(int i=0;i<r;i++){
            grid[i]=new int[c];
            for(int i2=0;i2<c;i2++){
                grid[i][i2]=0;
            }
        }

        /* Strategy, loop from top left diagonally down
         * Check first if it is valid to put in the coordinate.
         * If not, say impossible. 
         * fill whichever direction right or down that has lower space available
         * if the required mine is less than the space, and space-mine == 1
         * lay the mine out to the higher direction.
         * if there is no alternate direction (both has same space), divide the mine by two (remember the common one)
         * and then lay it out. 
         */

        Grid g;
        g.grid=grid;
        g.maxx=c;
        g.maxy=r;

        //meaning there is only one number
        if((r*c)-m==1){
            for(int i=0;i<r;i++){
                for(int i2=0;i2<c;i2++){
                    grid[i][i2]=-1;
                }
            }
            cout<<"Case #"<<testi+1<<": "<<endl;
            g.printIt();
            continue;
        }

        int left=m;
        int curx=0;
        int cury=0;
        bool impossible=false;

        while(left>0){
            if(g.isHereGood(curx,cury,left)){
                int onright=g.maxx-curx;
                int onbottom=g.maxy-cury;
                //cout<<"Loop pos "<<curx<<" "<<cury<<" onright "<<onright<<" onbottom "<<onbottom<<endl;
                if(onbottom<onright){
                    if(left>=onbottom){
                        left=g.markToVertical(curx,cury,left);
                        curx++;
                    }else if(onbottom-left==1){
                        left=g.markToHorizontal(curx,cury,left);
                        cury++;
                    }else{
                        left=g.markToVertical(curx,cury,left);
                        curx++;
                    }
                }else if(onright<onbottom){
                    if(left>=onright){
                        left=g.markToHorizontal(curx,cury,left);
                        cury++;
                    }else if(onright-left==1){
                        left=g.markToVertical(curx,cury,left);
                        curx++;
                    }else{
                        left=g.markToHorizontal(curx,cury,left);
                        cury++;
                    }
                }else{
                    //just do the right one
                    if(onright-left==1){
                        left=g.markSame(curx,cury,left);
                    }else{
                        left=g.markToHorizontal(curx,cury,left);
                        cury++;
                    }
                }
                
            }else{
                //cout<<"Failed on "<<curx<<" "<<cury<<endl;
                left=-1;
                //g.printIt();
            }
        }

        cout<<"Case #"<<testi+1<<": "<<endl;
        if(left==-1){
            //cout<<"Impossible "<<r<<" "<<c<<" "<<m<<" "<<(r*c)-m<<endl;
            cout<<"Impossible"<<endl;
            //g.printIt();
        }else{
            /*
            int got=g.mNum();
            if(got==m){
                cout<<"Mine test pass"<<endl;
            }else{
                cout<<"Mine test failed "<<got<<" suppose "<<m<<endl;
            }
            */
            g.printIt();

        }

        //cout<<endl<<endl;

    }

    return 0;
}



