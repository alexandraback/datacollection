######################################
# Author: Rodrigo Martins Racanicci  #
# E-mail: diguo.m@gmail.com          #
######################################
# - University of Sao Paulo          #
# - University of Hull               #
######################################

T = int(raw_input())

for case in range(T):
    smax, s = raw_input().split()
    smax = int(smax)
    s = map(int, list(s))

    standing = 0
    inviten = 0
    for i, si in enumerate(s):
        if standing >= i:
            standing += si
        elif si > 0:
            temp = i - standing
            standing += temp + si
            inviten += temp

    print "Case #%d: %d" %(case+1, inviten)

