######################################
# Author: Rodrigo Martins Racanicci  #
# E-mail: diguo.m@gmail.com          #
######################################
# - University of Sao Paulo          #
# - University of Hull               #
######################################

mult = {'1': {'1': '1', 'i': 'i', 'j':'j', 'k':'k'},
        'i': {'1': 'i', 'i': '-1', 'j': 'k', 'k': '-j'},
        'j': {'1': 'j', 'i': '-k', 'j': '-1', 'k': 'i'},
        'k': {'1': 'k', 'i': 'j', 'j': '-i', 'k': '-1'}}

T = int(raw_input())

for case in range(T):
    l, x = map(int, raw_input().split())
    root = raw_input()
    size = l * x

    print "Case #%d:" %(case + 1),
    if (size < 3 or l <= 1):
        print "NO"
        continue

    expected = ['i', 'j', 'k']
    signal = 0
    last_m = root[0]
    i = 1
    found = 0
    while(1):
        #print last_m, i
        if (last_m == 'i' and signal%2 == 0 and found == 0):
            #print "achei i"
            found += 1
            signal = 0
            last_m = '1'
        elif(last_m == 'j' and signal%2 == 0 and found == 1):
            #print "achei j"
            found += 1
            signal = 0
            last_m = '1'
        elif (last_m == 'k' and signal%2 == 0 and found == 2 and i == size):
            #print "achei k"
            found += 1
            signal = 0
            last_m = 'k'
            break
        else:
            if (i == size):
                break
            else:
                last_m = mult[last_m][root[i%l]]
                if last_m[0] == '-':
                    signal += 1
                    last_m = last_m[1:]
                i += 1

    if (found == 3):
        print "YES"
    else:
        print "NO"




