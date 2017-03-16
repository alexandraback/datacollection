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

for case_num in range(num_cases):
    line = f.readline().strip()
    if len(line) <= 0:
        continue
    N = int(line)
    bffs = f.readline().strip().split()
    bffs = [int(x)-1 for x in bffs]
    lone_pieces = []
    loops = []
    # For each student, you can figure out the biggest circle the kid can be in
    # Then you take the largest of those circles
    for student in range(N):
        chain = [student]
        done = False
        pos = student
        while not done:
            if bffs[pos] not in chain:
                chain.append(bffs[pos])
                pos = bffs[pos]
            else:
                done = True
                if bffs[pos] == chain[-2]:
                    # We need to add a lone piece
                    already_there = False
                    #print "Checking to see if", pos, "or", bffs[pos],
                    #print "is already in lone_pieces"
                    for i, lp in enumerate(lone_pieces):
                        #print "Currently checking", lp
                        #if lp[-1] in [pos, bffs[pos]]:
                        #if lp[-1] == bffs[pos] and lp[-2] == pos:
                        if lp[-2] == bffs[pos] and lp[-1] == pos:
                            #print("Found it")
                            already_there = True
                            if len(chain) > len(lp):
                                lone_pieces[i] = chain
                    if not already_there:
                        #print "Never found it"
                        lone_pieces.append(chain)
                else:
                    start = chain.index(bffs[pos])
                    loops.append(chain[start:])
    #print("Loops:")
    #for loop in loops:
        #print loop
    #print("Lone pieces:")
    #for lp in lone_pieces:
        #print lp
    lone_pieces_by_end = [[] for i in range(N)]
    for lp in lone_pieces:
        lone_pieces_by_end[lp[-1]].append(lp)
        if len(lone_pieces_by_end[lp[-1]]) > 1:
            print("lpbe too long!")
    lone_pieces = []
    for i, lpbe in enumerate(lone_pieces_by_end):
        if len(lpbe) == 1:
            lp = lpbe[0]
            if len(lone_pieces_by_end[lp[-2]]) == 1:
                other_piece = lone_pieces_by_end[lp[-2]][0]
                lone_pieces.append(lp + other_piece[:-2][::-1])
                lone_pieces_by_end[lp[-2]] = []
            else:
                lone_pieces.append(lp)
        elif len(lpbe) > 1:
            print("Too long, I said!")
            sorted(lpbe, key=lambda piece: len(piece), reverse=True)
            lone_pieces.append(lpbe[0] + lpbe[1][:-1][::-1])
    #print("Loops:")
    #for loop in loops:
        #print loop
    #print("Lone pieces:")
    #for lp in lone_pieces:
        #print lp
    if len(lone_pieces) > 0:
        longest_from_pieces = sum([len(x) for x in lone_pieces])
    else:
        longest_from_pieces = 0
    if len(loops) > 0:
        longest_from_loops = max([len(x) for x in loops])
    else:
        longest_from_loops = 0
    longest = max([longest_from_pieces, longest_from_loops])

    print "Case #" + str(case_num+1) + ":", longest

