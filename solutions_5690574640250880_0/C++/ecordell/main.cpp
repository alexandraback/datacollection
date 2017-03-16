#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>


bool isValidBombCount(int row, int col, int mines) {
    if (mines <= row*col - 4) {
        if (mines != row*col - 5 && mines != row*col - 7) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

std::vector< std::vector< char > > calcboard(int m, int n, int mines) {
    std::vector< std::vector< char > > board ( m, std::vector<char> ( n, '.' ) );
    
    if (mines <= (m-2)*(n-2)) {
        //fit in rec
        int minesPlaced = 0;
        for (int r = 0; r<m-2; r++) {
            for (int c = 0; c<n-2; c++) {
                board[r][c] = '*';
                ++minesPlaced;
                if (minesPlaced == mines) {
                    break;
                }
            }
            if (minesPlaced == mines) {
                break;
            }
        }
        
    } else {
        bool isOdd = (mines - (m-2)*(n-2)) % 2 != 0;
        int oddOffset = isOdd ? 1 : 0;
        //fill rec
        for (int r = 0; r<m-2; r++) {
            for (int c = 0; c<n-2; c++) {
                board[r][c] = '*';
            }
        }
        //fix corner
        if (isOdd) {
            board[m-3][n-3] = '.';
        }
        
        //fill sides
        int minesPlaced = (m-2)*(n-2);
        if (isOdd) {
            --minesPlaced;
        }
        
        for (int r = 0; r<m-2 - oddOffset; r++) {
            board[r][n-2] = '*';
            board[r][n-1] = '*';
            minesPlaced += 2;
            if (minesPlaced == mines) {
                break;
            }
        }
        
        if (minesPlaced < mines) {
            for (int c = 0; c<n-2 - oddOffset; c++) {
                board[m-2][c] = '*';
                board[m-1][c] = '*';
                minesPlaced += 2;
                if (minesPlaced == mines) {
                    break;
                }
            }
        }
    }
    
    board[m-1][n-1] = 'c';
    return board;
}

int main(int argc, const char * argv[])
{
    std::ifstream infile("/Users/evan/Git/GoogleCodeJam/Qualification/Problem C/QualProblemC/QualProblemC/C-small-attempt3.in");
    std::ofstream outfile;
    outfile.open("/Users/evan/Git/GoogleCodeJam/Qualification/Problem C/QualProblemC/QualProblemC/small.out");
    
    int T; //number of test cases
    infile >> T;
    
    for (int tcase = 1; tcase<=T; tcase++) {
        
        int rowCount, colCount, mineCount;
        
        infile >> rowCount >> colCount >> mineCount;
        
        std::vector< std::vector< char > > board ( rowCount, std::vector<char> ( colCount, '.' ) );
        
        //no bombs
        if (mineCount == 0) {
            board[rowCount - 1][colCount - 1] = 'c';
            
            outfile << "Case #" << tcase << ":\n";
            
            for ( std::vector<std::vector<int>>::size_type i = 0; i < board.size(); i++ )
            {
                for ( std::vector<int>::size_type j = 0; j < board[i].size(); j++ )
                {
                    outfile << board[i][j];
                }
                outfile << std::endl;
            }
            continue;
        }
        
        //all but one are bombs
        if (mineCount == rowCount*colCount - 1) {
            board = std::vector< std::vector< char > > ( rowCount, std::vector<char> ( colCount, '*' ) );
            board[rowCount - 1][colCount - 1] = 'c';
            
            outfile << "Case #" << tcase << ":\n";
            
            for ( std::vector<std::vector<int>>::size_type i = 0; i < board.size(); i++ )
            {
                for ( std::vector<int>::size_type j = 0; j < board[i].size(); j++ )
                {
                    outfile << board[i][j];
                }
                outfile << std::endl;
            }
            continue;
        }
        
        if (rowCount > 2 && colCount > 2) {
            if (!isValidBombCount(rowCount, colCount, mineCount)) {
                outfile << "Case #" << tcase << ":\nImpossible\n";
            } else {
                board = calcboard(rowCount, colCount, mineCount);
                outfile << "Case #" << tcase << ":\n";
    
                for ( std::vector<std::vector<int>>::size_type i = 0; i < board.size(); i++ )
                {
                    for ( std::vector<int>::size_type j = 0; j < board[i].size(); j++ )
                    {
                        outfile << board[i][j];
                    }
                    outfile << std::endl;
                }

            }
        } else {
            if (rowCount == 1 || colCount == 1) {
                if (mineCount == rowCount*colCount) {
                    outfile << "Case #" << tcase << ":\nImpossible\n";
                } else {
                    outfile << "Case #" << tcase << ":\n";
                    
                    int minesPlaced = 0;
                    for (int r = 0; r < rowCount; r++) {
                        for (int c = 0; c < colCount; c++) {
                            board[r][c] = '*';
                            minesPlaced++;
                            if (minesPlaced == mineCount) {
                                break;
                            }
                        }
                        if (minesPlaced == mineCount) {
                            break;
                        }
                    }
                    board[rowCount-1][colCount-1] = 'c';

                    for ( std::vector<std::vector<int>>::size_type i = 0; i < board.size(); i++ )
                    {
                        for ( std::vector<int>::size_type j = 0; j < board[i].size(); j++ )
                        {
                            outfile << board[i][j];
                        }
                        outfile << std::endl;
                    }
                }
            } else if (rowCount == 2 || colCount == 2) {
                if (mineCount > rowCount*colCount-4) {
                    outfile << "Case #" << tcase << ":\nImpossible\n";
                } else {
                    if (mineCount % 2 == 0) {
                        outfile << "Case #" << tcase << ":\n";
                        int minesPlaced = 0;
                        
                        if (rowCount > colCount) {
                            for (int r = 0; r < rowCount; r++) {
                                for (int c = 0; c < colCount; c++) {
                                    board[r][c] = '*';
                                    minesPlaced++;
                                    if (minesPlaced == mineCount) {
                                        break;
                                    }
                                }
                                if (minesPlaced == mineCount) {
                                    break;
                                }
                            }
                        } else {
                            for (int c = 0; c < colCount; c++) {
                                for (int r = 0; r < rowCount; r++) {
                                    board[r][c] = '*';
                                    minesPlaced++;
                                    if (minesPlaced == mineCount) {
                                        break;
                                    }
                                }
                                if (minesPlaced == mineCount) {
                                    break;
                                }
                            }
                        }
                        
                        board[rowCount-1][colCount-1] = 'c';
                        
                        for ( std::vector<std::vector<int>>::size_type i = 0; i < board.size(); i++ )
                        {
                            for ( std::vector<int>::size_type j = 0; j < board[i].size(); j++ )
                            {
                                outfile << board[i][j];
                            }
                            outfile << std::endl;
                        }

                    } else {
                        outfile << "Case #" << tcase << ":\nImpossible\n";
                    }
                }
            }
        }
    }
    outfile.close();
    return 0;
}