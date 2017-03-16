# Problem B. Falling Diamonds

##Problem
##
##Diamonds are falling from the sky. People are now buying up locations where the diamonds can land, just to own a diamond if one does land there. You have been offered one such place, and want to know whether it is a good deal.
##
##Diamonds are shaped like, you guessed it, diamonds: they are squares with vertices (X-1, Y), (X, Y+1), (X+1, Y) and (X, Y-1) for some X, Y which we call the center of the diamond. All the diamonds are always in the X-Y plane. X is the horizontal direction, Y is the vertical direction. The ground is at Y=0, and positive Y coordinates are above the ground.
##
##The diamonds fall one at a time along the Y axis. This means that they start at (0, Y) with Y very large, and fall vertically down, until they hit either the ground or another diamond.
##
##When a diamond hits the ground, it falls until it is buried into the ground up to its center, and then stops moving. This effectively means that all diamonds stop falling or sliding if their center reaches Y=0.
##
##When a diamond hits another diamond, vertex to vertex, it can start sliding down, without turning, in one of the two possible directions: down and left, or down and right. If there is no diamond immediately blocking either of the sides, it slides left or right with equal probability. If there is a diamond blocking one of the sides, the falling diamond will slide to the other side until it is blocked by another diamond, or becomes buried in the ground. If there are diamonds blocking the paths to the left and to the right, the diamond just stops.
##
##
##Consider the example in the picture. The first diamond hits the ground and stops when halfway buried, with its center at (0, 0). The second diamond may slide either to the left or to the right with equal probability. Here, it happened to go left. It stops buried in the ground next to the first diamond, at (-2, 0). The third diamond will also hit the first one. Then it will either randomly slide to the right and stop in the ground, or slide to the left, and stop between and above the two already-placed diamonds. It again happened to go left, so it stopped at (-1, 1). The fourth diamond has no choice: it will slide right, and stop in the ground at (2, 0).
##
##Input
##
##The first line of the input gives the number of test cases, T. T lines follow. Each line contains three integers: the number of falling diamonds N, and the position X, Y of the place you are interested in. Note the place that you are interested in buying does not have to be at or near the ground.
##
##Output
##
##For each test case output one line containing "Case #x: p", where x is the case number (starting from 1) and p is the probability that one of the N diamonds will fall so that its center ends up exactly at (X, Y). The answer will be considered correct if it is within an absolute error of 10-6 away from the correct answer. See the FAQ for an explanation of what that means, and what formats of floating-point numbers we accept.
##
##Limits
##
##1 ≤ T ≤ 100.
##-10,000 ≤ X ≤ 10,000.
##0 ≤ Y ≤ 10,000. 
##X + Y is even.
##
##Small dataset
##
##1 ≤ N ≤ 20.
##
##Large dataset
##
##1 ≤ N ≤ 106.

debug = True

def choose(n, m):
    prod = 1
    for x in range(m+1, n+1):
        prod = prod * x
    for x in range(1, (n-m)+1):
        prod = prod / x
    return(prod)
# end choose

# Get input file
input_fname = input("Input filename: ")
infile = open(input_fname, 'r')
# Set output file
output_fname = input_fname.replace("in", "out")
outfile = open(output_fname, 'w')

T = int(infile.readline().strip("\n"))

for casenum in range(T):
    print("Case #", casenum+1, ": ", sep="", end="", file=outfile)

    N, X, Y = [int(x) for x in infile.readline().strip("\n").split(" ")]

    if debug:
        print("Case:", N, X, Y)

    # Find the relevant triangular number
    k = int(pow(N, .5))
    while (2*k+1)*(k+1) <= N:
        k += 1
    if (2*k-1)*k > N:
        k -= 1
    tri_num = (2*k-1)*k

    # How wide is the base and how high is it?
    width = 2*k-1
    height = width

    # How many are left to place?
    remaining = N - tri_num

    ## Where does our diamond fall?
    level = Y
    
    if debug:
        print("Base is", width, "wide. Falls on level", level, "at", \
              int((abs(X) + 1) / 2), "from the center.", remaining, "remain.")
    
    # Inside? P = 1.0
    if abs(X) + Y <= width-1:
        if debug:
            print("Falls inside.")
        P = 1.0
    # Outside next layer? P = 0.0
    elif abs(X) + Y > width+1:
        if debug:
            print("Falls outside.")
        P = 0.0
    # On perimeter? Calculate how many have to fall right/left
    else:
        # We need at least (level+1) to fall on our side
        if remaining >= (height + level + 2):
            # Only a max of (height+1) can fall on each side
            if debug:
                print("Falls at a low enough level.")
            P = 1.0
        elif (remaining > 0 and X == 0) or \
             remaining == 0 or \
             remaining <= level:
            # This is at the top center, which would be for the next tri num
            if debug:
                print("Falls too high (maybe none remaining).")
            P = 0.0
        else:
            # We sum the cases [(level+1), (level+2), ..., (height+1)]
            # falling on this side, or at least as high as we can go
            P = 0.0

            # Some number may automatically go on each side
            if remaining > height + 1:
                excess = remaining - (height + 1)
                num_to_place = remaining - 2 * excess
            else:
                excess = 0
                num_to_place = remaining

            if debug:
                print("Falls at a non-trivial height.", num_to_place, \
                      "to place.")

            for x in range((level+1) - excess, num_to_place + 1):
                if debug:
                    print("Adding case of", num_to_place, "choose", x)
                P += choose(num_to_place, x)
            P = P / pow(2, num_to_place)
            
            if debug:
                print("Result: P =", P)
            
            
    print(P, end="", file=outfile)
    if debug:
        print()
    
    print("", file=outfile)
# end case loop

infile.close()
outfile.close()
