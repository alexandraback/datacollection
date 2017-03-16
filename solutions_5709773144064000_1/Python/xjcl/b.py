"""Python2- and Python3-compatible. That's all."""
from time import clock
from sys import argv
#import math
#import itertools
#import numpy

def read(f):
    return next(f).strip("\n")
    
def read_singles(f):
    # returns chars of a word
    # or digits (as strings) of an int
    return list(read(f))
    
def read_int(f, b=10):
    return int(read(f), b)
 
def read_float(f):
    return float(read(f))
 
def read_digits(f, b=10):
    return [int(n, b) for n in read_singles(f)]

#---------------------------------------------

def read_strs(f, s=" "):
    return read(f).split(s)
    
def read_ints(f, b=10, s=" "):
    return [int(n, b) for n in read_strs(f, s)]

def read_floats(f, s=" "):
    return [float(n) for n in read_strs(f, s)]
               
#---------------------------------------------

def read_lines(f, n, reader=read_ints, *args, **kwargs):
    ret = []
    for i in range(n):
        ret.append(reader(f, *args, **kwargs))
    return ret

#---------------------------------------------

def run(data):
    """farm_rate: Rate at which a farm produces"""
    farm_cost, farm_rate, goal = data
    total_rate = 2
    """time_until_goal: Time LEFT until goal, NOT TOTAL time until goal!"""
    farms = 0
    total_time = 0
    old_time_until_goal = goal / total_rate
    time_until_farm = farm_cost / total_rate
    time_until_goal = goal / (total_rate + farm_rate*(farms+1))
    while time_until_farm + time_until_goal < old_time_until_goal:
        """Dynamically: First examine the null option (no farms),
            then look if progressively adding one farm yields a
            more desirable (=lower) result (tested with the while-statement).
            Stop if it doesn't. Result: Now you know how many farms to buy!"""
        total_time += time_until_farm # already saving up for the result!
        farms += 1
        total_rate += farm_rate
        """above: farm bought! below: what if we bought another one?"""
        old_time_until_goal = time_until_goal # == goal / total_rate
        time_until_farm = farm_cost / total_rate
        time_until_goal = goal / (total_rate + farm_rate)
    """total_time = 0
    total_rate = 2 # I'm doing things twice here I know. :(
    for i in range(farms):
        total_time += farm_cost / total_rate
        total_rate += farm_rate"""
    total_time += goal / total_rate
    return str(total_time)

#---------------------------------------------

def read_case(f):
    return read_floats(f)

def write_case(f, i, sol):
    f.writelines("Case #"+str(i+1)+": "+str(sol)+"\n")

#---------------------------------------------

def main():
    f = open(argv[1])
    f2 = open(argv[2], "wt")
    for i in range(read_int(f)):
        print("Init case "+str(i+1)+".")
        write_case(f2, i, run(read_case(f)))
        print("Finished in "+str(clock())+".")
    f.close()
    f2.close()

if __name__ == "__main__":
    main()
