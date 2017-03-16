# Problem A. Osmos

##Problem
##
##Armin is playing Osmos, a physics-based puzzle game developed by Hemisphere Games. In this game, he plays a "mote", moving around and absorbing smaller motes.
##
##A "mote" in English is a small particle. In this game, it's a thing that absorbs (or is absorbed by) other things! The game in this problem has a similar idea to Osmos, but does not assume you have played the game.
##
##When Armin's mote absorbs a smaller mote, his mote becomes bigger by the smaller mote's size. Now that it's bigger, it might be able to absorb even more motes. For example: suppose Armin's mote has size 10, and there are other motes of sizes 9, 13 and 19. At the start, Armin's mote can only absorb the mote of size 9. When it absorbs that, it will have size 19. Then it can only absorb the mote of size 13. When it absorbs that, it'll have size 32. Now Armin's mote can absorb the last mote.
##
##Note that Armin's mote can absorb another mote if and only if the other mote is smaller. If the other mote is the same size as his, his mote can't absorb it.
##
##You are responsible for the program that creates motes for Armin to absorb. The program has already created some motes, of various sizes, and has created Armin's mote. Unfortunately, given his mote's size and the list of other motes, it's possible that there's no way for Armin's mote to absorb them all.
##
##You want to fix that. There are two kinds of operations you can perform, in any order, any number of times: you can add a mote of any positive integer size to the level, or you can remove any one of the existing motes. What is the minimum number of times you can perform those operations in order to make it possible for Armin's mote to absorb every other mote?
##
##For example, suppose Armin's mote is of size 10 and the other motes are of sizes [9, 20, 25, 100]. This level isn't currently solvable, but by adding a mote of size 3 and removing the mote of size 100, you can make it solvable in only 2 operations. The answer here is 2.
##
##Input
##
##The first line of the input gives the number of test cases, T. T test cases follow. The first line of each test case gives the size of Armin's mote, A, and the number of other motes, N. The second line contains the N sizes of the other motes. All the mote sizes given will be integers.
##
##Output
##
##For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the minimum number of operations needed to make the level solvable.
##
##Limits
##
##1 ≤ T ≤ 100.
##Small dataset
##
##1 ≤ A ≤ 100.
##1 ≤ all mote sizes ≤ 100.
##1 ≤ N ≤ 10.
##
##Large dataset
##
##1 ≤ A ≤ 106.
##1 ≤ all mote sizes ≤ 106.
##1 ≤ N ≤ 100.

debug = False
import copy

def operations(A, motes, count):
    if debug:
        print("Looking at case of", A, "and", motes, "with current count", \
              count)
    
    # Handle base cases
    if len(motes) == 0:
        return(count)
    
    if len(motes) == 1 and motes[0] >= A:
        # If the last one is too big, just remove it
        return(count + 1)

    # Handle general case
    while len(motes) > 0:
        # Can we absorb the next one?
        if motes[0] < A:
            A += motes[0]
            motes.pop(0)
        else:
            break

    if len(motes) > 0:
        # We can't absorb it.
        # Do we want to remove it or add another mote?
        
        # Try removing
        motes2 = copy.deepcopy(motes)
        remove = operations(A, motes2[1:], count + 1)

        # We can only add if A > 1 already
        if A > 1:
            motes2 = copy.deepcopy(motes)
            add = operations(2*A - 1, motes2, count + 1)
        else:
            add = remove + 1
        
        return(min(add, remove))
    else:
        return(count)
# end operations

# Get input file
input_fname = input("Input filename: ")
infile = open(input_fname, 'r')
# Set output file
output_fname = input_fname.replace("in", "out")
outfile = open(output_fname, 'w')

T = int(infile.readline().strip("\n"))

for casenum in range(T):
    print("Case #", casenum+1, ": ", sep="", end="", file=outfile)

    A, N = [int(x) for x in infile.readline().strip("\n").split(" ")]
    motes = [int(x) for x in infile.readline().strip("\n").split(" ")]

    # First, sort so we process these in order
    motes.sort()
    ops = operations(A, motes, 0)
    print(ops, end="", file=outfile)
    if debug:
        print()
        
    print("", file=outfile)
# end case loop

infile.close()
outfile.close()
