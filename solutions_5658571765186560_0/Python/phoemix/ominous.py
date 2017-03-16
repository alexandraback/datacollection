######################################
# Author: Rodrigo Martins Racanicci  #
# E-mail: diguo.m@gmail.com          #
######################################
# - University of Sao Paulo          #
# - University of Hull               #
######################################

T = int(raw_input())

for case in range(T):
    x, r, c = map(int, raw_input().split())

    print "Case #%d:" %(case+1),

    if (x >= 7):
        print "RICHARD"
        continue

    if ((r * c) % x != 0):
        print "RICHARD"
        continue

    i, j = x, 1
    min_rc = min(r, c)

    end = False
    while(i >= j):
        if(i > min_rc and j > min_rc):
            print "RICHARD"
            end = True
            break
        if (x > 3 and (i >= min_rc and j >= min_rc)):
            print "RICHARD"
            end = True
            break
        i -= 1
        j += 1

    if not end:
        print "GABRIEL"
