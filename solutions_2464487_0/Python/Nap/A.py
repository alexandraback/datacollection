"""Bullseye"""

'''
Notes
* Area of circle = pi * r ^ 2
* Area of ring = Area of outer circle - Area of inner circle
* Ring thickness = 1 cm
* Inter-ring distance = 1 cm
* Starting black paint volume = t ml
* Inner white circle radius = r cm
* 1 ml paint = pi cm^2 area
* Find no. of black rings Maria can draw, only whole rings count.
* There will always be enough paint to draw at least one black ring.
'''

from math import sqrt
import numpy as np
import decimal

debug = False

def bullseye():
  decimal.getcontext().prec = 60
  
  T = int(raw_input())
  for case in range(T):
    if debug: print "\nbullseye(): Case #{}".format(case + 1)
    
    line = raw_input()
    #if debug: print "bullseye(): line = {}".format(line)
    
    r, t = tuple(decimal.Decimal(x) for x in line.split())
    if debug: print "bullseye(): r = {}, t = {}".format(r, t)
    
    #x1 = (-1 + sqrt(1 + r * t)) / r
    #x2 = (-1 - sqrt(1 + r * t)) / r
    #n = int(x1) if x1 > 0 else int(x2)
    
    a = decimal.Decimal(2.0)
    b = decimal.Decimal(2.0) * r - decimal.Decimal(1.0)
    c = t.copy_negate()  #c = -t
    if debug: print "bullseye(): prec = {}, b^2 = {}".format(decimal.getcontext().prec, decimal.getcontext().power(b, decimal.Decimal(2.0)))
    d = b * b - decimal.Decimal(4.0) * a * c
    if debug: print "bullseye(): a = {}, b = {}, c = {}, d = {}".format(a, b, c, d)
    n1 = (-b + d.sqrt()) / (decimal.Decimal(2.0) * a)  #n1 = (-b + sqrt(d)) / (2.0 * a)
    n2 = (-b - d.sqrt()) / (decimal.Decimal(2.0) * a)  #n2 = (-b - sqrt(d)) / (2.0 * a)
    if debug: print "bullseye(): n1 = {}, n2 = {}".format(repr(n1), repr(n2))
    n = n1.quantize(decimal.Decimal('1.'), rounding=decimal.ROUND_DOWN) if n1 > decimal.Decimal(0) else n2.quantize(Decimal('1.'), rounding=decimal.ROUND_DOWN)  #n = int(n1) if n1 > 0 else int(n2)
    
    print "Case #{}: {}".format(case + 1, n)

if __name__ == "__main__":
  bullseye()
