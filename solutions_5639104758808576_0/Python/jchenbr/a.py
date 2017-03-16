#!/usr/bin/python

"Code Jam Quanlification Round, Problem A."

import sys

if __name__ == "__main__":

    if (len(sys.argv) != 2):
        print "Please specifiy input file.";
    
    try:
        fileIn = open(sys.argv[1], 'r');
    except error:
        print "Can't open the file.";

    datIn = fileIn.readlines();

    total = int(datIn[0]);

    for case in range(1, total + 1):
        
        shyness, audience = datIn[case].split();
        
        nShyness = int(shyness);

        nFriend = 0;
        nClapped = 0;

        for shy in range(nShyness + 1):
            if (shy > nClapped):
                nFriend     += shy - nClapped;
                nClapped    += shy - nClapped;
            
            nClapped += int(audience[shy]);

        print "Case #" + str(case) + ":", nFriend;


