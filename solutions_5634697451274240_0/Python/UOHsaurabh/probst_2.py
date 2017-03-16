#-------------------------------------------------------------------------------
# Name:        module1
# Purpose:
#
# Author:      Saurabh
#
# Created:     09/04/2016
# Copyright:   (c) Saurabh 2016
# Licence:     <your licence>
#-------------------------------------------------------------------------------

def main():
    fo = open("B-small-attempt1.in","r")
    fp = open("output.txt", "w")
    test = int(fo.readline())
    tri = 1
    while test > 0:
        test -= 1
        line = list(fo.readline().strip())
        if line[0] == '+' and line[-1] == "+":
            count = 0
            for i in range(0,len(line)-1):
                if not(line[i+1] == line[i]):
                    if(line[i+1] == '+' or line[i+1] == '-'):
                        count += 1
            fp.write("Case #"+str(tri)+": "+str(count)+"\n")

        if line[0] == '-' and line[-1] == "+":
            count = 0
            for i in range(0,len(line)-1):
                if not(line[i+1] == line[i]):
                    if(line[i+1] == '+' or line[i+1] == '-'):
                        count += 1
            fp.write("Case #"+str(tri)+": "+str(count)+"\n")

        if line[0] == '-' and line[-1] == "-":
            count = 0
            for i in range(0,len(line)-1):
                if not(line[i+1] == line[i]):
                    if(line[i+1] == '+' or line[i+1] == '-'):
                        count += 1
            fp.write("Case #"+str(tri)+": "+str(count+1)+"\n")

        if line[0] == '+' and line[-1] == "-":
            count = 0
            for i in range(0,len(line)-1):
                if not(line[i+1] == line[i]):
                    if(line[i+1] == '+' or line[i+1] == '-'):
                        count += 1
            fp.write("Case #"+str(tri)+": "+str(count+1)+"\n")
        tri += 1


if __name__ == '__main__':
    main()
