#!/usr/local/bin/python3
# Codejam ID 4244486

# Run with parameter
# -s for small input
# -l for large input


from GCJ import GCJ

def parse(infile):
    R, C, W = GCJ.readints(infile)
    return R, C, W

def solve(data):
    R, C, W = data

    if W == 1:
      return R*C
    if W == C or W == C+1:
      return R*C

    shoots = (C//W)+W
    if C % W == 0:
      shoots -= 1
    return R*shoots


GCJ('A', solve, parse, None).run()

