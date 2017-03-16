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
    fo = open("D-small-attempt0.in","r")
    fp = open("output.txt", "w")
    test = int(fo.readline())
    tri = 1
    while test > 0:
        test -= 1
        line = map(int, fo.readline().split())
        k = line[0]
        fp.write("Case #"+str(tri)+": ",)
        for i in range(k):
            fp.write(str(i+1)+" ",)
        fp.write("\n")
        tri+=1



if __name__ == '__main__':
    main()
