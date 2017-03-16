# Problem B. Pogo

##Problem
##
##You have just got the best gift ever, a Pogo stick. The pogo stick is something you use to jump off the ground while standing on it. 
##
##This Pogo stick is a special one: the first jump will move you a distance of 1 unit, the second jump will move you 2 units, the third jump will move you 3 units and so on. You can jump in only four directions using this stick: north (increasing y), south (decreasing y), east (increasing x) or west (decreasing x). 
##
##Now you want to play a game in your backyard, which we model as an infinite plane. You are standing with your stick in at point (0, 0) and you want to go to point (X, Y). 
##
##The point (X, Y) will never be (0, 0), and it will always be reachable from your starting point. 
##
##Check the output section carefully, because the required outputs for the small and large datasets are not the same.
##
##Input
##
##The first line of the input gives the number of test cases, T. T test cases follow, one per line. Each line consists of 2 integers separated by a single space, X and Y, the coordinates of the point you want to reach.
##
##Output
##
##For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is a string represents the directions of the moves, for example if you are going to move north then south then east then west, this string should be NSEW. 
##
##For the small dataset, the output is considered correct if it does not take more than 500 moves to reach the destination in each test case. 
##
##For the large dataset, the output is considered correct if it reaches the destination point in the minimum possible number of moves. 
##
##If there are multiple correct solutions, print any of them.
##
##Limits
##
##Small dataset
##
##1 ≤ T ≤ 50.
##0 ≤ |X|, |Y| ≤ 100.
##
##Large dataset
##
##1 ≤ T ≤ 100.
##0 ≤ |X|, |Y| ≤ 106.

debug = True

# Get input file
input_fname = input("Input filename: ")
infile = open(input_fname, 'r')
# Set output file
output_fname = input_fname.replace("in", "out")
outfile = open(output_fname, 'w')

T = int(infile.readline().strip("\n"))

for casenum in range(T):
    print("Case #", casenum+1, ": ", sep="", end="", file=outfile)

    X, Y = [int(x) for x in infile.readline().strip("\n").split(" ")]
    
    moves = ""
    if X < 0:
        moves += "EW" * abs(X)
    elif X > 0:
        moves += "WE" * abs(X)
    
    if Y < 0:
        moves += "NS" * abs(Y)
    elif Y > 0:
        moves += "SN" * abs(Y)
    
    print(moves, end="", file=outfile)
        
    print("", file=outfile)
# end case loop

infile.close()
outfile.close()
