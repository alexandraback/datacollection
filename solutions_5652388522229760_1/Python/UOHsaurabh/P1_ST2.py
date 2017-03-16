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
    fo = open("A-large.in", "r")
    test = int(fo.next())
    f = open('out1large.txt', 'w')
    trial = 1
    while test > 0:
        test -= 1
        n = int(fo.next())
        if n == 0:
            f.write("Case #"+str(trial)+": "+"INSOMNIA\n")
        else:
            ls = [0,0,0,0,0,0,0,0,0,0]
            i = 1
            count = 0
            while(count < 10):
                k = i*n
                while (k > 0):
                    d = k % 10
                    k = k / 10
                    if ls[d] == 0:
                        ls[d] = 1
                        count += 1
                i += 1
            f.write("Case #"+str(trial)+": "+str((i-1)*n)+"\n")
        trial+=1
    fo.close()

if __name__ == '__main__':
    import time
    start_time = time.time()
    main()
    print("--- %s seconds ---" % (time.time() - start_time))

