######################################
# Author: Rodrigo Martins Racanicci  #
# E-mail: diguo.m@gmail.com          #
######################################
# - University of Sao Paulo          #
# - University of Hull               #
######################################

def solve(r, c, w):
    hits = 0


    for i in range(r):
        j = 0
        while(j < c):
            if (i == r - 1 and j >= c - w):
                hits += w
                break
            else:
                j += w
                hits += 1
    return hits


if __name__ == '__main__':
    T = int(raw_input())

    for case in xrange(1, T + 1):
        r, c, w = map(int, raw_input().split())
        h = solve(r, c, w)

        print "Case #%d: %d" %(case, h)
