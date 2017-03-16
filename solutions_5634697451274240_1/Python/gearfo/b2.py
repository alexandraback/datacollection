from __future__ import print_function
import argparse


def complement(string):
    string = string.replace('+', ".")
    string = string.replace('-', '+')
    string = string.replace('.','-')
    return string

def flipn(stack, n):
    top = stack[0:n]
    bottom = stack[n:]
    top = top[::-1]
    top = complement(top)
    return top + bottom

def flip(stack):
    stack = stack[::-1]
    stack = complement(stack)
    return stack

def nflips(s):
    s = s.strip()
    s = s + "+"
    j = 0
    for i in range(len(s)-1):
        if s[i] != s[i+1]:
            j += 1
    return j



def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('infile')
    args = parser.parse_args()
    with open(args.infile, 'rU') as infile:
        infile.readline()
        j = 1
        for line in infile:
            answer = nflips(line)
            print("Case #%s: %s" % (j, answer))
            j += 1

if __name__=="__main__":
    main()
