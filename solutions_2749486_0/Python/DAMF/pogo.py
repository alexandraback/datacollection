#!/usr/bin/python

import sys
import math

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

for i in range(num_cases):
    line = f.readline().strip()
    if len(line) <= 0:
        continue
    [X, Y] = line.split()
    [X, Y] = [int(X), int(Y)]

    output = []
    forward_X_letter = 'E'
    backward_X_letter = 'W'
    if X < 0:
        forward_X_letter = 'W'
        backward_X_letter = 'E'
    forward_Y_letter = 'N'
    backward_Y_letter = 'S'
    if Y < 0:
        forward_Y_letter = 'S'
        backward_Y_letter = 'N'
    X = abs(X)
    Y = abs(Y)


    #NEED TO HANDLE X = 0 AND Y = 0 <-- ONLY SPECIAL FOR LARGE INPUT!

    '''
    # First move the X direction
    # Find an n such that n(n+1)/2 is greater than X and such that the difference is even
    # 2X < n(n + 1); n^2 + n - 2X < 0
    # -1 + \sqrt{1+8X}/2
    nx = 1 + 8*X
    nx = math.sqrt(nx)
    #print "Square root was", n
    nx -= 1
    nx /= 2.0
    nx = int(math.ceil(nx))
    #print "Ceiling was", n
    total_x_distance = nx*(nx+1)/2
    if (total_x_distance-X)%2:
        nx += 1
        total_x_distance = nx*(nx+1)/2
    #print "n was", n
    # Take its difference from X and divide it by 2 and make that move be in the opposite direction
    opposite_move = (total_x_distance - X)/2
    for j in range(nx):
        if j == (opposite_move-1):
            output.append( backward_X_letter )
        else:
            output.append( forward_X_letter )
    '''

    '''
    # Now do the same for Y, but the necessary negative move might not be available so we might have to bump up n
    # This time, we want an integer where n(n + 1)/2 - nx(nx + 1)/2 > Y
    # n^2 + n - total_distance - 2Y > 0
    ny = 1 + 8*Y + 4*total_x_distance
    ny = math.sqrt(ny)
    #print "Square root was", n
    ny -= 1
    ny /= 2.0
    ny = int(math.ceil(ny))
    print "Ceiling was", ny
    total_y_distance = ny*(ny+1)/2 - total_x_distance
    # MAYBE THERE'S SOMETHING SMARTER WE CAN DO HERE SWAPPING WITH AN X MOVE?
    while (total_y_distance-Y)%2 or ((total_y_distance - Y)/2) < nx:
        ny += 1
        total_y_distance = ny*(ny+1)/2 - total_x_distance
    #print "n was", n
    # Take its difference from X and divide it by 2 and make that move be in the opposite direction
    opposite_move = (total_y_distance - Y)/2
    print "Opposite move was", opposite_move
    for j in range(nx,ny):
        if j == (opposite_move-1):
            output.append( backward_Y_letter )
        else:
            output.append( forward_Y_letter )
    '''

    for j in range(2*X):
        if j%2:
            output.append( forward_X_letter )
        else:
            output.append( backward_X_letter )

    # Y presents some difficulties, but for the small dataset, we don't have to be so clever
    for j in range(2*Y):
        if j%2:
            output.append( forward_Y_letter )
        else:
            output.append( backward_Y_letter )

    print "Case #" + str(i+1) + ":", "".join( output )

