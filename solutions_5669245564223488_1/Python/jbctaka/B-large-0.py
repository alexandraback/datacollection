#!python
#-*- coding:utf-8 -*-

import sys
import re
import math

T = int( sys.stdin.readline() )
for index in range( 1, T + 1 ):
    N = int( sys.stdin.readline() )
    cars = [ re.sub( r"(.)\1*", "\\1", x ) for x in sys.stdin.readline().split() ]
    result = None
    new_cars = []
    for ci in range(len(cars)):
        car = cars[ci]
        if len(car) >= 3:
            if cars[ci][0] == cars[ci][-1]:
                result = "impossible"
                break
            for i in range( 1, len(car) - 1 ):
                if len( re.findall( car[i], car ) ) >= 2:
                    result = "impossible"
                    break
                for cj in range(len(cars)):
                    if ci != cj and car[i] in cars[cj]:
                        result = "impossible"
                        break
        new_cars.append( cars[ci][0] + cars[ci][-1] )
    
    if result:
        print "Case #%d: 0" % ( index )
        continue
    
    cars = new_cars
    
    blocks = {}
    for char in "abcdefghijklmnopqrstuvwxyz":
        found_cars = [ car for car in cars if char in car ]
        lcars  = [ car for car in found_cars if car[0] == char and car[1] != char ]
        rcars  = [ car for car in found_cars if car[0] != char and car[1] == char ]
        lrcars = [ car for car in found_cars if car[0] == char and car[1] == char ]
        if len(lcars) > 1 or len(rcars) > 1:
            result = "impossible"
            break
        if len(found_cars) == 0:
            continue
        
        num = math.factorial(len(lrcars))
        left  = rcars[0][0] if len(rcars) == 1 else ""
        right = lcars[0][1] if len(lcars) == 1 else ""
        
        lb = blocks[left]  if left  in blocks else None
        rb = blocks[right] if right in blocks else None
        while isinstance( lb, str ):
            left = lb
            lb = blocks[left] if left in blocks else None
        while isinstance( rb, str ):
            right = rb
            rb = blocks[right] if right in blocks else None
        if left != "" and right != "" and left == right:
            result = "impossible"
            break
        
        if lb and rb:
            blocks[left]  = blocks[left] * blocks[right] * num
            blocks[right] = left
            blocks[char]  = left
        elif lb:
            blocks[left] *= num
            blocks[char] =  left
        elif rb:
            blocks[right] *= num
            blocks[char]  =  right
        else:
            blocks[char] = num
    
    if result:
        print "Case #%d: 0" % ( index )
        continue
    
    block_num = 0
    seki = 1
    for k, b in blocks.iteritems():
        if isinstance( b, int ):
            block_num += 1
            seki *= b
    print "Case #%d: %d" % ( index, math.factorial( block_num ) * seki % 1000000007 )
