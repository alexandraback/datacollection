#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int q=0; q<t; q++)
    {
        int rows;
        int cols;
        cin>>rows>>cols;
        vector< vector<int> > arr(rows,vector<int>(cols));

        int min_row=-1;
        int min_col=-1;
        int minVal=1000;
        for ( int i=0; i< rows; i++)
        {
            for( int j=0 ; j<cols; j++)
            {
                cin>>arr[i][j];
            }
        }

        while(1)
        {
            if(arr.size()==0)
            {
                cout<<"Case #"<<q+1<<": YES"<<endl;
                break;
            }
            rows = arr.size();
            cols = arr[0].size();
            int min_row=-1;
            int min_col=-1;
            int minVal=1000;
            for ( int i=0; i< rows; i++)
            {
                for( int j=0 ; j<cols; j++)
                {
                    if(arr[i][j] < minVal) 
                    {
                        minVal = arr[i][j];
                        min_col = j;
                        min_row = i;
                    }
                }
            }
            bool row_not_deleted = false;
            bool col_not_deleted = false;
            for( int j=0 ; j<cols; j++)
            {
                if(arr[min_row][j]!=minVal)
                {
                    row_not_deleted = true;
                    break;
                }
            }

            if(row_not_deleted)
            {
                for( int j=0 ; j<rows; j++)
                {
                    if(arr[j][min_col]!=minVal)
                    {
                        col_not_deleted = true;
                        break;
                    }
                }
            }
            else
            {
                arr.erase(arr.begin() + min_row);
                continue;
            }
            if(col_not_deleted && row_not_deleted )
            {
                cout<<"Case #"<<q+1<<": NO"<<endl;
                break;
            }
            if(!col_not_deleted)
            {
                for(int j=0; j <rows; j++)
                {
                    arr[j].erase(arr[j].begin()+min_col);
                }
            }

        }

    }


    return 0;
}
