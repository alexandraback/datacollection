#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>

#define FORLOOP(i,n) for (int i=0; i<(int)(n); i++)

int main(int argc, char *argv[])
{
    typedef std::pair<long long, int> Stuff;
    
    int ncases;
    std::cin >> ncases;

    for(int c = 0; c < ncases; c++)
    {
        int N, M;
        std::cin >> N >> M;

        int maxBox = 0, maxToy = 0;
        std::vector<Stuff> boxes(N), toys(M);
        FORLOOP(i, N)
        {
            std::cin >> boxes[i].first >> boxes[i].second;
            maxBox = std::max(maxBox, boxes[i].second);
        }
        FORLOOP(i, M)
        {
            std::cin >> toys[i].first >> toys[i].second;
            maxToy = std::max(maxToy, toys[i].second);
        }
//std::cout << maxBox << " " << maxToy << std::endl;
        std::vector<std::vector<long long> > remBoxes(N+1, std::vector<long long>(maxBox, 0));
        for(int i = N-1; i >= 0; i--)
        {
            FORLOOP(j, maxBox)
            {
                remBoxes[i][j] += remBoxes[i+1][j];
                if(boxes[i].second==j+1)
                {
                    remBoxes[i][j] += boxes[i].first;
                }
            }
        }
/*        FORLOOP(i, N)
        {
            FORLOOP(j, maxBox)
                std::cout << remBoxes[i][j] << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl;*/

        std::vector<std::vector<long long> > remToys(M+1, std::vector<long long>(maxToy, 0));
        for(int i = M-1; i >= 0; i--)
        {
            FORLOOP(j, maxToy)
            {
                remToys[i][j] += remToys[i+1][j];
                if(toys[i].second==j+1)
                {
                    remToys[i][j] += toys[i].first;
                }
            }
        }
/*        FORLOOP(i, M)
        {
            FORLOOP(j, maxToy)
                std::cout << remToys[i][j] << " ";
            std::cout << std::endl;
        }
        std::cout << std::endl;*/

//        exit(1);
        

        int b = 0, t = 0;
        long long currSum = 0;
        Stuff currBox = boxes[0], currToy = toys[0];        
        while(b<N && t<M)
        {
            if(currBox.second==currToy.second)
            {
                
                long long inc = std::min(currBox.first, currToy.first);
//                std::cout << "matched " << inc << std::endl;
                currSum += inc;
                currBox.first -= inc;
                currToy.first -= inc;

//                std::cout << "curr box = " << currBox.first << "  " << currBox.second << std::endl;
//                std::cout << "curr toy = " << currToy.first << "  " << currToy.second << std::endl;
                if(currBox.first==0)
                {
                    ++b;
                    currBox = boxes[b];
                }

                if(currToy.first==0)
                {
                    ++t;
                    currToy = toys[t];
                }

//                std::cout << "curr box = " << currBox.first << "  " << currBox.second << std::endl;
//                std::cout << "curr toy = " << currToy.first << "  " << currToy.second << std::endl;
//                std::cout << toys[t].first << " " << toys[t].second << std::endl;
//                std::cout << std::endl;
            }
            else
            {
//                std::cout << "curr box = " << currBox.first << "  " << currBox.second << std::endl;
//                std::cout << "curr toy = " << currToy.first << "  " << currToy.second << std::endl;
                long long maxKeepBox = std::min(currBox.first, std::min(remBoxes[b][currBox.second-1], remToys[t][currBox.second-1]));
                long long maxKeepToy = std::min(currToy.first, std::min(remBoxes[b][currToy.second-1], remToys[t][currToy.second-1]));
//                std::cout << maxKeepBox << " " << maxKeepToy << std::endl;
                if(maxKeepBox<maxKeepToy)
                {
//                    std::cout << "throwing " << b+1 << "th box" << std::endl;
                    ++b;
                    currBox = boxes[b];
                }
                else if(maxKeepBox>maxKeepToy)
                {
//                    std::cout << "throwing " << t+1 << "th toy" << std::endl;
                    ++t;
                    currToy = toys[t];
                }
                else if(currBox.second==toys[t+1].second)
                {
//                    std::cout << "throwing " << t+1 << "th toy" << std::endl;
                    ++t;
                    currToy = toys[t];
                }
                else
                {
//                    std::cout << "throwing " << b+1 << "th box" << std::endl;
                    ++b;
                    currBox = boxes[b];
                }
            }
        }

        std::cout << "Case #" << c+1 << ": " << currSum << std::endl;
//        std::cout << std::endl;


        /*
        std::vector<std::vector<int> > sums(N, M, 0);
        std::vector<std::vector<Stuff> > boxTable(N, M);
        std::vector<std::vector<stuff> > toyTable(N, M);
        FORLOOP(i, N)
        {
            Stuff tempBox = boxes[i];
            Stuff tempToy = toys[0];

            if(tempBox.second==tempToy.first)
            {
                tempBox.first -= min(tempBox.first, tempToy.first);
                tempToy.first -= min(tempBox.first, tempToy.first);
            }
            
            boxTable[i][0] = tempBox;;
            toyTable[i][0] = tempToy;
        }
        FORLOOP(i, M)
        {
            Stuff tempBox = boxes[0];
            Stuff tempToy = toys[i];

            if(tempBox.second==tempToy.first)
            {
                tempBox.first -= min(tempBox.first, tempToy.first);
                tempToy.first -= min(tempBox.first, tempToy.first);
            }
            
            boxTable[0][i] = tempBox;;
            toyTable[0][i] = tempToy;
        }
        
        FORLOOP(i, N)
        {
            FORLOOP(j, M)
            {
                Stuff currBox0 = boxTable[i+1][j];
                Stuff currToy0 = toyTable[i+1][j];

                
            }
        }*/
    }
}
