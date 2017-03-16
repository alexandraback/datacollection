#include <deque>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <eigen3/Eigen/Core>

int main(int argc, char**argv){


    if(argc != 2){
        std::cout << "Pass the filename" << std::endl;
        return 0;
    }

    std::string line;
    std::ifstream infile(argv[1]);

    std::getline(infile,line); // discard number of cases
    int case_ = 0;

    int B =0;
    int M =0;

    while (std::getline(infile, line))  // this does the checking!
    {
        std::istringstream iss(line);
        iss >> B;
        iss >> M;


        std::cout << "Case #" << ++case_ << ": ";

        if( M > std::pow(2,B-2)){
            std::cout << "IMPOSSIBLE" << std::endl;
            continue;
        }
        

        Eigen::MatrixXi connection(Eigen::MatrixXi::Zero(B,B));
        //make upper triangular except first row
        
        for(int i=1; i < connection.rows(); ++i){
            for(int j=i+1; j < connection.cols(); ++j){
                connection(i,j) = 1;
            }
        }

        Eigen::VectorXi firstRow(Eigen::VectorXi::Zero(B));
        //take care of M=maxPaths here

        if(M == std::pow(2,B-2)){
            firstRow = Eigen::VectorXi::Ones(B);
            connection.row(0) = firstRow.transpose();
            connection(0,0) = 0;
            std::cout << "POSSIBLE\n" << connection << std::endl;;    
            continue;
        }
        int shift = 0;
        while(M > 0){
            ++shift;
            if(M %2 == 0){
                M /= 2; 

            }
            else{
                firstRow( B - 1 - shift) = 1; 
                M /= 2;
            }
        }
        connection.row(0) = firstRow.transpose();
        std::cout << "POSSIBLE\n" << connection;
        
        std::cout << std::endl;
    }


    return 0;
}
