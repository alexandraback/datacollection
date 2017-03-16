#!/usr/bin/python
import math
import sys

def main():
        count = int(input());
        for i in range(0, count):
                sys.stdout.write ("Case #" + str(i+1) + ": ")

                (sC, sF, sX) = input().split(' ')
                (C, F, X) = (float(sC), float(sF), float(sX))


                rate = 2.0

                time = 0.0

                while(True):

                    nextFarmTime = C / rate;

                    theoreticalWinTime = X / rate;

                    winIfBuyTime = nextFarmTime + ( X / (rate + F))

                    if(winIfBuyTime > theoreticalWinTime):
                        print (str((time + theoreticalWinTime)));
                        break;
                    else:
                        time = time + nextFarmTime
                        rate = rate + F
                
                


if __name__ == "__main__":
        main()
