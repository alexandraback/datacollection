#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

bool validate(std::string pattern, int destX, int destY){
    int x = 0;
    int y = 0;
    for (int i = 1; i <= pattern.length(); i++){
        char c = pattern.at(i-1);
        if (c == 'N'){
            y += i;
        } else if (c == 'S'){
            y -= i;
        } else if (c == 'E'){
            x += i;
        } else if (c == 'W'){
            x -= i;
        }
    }

    return x == destX && y == destY;
}

int main(int argc, char *argv[])
{
    // xxxxx
    std::cout << "Starting solution of problem A..." << std::endl;

    //file names for input and output
    //std::string filenameIn = "A-large.in";
    //std::string filenameOut = "A-large.out";
    //std::string filenameIn = "A-small-practice.in";
    //std::string filenameOut = "A-small-practice.out";
    std::string filenameIn = "B-small-attempt2.in";
    std::string filenameOut = "B-small-attempt2.out";

    std::ofstream os(filenameOut.c_str());

    std::ifstream is(filenameIn.c_str());
    if (is.is_open()){
        int numTestCases = 0;
        is >> numTestCases;

        for (int nCase = 1; nCase <= numTestCases; nCase++){
            std::cout << "Processing case #" << nCase << std::endl;


            int destX = 0;
            int destY = 0;
            is >> destX >> destY;

            std::string pattern = "";

            int x = 0;
            int y = 0;
            for (int i = 1; i <= 500; i++){
                if (x == destX && y == destY){
                    break;
                }

                //finishing operations
                if (x == destX-i){
                    x += i;
                    pattern += "E";
                    continue;
                }
                if (x == destX+i){
                    x -= i;
                    pattern += "W";
                    continue;
                }
                if (y == destY-i){
                    y += i;
                    pattern += "N";
                    continue;
                }
                if (y == destY+i){
                    y -= i;
                    pattern += "S";
                    continue;
                }


                int diffX = std::abs(std::abs(x) - std::abs(destX));
                int diffY = std::abs(std::abs(y) - std::abs(destY));
                int diffXnew = std::abs(diffX - i);
                int diffYnew = std::abs(diffY - i);

                if (diffX >= diffY || diffY == 0){
                    //move in x direction
                    if (x > destX && x-i > destX ){
                        x -= i;
                        pattern += "W";
                    } else if (x > destX && x-i < destX ){
                        x += i;
                        pattern += "E";
                        i++;
                        x -= i;
                        pattern += "W";
                    } else if (x < destX && x+i < destX ){
                        x += i;
                        pattern += "E";
                    } else if (x < destX && x+i > destX ){
                        x -= i;
                        pattern += "W";
                        i++;
                        x += i;
                        pattern += "E";
                    }
                } else {
                    //move in y direction
                    if (y > destY && y-i > destY ){
                        y -= i;
                        pattern += "S";
                    } else if (y > destY && y-i < destY ){
                        y += i;
                        pattern += "N";
                        i++;
                        y -= i;
                        pattern += "S";
                    } else if (y < destY && y+i < destY ){
                        y += i;
                        pattern += "N";
                    } else if (y < destY && y+i > destY ){
                        y -= i;
                        pattern += "S";
                        i++;
                        y += i;
                        pattern += "N";
                    }
                }
            }

            //validate pattern
            bool valid = validate(pattern, destX, destY);

            //result is minimum number of operations
            std::string result = pattern;

            //write result for test case into file
            os << "Case #" << nCase << ": " << result << std::endl;
            std::cout << "Case #" << nCase << ": " << result << " - valid " << valid << std::endl;
        }

    }
    is.close();

    os.close();

    return 0;
}
