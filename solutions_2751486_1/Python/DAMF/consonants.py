#!/usr/bin/python

import sys

def factorial( n ):
    if n == 0:
        return 1
    else:
        return n*factorial(n-1)


def nchoosek( n, k ):
    #return factorial(n)/(factorial(k)*factorial(n-k))
    answer = 1
    for i in range(1,k+1):
        answer *= (n - (k - i))
        answer /= i
    return answer


f = open( sys.argv[1] )

num_cases = int(f.readline().split()[0])

consonants = list( "bcdfghjklmnpqrstvwxyz")

for i in range(num_cases):
    line = f.readline().strip()
    if len(line) <= 0:
        continue
    [name, n] = line.split()
    n = int(n)
    name_len = len(name)

    good_positions = []
    # First we find all the positions where there are n consecutive consonants
    num_consec = 0
    #print len( consonants )
    for j, letter in enumerate(name):
        if letter in consonants:
            num_consec += 1
            if num_consec >= n:
                good_positions.append( j-n+1 )
        else:
            num_consec = 0
    #print good_positions

    # Then we make a set containing tuples of position, length that include those positions
    #good_substrings = set([])
    #for position in good_positions:
        #for start_position in range(position+1):
            ##print "start position", start_position
            ##print "position+n is", position+n
            ##print "name_len is", name_len
            #for end_position in range(position+n-1,name_len):
                ##print "end position", end_position
                #good_substrings.add((start_position,end_position))

    # Better: For each letter in the name, we count the number that start at that position
    answer = 0
    position_index = 0
    len_good_positions = len(good_positions)
    #print "name_len-n is", name_len-n
    for j in range(name_len-n+1):
        #print "Trying start position", j
        while (position_index < len_good_positions) and j > good_positions[position_index]:
            #print "Incrementing"
            position_index += 1
        if position_index >= len_good_positions:
            #print "Breaking"
            break
        #print "Adding", name_len - (good_positions[position_index] + (n-1))
        answer += name_len - (good_positions[position_index] + (n-1))


    # Then we print the size of the set
    print "Case #" + str(i+1) + ":", answer

