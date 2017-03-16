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

"""
This problem sounds like it would be well-suited to Haskell actually
"""

mul = {
    "1": {"1": "1", "i": "i",  "j": "j",  "k": "k" },
    "i": {"1": "i", "i": "-1", "j": "k",  "k": "-j"},
    "j": {"1": "j", "i": "-k", "j": "-1", "k": "i" },
    "k": {"1": "k", "i": "j",  "j": "-i", "k": "-1"},
       }

def mult(a, b):
    sign = a[0]=="-" and b[0]=="-" or a[0]!="-" and b[0]!="-"
    ret = mul[a.strip("-")][b.strip("-")]
    if sign:
        return ret
    if ret[0]=="-":
        return ret[1]
    return "-"+ret

def eval_str(s):
    run = "1"
    for c in s:
        run = mult(run, c)
    return run

def eval_times(c, n):
    run = "1"
    for i in range(n):
        run = mult(run, c)
    return run

"""
idea: we found a and b such that:
    dfijoidfjejdwiwjdioiaiokiaklsdkl
    ----i----|             |---k----
            a^            b^
squeeze_j returns True iff the middle
    (string between a and b) evaluates to "j"

Oh I'm just now realizing we don't need to check
    for every a and b. because if
    dfijoidfjejdwiwjdioiaiokiaklsdkl
    ----i----|          |------k----
            a^        b'^
    is an alternate solution, the string from
        b to b' evaluates to 1 anyway!

Yeah so don't be irritated by the code in run(data);
    cutoff_i and cutoff_k will only ever have one element
"""
def squeeze_j(a, b, s, rep):

    diff = a[0] - b[0]

    if diff > rep:
        return False
    if diff == rep:
        return eval_str( s[ a[1]+1 : b[1] ] ) == "j"

    front = eval_str( s[ a[1]+1 : ] )
    back = eval_str( s[ : b[1] ] )  # ok if str empty
    middle = eval_str(s)

    #[mult(mult(mult(x,x),x),x) for x in ["1","i","j","k","-1","-i","-j","-k"]]
    return mult(mult(front, eval_times(middle, (rep-diff-1) % 4)), back) == "j"


# find possible position for the i
# WARNING! we record the closed interval, not the half-open one
#   so we will need to add +1 later on
# only check the first 4, then they repeat (see above)
def find_cutoff_i(s):
    res = "1"
    for i in range(4):
        for j in range(len(s)):
            res = mult(res, s[j])
            if res == "i":
                return (i, j)

# find possible position for the k
def find_cutoff_k(s):
    res = "1"
    for i in range(-1,-5,-1):
        for j in range(len(s)-1,-1,-1):
            res = mult(s[j], res)
            if res == "k":
                return (i, j)

def run(data):
    rep, s = data

    cutoff_i = find_cutoff_i(s)
    if cutoff_i:
        cutoff_k = find_cutoff_k(s)
        if cutoff_k:
            if squeeze_j(cutoff_i,cutoff_k,s,rep):
                return "YES"

    return "NO"

#---------------------------------------------

def read_case(f):
    _, rep = read_ints(f)
    return (rep, read_singles(f))

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
